%{
#ifndef INCLUDEME_H
#   include"includeme.h"
#endif
#include "clikeg.tab.h"  
%}
lalpha [a-z]
calpha [A-Z]
dgt [0-9]
%%
{dgt}+ { yylval.type.othertype = INT; char *tmp = (char *)malloc(strlen(yytext)+1); strcpy(tmp, yytext); yylval.type.place = tmp; yylval.type.code = malloc(1); yylval.type.code[0] = 0; return INTCONST;}
{dgt}*"."{dgt}+ {yylval.type.othertype = DOUBLE; char *tmp = (char *)malloc(strlen(yytext)+1); strcpy(tmp, yytext); yylval.type.place = tmp; yylval.type.code = malloc(1); yylval.type.code[0] = 0; return DOUBLECONST;}
"\'"."\'" {yylval.type.othertype = CHAR; char *tmp = (char *)malloc(strlen(yytext)+1); strcpy(tmp, yytext); yylval.type.place = tmp; yylval.type.code = malloc(1); yylval.type.code[0] = 0; return CHARCONST;}
"while" {return WHILE_TOK;}
"for" {return FOR_TOK;}
"switch"    {return SWITCH_TOK;}
"case"  {return CASE_TOK;}
"default"   {return DEFAULT_TOK;}
"if" {return IF_TOK;}
"else if" {return ELSEIF_TOK;}
"else" {return ELSE_TOK;}
"int"   {yylval.type.othertype = INT; return TYPE_TOK;}
"char"  {yylval.type.othertype = CHAR; return TYPE_TOK;}
"double" {yylval.type.othertype = DOUBLE; return TYPE_TOK;}
"void" {yylval.type.othertype = NONE; return TYPE_TOK;}
[a-zA-Z_][a-zA-Z0-9_]* {char *tmp = (char *)malloc(strlen(yytext)+1); strcpy(tmp, yytext); yylval.type.place = tmp; yylval.type.code = malloc(1); yylval.type.code[0] = 0; return ID_TOK;}
"/*"([^*]|\*+[^*/])*"*/" {}
"//".*"\n" {}
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