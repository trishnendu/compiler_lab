%{
#include "lexer_def.h"  
%}
dgt [0-9]
%%
{dgt}+ {return INTCONST;}
"while" {return WHILE_TOK;}
"for" {return FOR_TOK;}
"if" {return IF_TOK;}
"else" {return ELSE_TOK;}
[-(){}#=><+*/%^!&|;,] {return (int)yytext[0];}
%%

int main(int argc, char *argv[]){
	int token;
	if(argc != 2){
		fprintf(stderr, "Usage: ./lexer <input_file>");
		exit(1);		
	} else {
		yyin = fopen(argv[1], "r");
	}	
	while(token = yylex()){
        printf("%d\n",token);
	}
    fclose(yyin);	
    return 0;
}

yywrap(){}