#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifndef INCLUDEME_H
#   include"includeme.h"
#endif
#define HASHKEY 101
#define HASHSIZE 32

typedef struct t{
    char name[50];
    _datatype type; 
    struct t *next;
} symt_node;

typedef struct ta{
    symt_node* symt[HASHSIZE];
    struct ta *prev;
    struct ta *next;    
} symt_table;

symt_table global;
symt_table *curscope = &global;

char printtype[][10] = {"none\0", "char\0", "int\0", "double\0"};   

int printhashtable();

int newscope(){
    curscope->next = (symt_table *)malloc(sizeof(symt_table));
    curscope->next->prev = curscope;
    curscope = curscope->next;
    curscope->next = (symt_table *)0;
    for(int i = 0; i < HASHSIZE; i++)
        curscope->symt[i] = (symt_node *)0;
    return 0; 
}

int endscope(){
    if(curscope->prev){
        curscope = curscope->prev;
        free(curscope->next);
        curscope->next = (symt_table *)0;
        return 0;
    }
    printf("Can't delete global scope\n");
    return 1;
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

int symt_insert(char key[], int type){
    int hashkey = symt_hashfunc(key);
    symt_node **tmp;
    for(tmp = &(curscope->symt[hashkey]); *tmp != (symt_node*)0; *tmp = (*tmp)->next);
    *tmp = (symt_node *)malloc(sizeof(symt_node));
    strcpy((*tmp)->name, key);
    (*tmp)->type = type;
    (*tmp)->next = (symt_node *)0;
    //printf("inserted key '%s' @hashval %d\n",key,symt_hashfunc(key));
    //printhashtable();
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
        tmpscope = tmpscope->prev;
    }
    //printf("NOthing FoUnd\n");
    return NONE;
} 

int printhashtable(){
    symt_table *table = &global;
    int scopelevel = 0;
    while(table){
        int i;
        int flag = 1;
        for(i = 0; i < HASHSIZE; i++){
            if(table->symt[i]){
                if(flag){
                    printf("\n======== SCOPE LEVEL %d ============\n", scopelevel);
                    flag = 0;
                }
                printf("%d ",i);
                symt_node *tmp;
                for(tmp = table->symt[i]; tmp != (symt_node *)0; tmp = tmp->next){
                    printf(" -> (%s,'%s') -> ", tmp->name, printtype[tmp->type]);
                }
                printf("null\n");
            }
        }
        if(flag)    printf("No variables declared in scope level %d\n",scopelevel);
        else    printf("===================================\n");
        table = table->next;
        scopelevel++;
    }
    printf("\n");
    return 0;
}
/*
int main(){
    char s[50];
    //sprintf(s,"abc");
    symt_insert("abc\0",1);
    symt_insert("bca\0", 2);
    //printhashtable();
    newscope();
    //symt_insert("i",3);
    //printhashtable();
    //endscope();
    //printf("%d\n",curscope);
    printhashtable();
    printf("%d", symt_gettype("bcaf"));
    endscope();
}*/