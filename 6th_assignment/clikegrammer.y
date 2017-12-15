%{
#include<stdio.h>
#ifndef INCLUDEME_H
#   include"includeme.h"
#endif
#define MAX(a,b) (((a)>(b))?(a):(b))
#define YYDEBUG 1
extern FILE *yyin;
extern int yylineno;
extern char* yytext;
extern char printtype[][10]; 
extern int curscope;   
%}

%union {
    char* idtype;
    _datatype othertype;
}

%start DEBUG
%token LPAREN_TOK RPAREN_TOK CURL_LPAREN_TOK CURL_RPAREN_TOK DEFINE_TOK 
%token EQ_TOK GT_TOK LT_TOK MINUS_TOK PLUS_TOK MULT_TOK DIVIDE_TOK MOD_TOK XOR_TOK NOT_TOK AND_TOK OR_TOK COLON_TOK SEMICOLON_TOK COMMA_TOK 
%token SWITCH_TOK CASE_TOK DEFAULT_TOK WHILE_TOK FOR_TOK IF_TOK ELSE_TOK ELSEIF_TOK COMPARE_TOK GTEQ_TOK LTEQ_TOK NOT_EQ_TOK 
%token BIT_AND_TOK BIT_OR_TOK PLUS_EQ_TOK MINUS_EQ_TOK MULT_EQ_TOK DIVIDE_EQ_TOK RIGHT_SHIFT_TOK LEFT_SHIFT_TOK 
%token MINUS_MINUS_TOK PLUS_PLUS_TOK MOD_EQ_TOK ERROR_TOK
%token RETURN_TOK

%token<othertype> INTCONST TYPE_TOK DOUBLECONST CHARCONST
%token<idtype> ID_TOK

%left PLUS_TOK MINUS_TOK MULT_TOK DIVIDE_TOK

%type<othertype> var vardec exp0 exp1 exp2 exp funccall funcdef 
%%

DEBUG: START 

START: vardec START | funcdef START | %empty ;

vardec: TYPE_TOK ID_TOK vardecex SEMICOLON_TOK  { symt_insert($2, $1); } 
    | TYPE_TOK ID_TOK EQ_TOK exp2 vardecex SEMICOLON_TOK 
    ;

vardecex: vardecex COMMA_TOK ID_TOK  
  | vardecex COMMA_TOK ID_TOK EQ_TOK exp2  
  | %empty
  ;   

funcdef: TYPE_TOK ID_TOK LPAREN_TOK arglist RPAREN_TOK block  {   symt_insert($2, $1);  }  
    |    ID_TOK LPAREN_TOK arglist RPAREN_TOK block    {   symt_insert($1, NONE);   } 
    ;

returnstatement: RETURN_TOK exp2 SEMICOLON_TOK;

arglist: TYPE_TOK ID_TOK arglistex | %empty;
arglistex: COMMA_TOK TYPE_TOK ID_TOK arglistex | COMMA_TOK TYPE_TOK ID_TOK;

funccall: ID_TOK LPAREN_TOK paramlist RPAREN_TOK SEMICOLON_TOK {  $$ = symt_gettype($1); };
paramlist: exp COMMA_TOK paramlist | exp;

nestedblock:    vardeclines estatements block estatements | vardeclines estatements;

estatements: statements | %empty;

block: CURL_LPAREN_TOK {newscope();}  nestedblock CURL_RPAREN_TOK {endscope();} ;

vardeclines: vardeclines vardec | %empty;

nonfunctionblock: exp SEMICOLON_TOK | ifstatement | loopstatement | returnstatement | funccall | block;

statements: exp SEMICOLON_TOK statements  
    | ifstatement statements
    | loopstatement statements
    | returnstatement statements
    | funccall statements
    | switchstatement statements
    | exp SEMICOLON_TOK | ifstatement | loopstatement | returnstatement | funccall | switchstatement
    ;

ifstatement: IF_TOK condexp nonfunctionblock ifstatementex
    | IF_TOK condexp nonfunctionblock ifstatementex ELSE_TOK nonfunctionblock
    ;

ifstatementex: ELSEIF_TOK condexp nonfunctionblock ifstatementex | %empty;

switchstatement: SWITCH_TOK condexp switchblock

switchblock:  CURL_LPAREN_TOK vardeclines caseblocks defaultblock CURL_RPAREN_TOK

caseblocks: CASE_TOK var COLON_TOK statements caseblocks | %empty

defaultblock:   DEFAULT_TOK COLON_TOK statements caseblocks | %empty

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

exp: ID_TOK EQ_TOK exp2     {  $$ = symt_gettype($1); check_compatibility($$, $3);  }
    | ID_TOK PLUS_EQ_TOK exp2   {   $$ = symt_gettype($1); check_compatibility($$, $3);  }
    | ID_TOK MINUS_EQ_TOK exp2  {   $$ = symt_gettype($1); check_compatibility($$, $3);  }
    | ID_TOK MULT_EQ_TOK exp2   {   $$ = symt_gettype($1); check_compatibility($$, $3);  }
    | ID_TOK DIVIDE_EQ_TOK exp2 {   $$ = symt_gettype($1); check_compatibility($$, $3);  }
    | ID_TOK MOD_EQ_TOK exp2    {   
        if(symt_gettype($1)!=INT || $3!=INT)    
            printf("Modulo operation is not permitted on <int> only\n");
        $$ = INT; }
    | exp0
    ;

exp2: LPAREN_TOK exp2 RPAREN_TOK    {   $$ = $2; }
    | exp1 PLUS_TOK exp2    {   $$ = MAX($1, $3); }
    | exp1 MINUS_TOK exp2   {   $$ = MAX($1, $3); }
    | exp1
    ;

exp1: var MULT_TOK exp1     {   $$ = MAX($1, $3); }
    | var DIVIDE_TOK exp1   {   $$ = MAX($1, $3); }
    | var MOD_TOK exp1  
    | var
    | exp0
    | funccall
    ;

exp0: ID_TOK PLUS_PLUS_TOK  {   $$ = symt_gettype($1);  } 
    | ID_TOK MINUS_MINUS_TOK    {   $$ = symt_gettype($1);  }
    | PLUS_PLUS_TOK ID_TOK  { $$ = symt_gettype($2); }
    | MINUS_MINUS_TOK ID_TOK    { $$ = symt_gettype($2); }
    ;

var: ID_TOK {   $$ = symt_gettype($1);  }
    | INTCONST  
    | DOUBLECONST
    | CHARCONST
    ;
   
%%
int check_compatibility(int a, int b){
    if(a == NONE || b == NONE){
        printf("@line no - %d: error - one or more variables are undeclared!!\n", yylineno);
        return 1;
    } else if(a != b){
        printf("@line no - %d: Warning - type mismatch!! trying to assign <%s> in <%s>\n", yylineno, printtype[b], printtype[a]);
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]){
	int token;
    yydebug = 1;
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
    return 0;
}

void yyerror (char const *s) {
    fprintf(stderr, "%s!! @line no - %d:  @symbol '%s' :(  \n",s ,yylineno, yytext);
}