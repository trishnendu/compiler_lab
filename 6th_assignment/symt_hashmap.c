#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifndef INCLUDEME_H
#   include"includeme.h"
#endif
#define HASHKEY 101
#define HASHSIZE 32
#define GLOBAL 0

typedef struct t{
    char name[50];
    _datatype type; 
    int scope;
    struct t *next;
} symt_node;

symt_node* symt[HASHSIZE];
char printtype[][10] = {"none\0", "char\0", "int\0", "double\0"};   

int printhashtable();

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
    for(tmp = &symt[hashkey]; *tmp != (symt_node*)0; *tmp = (*tmp)->next);
    *tmp = (symt_node *)malloc(sizeof(symt_node));
    strcpy((*tmp)->name, key);
    (*tmp)->type = type;
    (*tmp)->next = (symt_node *)0;
    //printf("inserted key %s hashval %d\n",key,symt_hashfunc(key));
    //printhashtable();
    return 0;
}

_datatype symt_gettype(char key[]){ 
    int hashkey = symt_hashfunc(key);
    symt_node *tmp;
    for(tmp = symt[hashkey]; tmp != (symt_node*)0; tmp = tmp->next){
        if(tmp && !strcmp(tmp->name, key)){
            return tmp->type;
        }
    }
    //printf("NOthing FoUnd\n");
    return NONE;
} 

int printhashtable(){
    int i, flag = 1;
    for(i = 0; i < HASHSIZE; i++){
        if(symt[i]){
            if(flag){
                printf("======== PRINTING HASHTABLE ============\n");
                flag = 0;
            }
            printf("%d ",i);
            symt_node *tmp;
            for(tmp = symt[i]; tmp != (symt_node *)0; tmp = tmp->next){
                printf(" -> (%s,'%s') -> ", tmp->name, printtype[tmp->type]);
            }
            printf("null\n");
        }
    }
    if(flag)    printf("Nothing found in hashtable :(\n");
    return 0;
}
/*
int main(){
    char s[50];
    //sprintf(s,"abc");
    symt_insert("abc\0",0);
    symt_insert("bca\0", 1);
    printhashtable();
    printf("%d", symt_gettype("bca"));
}*/