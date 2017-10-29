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

#ifndef YY_YY_CLIKEG_TAB_H_INCLUDED
# define YY_YY_CLIKEG_TAB_H_INCLUDED
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
    COLON_TOK = 275,
    SEMICOLON_TOK = 276,
    COMMA_TOK = 277,
    SWITCH_TOK = 278,
    CASE_TOK = 279,
    DEFAULT_TOK = 280,
    WHILE_TOK = 281,
    FOR_TOK = 282,
    IF_TOK = 283,
    ELSE_TOK = 284,
    ELSEIF_TOK = 285,
    COMPARE_TOK = 286,
    GTEQ_TOK = 287,
    LTEQ_TOK = 288,
    NOT_EQ_TOK = 289,
    BIT_AND_TOK = 290,
    BIT_OR_TOK = 291,
    PLUS_EQ_TOK = 292,
    MINUS_EQ_TOK = 293,
    MULT_EQ_TOK = 294,
    DIVIDE_EQ_TOK = 295,
    RIGHT_SHIFT_TOK = 296,
    LEFT_SHIFT_TOK = 297,
    MINUS_MINUS_TOK = 298,
    PLUS_PLUS_TOK = 299,
    MOD_EQ_TOK = 300,
    ERROR_TOK = 301,
    RETURN_TOK = 302,
    INTCONST = 303,
    TYPE_TOK = 304,
    DOUBLECONST = 305,
    CHARCONST = 306,
    ID_TOK = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "clikeg.y" /* yacc.c:1909  */

    char* idtype;
    _datatype othertype;

#line 112 "clikeg.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CLIKEG_TAB_H_INCLUDED  */
