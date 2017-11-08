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
#line 1 "clikeg.y" /* yacc.c:339  */

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

#line 86 "clikeg.tab.c" /* yacc.c:339  */

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
   by #include "clikeg.tab.h".  */
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
    ID_TOK = 307,
    UMINUS = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "clikeg.y" /* yacc.c:355  */

    struct t{
        _datatype othertype;
        char *idtype;
        char *place;
        char *code;
    } type;

#line 189 "clikeg.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CLIKEG_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "clikeg.tab.c" /* yacc.c:358  */

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
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  93

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    51,    52,    55,    56,    57,    59,    60,
      61,    64,    69,    82,    84,   100,   102,   103,   104,   105,
     106,   109,   110,   111,   112,   113,   114,   115,   116,   119,
     120,   121,   122,   123,   124,   125,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   139,   140,   141,   142,   145,
     146,   147,   148
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
  "CHARCONST", "ID_TOK", "UMINUS", "$accept", "DEBUG", "nonfunctionblock",
  "block", "statement", "ifstatement", "ifstatementex", "loopstatement",
  "condexp", "exp4", "exp3", "exp", "exp2", "exp0", "var", YY_NULLPTR
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
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -40

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-40)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,    -1,    27,    27,   -39,   -28,    63,    39,   -40,    61,
     -40,   -40,   -40,    19,   -40,    66,    30,    -1,    -1,   -40,
     -40,     5,     5,     5,     5,     5,   -40,   -40,     5,   -40,
     -40,   -40,   -40,    30,     5,    30,   -40,   -40,   -40,   -37,
      42,    40,   117,   -40,   -40,   -40,   -40,     5,   122,   122,
     122,   122,   122,   122,    46,    10,   110,    29,   -40,   -40,
      30,    30,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,    23,    84,   -40,   -40,   -40,   -40,   -40,
     122,   122,    21,    21,    29,    29,   122,   122,   122,   122,
     122,    -1,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     7,     0,     0,     0,     0,     0,     0,     5,     2,
       4,     9,    10,     0,    35,     0,     0,     0,     0,    48,
      47,     0,     0,     0,     0,     0,    46,    45,     0,     1,
       6,     8,     3,     0,     0,     0,    50,    51,    52,    49,
       0,    20,    28,    43,    44,    14,    13,     0,    29,    30,
      31,    32,    33,    34,     0,     0,    28,    37,    19,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,    16,    21,    36,    18,    17,
      23,    22,    39,    38,    40,    41,    42,    26,    24,    25,
      27,     0,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -15,    53,    -4,   -40,   -40,   -40,    72,   -23,
      44,   -40,    -2,     0,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    73,    12,    17,    40,
      41,    13,    42,    43,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      14,    14,    45,    46,     1,    30,    26,    27,    47,    14,
      54,    30,    58,    19,    76,    14,    34,    14,    14,    48,
      49,    50,    51,    52,    20,     2,    53,     3,    60,    61,
      16,    56,    57,    33,    66,    67,    68,    78,    79,    29,
      31,    34,     4,     5,    68,    74,    59,    35,     4,     5,
      75,     6,    91,    36,    15,    37,    38,    39,    60,    61,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    21,    32,     4,     5,    18,    92,    55,    36,     0,
      37,    38,    39,     0,     0,     0,     0,     2,    77,     3,
       0,    14,     2,     0,     3,    64,    65,    66,    67,    68,
      22,    23,    24,    25,     4,     5,    26,    27,    28,     4,
       5,     0,     0,     6,    77,     0,     0,     0,     6,    62,
      63,    64,    65,    66,    67,    68,    62,    63,    64,    65,
      66,    67,    68,    64,    65,    66,    67,    68,     0,     0,
       0,    69,    70,    71,    72,     0,     0,     0,    69,    70,
      71,    72
};

static const yytype_int8 yycheck[] =
{
       0,     1,    17,    18,     5,     9,    43,    44,     3,     9,
      33,    15,    35,    52,     4,    15,    11,    17,    18,    21,
      22,    23,    24,    25,    52,    26,    28,    28,    18,    19,
       3,    33,    34,     3,    13,    14,    15,    60,    61,     0,
      21,    11,    43,    44,    15,    47,     4,    17,    43,    44,
       4,    52,    29,    48,     1,    50,    51,    52,    18,    19,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     8,     6,    43,    44,     3,    91,    33,    48,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    26,     4,    28,
      -1,    91,    26,    -1,    28,    11,    12,    13,    14,    15,
      37,    38,    39,    40,    43,    44,    43,    44,    45,    43,
      44,    -1,    -1,    52,     4,    -1,    -1,    -1,    52,     9,
      10,    11,    12,    13,    14,    15,     9,    10,    11,    12,
      13,    14,    15,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    31,    32,    33,    34,    -1,    -1,    -1,    31,    32,
      33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    26,    28,    43,    44,    52,    55,    56,    57,
      58,    59,    61,    65,    67,    57,     3,    62,    62,    52,
      52,     8,    37,    38,    39,    40,    43,    44,    45,     0,
      58,    21,     6,     3,    11,    17,    48,    50,    51,    52,
      63,    64,    66,    67,    68,    56,    56,     3,    66,    66,
      66,    66,    66,    66,    63,    64,    66,    66,    63,     4,
      18,    19,     9,    10,    11,    12,    13,    14,    15,    31,
      32,    33,    34,    60,    66,     4,     4,     4,    63,    63,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    29,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    58,    58,
      58,    59,    59,    60,    61,    62,    63,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    67,    67,    67,    67,    68,
      68,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     2,     0,     2,     1,
       1,     4,     6,     0,     3,     3,     3,     3,     3,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     2,     3,     3,
       3,     3,     3,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1
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
        case 2:
#line 48 "clikeg.y" /* yacc.c:1646  */
    {  concatcode(&(yyvsp[0].type).code, "end ",":)\n"); fprintf(fpout, "%s", (yyvsp[0].type).code);}
#line 1366 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 51 "clikeg.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 1372 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 52 "clikeg.y" /* yacc.c:1646  */
    {(yyval.type).place = malloc(1); (yyval.type).place[0] = 0; (yyval.type).code = malloc(strlen((yyvsp[0].type).code)+1); strcpy((yyval.type).code, (yyvsp[0].type).code);}
#line 1378 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 56 "clikeg.y" /* yacc.c:1646  */
    {(yyval.type).place = malloc(1); (yyval.type).place[0] = 0; (yyval.type).code = 0; concatcode(&(yyval.type).code, (yyvsp[-1].type).code, (yyvsp[0].type).code); }
#line 1384 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 65 "clikeg.y" /* yacc.c:1646  */
    {   (yyval.type).place = malloc(10); sprintf((yyval.type).place, "tag%d", ++tmpcnt); 
                    addtocode(&(yyval.type).code, (yyvsp[-2].type).code, "", "jnz", (yyvsp[-2].type).place, "", (yyval.type).place);
                    strcat((yyval.type).place, ":\n"); 
                    concatcode(&(yyval.type).code, (yyval.type).place, (yyvsp[-1].type).code); }
#line 1393 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 70 "clikeg.y" /* yacc.c:1646  */
    {   char tmp[10];
                    (yyval.type).place = malloc(10); sprintf((yyval.type).place, "tag%d", ++tmpcnt); 
                    addtocode(&(yyval.type).code, (yyvsp[-4].type).code, "", "jnz", (yyvsp[-4].type).place, "", (yyval.type).place);
                    strcat((yyval.type).place, ":\n"); 
                    sprintf(tmp,"jmp,,,tag%d\n", ++tmpcnt); 
                    concatcode(&(yyval.type).code, (yyvsp[0].type).code, tmp);
                    concatcode(&(yyval.type).code, (yyval.type).place, (yyvsp[-3].type).code);
                    sprintf(tmp,"tag%d:\n", tmpcnt);
                    concatcode(&(yyval.type).code, tmp, "");
                }
#line 1408 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 85 "clikeg.y" /* yacc.c:1646  */
    {   char outofloop[10];
                        sprintf(outofloop, "tag%d", ++tmpcnt);
                        (yyval.type).place = malloc(10); sprintf((yyval.type).place, "tag%d", ++tmpcnt);
                        (yyval.type).code = 0;
                        concatcode(&(yyval.type).code, (yyval.type).place, ":\n");
                        concatcode(&(yyval.type).code, (yyvsp[-1].type).code, ",jz,");
                        concatcode(&(yyval.type).code, (yyvsp[-1].type).place, ",");
                        concatcode(&(yyval.type).code, outofloop, "\n");
                        concatcode(&(yyval.type).code, (yyvsp[0].type).code, (yyvsp[-1].type).code);
                        strcat((yyval.type).place, "\n");
                        concatcode(&(yyval.type).code, ",jmp,,", (yyval.type).place);
                        concatcode(&(yyval.type).code, outofloop, ":\n");
                    }
#line 1426 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 100 "clikeg.y" /* yacc.c:1646  */
    {  (yyval.type) = (yyvsp[-1].type); }
#line 1432 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 102 "clikeg.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 1438 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 103 "clikeg.y" /* yacc.c:1646  */
    { addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "||", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyval.type).place); }
#line 1444 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 104 "clikeg.y" /* yacc.c:1646  */
    { addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "&&", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyval.type).place); }
#line 1450 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 105 "clikeg.y" /* yacc.c:1646  */
    { addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[0].type).code, "", "!", (yyvsp[0].type).place, "", (yyval.type).place); }
#line 1456 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 109 "clikeg.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 1462 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 110 "clikeg.y" /* yacc.c:1646  */
    { addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "<", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyval.type).place); }
#line 1468 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 111 "clikeg.y" /* yacc.c:1646  */
    { addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, ">", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyval.type).place); }
#line 1474 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 112 "clikeg.y" /* yacc.c:1646  */
    { addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, ">=", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyval.type).place); }
#line 1480 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 113 "clikeg.y" /* yacc.c:1646  */
    { addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "<=", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyval.type).place); }
#line 1486 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 114 "clikeg.y" /* yacc.c:1646  */
    { addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "==", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyval.type).place); }
#line 1492 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 115 "clikeg.y" /* yacc.c:1646  */
    { addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "!=", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyval.type).place); }
#line 1498 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 119 "clikeg.y" /* yacc.c:1646  */
    {  (yyval.type).othertype = (yyvsp[-2].type).othertype; (yyval.type).place = malloc(1); (yyval.type).place[0] = 0; addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "=", (yyvsp[0].type).place, "", (yyvsp[-2].type).place); }
#line 1504 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 120 "clikeg.y" /* yacc.c:1646  */
    {  (yyval.type).othertype = (yyvsp[-2].type).othertype; (yyval.type).place = malloc(1); (yyval.type).place[0] = 0; addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "+", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyvsp[-2].type).place); }
#line 1510 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 121 "clikeg.y" /* yacc.c:1646  */
    {  (yyval.type).othertype = (yyvsp[-2].type).othertype; (yyval.type).place = malloc(1); (yyval.type).place[0] = 0; addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "-", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyvsp[-2].type).place); }
#line 1516 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 122 "clikeg.y" /* yacc.c:1646  */
    {  (yyval.type).othertype = (yyvsp[-2].type).othertype; (yyval.type).place = malloc(1); (yyval.type).place[0] = 0; addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "*", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyvsp[-2].type).place); }
#line 1522 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 123 "clikeg.y" /* yacc.c:1646  */
    {  (yyval.type).othertype = (yyvsp[-2].type).othertype; (yyval.type).place = malloc(1); (yyval.type).place[0] = 0; addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "/", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyvsp[-2].type).place); }
#line 1528 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 124 "clikeg.y" /* yacc.c:1646  */
    {  (yyval.type).othertype = (yyvsp[-2].type).othertype; (yyval.type).place = malloc(1); (yyval.type).place[0] = 0; addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "%", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyvsp[-2].type).place); }
#line 1534 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 128 "clikeg.y" /* yacc.c:1646  */
    {   (yyval.type) = (yyvsp[-1].type); }
#line 1540 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 129 "clikeg.y" /* yacc.c:1646  */
    { (yyval.type).othertype = (yyvsp[0].type).othertype; addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[0].type).code, "", "-", "0", (yyvsp[0].type).place, (yyval.type).place); }
#line 1546 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 130 "clikeg.y" /* yacc.c:1646  */
    {   (yyval.type).othertype = MAX((yyvsp[-2].type).othertype, (yyvsp[0].type).othertype); addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "+", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyval.type).place); }
#line 1552 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 131 "clikeg.y" /* yacc.c:1646  */
    {   (yyval.type).othertype = MAX((yyvsp[-2].type).othertype, (yyvsp[0].type).othertype); addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "-", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyval.type).place);  }
#line 1558 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 132 "clikeg.y" /* yacc.c:1646  */
    {   (yyval.type).othertype = MAX((yyvsp[-2].type).othertype, (yyvsp[0].type).othertype); addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "*", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyval.type).place);  }
#line 1564 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 133 "clikeg.y" /* yacc.c:1646  */
    {   (yyval.type).othertype = MAX((yyvsp[-2].type).othertype, (yyvsp[0].type).othertype); addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "/", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyval.type).place); }
#line 1570 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 134 "clikeg.y" /* yacc.c:1646  */
    {   (yyval.type).othertype = MAX((yyvsp[-2].type).othertype, (yyvsp[0].type).othertype); addtmptoplace(&(yyval.type).place); addtocode(&(yyval.type).code, (yyvsp[-2].type).code, (yyvsp[0].type).code, "%", (yyvsp[-2].type).place, (yyvsp[0].type).place, (yyval.type).place); }
#line 1576 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 139 "clikeg.y" /* yacc.c:1646  */
    { (yyval.type).othertype = (yyvsp[-1].type).othertype; addtoplace(&(yyval.type).place, (yyvsp[-1].type).place);  addtocode(&(yyval.type).code, (yyvsp[-1].type).code, "", "+",(yyvsp[-1].type).place,"1",(yyvsp[-1].type).place); }
#line 1582 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 140 "clikeg.y" /* yacc.c:1646  */
    { (yyval.type).othertype = (yyvsp[-1].type).othertype;  addtoplace(&(yyval.type).place, (yyvsp[-1].type).place);  addtocode(&(yyval.type).code, (yyvsp[-1].type).code, "", "-",(yyvsp[-1].type).place,"1",(yyvsp[-1].type).place); }
#line 1588 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 141 "clikeg.y" /* yacc.c:1646  */
    { (yyval.type).othertype = (yyvsp[0].type).othertype;  addtoplace(&(yyval.type).place, (yyvsp[0].type).place);  addtocode(&(yyval.type).code, (yyvsp[0].type).code, "", "+",(yyvsp[0].type).place,"1",(yyvsp[0].type).place); }
#line 1594 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 142 "clikeg.y" /* yacc.c:1646  */
    { (yyval.type).othertype = (yyvsp[0].type).othertype;  addtoplace(&(yyval.type).place, (yyvsp[0].type).place); addtocode(&(yyval.type).code, (yyvsp[0].type).code, "", "-",(yyvsp[0].type).place,"1",(yyvsp[0].type).place); }
#line 1600 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 145 "clikeg.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type);  }
#line 1606 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 146 "clikeg.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); (yyval.type).code = malloc(1); (yyval.type).code[0] = 0;}
#line 1612 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 147 "clikeg.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); (yyval.type).code = malloc(1); (yyval.type).code[0] = 0;}
#line 1618 "clikeg.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 148 "clikeg.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); (yyval.type).code = malloc(1); (yyval.type).code[0] = 0;}
#line 1624 "clikeg.tab.c" /* yacc.c:1646  */
    break;


#line 1628 "clikeg.tab.c" /* yacc.c:1646  */
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
#line 151 "clikeg.y" /* yacc.c:1906  */


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
