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
FILE *fpout;
int tmpcnt;
%}

%union {
    struct t{
        _datatype othertype;
        char *idtype;
        char *place;
        char *code;
    } type;
}

%start DEBUG
%token LPAREN_TOK RPAREN_TOK CURL_LPAREN_TOK CURL_RPAREN_TOK DEFINE_TOK 
%token EQ_TOK GT_TOK LT_TOK MINUS_TOK PLUS_TOK MULT_TOK DIVIDE_TOK MOD_TOK XOR_TOK NOT_TOK AND_TOK OR_TOK COLON_TOK SEMICOLON_TOK COMMA_TOK 
%token SWITCH_TOK CASE_TOK DEFAULT_TOK WHILE_TOK FOR_TOK IF_TOK ELSE_TOK ELSEIF_TOK COMPARE_TOK GTEQ_TOK LTEQ_TOK NOT_EQ_TOK 
%token BIT_AND_TOK BIT_OR_TOK PLUS_EQ_TOK MINUS_EQ_TOK MULT_EQ_TOK DIVIDE_EQ_TOK RIGHT_SHIFT_TOK LEFT_SHIFT_TOK 
%token MINUS_MINUS_TOK PLUS_PLUS_TOK MOD_EQ_TOK ERROR_TOK
%token RETURN_TOK

%token<type> INTCONST TYPE_TOK DOUBLECONST CHARCONST
%token<type> ID_TOK

%left PLUS_TOK MINUS_TOK
%left MULT_TOK DIVIDE_TOK
%nonassoc UMINUS

%type<type> var exp0 exp2 exp exp3 exp4
%%

DEBUG: condexp DEBUG | exp DEBUG | %empty

nonfunctionblock: exp SEMICOLON_TOK;

ifstatement: IF_TOK condexp nonfunctionblock ifstatementex
    | IF_TOK condexp nonfunctionblock ifstatementex ELSE_TOK nonfunctionblock
    ;

ifstatementex: %empty

condexp: CURL_LPAREN_TOK exp4 CURL_RPAREN_TOK;

exp4: LPAREN_TOK exp4 RPAREN_TOK { $$ = $2; }
    | exp3 OR_TOK exp4 { fprintf(fpout,"||,%s,%s,tmp%d\n", $1.idtype, $3.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt); }
    | exp3 AND_TOK exp4 { fprintf(fpout,"&&,%s,%s,tmp%d\n", $1.idtype, $3.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt); }
    | NOT_TOK exp4 { fprintf(fpout,"!,%s, ,tmp%d\n", $2.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt); }
    | exp3
    ;

exp3: LPAREN_TOK exp3 RPAREN_TOK { $$ = $2; }
    | exp2 LT_TOK exp2 { fprintf(fpout,"<,%s,%s,tmp%d\n", $1.idtype, $3.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt); }
    | exp2 GT_TOK exp2 { fprintf(fpout,">,%s,%s,tmp%d\n", $1.idtype, $3.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt); }
    | exp2 GTEQ_TOK exp2 { fprintf(fpout,">=,%s,%s,tmp%d\n", $1.idtype, $3.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt); } 
    | exp2 LTEQ_TOK exp2 { fprintf(fpout,"<=,%s,%s,tmp%d\n", $1.idtype, $3.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt); }
    | exp2 COMPARE_TOK exp2 { fprintf(fpout,"==,%s,%s,tmp%d\n", $1.idtype, $3.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt); }
    | exp2 NOT_EQ_TOK exp2 { fprintf(fpout,"!=,%s,%s,tmp%d\n", $1.idtype, $3.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt); }
    | exp2
    | exp
    ;

exp: ID_TOK EQ_TOK exp2     {  $$ = $1; /*$$ = doesexist($1, symt_gettype($1)); check_compatibility($$, $3);*/ fprintf(fpout,"=,%s, ,%s\n", $1.idtype, $3.idtype); }
    | ID_TOK PLUS_EQ_TOK exp2   {  $$ = $1; /*$$ = doesexist($1, symt_gettype($1)); check_compatibility($$, $3);*/ fprintf(fpout,"+,%s,%s,%s\n", $1.idtype, $3.idtype, $1.idtype); }
    | ID_TOK MINUS_EQ_TOK exp2  {  $$ = $1; /*$$ = doesexist($1, symt_gettype($1)); check_compatibility($$, $3);*/ fprintf(fpout,"-,%s,%s,%s\n", $1.idtype, $3.idtype, $1.idtype); }
    | ID_TOK MULT_EQ_TOK exp2   {  $$ = $1; /*$$ = doesexist($1, symt_gettype($1)); check_compatibility($$, $3);*/ fprintf(fpout,"*,%s,%s,%s\n", $1.idtype, $3.idtype, $1.idtype); }
    | ID_TOK DIVIDE_EQ_TOK exp2 {  $$ = $1; /*$$ = doesexist($1, symt_gettype($1)); check_compatibility($$, $3);*/ fprintf(fpout,"/,%s,%s,%s\n", $1.idtype, $3.idtype, $1.idtype); }
    | ID_TOK MOD_EQ_TOK exp2    { /*  
        if(symt_gettype($1)!=INT || $3!=INT)    
            printf("Modulo operation is not permitted on <int> only\n");
        $$ = INT;*/ }
    | exp0
    ;

exp2: LPAREN_TOK exp2 RPAREN_TOK    {   $$ = $2; }
    | MINUS_TOK exp2 { fprintf(fpout,"-,%d,%s,tmp%d\n", 0, $2.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt); } %prec UMINUS
    | exp2 PLUS_TOK exp2    {   $$.othertype = MAX($1.othertype, $3.othertype); fprintf(fpout,"+,%s,%s,tmp%d\n", $1.idtype, $3.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt);}
    | exp2 MINUS_TOK exp2   {   $$.othertype = MAX($1.othertype, $3.othertype); fprintf(fpout,"-,%s,%s,tmp%d\n", $1.idtype, $3.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt);}
    | exp2 MULT_TOK exp2    {   $$.othertype = MAX($1.othertype, $3.othertype); fprintf(fpout,"*,%s,%s,tmp%d\n", $1.idtype, $3.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt);}
    | exp2 DIVIDE_TOK exp2   {   $$.othertype = MAX($1.othertype, $3.othertype); fprintf(fpout,"/,%s,%s,tmp%d\n", $1.idtype, $3.idtype, ++tmpcnt); $$.idtype = (char *)malloc(10); sprintf($$.idtype,"tmp%d",tmpcnt); }
    | exp2 MOD_TOK exp2  
    | exp0
    | var
    ;

exp0: ID_TOK PLUS_PLUS_TOK  {  $$ = $1; /*$$ = doesexist($1, symt_gettype($1));*/ fprintf(fpout,"+,%s,1,%s\n", $1.idtype, $1.idtype); } 
    | ID_TOK MINUS_MINUS_TOK    {  $$=$1 ; /*$$ = doesexist($1, symt_gettype($1));*/ fprintf(fpout,"-,%s,1,%s\n", $1.idtype, $1.idtype); }
    | PLUS_PLUS_TOK ID_TOK  { $$ = $2; /*$$ = doesexist($2, symt_gettype($2)); */ fprintf(fpout,"+,%s,1,%s\n", $2.idtype, $2.idtype); }
    | MINUS_MINUS_TOK ID_TOK    { $$ = $2; /*$$.othertype = doesexist($2, symt_gettype($2)); */  fprintf(fpout,"-,%s,1,%s\n", $2.idtype, $2.idtype); }
    ;

var: ID_TOK { $$ = $1; /*$$.othertype = doesexist($1.type.idtype, symt_gettype($1.type.idtype));*/ }
    | INTCONST  { $$ = $1;}
    | DOUBLECONST { $$ = $1;}
    | CHARCONST { $$ = $1;}
    ;
   
%%
void concat(char *dest, char *src){
    int l1, l2;
    l1 = strlen(dest);
    l2 = strlen(src);
    dest = malloc(l1 + l2 + 1);
    sprintf(dest,"%s%s", dest, src);
}

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
    yydebug = 1;
	if(argc != 2){
		yytext = stdin;
        //fprintf(stderr, "Usage: ./lexer <input_file>");
		//exit(1);		
	} else {
		yyin = fopen(argv[1], "r");
    }	
    fpout = fopen("threeaddresscode.txt","w");
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