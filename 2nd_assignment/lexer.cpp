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
	int state;
	int token;
	yyleng = state = token = 0;
//	cout << "DEBUGGING  " << yytext[yyleng - 1] << " @ " << yyleng - 1 << endl; 
	while(1){
		switch(state){
			case 0:		ch = getc(yyin);
						while(isspace(ch))	ch = getc(yyin);
						yytext[yyleng++] = ch;
						if(ch == 'f')	state = 1;
						else if(ch == 'w') state = 2;
						else if(ch == 'i')	state = 3;
						else if(ch == 'e')	state = 4;
						else if(isalpha(ch))	state = 5;
						else if(isdigit(ch))	state = 6;
						else if(ch == '(')	state = 7;
						else if(ch == ')')	state = 8;
						else if(ch == '{')	state = 9;
						else if(ch == '}')	state = 10;
						else if(ch == '#')	state = 11;
						else if(ch == '=')	state = 12;
						else if(ch == '>')	state = 13;
						else if(ch == '<')	state = 14;
						else if(ch == '-')	state = 15;
						else if(ch == '+')	state = 16;
						else if(ch == '*')	state = 17;
						else if(ch == '/')	state = 18;
						else if(ch == '%')	state = 19;
						else if(ch == '^')	state = 20;
						else if(ch == '!')	state = 21;
						else if(ch == '&')	state = 22;
						else if(ch == '|')	state = 23;
						else if(ch == ';')	state = 24;
						else if(ch == ',')	state = 25;
						else state = 999;
						break; 

			case 1:		ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = ID_TOK;
						if(ch == 'o')	state = 26;
						else if(isalnum(ch))	state = 5;
						else state = 1000;
						break;

			case 26:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = ID_TOK;
						if(ch == 'r')	state = 27;
						else if(isalnum(ch))	state = 5;
						else state = 1000;
						break;	
			
			case 27:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = FOR_TOK;
						if(isalnum(ch))	state = 5;
						else state = 1000;
						break;
					
			case 2:		ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = ID_TOK;
						if(ch == 'h')	state = 28;
						else if(isalnum(ch))	state = 5;
						else state = 1000;
						break;
			
			case 28:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = ID_TOK;
						if(ch == 'i')	state = 29;
						else if(isalnum(ch))	state = 5;
						else state = 1000;
						break;

			case 29:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = ID_TOK;
						if(ch == 'l')	state = 30;
						else if(isalnum(ch))	state = 5;
						else state = 1000;
						break;

			case 30:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = ID_TOK;
						if(ch == 'e')	state = 31;
						else if(isalnum(ch))	state = 5;
						else state = 1000;
						break;

			case 31:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = WHILE_TOK;
						if(isalnum(ch))	state = 5;
						else state = 1000;
						break;
			
			case 3:		ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = ID_TOK;
						if(ch == 'f')	state = 32;
						else if(isalnum(ch))	state = 5;
						else state = 1000;
						break;

			case 32:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = IF_TOK;
						if(isalnum(ch))	state = 5;
						else state = 1000;
						break;
			
			case 4:		ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = ID_TOK;
						if(ch == 'l')	state = 33;
						else if(isalnum(ch))	state = 5;
						else state = 1000;
						break;
			
			case 33:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = ID_TOK;
						if(ch == 's')	state = 34;
						else if(isalnum(ch))	state = 5;
						else state = 1000;
						break;
	
			case 34:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = ID_TOK;
						if(ch == 'e')	state = 35;
						else if(isalnum(ch))	state = 5;
						else state = 1000;
						break;

			case 35:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = ELSE_TOK;
						if(isalnum(ch))	state = 5;
						else state = 1000;
						break;
			
			case 5:		ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = ID_TOK;
						if(isalnum(ch))	state = 5;
						else state = 1000;
						break;
			
			case 6:		ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = INTCONST;
						if(isdigit(ch))	state = 6;
						else if(isalpha(ch)) {
							while(isalnum(ch))	ch = getc(yyin);
							cout << endl << "DEGBUGGING : " << endl;
							state = 999;
						} else state = 1000;
						break;

			case 7:		ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = LPAREN_TOK;
						state = 1000;
						break;

			case 8:		ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = RPAREN_TOK;
						state = 1000;
						break;

			case 9:		ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = CURL_LPAREN_TOK;
						state = 1000;
						break;

			case 10:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = CURL_RPAREN_TOK;
						state = 1000;
						break;

			case 11:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = DEFINE_TOK;
						state = 1000;
						break;
			
			case 12:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = EQ_TOK;
						if(ch == '=')	state = 36;
						else 	state = 1000;
						break;

			case 36:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = COMPARE_TOK;
						state = 1000;
						break;

			case 13:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = GT_TOK;
						if(ch == '=')	state = 37;
						else if(ch == '>') state = 38;
						else 	state = 1000;
						break;
					
			case 37:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = GTEQ_TOK;
						state = 1000;
						break;		

			case 38:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = RIGHT_SHIFT_TOK;
						state = 1000;
						break;		

			case 14:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = LT_TOK;
						if(ch == '=')	state = 39;
						else if(ch == '<')	state = 40;
						else 	state = 1000;
						break;
					
			case 39:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = LTEQ_TOK;
						state = 1000;
						break;

			case 40:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = LEFT_SHIFT_TOK;
						state = 1000;
						break;

			case 15:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = MINUS_TOK;
						if(ch == '=')	state = 41;
						else if(ch == '-')	state = 42;
						else 	state = 1000;
						break;
					
			case 41:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = MINUS_EQ_TOK;
						state = 1000;
						break;
			
			case 42:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = MINUS_MINUS_TOK;
						state = 1000;
						break;
			
			case 16:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = PLUS_TOK;
						if(ch == '=')	state = 43;
						else if(ch == '+')	state = 44;
						else 	state = 1000;
						break;
					
			case 43:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = PLUS_EQ_TOK;
						state = 1000;
						break;
			
			case 44:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = PLUS_PLUS_TOK;
						state = 1000;
						break;
			
			case 17:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = MULT_TOK;
						if(ch == '=')	state = 45;
						else 	state = 1000;
						break;
					
			case 45:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = MULT_EQ_TOK;
						state = 1000;
						break;
			
			case 18:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = DIVIDE_TOK;
						if(ch == '=')	state = 46;
						else 	state = 1000;
						break;
					
			case 46:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = DIVIDE_EQ_TOK;
						state = 1000;
						break;
			
			case 19:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = MOD_TOK;
						if(ch == '=')	state = 47;
						else 	state = 1000;
						break;
					
			case 47:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = MOD_EQ_TOK;
						state = 1000;
						break;

			case 20:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = XOR_TOK;
						state = 1000;
						break;

			case 21:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = NOT_TOK;
						if(ch == '=')	state = 48;
						else 	state = 1000;
						break;
					
			case 48:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = NOT_EQ_TOK;
						state = 1000;
						break;

			case 22:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = AND_TOK;
						if(ch == '&')	state = 49;
						else 	state = 1000;
						break;
					
			case 49:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = BIT_AND_TOK;
						state = 1000;
						break;

			case 23:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = OR_TOK;
						if(ch == '|')	state = 50;
						else 	state = 1000;
						break;
					
			case 50:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = BIT_OR_TOK;
						state = 1000;
						break;

			case 24:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = SEMICOLON_TOK;
						state = 1000;
						break;

			case 25:	ch = getc(yyin);
						yytext[yyleng++] = ch;
						token = COMMA_TOK;
						state = 1000;
						break;

			case 1000:	ungetc(ch, yyin);
						yytext[--yyleng] = (char) 0;
						return token;
			
			default:	cout << "Lexical Error" << endl;
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

