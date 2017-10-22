/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "clikegrammer.y" /* yacc.c:339  */

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
extern int curscope;   

#line 80 "clikegrammer.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "clikegrammer.tab.h".  */
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
#line 15 "clikegrammer.y" /* yacc.c:355  */

    char* idtype;
    _datatype othertype;

#line 178 "clikegrammer.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CLIKEGRAMMER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 195 "clikegrammer.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   288

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    36,    36,    38,    38,    38,    41,    42,    45,    46,
      47,    50,    51,    54,    56,    56,    57,    57,    59,    60,
      60,    62,    62,    63,    63,    66,    66,    69,    69,    69,
      69,    69,    69,    71,    72,    73,    74,    75,    76,    77,
      77,    77,    77,    77,    77,    80,    81,    84,    84,    86,
      88,    90,    90,    92,    92,    94,    95,    98,    98,    98,
      99,    99,   101,   101,   102,   102,   104,   104,   105,   105,
     107,   109,   110,   111,   112,   113,   116,   117,   118,   119,
     120,   121,   122,   123,   126,   127,   128,   129,   130,   131,
     135,   138,   139,   140,   141,   144,   145,   146,   147,   148,
     149,   152,   153,   154,   155,   158,   159,   160,   161
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LPAREN_TOK", "RPAREN_TOK",
  "CURL_LPAREN_TOK", "CURL_RPAREN_TOK", "DEFINE_TOK", "EQ_TOK", "GT_TOK",
  "LT_TOK", "MINUS_TOK", "PLUS_TOK", "MULT_TOK", "DIVIDE_TOK", "MOD_TOK",
  "XOR_TOK", "NOT_TOK", "AND_TOK", "OR_TOK", "COLON_TOK", "SEMICOLON_TOK",
  "COMMA_TOK", "SWITCH_TOK", "CASE_TOK", "DEFAULT_TOK", "WHILE_TOK",
  "FOR_TOK", "IF_TOK", "ELSE_TOK", "ELSEIF_TOK", "COMPARE_TOK", "GTEQ_TOK",
  "LTEQ_TOK", "NOT_EQ_TOK", "BIT_AND_TOK", "BIT_OR_TOK", "PLUS_EQ_TOK",
  "MINUS_EQ_TOK", "MULT_EQ_TOK", "DIVIDE_EQ_TOK", "RIGHT_SHIFT_TOK",
  "LEFT_SHIFT_TOK", "MINUS_MINUS_TOK", "PLUS_PLUS_TOK", "MOD_EQ_TOK",
  "ERROR_TOK", "RETURN_TOK", "INTCONST", "TYPE_TOK", "DOUBLECONST",
  "CHARCONST", "ID_TOK", "$accept", "DEBUG", "START", "vardec", "vardecex",
  "funcdef", "returnstatement", "arglist", "arglistex", "funccall",
  "paramlist", "block", "$@1", "$@2", "vardeclines", "nonfunctionblock",
  "statements", "ifstatement", "ifstatementex", "switchstatement",
  "switchblock", "caseblocks", "defaultblock", "loopstatement", "forpart1",
  "varinitlist", "forpart2", "forpart2ex", "forpart3", "forpart3ex",
  "condexp", "exp4", "exp3", "exp", "exp2", "exp1", "exp0", "var", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define YYTABLE_NINF -24

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -36,   -30,    31,    24,  -102,   -36,   -36,    17,   -19,  -102,
    -102,  -102,   -19,   152,    75,   -13,    39,    50,   152,     5,
      16,  -102,  -102,  -102,     9,  -102,  -102,   115,  -102,    36,
    -102,    20,    57,    56,    56,    94,  -102,  -102,    86,  -102,
    -102,   118,   152,   152,   222,   222,   222,    92,    62,  -102,
     113,  -102,  -102,  -102,   182,   117,   101,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,   152,    76,  -102,  -102,   152,   152,
     152,   152,   152,   152,   110,    86,  -102,    57,   205,    -1,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   140,
     140,   145,   140,   152,   100,   198,  -102,   232,   232,   164,
     232,   232,   232,   154,  -102,   141,   172,   171,    53,   171,
     162,   180,  -102,  -102,  -102,  -102,  -102,  -102,   232,   141,
     141,   190,   149,   230,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,   189,  -102,   216,  -102,   130,  -102,   204,  -102,
    -102,   209,    10,   103,  -102,  -102,   141,   141,   152,   152,
     152,   152,   152,   152,   -16,  -102,   152,  -102,    86,   223,
     140,   215,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,   157,   221,   138,   243,   228,   141,   235,   171,
     171,  -102,   231,   233,   261,  -102,   217,   171,    86,  -102,
     223,  -102,   204,  -102,   232,   232,  -102,  -102,  -102,   228,
    -102,  -102,   244,   244,  -102,  -102,  -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     0,     2,     5,     5,    10,    15,     1,
       3,     4,    15,     0,     0,     0,     0,     0,     0,     0,
       0,   106,   107,   108,   105,   100,    10,    94,    99,    98,
       6,     0,     0,     0,     0,     0,   104,   103,     0,   102,
     101,     0,     0,     0,     0,     0,     0,     8,     0,    14,
      21,    12,    11,    91,     0,     0,    20,    90,     7,    93,
      92,    95,    96,    97,     0,     0,    26,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    17,     0,     0,
      84,    85,    86,    87,    88,    89,    18,    19,    16,     0,
       0,     0,     0,     0,     0,     0,    25,    42,    43,     0,
      40,    44,    41,     0,    24,     0,     0,     0,     0,     0,
       0,    10,    36,    37,    22,    34,    38,    35,    39,     0,
       0,     0,    75,    83,    26,    49,    30,    31,    32,    55,
      28,    29,     0,    59,     0,    58,     0,    57,    48,    13,
      33,     0,     0,    83,    74,    70,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    27,     0,    63,    67,    65,
       0,    45,    71,    76,    73,    72,    78,    77,    81,    79,
      80,    82,     0,    54,     0,     0,    69,     0,     0,     0,
       0,   105,     0,     0,     0,    61,     0,     0,     0,    66,
      65,    62,    48,    46,     0,     0,    50,    60,    56,    69,
      64,    47,    52,    52,    68,    51,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,   206,   -76,   245,  -102,   -92,   265,   201,    -8,
     207,   183,  -102,  -102,   -66,   -62,   -91,   -71,    88,  -102,
    -102,    27,  -102,   -65,  -102,    95,  -102,    93,  -102,    87,
     -69,  -101,   166,   -34,    13,    21,   -38,   116
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    14,     6,    97,    16,    49,    25,
      55,   128,    66,    67,    78,   129,    99,   100,   161,   101,
     125,   173,   184,   102,   136,   137,   158,   178,   175,   189,
     106,   121,   122,   103,   123,    27,    28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    79,    96,    96,    56,   104,   112,   113,   172,   115,
     116,   117,    38,     1,   163,   126,     2,   126,   141,   144,
      12,   107,     7,   109,     9,    13,    26,   140,   146,   147,
      15,    35,   135,    94,     8,   159,   130,    57,   130,    32,
      57,    56,   131,    33,   131,   164,   165,   138,    94,    44,
      45,    46,    39,    40,    34,    59,    60,    36,   154,    57,
      57,    50,    57,    57,    57,    61,    62,    63,    37,    57,
      98,    57,    47,   132,   133,   132,   190,    76,    96,    48,
      57,    80,    81,    82,    83,    84,    85,   126,   126,    98,
      98,   179,    98,    98,    98,   126,    30,    31,    53,   127,
      64,   127,    94,   202,   203,   134,   110,    53,   130,   130,
      98,    65,   148,   149,   131,   131,   130,   192,   193,   -23,
      57,    74,   131,    75,   176,   198,    42,    43,    77,    19,
      20,    86,   143,   119,   150,   151,   152,   153,    54,    58,
      31,    57,    57,   105,   119,   132,   132,   120,   108,    57,
      57,   157,   111,   132,   199,    18,    57,    57,   120,   185,
     186,   166,   167,   168,   169,   170,   171,   146,   147,   174,
     114,   127,   127,    19,    20,   118,    50,   124,    21,   127,
      22,    23,    24,   139,    19,    20,    98,    98,    13,    21,
      68,    22,    23,    24,   145,    19,    20,    90,    91,    92,
      21,    38,    22,    23,    24,    21,    68,    22,    23,   181,
     155,    10,    11,   162,    19,    20,    51,    52,    93,    69,
      70,    71,    72,    95,   156,    39,    40,    73,    89,   205,
     206,    90,    91,    92,   160,    69,    70,    71,    72,   148,
     149,    39,    40,    73,   180,   177,   183,   187,    19,    20,
     188,   194,    93,   195,    94,    89,   191,    95,    90,    91,
      92,   150,   151,   152,   153,    19,    20,   196,   172,   134,
      21,    41,    22,    23,    24,    19,    20,    17,    88,    93,
     201,   197,    87,   200,    95,   142,   204,     0,   182
};

static const yytype_int16 yycheck[] =
{
      38,    67,    78,    79,    38,     6,    97,    98,    24,   100,
     101,   102,     3,    49,     4,   107,    52,   109,   119,   120,
       3,    90,    52,    92,     0,     8,    13,   118,    18,    19,
      49,    18,   108,    49,     3,   136,   107,    75,   109,    52,
      78,    75,   107,     4,   109,   146,   147,   109,    49,    13,
      14,    15,    43,    44,     4,    42,    43,    52,   124,    97,
      98,     5,   100,   101,   102,    44,    45,    46,    52,   107,
      78,   109,    52,   107,    21,   109,   177,    64,   154,    22,
     118,    68,    69,    70,    71,    72,    73,   179,   180,    97,
      98,   160,   100,   101,   102,   187,    21,    22,     4,   107,
       8,   109,    49,   194,   195,    52,    93,     4,   179,   180,
     118,    49,     9,    10,   179,   180,   187,   179,   180,     6,
     158,     4,   187,    22,   158,   187,    11,    12,    52,    43,
      44,    21,   119,     3,    31,    32,    33,    34,    52,    21,
      22,   179,   180,     3,     3,   179,   180,    17,     3,   187,
     188,    21,    52,   187,   188,     3,   194,   195,    17,    21,
      22,   148,   149,   150,   151,   152,   153,    18,    19,   156,
       6,   179,   180,    43,    44,    21,     5,     5,    48,   187,
      50,    51,    52,    21,    43,    44,   194,   195,     8,    48,
       8,    50,    51,    52,     4,    43,    44,    26,    27,    28,
      48,     3,    50,    51,    52,    48,     8,    50,    51,    52,
      21,     5,     6,     4,    43,    44,    33,    34,    47,    37,
      38,    39,    40,    52,     8,    43,    44,    45,    23,   202,
     203,    26,    27,    28,    30,    37,    38,    39,    40,     9,
      10,    43,    44,    45,    29,    22,    25,     4,    43,    44,
      22,    20,    47,    20,    49,    23,    21,    52,    26,    27,
      28,    31,    32,    33,    34,    43,    44,     6,    24,    52,
      48,    26,    50,    51,    52,    43,    44,    12,    77,    47,
     192,   186,    75,   190,    52,   119,   199,    -1,   172
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    52,    54,    55,    56,    58,    52,     3,     0,
      55,    55,     3,     8,    57,    49,    60,    60,     3,    43,
      44,    48,    50,    51,    52,    62,    87,    88,    89,    90,
      21,    22,    52,     4,     4,    87,    52,    52,     3,    43,
      44,    57,    11,    12,    13,    14,    15,    52,    22,    61,
       5,    64,    64,     4,    52,    63,    86,    89,    21,    87,
      87,    88,    88,    88,     8,    49,    65,    66,     8,    37,
      38,    39,    40,    45,     4,    22,    87,    52,    67,    67,
      87,    87,    87,    87,    87,    87,    21,    63,    61,    23,
      26,    27,    28,    47,    49,    52,    56,    59,    62,    69,
      70,    72,    76,    86,     6,     3,    83,    83,     3,    83,
      87,    52,    69,    69,     6,    69,    69,    69,    21,     3,
      17,    84,    85,    87,     5,    73,    59,    62,    64,    68,
      70,    76,    86,    21,    52,    56,    77,    78,    68,    21,
      69,    84,    85,    87,    84,     4,    18,    19,     9,    10,
      31,    32,    33,    34,    67,    21,     8,    21,    79,    84,
      30,    71,     4,     4,    84,    84,    87,    87,    87,    87,
      87,    87,    24,    74,    87,    81,    86,    22,    80,    83,
      29,    52,    90,    25,    75,    21,    22,     4,    22,    82,
      84,    21,    68,    68,    20,    20,     6,    78,    68,    86,
      80,    71,    69,    69,    82,    74,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    55,    56,    56,    57,    57,
      57,    58,    58,    59,    60,    60,    61,    61,    62,    63,
      63,    65,    64,    66,    64,    67,    67,    68,    68,    68,
      68,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    84,    84,    84,    84,    84,    85,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    86,    86,    86,    86,
      86,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    90,    90,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     4,     6,     3,     5,
       0,     6,     5,     3,     3,     0,     4,     3,     5,     3,
       1,     0,     5,     0,     4,     2,     0,     2,     1,     1,
       1,     1,     1,     3,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     4,     6,     4,     0,     3,
       5,     5,     0,     4,     0,     3,     7,     1,     1,     1,
       5,     4,     3,     1,     3,     0,     2,     0,     3,     0,
       3,     3,     3,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 41 "clikegrammer.y" /* yacc.c:1646  */
    { symt_insert((yyvsp[-2].idtype), (yyvsp[-3].othertype)); }
#line 1437 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 50 "clikegrammer.y" /* yacc.c:1646  */
    {   symt_insert((yyvsp[-4].idtype), (yyvsp[-5].othertype));  }
#line 1443 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 51 "clikegrammer.y" /* yacc.c:1646  */
    {   symt_insert((yyvsp[-4].idtype), NONE);   }
#line 1449 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 59 "clikegrammer.y" /* yacc.c:1646  */
    {  (yyval.othertype) = symt_gettype((yyvsp[-4].idtype)); }
#line 1455 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 62 "clikegrammer.y" /* yacc.c:1646  */
    {newscope();}
#line 1461 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 62 "clikegrammer.y" /* yacc.c:1646  */
    {endscope();}
#line 1467 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 63 "clikegrammer.y" /* yacc.c:1646  */
    {newscope();}
#line 1473 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 63 "clikegrammer.y" /* yacc.c:1646  */
    {endscope();}
#line 1479 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 126 "clikegrammer.y" /* yacc.c:1646  */
    {  (yyval.othertype) = symt_gettype((yyvsp[-2].idtype)); check_compatibility((yyval.othertype), (yyvsp[0].othertype));  }
#line 1485 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 127 "clikegrammer.y" /* yacc.c:1646  */
    {   (yyval.othertype) = symt_gettype((yyvsp[-2].idtype)); check_compatibility((yyval.othertype), (yyvsp[0].othertype));  }
#line 1491 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 128 "clikegrammer.y" /* yacc.c:1646  */
    {   (yyval.othertype) = symt_gettype((yyvsp[-2].idtype)); check_compatibility((yyval.othertype), (yyvsp[0].othertype));  }
#line 1497 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 129 "clikegrammer.y" /* yacc.c:1646  */
    {   (yyval.othertype) = symt_gettype((yyvsp[-2].idtype)); check_compatibility((yyval.othertype), (yyvsp[0].othertype));  }
#line 1503 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 130 "clikegrammer.y" /* yacc.c:1646  */
    {   (yyval.othertype) = symt_gettype((yyvsp[-2].idtype)); check_compatibility((yyval.othertype), (yyvsp[0].othertype));  }
#line 1509 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 131 "clikegrammer.y" /* yacc.c:1646  */
    {   
        if(symt_gettype((yyvsp[-2].idtype))!=INT || (yyvsp[0].othertype)!=INT)    
            printf("Modulo operation is not permitted on <int> only\n");
        (yyval.othertype) = INT; }
#line 1518 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 138 "clikegrammer.y" /* yacc.c:1646  */
    {   (yyval.othertype) = (yyvsp[-1].othertype); }
#line 1524 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 139 "clikegrammer.y" /* yacc.c:1646  */
    {   (yyval.othertype) = MAX((yyvsp[-2].othertype), (yyvsp[0].othertype)); }
#line 1530 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 140 "clikegrammer.y" /* yacc.c:1646  */
    {   (yyval.othertype) = MAX((yyvsp[-2].othertype), (yyvsp[0].othertype)); }
#line 1536 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 144 "clikegrammer.y" /* yacc.c:1646  */
    {   (yyval.othertype) = MAX((yyvsp[-2].othertype), (yyvsp[0].othertype)); }
#line 1542 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 145 "clikegrammer.y" /* yacc.c:1646  */
    {   (yyval.othertype) = MAX((yyvsp[-2].othertype), (yyvsp[0].othertype)); }
#line 1548 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 152 "clikegrammer.y" /* yacc.c:1646  */
    {   (yyval.othertype) = symt_gettype((yyvsp[-1].idtype));  }
#line 1554 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 153 "clikegrammer.y" /* yacc.c:1646  */
    {   (yyval.othertype) = symt_gettype((yyvsp[-1].idtype));  }
#line 1560 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 154 "clikegrammer.y" /* yacc.c:1646  */
    { (yyval.othertype) = symt_gettype((yyvsp[0].idtype)); }
#line 1566 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 155 "clikegrammer.y" /* yacc.c:1646  */
    { (yyval.othertype) = symt_gettype((yyvsp[0].idtype)); }
#line 1572 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 158 "clikegrammer.y" /* yacc.c:1646  */
    {   (yyval.othertype) = symt_gettype((yyvsp[0].idtype));  }
#line 1578 "clikegrammer.tab.c" /* yacc.c:1646  */
    break;


#line 1582 "clikegrammer.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 164 "clikegrammer.y" /* yacc.c:1906  */

int check_compatibility(int a, int b){
    if(a == NONE || b == NONE){
        printf("@line no - %d: error - one or more variables are undeclared!!\n", yylineno);
        return 1;
    } else if(a != b){
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
    return 0;
}

void yyerror (char const *s) {
    fprintf(stderr, "%s!! @line no - %d:  @symbol '%s' :(  \n",s ,yylineno, yytext);
}
