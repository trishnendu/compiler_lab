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
    int itype;
    double dtype;
    char ctype;
    char* idtype;
    _gentype gentype;
}

%start DEBUG
%token<itype> LPAREN_TOK RPAREN_TOK CURL_LPAREN_TOK CURL_RPAREN_TOK DEFINE_TOK 
%token<itype> EQ_TOK GT_TOK LT_TOK MINUS_TOK PLUS_TOK MULT_TOK DIVIDE_TOK MOD_TOK XOR_TOK NOT_TOK AND_TOK OR_TOK SEMICOLON_TOK COMMA_TOK 
%token<itype> COMPARE_TOK GTEQ_TOK LTEQ_TOK NOT_EQ_TOK 
%token<itype> BIT_AND_TOK BIT_OR_TOK PLUS_EQ_TOK MINUS_EQ_TOK MULT_EQ_TOK DIVIDE_EQ_TOK RIGHT_SHIFT_TOK LEFT_SHIFT_TOK 
%token<itype> MINUS_MINUS_TOK PLUS_PLUS_TOK MOD_EQ_TOK  
%token<itype> MAIN_TOK RETURN_TOK

%token<itype> INTCONST TYPE_TOK
%token<dtype> DOUBLECONST
%token<ctype> CHARCONST
%token<idtype> ID_TOK

%type<gentype> var exp1 exp2 exp vardec
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
    | exp2 | exp
    ;

exp: ID_TOK EQ_TOK exp2 {   
            _gentype tmp; 
            if(symt_getval($1, &tmp) || symt_update($1,$3))
                printf("@line no %d - ERROR: use before declaration! variable \'%s\' is not declared\n",yylineno,$1);
            if(tmp.datatype != $3.datatype)  
                printf("@line no %d - WARNING: type mismatch! trying to assign <%s> in <%s>\n" \ 
                ,yylineno, printtype[$3.datatype], printtype[tmp.datatype]);
            $$ = $3;    
           }
    | ID_TOK PLUS_EQ_TOK exp2
    | ID_TOK MINUS_EQ_TOK exp2
    | ID_TOK MULT_EQ_TOK exp2
    | ID_TOK DIVIDE_EQ_TOK exp2
    | ID_TOK MOD_EQ_TOK exp2
    | exp1
    ;

exp2: LPAREN_TOK exp2 RPAREN_TOK { $$ = $2; }
    | exp2 PLUS_TOK exp1    { 
        $$.datatype = $1.datatype > $3.datatype ? $1.datatype : $2.datatype; 
        switch($$.datatype){
            case DOUBLE:  switch($1.datatype){
                            case DOUBLE:  switch($3.datatype){
                                case CHAR:  $$.val.dval = $1.val.dval + $3.val.chval;
                                            break;
                                case INT:  $$.val.dval = $1.val.dval + $3.val.ival;
                                            break;
                                case DOUBLE:  $$.val.dval = $1.val.dval + $3.val.dval;
                                            break;
                            }   break;
                            case INT:   $$.val.dval = $1.val.ival + $3.val.dval;
                                        break;
                            case CHAR:  $$.val.dval = $1.val.chval + $3.val.ival;
                                        break;
            }   break;
            case INT:  switch($1.datatype){
                            case INT:  switch($3.datatype){
                                case CHAR:  $$.val.ival = $1.val.ival + $3.val.chval;
                                            break;
                                case INT:  $$.val.ival = $1.val.ival + $3.val.ival;
                                            break;
                            }   break;
                            case CHAR:  $$.val.ival = $1.val.chval + $3.val.ival;
                                        break;
            }   break;
            case CHAR:  $$.val.chval = $1.val.chval + $3.val.chval;
                        break;
        }
    }
    | exp2 MINUS_TOK exp1   { 
        $$.datatype = $1.datatype > $3.datatype ? $1.datatype : $2.datatype; 
        switch($$.datatype){
            case DOUBLE:  switch($1.datatype){
                            case DOUBLE:  switch($3.datatype){
                                case CHAR:  $$.val.dval = $1.val.dval - $3.val.chval;
                                            break;
                                case INT:  $$.val.dval = $1.val.dval - $3.val.ival;
                                            break;
                                case DOUBLE:  $$.val.dval = $1.val.dval - $3.val.dval;
                                            break;
                            }   break;
                            case INT:   $$.val.dval = $1.val.ival - $3.val.dval;
                                        break;
                            case CHAR:  $$.val.dval = $1.val.chval - $3.val.ival;
                                        break;
            }   break;
            case INT:  switch($1.datatype){
                            case INT:  switch($3.datatype){
                                case CHAR:  $$.val.ival = $1.val.ival - $3.val.chval;
                                            break;
                                case INT:  $$.val.ival = $1.val.ival - $3.val.ival;
                                            break;
                            }   break;
                            case CHAR:  $$.val.ival = $1.val.chval - $3.val.ival;
                                        break;
            }   break;
            case CHAR:  $$.val.chval = $1.val.chval - $3.val.chval;
                        break;
        }
    }
    | exp2 DIVIDE_TOK exp1   { 
        $$.datatype = $1.datatype > $3.datatype ? $1.datatype : $2.datatype; 
        switch($$.datatype){
            case DOUBLE:  switch($1.datatype){
                            case DOUBLE:  switch($3.datatype){
                                case CHAR:  $$.val.dval = $1.val.dval / $3.val.chval;
                                            break;
                                case INT:  $$.val.dval = $1.val.dval / $3.val.ival;
                                            break;
                                case DOUBLE:  $$.val.dval = $1.val.dval / $3.val.dval;
                                            break;
                            }   break;
                            case INT:   $$.val.dval = $1.val.ival / $3.val.dval;
                                        break;
                            case CHAR:  $$.val.dval = $1.val.chval / $3.val.ival;
                                        break;
            }   break;
            case INT:  switch($1.datatype){
                            case INT:  switch($3.datatype){
                                case CHAR:  $$.val.ival = $1.val.ival / $3.val.chval;
                                            break;
                                case INT:  $$.val.ival = $1.val.ival / $3.val.ival;
                                            break;
                            }   break;
                            case CHAR:  $$.val.ival = $1.val.chval / $3.val.ival;
                                        break;
            }   break;
            case CHAR:  $$.val.chval = $1.val.chval / $3.val.chval;
                        break;
        }
    }
    | exp2 MULT_TOK exp1   { 
        $$.datatype = $1.datatype > $3.datatype ? $1.datatype : $2.datatype; 
        switch($$.datatype){
            case DOUBLE:  switch($1.datatype){
                            case DOUBLE:  switch($3.datatype){
                                case CHAR:  $$.val.dval = $1.val.dval * $3.val.chval;
                                            break;
                                case INT:  $$.val.dval = $1.val.dval * $3.val.ival;
                                            break;
                                case DOUBLE:  $$.val.dval = $1.val.dval * $3.val.dval;
                                            break;
                            }   break;
                            case INT:   $$.val.dval = $1.val.ival * $3.val.dval;
                                        break;
                            case CHAR:  $$.val.dval = $1.val.chval * $3.val.ival;
                                        break;
            }   break;
            case INT:  switch($1.datatype){
                            case INT:  switch($3.datatype){
                                case CHAR:  $$.val.ival = $1.val.ival * $3.val.chval;
                                            break;
                                case INT:  $$.val.ival = $1.val.ival * $3.val.ival;
                                            break;
                            }   break;
                            case CHAR:  $$.val.ival = $1.val.chval * $3.val.ival;
                                        break;
            }   break;
            case CHAR:  $$.val.chval = $1.val.chval * $3.val.chval;
                        break;
        }
    }
    | exp2 MOD_TOK exp1   { 
                            if($1.datatype==$3.datatype==INT) {
                                $$.val.ival = $1.val.ival % $3.val.ival;
                                $$.datatype = INT;
                            }   else    printf("@line no %d - ERROR: modulo operation is only permited on <int>\n");
                          }
    | exp1 { $$ = $1; }
    ;

exp1: ID_TOK PLUS_PLUS_TOK { }
    | ID_TOK MINUS_MINUS_TOK { }
    | PLUS_PLUS_TOK ID_TOK          {  }
    | MINUS_MINUS_TOK ID_TOK       { }
    | var { $$ = $1;}
    ;

var: ID_TOK     {symt_getval($1, &$$);}
    | INTCONST      { $$.val.ival =  $1; $$.datatype = INT;}
    | DOUBLECONST   { $$.datatype = DOUBLE; $$.val.dval = $1; }
    | CHARCONST { $$.datatype = CHAR; $$.val.chval = $1; }
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
    fprintf(stderr, "Parsing error :( - %s \n", s);
}