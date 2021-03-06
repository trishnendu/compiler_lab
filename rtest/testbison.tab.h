/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_TESTBISON_TAB_H_INCLUDED
# define YY_YY_TESTBISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LPAREN_TOK = 258,
    RPAREN_TOK = 259,
    CURL_LPAREN_TOK = 260,
    CURL_RPAREN_TOK = 261,
    DEFINE_TOK = 262,
    EQ_TOK = 263,
    GT_TOK = 264,
    LT_TOK = 265,
    MINUS_TOK = 266,
    PLUS_TOK = 267,
    MULT_TOK = 268,
    DIVIDE_TOK = 269,
    MOD_TOK = 270,
    XOR_TOK = 271,
    NOT_TOK = 272,
    AND_TOK = 273,
    OR_TOK = 274,
    SEMICOLON_TOK = 275,
    COMMA_TOK = 276,
    COMPARE_TOK = 277,
    GTEQ_TOK = 278,
    LTEQ_TOK = 279,
    NOT_EQ_TOK = 280,
    BIT_AND_TOK = 281,
    BIT_OR_TOK = 282,
    PLUS_EQ_TOK = 283,
    MINUS_EQ_TOK = 284,
    MULT_EQ_TOK = 285,
    DIVIDE_EQ_TOK = 286,
    RIGHT_SHIFT_TOK = 287,
    LEFT_SHIFT_TOK = 288,
    MINUS_MINUS_TOK = 289,
    PLUS_PLUS_TOK = 290,
    MOD_EQ_TOK = 291,
    MAIN_TOK = 292,
    RETURN_TOK = 293,
    INTCONST = 294,
    TYPE_TOK = 295,
    DOUBLECONST = 296,
    CHARCONST = 297,
    ID_TOK = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "testbison.y" /* yacc.c:1909  */

    int itype;
    double dtype;
    char ctype;
    char* idtype;
    _gentype gentype;

#line 106 "testbison.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TESTBISON_TAB_H_INCLUDED  */
