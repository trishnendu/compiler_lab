%{
#ifndef INCLUDEME_H
#   include"includeme.h"
#endif
#include "testbison.tab.h"  
%}
lalpha [a-z]
calpha [A-Z]
dgt [0-9]
%%
{dgt}+ {yylval = (YYSTYPE) atoi(yytext); return INTCONST;}
{dgt}*"."{dgt}+ {yylval = (YYSTYPE) atof(yytext); return DOUBLECONST;}
"\'"."\'" {yylval = (YYSTYPE) yytext[1]; return CHARCONST;}
"int"   {yylval = (YYSTYPE)INT; return TYPE_TOK;}
"char"  {yylval = (YYSTYPE)CHAR; return TYPE_TOK;}
"double" {yylval = (YYSTYPE)DOUBLE; return TYPE_TOK;}
[a-zA-Z_][a-zA-Z0-9_]* {char *tmp = (char *)malloc(strlen(yytext)+1); strcpy(tmp, yytext); yylval = (YYSTYPE)tmp; return ID_TOK;}
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
"\n" {yylineno++;}
[ \t\n] {}
%%

int yywrap(){
    return 1;
}