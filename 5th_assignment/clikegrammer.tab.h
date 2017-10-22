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

#ifndef YY_YY_CLIKEGRAMMER_TAB_H_INCLUDED
# define YY_YY_CLIKEGRAMMER_TAB_H_INCLUDED
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
    WHILE_TOK = 277,
    FOR_TOK = 278,
    IF_TOK = 279,
    ELSE_TOK = 280,
    ELSEIF_TOK = 281,
    COMPARE_TOK = 282,
    GTEQ_TOK = 283,
    LTEQ_TOK = 284,
    NOT_EQ_TOK = 285,
    BIT_AND_TOK = 286,
    BIT_OR_TOK = 287,
    PLUS_EQ_TOK = 288,
    MINUS_EQ_TOK = 289,
    MULT_EQ_TOK = 290,
    DIVIDE_EQ_TOK = 291,
    RIGHT_SHIFT_TOK = 292,
    LEFT_SHIFT_TOK = 293,
    MINUS_MINUS_TOK = 294,
    PLUS_PLUS_TOK = 295,
    MOD_EQ_TOK = 296,
    ID_TOK = 297,
    INTCONST = 298,
    ERROR_TOK = 299,
    DOUBLECONST = 300,
    CHARCONST = 301,
    TYPE_TOK = 302,
    RETURN_TOK = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "clikegrammer.y" /* yacc.c:1909  */

    int i;
    char *s;

#line 108 "clikegrammer.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CLIKEGRAMMER_TAB_H_INCLUDED  */
