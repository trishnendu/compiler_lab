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
    double d;
} U;

int valreturn(U d){
    U f = d;
    printf("%d\n",f.c);
    return 0;
}

int main(){
    U s,u,v;
    s.a = 4;
    u.c = 'G';
    v.d = 10.0432;
    printf("%e\n",s.d*v.d);
    //valreturn((U)'3');
    return 0;
}