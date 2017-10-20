%{
#include<stdio.h>
#include"includeme.h"
#define YYDEBUG 1
extern FILE *yyin;
extern int yylineno;
extern char* yytext;
%}

%union {
    int itype;
    double dtype;
    char ctype;
    char* idtype;
    _gentype gentype;
}

%start DEBUG
%token LPAREN_TOK RPAREN_TOK CURL_LPAREN_TOK CURL_RPAREN_TOK DEFINE_TOK 
%token EQ_TOK GT_TOK LT_TOK MINUS_TOK PLUS_TOK MULT_TOK DIVIDE_TOK MOD_TOK XOR_TOK NOT_TOK AND_TOK OR_TOK SEMICOLON_TOK COMMA_TOK 
%token COMPARE_TOK GTEQ_TOK LTEQ_TOK NOT_EQ_TOK 
%token BIT_AND_TOK BIT_OR_TOK PLUS_EQ_TOK MINUS_EQ_TOK MULT_EQ_TOK DIVIDE_EQ_TOK RIGHT_SHIFT_TOK LEFT_SHIFT_TOK 
%token MINUS_MINUS_TOK PLUS_PLUS_TOK MOD_EQ_TOK  
%token MAIN_TOK RETURN_TOK

%token<itype> INTCONST TYPE_TOK
%token<dtype> DOUBLECONST
%token<ctype> CHARCONST
%token<idtype> ID_TOK

%type<gentype> var exp0 exp1 exp2 exp vardec
%type<idtype> ids

%left PLUS_TOK MINUS_TOK MULT_TOK DIVIDE_TOK
%%
DEBUG: vardeclines;

vardeclines: vardec vardeclines | statements;

vardec: TYPE_TOK ids    {symt_insert($2, $1);/*printf("key found %s | type found %d\n",$2,$1);*/};   

ids: ID_TOK COMMA_TOK ids 
  | ID_TOK EQ_TOK exp2 COMMA_TOK ids
  | ID_TOK SEMICOLON_TOK  
  | ID_TOK EQ_TOK exp2 SEMICOLON_TOK 
  ;   


statements: exp SEMICOLON_TOK statements
    | condexp SEMICOLON_TOK statements
    | exp SEMICOLON_TOK | condexp SEMICOLON_TOK
    ;

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

exp: ID_TOK EQ_TOK exp2 {symt_update($1,$3.val); $$ = $3;}
    | ID_TOK PLUS_EQ_TOK exp2
    | ID_TOK MINUS_EQ_TOK exp2
    | ID_TOK MULT_EQ_TOK exp2
    | ID_TOK DIVIDE_EQ_TOK exp2
    | ID_TOK MOD_EQ_TOK exp2
    | exp0 
    ;

exp2: LPAREN_TOK exp2 RPAREN_TOK { }
    | exp1 PLUS_TOK exp2    { }
    | exp1 MINUS_TOK exp2   { }
    | exp1     
    ;

exp1: var MULT_TOK exp1 { }
    | var DIVIDE_TOK exp1 { }
    | var MOD_TOK exp1 { }
    | var 
    | exp0 
    ;

exp0: ID_TOK PLUS_PLUS_TOK { }
    | ID_TOK MINUS_MINUS_TOK { }
    | PLUS_PLUS_TOK ID_TOK          {  }
    | MINUS_MINUS_TOK ID_TOK       { }
    ;

var: ID_TOK     {symt_getval($1, &$$);}
    | INTCONST      { $$.val.ival =  $1; $$.datatype = INT;}
    | DOUBLECONST   { $$.datatype = DOUBLE; $$.val.dval = $1; }
    | CHARCONST { $$.datatype = CHAR; $$.val.cval = $1; }
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
	    fprintf(stdout, "End of input file :)\n");
    fclose(yyin);
    printhashtable();
    return 0;
}

void yyerror (char const *s) {
    fprintf(stderr, "Parsing error :( - %s \n", yytext);
}