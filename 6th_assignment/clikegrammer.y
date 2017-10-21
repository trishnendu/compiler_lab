%{
#include<stdio.h>
#ifndef INCLUDEME_H
#   include"includeme.h"
#endif
#define YYDEBUG 1
extern FILE *yyin;
extern int yylineno;
extern char* yytext;
extern char printtype[][10];    
%}

%union {
    char* idtype;
    _datatype othertype;
}

%start DEBUG
%token LPAREN_TOK RPAREN_TOK CURL_LPAREN_TOK CURL_RPAREN_TOK DEFINE_TOK 
%token EQ_TOK GT_TOK LT_TOK MINUS_TOK PLUS_TOK MULT_TOK DIVIDE_TOK MOD_TOK XOR_TOK NOT_TOK AND_TOK OR_TOK SEMICOLON_TOK COMMA_TOK 
%token WHILE_TOK FOR_TOK IF_TOK ELSE_TOK COMPARE_TOK GTEQ_TOK LTEQ_TOK NOT_EQ_TOK 
%token BIT_AND_TOK BIT_OR_TOK PLUS_EQ_TOK MINUS_EQ_TOK MULT_EQ_TOK DIVIDE_EQ_TOK RIGHT_SHIFT_TOK LEFT_SHIFT_TOK 
%token MINUS_MINUS_TOK PLUS_PLUS_TOK MOD_EQ_TOK ERROR_TOK
%token MAIN_TOK RETURN_TOK

%token<othertype> INTCONST TYPE_TOK DOUBLECONST CHARCONST
%token<idtype> ID_TOK

%left PLUS_TOK MINUS_TOK MULT_TOK DIVIDE_TOK
%type<othertype> var vardec ids
%%
DEBUG: START;

START:  returntype MAIN_TOK LPAREN_TOK RPAREN_TOK block funcdeflist;

vardeclines: vardec vardeclines | %empty;

vardec: TYPE_TOK ids   {symt_insert($2, $1);}
        ; 

ids: ID_TOK COMMA_TOK ids 
  | ID_TOK EQ_TOK exp2 COMMA_TOK ids
  | ID_TOK SEMICOLON_TOK
  | ID_TOK EQ_TOK exp2 SEMICOLON_TOK 
  ;   

funcdeflist: funcdef funcdeflist | %empty;

funcdef: returntype ID_TOK LPAREN_TOK arglist RPAREN_TOK block;

returnstatement: RETURN_TOK exp2 SEMICOLON_TOK;
returntype: TYPE_TOK | %empty;

arglist: TYPE_TOK ID_TOK arglistex | %empty;
arglistex: COMMA_TOK TYPE_TOK ID_TOK arglistex | COMMA_TOK TYPE_TOK ID_TOK;

funccall: ID_TOK LPAREN_TOK paramlist RPAREN_TOK SEMICOLON_TOK;
paramlist: exp COMMA_TOK paramlist | exp;

block: CURL_LPAREN_TOK vardeclines statements CURL_RPAREN_TOK 
    | CURL_LPAREN_TOK vardeclines CURL_RPAREN_TOK 
    ;

nonfunctionblock: exp SEMICOLON_TOK | ifstatement | loopstatement | returnstatement | funccall | block;

statements: exp SEMICOLON_TOK statements  
    | ifstatement statements
    | loopstatement statements
    | returnstatement statements
    | funccall statements
    | exp SEMICOLON_TOK | ifstatement | loopstatement | returnstatement | funccall
    ;

ifstatement: IF_TOK condexp nonfunctionblock
    | IF_TOK condexp nonfunctionblock ELSE_TOK nonfunctionblock
    ;

loopstatement: WHILE_TOK condexp nonfunctionblock
            | FOR_TOK LPAREN_TOK forpart1 forpart2 forpart3 RPAREN_TOK nonfunctionblock
            ;

forpart1: varinitlist | vardec | SEMICOLON_TOK;
varinitlist: ID_TOK EQ_TOK exp2 COMMA_TOK varinitlist | ID_TOK EQ_TOK exp2 SEMICOLON_TOK;

forpart2: exp4 forpart2ex SEMICOLON_TOK | SEMICOLON_TOK;
forpart2ex: COMMA_TOK exp4 forpart2ex | %empty;

forpart3: exp forpart3ex | %empty;
forpart3ex: COMMA_TOK exp forpart3ex | %empty;

condexp: LPAREN_TOK exp4 RPAREN_TOK;

exp4: LPAREN_TOK exp4 RPAREN_TOK
    | exp3 OR_TOK exp4
    | exp3 AND_TOK exp4
    | NOT_TOK exp4
    | exp3
    ;

exp3: LPAREN_TOK exp3 RPAREN_TOK
    | exp2 LT_TOK exp2
    | exp2 GT_TOK exp2 
    | exp2 GTEQ_TOK exp2 
    | exp2 LTEQ_TOK exp2 
    | exp2 COMPARE_TOK exp2 
    | exp2 NOT_EQ_TOK exp2
    | exp2
    ;

exp: ID_TOK EQ_TOK exp2
    | ID_TOK PLUS_EQ_TOK exp2
    | ID_TOK MINUS_EQ_TOK exp2
    | ID_TOK MULT_EQ_TOK exp2
    | ID_TOK DIVIDE_EQ_TOK exp2
    | ID_TOK MOD_EQ_TOK exp2
    | exp0
    ;

exp2: LPAREN_TOK exp2 RPAREN_TOK
    | exp1 PLUS_TOK exp2
    | exp1 MINUS_TOK exp2
    | exp1
    ;

exp1: var MULT_TOK exp1
    | var DIVIDE_TOK exp1
    | var MOD_TOK exp1
    | var
    | exp0
    | funccall
    ;

exp0: ID_TOK PLUS_PLUS_TOK
    | ID_TOK MINUS_MINUS_TOK
    | PLUS_PLUS_TOK ID_TOK
    | MINUS_MINUS_TOK ID_TOK
    ;

var: ID_TOK {$$ = symt_gettype($1);}
    | INTCONST
    | DOUBLECONST
    | CHARCONST
    ;
   
%%

int main(int argc, char *argv[]){
	int token;
    yydebug = 0;
	if(argc != 2){
		yytext = stdin;
        //fprintf(stderr, "Usage: ./lexer <input_file>");
		//exit(1);		
	} else {
		yyin = fopen(argv[1], "r");
	}	
    if(!yyparse());
	    fprintf(stdout, "Total %d line parsed successfully :)\n", yylineno);
    fclose(yyin);
    printhashtable();
    return 0;
}

void yyerror (char const *s) {
    fprintf(stderr, "@line no - %d: Parsing error @symbol '%s' :( - %s \n", yylineno, yytext, s);
}