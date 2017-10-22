%{
#include "clikegrammer.tab.h"  
int lineno = 1;
%}
lalpha [a-z]
calpha [A-Z]
dgt [0-9]
%%
{dgt}+ {return INTCONST;}
{dgt}*"."{dgt}+ {return DOUBLECONST;}
"\'"."\'"   {return CHARCONST;}
"main" {return MAIN_TOK;}
"while" {return WHILE_TOK;}
"for" {return FOR_TOK;}
"if" {return IF_TOK;}
"else" {return ELSE_TOK;}
"int"|"char"|"char*"|"double" {return TYPE_TOK;}
"return" {return RETURN_TOK;}
[a-zA-Z_][a-zA-Z0-9_]* {return ID_TOK;}
"/*"([^*]|\*+[^*/])*"*/" {}
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
";" {return SEMICOLON_TOK;}
"-" {return MINUS_TOK;}
"+" {return PLUS_TOK;}
"*" {return MULT_TOK;}
"/" {return DIVIDE_TOK;}
"%" {return MOD_TOK;}
"^" {return XOR_TOK;}
"!" {return NOT_TOK;}
"&" {return AND_TOK;}
"|" {return OR_TOK;}
"," {return COMMA_TOK;}
"(" {return LPAREN_TOK;}
")" {return RPAREN_TOK;}
"{" {return CURL_LPAREN_TOK;}
"}" {return CURL_RPAREN_TOK;}
"=" {return EQ_TOK;}
">" {return GT_TOK;}
"<" {return LT_TOK;}
[ \t\n] ;
%%

int yywrap(){
    return 1;
}