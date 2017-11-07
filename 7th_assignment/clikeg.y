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

%type<type> var exp0 exp2 exp exp3 exp4 condexp nonfunctionblock ifstatement statement loopstatement
%%

DEBUG: nonfunctionblock {  concatcode(&$1.code, "end ",":)\n"); fprintf(fpout, "%s", $1.code);} 
    ;

nonfunctionblock: nonfunctionblock statement {$$.place = malloc(1); $$.place[0] = 0; $$.code = 0; concatcode(&$$.code, $1.code, $2.code); }
    |   statement {$$.place = malloc(1); $$.place[0] = 0; $$.code = malloc(strlen($1.code)+1); strcpy($$.code, $1.code);}
    ;

statement: exp SEMICOLON_TOK
    |   ifstatement
    |   loopstatement 
    ;

ifstatement: IF_TOK condexp nonfunctionblock ifstatementex  
                {   $$.place = malloc(10); sprintf($$.place, "tag%d", ++tmpcnt); 
                    addtocode(&$$.code, $2.code, "", "jnz", $2.place, "", $$.place);
                    strcat($$.place, ":\n"); 
                    concatcode(&$$.code, $$.place, $3.code); } 
    | IF_TOK condexp nonfunctionblock ifstatementex ELSE_TOK nonfunctionblock 
                {   char tmp[10];
                    $$.place = malloc(10); sprintf($$.place, "tag%d", ++tmpcnt); 
                    addtocode(&$$.code, $2.code, "", "jnz", $2.place, "", $$.place);
                    strcat($$.place, ":\n\t"); 
                    sprintf(tmp,"jmp,,,tag%d\n", ++tmpcnt); 
                    concatcode(&$$.code, $6.code, tmp);
                    concatcode(&$$.code, $$.place, $3.code);
                    sprintf(tmp,"tag%d:\n\t", tmpcnt);
                    concatcode(&$$.code, tmp, "");
                }
    ;

ifstatementex: %empty;

loopstatement: WHILE_TOK condexp nonfunctionblock 
                    {   char outofloop[10];
                        sprintf(outofloop, "tag%d", ++tmpcnt);
                        $$.place = malloc(10); sprintf($$.place, "tag%d", ++tmpcnt);
                        $$.code = 0;
                        concatcode(&$$.code, $$.place, ":\n\t");
                        concatcode(&$$.code, $2.code, ",jz,");
                        concatcode(&$$.code, $2.place, ",");
                        concatcode(&$$.code, outofloop, "\n");
                        concatcode(&$$.code, $3.code, $2.code);
                        concatcode(&$$.code, ",jmp,,", $$.place);
                        concatcode(&$$.code, outofloop, ":\n\t");
                    }
        ;

condexp: LPAREN_TOK exp4 RPAREN_TOK    {  $$ = $2; } ;

exp4: LPAREN_TOK exp4 RPAREN_TOK { $$ = $2; }
    | exp3 OR_TOK exp4 { addtmptoplace(&$$.place); addtocode(&$$.code, $1.code, $3.code, "||", $1.place, $3.place, $$.place); }
    | exp3 AND_TOK exp4 { addtmptoplace(&$$.place); addtocode(&$$.code, $1.code, $3.code, "&&", $1.place, $3.place, $$.place); }
    | NOT_TOK exp4 { addtmptoplace(&$$.place); addtocode(&$$.code, $2.code, "", "!", $2.place, "", $$.place); }
    | exp3
    ;

exp3: LPAREN_TOK exp3 RPAREN_TOK { $$ = $2; }
    | exp2 LT_TOK exp2 { addtmptoplace(&$$.place); addtocode(&$$.code, $1.code, $3.code, "<", $1.place, $3.place, $$.place); }
    | exp2 GT_TOK exp2 { addtmptoplace(&$$.place); addtocode(&$$.code, $1.code, $3.code, ">", $1.place, $3.place, $$.place); }
    | exp2 GTEQ_TOK exp2 { addtmptoplace(&$$.place); addtocode(&$$.code, $1.code, $3.code, ">=", $1.place, $3.place, $$.place); }
    | exp2 LTEQ_TOK exp2 { addtmptoplace(&$$.place); addtocode(&$$.code, $1.code, $3.code, "<=", $1.place, $3.place, $$.place); }
    | exp2 COMPARE_TOK exp2 { addtmptoplace(&$$.place); addtocode(&$$.code, $1.code, $3.code, "==", $1.place, $3.place, $$.place); }
    | exp2 NOT_EQ_TOK exp2 { addtmptoplace(&$$.place); addtocode(&$$.code, $1.code, $3.code, "!=", $1.place, $3.place, $$.place); }
    | exp2
    ;

exp: ID_TOK EQ_TOK exp2     {  $$.othertype = $1.othertype; $$.place = malloc(1); $$.place[0] = 0; addtocode(&$$.code, $1.code, $3.code, "=", $3.place, "", $1.place); }
    | ID_TOK PLUS_EQ_TOK exp2   {  $$.othertype = $1.othertype; $$.place = malloc(1); $$.place[0] = 0; addtocode(&$$.code, $1.code, $3.code, "+", $1.place, $3.place, $1.place); }
    | ID_TOK MINUS_EQ_TOK exp2  {  $$.othertype = $1.othertype; $$.place = malloc(1); $$.place[0] = 0; addtocode(&$$.code, $1.code, $3.code, "-", $1.place, $3.place, $1.place); }
    | ID_TOK MULT_EQ_TOK exp2   {  $$.othertype = $1.othertype; $$.place = malloc(1); $$.place[0] = 0; addtocode(&$$.code, $1.code, $3.code, "*", $1.place, $3.place, $1.place); }
    | ID_TOK DIVIDE_EQ_TOK exp2 {  $$.othertype = $1.othertype; $$.place = malloc(1); $$.place[0] = 0; addtocode(&$$.code, $1.code, $3.code, "/", $1.place, $3.place, $1.place); }
    | ID_TOK MOD_EQ_TOK exp2    {  $$.othertype = $1.othertype; $$.place = malloc(1); $$.place[0] = 0; addtocode(&$$.code, $1.code, $3.code, "%", $1.place, $3.place, $1.place); }
    | exp0
    ;

exp2: LPAREN_TOK exp2 RPAREN_TOK    {   $$ = $2; }
    | MINUS_TOK exp2 { $$.othertype = $2.othertype; addtmptoplace(&$$.place); addtocode(&$$.code, $2.code, "", "-", "0", $2.place, $$.place); } %prec UMINUS
    | exp2 PLUS_TOK exp2    {   $$.othertype = MAX($1.othertype, $3.othertype); addtmptoplace(&$$.place); addtocode(&$$.code, $1.code, $3.code, "+", $1.place, $3.place, $$.place); }
    | exp2 MINUS_TOK exp2   {   $$.othertype = MAX($1.othertype, $3.othertype); addtmptoplace(&$$.place); addtocode(&$$.code, $1.code, $3.code, "-", $1.place, $3.place, $$.place);  }
    | exp2 MULT_TOK exp2    {   $$.othertype = MAX($1.othertype, $3.othertype); addtmptoplace(&$$.place); addtocode(&$$.code, $1.code, $3.code, "*", $1.place, $3.place, $$.place);  }
    | exp2 DIVIDE_TOK exp2   {   $$.othertype = MAX($1.othertype, $3.othertype); addtmptoplace(&$$.place); addtocode(&$$.code, $1.code, $3.code, "/", $1.place, $3.place, $$.place); }
    | exp2 MOD_TOK exp2  {   $$.othertype = MAX($1.othertype, $3.othertype); addtmptoplace(&$$.place); addtocode(&$$.code, $1.code, $3.code, "%", $1.place, $3.place, $$.place); }
    | exp0
    | var
    ;

exp0: ID_TOK PLUS_PLUS_TOK  { $$.othertype = $1.othertype; addtoplace(&$$.place, $1.place);  addtocode(&$$.code, $1.code, "", "+",$1.place,"1",$1.place); } 
    | ID_TOK MINUS_MINUS_TOK    { $$.othertype = $1.othertype;  addtoplace(&$$.place, $1.place);  addtocode(&$$.code, $1.code, "", "-",$1.place,"1",$1.place); }
    | PLUS_PLUS_TOK ID_TOK  { $$.othertype = $2.othertype;  addtoplace(&$$.place, $2.place);  addtocode(&$$.code, $2.code, "", "+",$2.place,"1",$2.place); }
    | MINUS_MINUS_TOK ID_TOK    { $$.othertype = $2.othertype;  addtoplace(&$$.place, $2.place); addtocode(&$$.code, $2.code, "", "-",$2.place,"1",$2.place); }
    ;

var: ID_TOK { $$ = $1;  }
    | INTCONST  { $$ = $1; $$.code = malloc(1); $$.code[0] = 0;}
    | DOUBLECONST { $$ = $1; $$.code = malloc(1); $$.code[0] = 0;}
    | CHARCONST { $$ = $1; $$.code = malloc(1); $$.code[0] = 0;}
    ;
   
%%

void addtmptoplace(char **dest){
    *dest = (char *)malloc(10);
    sprintf(*dest,"tmp%d",++tmpcnt);
}

void addtoplace(char **dest, const char *src){  
    *dest = (char *)malloc(strlen(src)+1);
    strcpy(*dest, src);
}

void addtocode(char **dest, const char *code1, const char *code2, const char *op, const char *arg1, const char *arg2, const char *res){
    int l = 0;
    l = strlen(code1) + strlen(code2) + strlen(op) + strlen(arg1) + strlen(arg2) + strlen(res) + 4;
    *dest = (char *)malloc(l+1);
    *dest[0] = (char)0;
    
    strcat(*dest, code1);
    strcat(*dest, code2);
    sprintf(*dest,"%s%s,%s,%s,%s\n",*dest, op, arg1, arg2, res );
}

void concatcode(char **dest, const char *code1, const char *code2){
    int l = 0;
    if(*dest)   l = strlen(*dest);
    *dest = realloc(*dest, l+strlen(code1)+strlen(code2)+1); 
    if(l){  
        strcat(*dest, code1);
        strcat(*dest, code2);
    }else    sprintf(*dest,"%s%s", code1, code2);
    
}

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
    yydebug = 0;
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
    //printhashtable();
    return 0;
}

void yyerror (char const *s) {
    fprintf(stderr, "%s!! @line no - %d:  @symbol '%s' :(  \n",s ,yylineno, yytext);
}