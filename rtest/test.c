#include<stdio.h>

struct {
    int a;
    union {
        int i;
        double d;
    };
} s;

typedef union{
    int a;
    char c;
} U;

int valreturn(U d){
    U f = d;
    printf("%d\n",f.c);
    return 0;
}

int main(){
    int i = 9;
    char c = 'c';
    float f = 9.843;
    double d = f;
    s.a = 4;
    s.i = 7;
    s.d = 10.0432;
    //printf("%d %e\n",s.a,s.d);
    valreturn((U)'3');
    return 0;
}