%{
#include "lexer_def.h"  
%}
lalpha [a-z]
calpha [A-Z]
dgt [0-9]
%%
{dgt}+ {return INTCONST;}
[a-zA-Z_][a-zA-Z0-9_]* {return INTCONST;}
"/*"([^*]|\*+[^*/])*"*/" {}
"while" {return WHILE_TOK;}
"for" {return FOR_TOK;}
"if" {return IF_TOK;}
"else" {return ELSE_TOK;}
"==" {return COMPARE_TOK;}
">=" {return GTEQ_TOK;}
"<=" {return LTEQ_TOK;}
"!=" {return NOT_EQ_TOK;}
"&&" {return BIT_AND_TOK;}
"||" {return BIT_OR_TOK;}
"+=" {return PLUS_EQ_TOK;}
"-=" {return MINUS_EQ_TOK;}
"/=" {return DIVIDE_EQ_TOK;}
"%=" {return MOD_EQ_TOK;}
">>" {return RIGHT_SHIFT_TOK;}
"<<" {return LEFT_SHIFT_TOK;}
"--" {return MINUS_MINUS_TOK;}
"++" {return PLUS_PLUS_TOK;}
[-(){}#=><+\*/%^!&|;,] {return (int)yytext[0];}
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