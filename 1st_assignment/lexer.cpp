#include<cstdio>
#include<iostream>
#include<cstring>
#include "lexer_def.h"

using namespace std;

FILE *yyin;
char yytext[256];
int yyleng;

int yylex(){
	char ch;
	ch = getc(yyin);
	while(isspace(ch))	ch = getc(yyin);
	yyleng = 0;
	yytext[yyleng++] = ch;
//	cout << "DEBUGGING  " << yytext[yyleng - 1] << " @ " << yyleng - 1 << endl; 
	switch(ch){
		case '(':	return LPAREN_TOK;
		case ')':	return RPAREN_TOK;
		case '{':	return CURL_LPAREN_TOK;
		case '}':	return CURL_RPAREN_TOK;
		case '#':	return DEFINE_TOK;
		case '=':	ch = getc(yyin);
					if(ch=='=') {
						yytext[yyleng++] = ch;
						return COMPARE_TOK;
					} else {
						ungetc(ch, yyin);
						return EQ_TOK;
					}
		case '>':	ch = getc(yyin);
					if(ch=='=') {
						yytext[yyleng++] = ch;
						return GTEQ_TOK;
					} else if(ch=='>') {
						yytext[yyleng++] = ch;
						return RIGHT_SHIFT_TOK;
					} else {
						ungetc(ch, yyin);
						return GT_TOK;
					}
		case '<':	ch = getc(yyin);
					if(ch=='=') {
						yytext[yyleng++] = ch;
						return LTEQ_TOK;
					} else if(ch=='<') {
						yytext[yyleng++] = ch;
						return LEFT_SHIFT_TOK;
					} else {
						ungetc(ch, yyin);
						return LT_TOK;
					}				
		case '-':	ch = getc(yyin);
					if(ch=='='){
						yytext[yyleng++] = ch;
						return MINUS_EQ_TOK;
					} else {
						ungetc(ch, yyin);
						return MINUS_TOK;
					}
		case '+':	ch = getc(yyin);
					if(ch=='=') {
						yytext[yyleng++] = ch;
						return PLUS_EQ_TOK;
					} else {
						ungetc(ch, yyin);
						return PLUS_TOK;
					}
		case '*':	ch = getc(yyin);
					if(ch=='=') {
						yytext[yyleng++] = ch;
						return MULT_EQ_TOK;
					} else {
						ungetc(ch, yyin);
						return MULT_TOK;
					}	
		case '/':	ch = getc(yyin);
					if(ch=='=') {
						yytext[yyleng++] = ch;
						return DIVIDE_EQ_TOK;
					} else {
						ungetc(ch, yyin);
						return DIVIDE_TOK;
					}
		case '%':	return MOD_TOK;
		case '^':	return XOR_TOK;
		case '!':	ch = getc(yyin);
					if(ch=='=') {
						yytext[yyleng++] = ch;
						return NOT_EQ_TOK;
					} else {
						ungetc(ch, yyin);
						return NOT_TOK;
					}
		case '&':	ch = getc(yyin);
					if(ch=='&') {
						yytext[yyleng++] = ch;
						return BIT_AND_TOK;
					} else {
						ungetc(ch, yyin);
						return AND_TOK;
					}
		case '|':	ch = getc(yyin);
					if(ch=='|') {
						yytext[yyleng++] = ch;
						return OR_TOK;
					} else {
						ungetc(ch, yyin);
						return BIT_OR_TOK;
					}
		case ',':	return COMMA_TOK;
		case ';':	return SEMICOLON_TOK;
		default :	if(isdigit(ch)) {
						bool flag = false;
						yytext[yyleng++] = ch;
						while(1){
							ch = getc(yyin);
							if(isdigit(ch)){
								yytext[yyleng++] = ch;
							} else if(isalpha(ch)){
								flag = true;
								while(!isspace(ch) && isalnum(ch)){
									yytext[yyleng++] = ch;
									ch = getc(yyin);
								}
								ungetc(ch, yyin);
							} else {
								ungetc(ch, yyin);
								break;
							}
						}	
						if(flag){
							return ERROR_TOK;
						} else {
							return INTCONST;
						}
						cout << "Returning" << endl;	
					} else if (isalpha(ch)) {
						while(1){
							ch = getc(yyin);
							if(isalnum(ch)){
								yytext[yyleng++] = ch;
								//cout << "DEBUGGING  " << yytext[yyleng - 1] << " @ " << yyleng - 1 << endl;
							} else {
								ungetc(ch, yyin);
								break;
							}
						}
						yytext[yyleng + 1] = (char) 0;
						//cout << "DEBUGGING  " << yytext[yyleng - 1] << " @ " << yyleng - 1 << endl;
						if(!strcmp(yytext,"while"))	return WHILE_TOK;
						if(!strcmp(yytext,"for"))	return FOR_TOK;
						if(!strcmp(yytext,"if"))	return IF_TOK;
						if(!strcmp(yytext,"else"))	return ELSE_TOK;
						return ID_TOK;
					} else {
						return ERROR_TOK;
					}
	}
}

int main(int argc, char *argv[]){
	int token;
	if(argc != 2){
		fprintf(stderr, "Usage: ./lexer <input_file>");
		exit(1);		
	} else {
		yyin = fopen(argv[1], "r");
	}	
	while(!feof(yyin)){
		token = yylex();
		cout << token << " ";
		for(int i = 0; i < yyleng; i++){
			cout << yytext[i];
		}
		cout << endl;
	}
	fclose(yyin);	
}

