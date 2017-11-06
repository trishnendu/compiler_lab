#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifndef INCLUDEME_H
#   include"includeme.h"
#endif
#define HASHKEY 101
#define HASHSIZE 4

typedef struct t{
    char name[50];
    _datatype type;
    _vartype type1; 
    struct t *next;
} symt_node;

typedef struct ta{
    symt_node* symt[HASHSIZE];
    struct ta *up;
    struct ta *down;
    struct ta *next;    
} symt_table;

symt_table global_scope;
symt_table *curscope = &global_scope;

char printtype[][10] = {"void\0", "char\0", "int\0", "double\0"};
char printtype1[][10] = {"variable\0", "function\0"};   

int printhashtable();

int symt_wrapup(){
    wrapup(&global_scope);
}

int symt_newscope(){
    symt_table *tmpnode = (symt_table *)malloc(sizeof(symt_table));
    tmpnode->next = curscope->down;
    tmpnode->up = curscope;
    tmpnode->down = (symt_table *)0;
    curscope->down = tmpnode;
    curscope = curscope->down;
    for(int i = 0; i < HASHSIZE; i++)
        curscope->symt[i] = (symt_node *)0;
    //printf("scope created\n");
    return 0; 
}

int symt_endscope(){
    if(!curscope->up){
        printf("Can't delete global_scope scope\n");
        return 1;
    }
    curscope = curscope->up;
    //printf("scope deleted\n");
    return 0;
}

int wrapup(symt_table *root){
    symt_table *cur = root->down, *prev = (symt_table *)0;
    if(!cur)   return;
    while(cur){
        symt_table *swap = cur->next;
        cur->next = prev;
        prev = cur;
        cur = swap;
    }
    root->down = prev;
    for( ; prev; prev = prev->next)
        wrapup(prev);
    return 0;
}

int symt_hashfunc(char s[]){
    int hashval = 0;
    int cnt;
    for(cnt = 0; cnt < strlen(s); cnt++){
        hashval += (s[cnt] - 'A') * ((HASHKEY * (cnt+1))%HASHSIZE);
        hashval %= HASHSIZE;
    }
    return hashval;
}

int symt_insert(char key[], int type, int type1){
    int hashkey = symt_hashfunc(key);
    symt_node **tmp;
    for(tmp = &(curscope->symt[hashkey]); *tmp && (strcmp((*tmp)->name,key) || type1!=(*tmp)->type1) ; *tmp = (*tmp)->next);
    if(*tmp){    
        printf("Error redifination of same variable '%s'\n", key);
        return 1;
    }        
    *tmp = (symt_node *)malloc(sizeof(symt_node));
    strcpy((*tmp)->name, key);
    (*tmp)->type = type;
    (*tmp)->next = (symt_node *)0;
    (*tmp)->type1 = type1;
    //printf("added '%s' of <%d>\n", key, type);
    return 0;
}

_datatype symt_gettype(char key[]){ 
    int hashkey = symt_hashfunc(key);
    symt_table *tmpscope = curscope;
    symt_node *tmp;
    while(tmpscope){
        for(tmp = tmpscope->symt[hashkey]; tmp != (symt_node*)0; tmp = tmp->next){
            if(tmp && !strcmp(tmp->name, key)){
                return tmp->type;
            }
        }
        tmpscope = tmpscope->up;
    }
    return NONE;
} 

int printhashtable(){
    symt_table *downitr = &global_scope;
    int scopelevel = 0;
    while(1){
        while(1){
            int i;
            printf("{\n");
            for(i = 0; i < HASHSIZE; i++){
                if(downitr->symt[i]){
                    symt_node *tmp;
                    for(tmp = downitr->symt[i]; tmp != (symt_node *)0; tmp = tmp->next){
                        printf("\t(%s, '%s', '%s');\t", tmp->name, printtype[tmp->type], printtype1[tmp->type1]);
                    }
                    printf("\n");
                }
            }
            if(!downitr->down)  break;
            downitr = downitr->down;
       }
        while(downitr->up){
            printf("}\n");
            if(downitr->next){
                downitr = downitr->next;
                break;
            } else {
                downitr = downitr->up;
            }
        } 
        if(!downitr->up)    break;
    } 
    printf("}\n");
    return 0;
}
/*
int main(){
    symt_insert("a",1);
    newscope();
    symt_insert("ab",2);
    newscope();
    symt_insert("abcd",3);
    endscope();
    newscope();
    symt_insert("abce",3);
    endscope();
    newscope();
    symt_insert("abcf",3);
    endscope();
    endscope();
    symt_wrapup(&global_scope);
    printhashtable();
}*/