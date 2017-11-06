#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void print(const char *s){
    printf("from func -> %d\n",strlen(s));
}


int main(void) {
    char *s;
    //s = malloc(7987);
    char arr[100];
    sprintf(arr, "%s", s);
    //print(arr);
 /*   s = "wow!! *-* ";
    printf("%d\n",s);
    s = realloc(s, 15);
    printf("%d\n",s);
    //sprintf(s,"nacsn lvdsnkjn\n");
    printf("%s %d\n",s, strlen(s));
    print(s);*/
/*	s = (char *)realloc(0, 10);
	strcpy(s, "Hel lo\n");
	s = (char *)realloc(s, 15);
	strcat(s, s);
	printf("%s %d",s,strlen(s));*/
	return 0;
}

