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
struct vardecex_tmpstruct{
    char name[50];
    _datatype type;
} buf[50];
int bufcnt;
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

%type<othertype> var vardec exp0 exp1 exp2 exp funccall funcdef vardecex
%%

DEBUG: START 

START: vardec START | funcdef START | %empty ;

vardec: TYPE_TOK ID_TOK vardecex SEMICOLON_TOK  { 
                symt_insert($2, $1, VAR); 
                while(bufcnt){
                    bufcnt--;
                    symt_insert(buf[bufcnt].name, $1, VAR);
                    if(buf[bufcnt].type)    check_compatibility($1, buf[bufcnt].type);
                }
        } 
    | TYPE_TOK ID_TOK EQ_TOK exp2 vardecex SEMICOLON_TOK  { 
                symt_insert($2, $1, VAR); 
                check_compatibility($1, $4);
                while(bufcnt){
                    bufcnt--;
                    symt_insert(buf[bufcnt].name, $1, VAR);
                    if(buf[bufcnt].type)    check_compatibility($1, buf[bufcnt].type);
                }
        }
    ;

vardecex: vardecex COMMA_TOK ID_TOK  {  strcpy(buf[bufcnt].name, $3); buf[bufcnt].type = 0; bufcnt++; }
  | vardecex COMMA_TOK ID_TOK EQ_TOK exp2  {  strcpy(buf[bufcnt].name, $3); buf[bufcnt].type = $5; bufcnt++;  }
  | %empty
     

funcdef: TYPE_TOK ID_TOK LPAREN_TOK arglist RPAREN_TOK block   {   symt_insert($2, $1, FUNC);  }  
    |    ID_TOK LPAREN_TOK arglist RPAREN_TOK block    {   symt_insert($1, NONE, FUNC);   } 
    ;

returnstatement: RETURN_TOK exp2 SEMICOLON_TOK;

arglist: TYPE_TOK ID_TOK arglistex {  strcpy(buf[bufcnt].name, $2); buf[bufcnt].type = $1; bufcnt++; }
    | %empty
    ;
arglistex: COMMA_TOK TYPE_TOK ID_TOK arglistex {  strcpy(buf[bufcnt].name, $3); buf[bufcnt].type = $2; bufcnt++; }
    | %empty
    ;

funccall: ID_TOK LPAREN_TOK paramlist RPAREN_TOK {  $$ = symt_gettype($1); };
paramlist: exp paramlistex | %empty; 
paramlistex: COMMA_TOK exp paramlistex | COMMA_TOK exp;

nestedblock:    vardeclines estatements block estatements | vardeclines estatements;

estatements: statements | %empty

block: CURL_LPAREN_TOK {
                symt_newscope();
                while(bufcnt){
                    bufcnt--;
                    symt_insert(buf[bufcnt].name, buf[bufcnt].type, VAR);
                }
        }  nestedblock CURL_RPAREN_TOK {symt_endscope();} ;

vardeclines: vardeclines vardec | %empty;

nonfunctionblock: exp SEMICOLON_TOK | ifstatement | loopstatement | returnstatement | block;

statements: exp SEMICOLON_TOK statements  
    | ifstatement statements
    | loopstatement statements
    | returnstatement statements
    | switchstatement statements
    | %empty
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

exp: ID_TOK EQ_TOK exp2     {  $$ = doesexist($1, symt_gettype($1)); check_compatibility($$, $3);  }
    | ID_TOK PLUS_EQ_TOK exp2   {   $$ = doesexist($1, symt_gettype($1)); check_compatibility($$, $3);  }
    | ID_TOK MINUS_EQ_TOK exp2  {   $$ = doesexist($1, symt_gettype($1)); check_compatibility($$, $3);  }
    | ID_TOK MULT_EQ_TOK exp2   {   $$ = doesexist($1, symt_gettype($1)); check_compatibility($$, $3);  }
    | ID_TOK DIVIDE_EQ_TOK exp2 {   $$ = doesexist($1, symt_gettype($1)); check_compatibility($$, $3);  }
    | ID_TOK MOD_EQ_TOK exp2    {   
        if(symt_gettype($1)!=INT || $3!=INT)    
            printf("Modulo operation is not permitted on <int> only\n");
        $$ = INT; }
    | exp0
    ;

exp2: LPAREN_TOK exp2 RPAREN_TOK    {   $$ = $2; }
    | exp2 PLUS_TOK exp2    {   $$ = MAX($1, $3); }
    | exp2 MINUS_TOK exp2   {   $$ = MAX($1, $3); }
    | exp2 MULT_TOK exp1     {   $$ = MAX($1, $3); }
    | exp1 DIVIDE_TOK exp1   {   $$ = MAX($1, $3); }
    | exp1 MOD_TOK exp1  
    | exp1
    ;

exp1 : exp0 | var | funccall ;  

exp0: ID_TOK PLUS_PLUS_TOK  {   $$ = doesexist($1, symt_gettype($1));  } 
    | ID_TOK MINUS_MINUS_TOK    {   $$ = doesexist($1, symt_gettype($1));  }
    | PLUS_PLUS_TOK ID_TOK  { $$ = doesexist($2, symt_gettype($2)); }
    | MINUS_MINUS_TOK ID_TOK    { $$ = doesexist($2, symt_gettype($2)) ; }
    ;

var: ID_TOK {   $$ = doesexist($1, symt_gettype($1));  }
    | INTCONST  
    | DOUBLECONST
    | CHARCONST
    ;
   
%%
int doesexist(char s[], int type){
    if(type == NONE){
        printf("@line no - %d: error - variable '%s' is undeclared!!\n", yylineno, s);
    }
    return type;
}

int check_compatibility(int a, int b){
    if(a != b){
        printf("@line no - %d: Warning - type mismatch!! trying to assign <%s> in <%s>\n", yylineno, printtype[b], printtype[a]);
        return 1;
    }
    return 0;
}

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
    symt_wrapup();
    printhashtable();
    return 0;
}

void yyerror (char const *s) {
    fprintf(stderr, "%s!! @line no - %d:  @symbol '%s' :(  \n",s ,yylineno, yytext);
}