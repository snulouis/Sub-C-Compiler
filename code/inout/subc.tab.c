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
#line 1 "subc.y" /* yacc.c:339  */

/*
 * File Name   : subc.y
 * Description : a skeleton bison input
 */
#include <string.h>
#include "subc.h"
#include "subc.tab.h"

#define Int 0
#define Char 1
#define Array 2
#define Ptr 3
#define Struct 4
#define Null 5
#define Void 6


int    yylex ();
int    yyerror (char* s);


#line 89 "subc.tab.c" /* yacc.c:339  */

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
   by #include "subc.tab.h".  */
#ifndef YY_YY_SUBC_TAB_H_INCLUDED
# define YY_YY_SUBC_TAB_H_INCLUDED
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
    ID = 258,
    INTEGER_CONST = 259,
    CHAR_CONST = 260,
    STRING_CONST = 261,
    STRING = 262,
    WRITE_STRING = 263,
    WRITE_INT = 264,
    LOGICAL_OR = 265,
    LOGICAL_AND = 266,
    EQUOP = 267,
    RELOP = 268,
    INCOP = 269,
    DECOP = 270,
    STRUCTOP = 271,
    THEN = 272,
    ELSE = 273,
    INT = 274,
    CHAR = 275,
    STRUCT = 276,
    RETURN = 277,
    IF = 278,
    WHILE = 279,
    FOR = 280,
    BREAK = 281,
    CONTINUE = 282,
    VOID = 283,
    Nu = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "subc.y" /* yacc.c:355  */

	int				intVal;
	double			floatval;
	char			*stringVal;
	struct id		*idptr;
	struct decl		*declptr;
	struct ste		*steptr;

#line 168 "subc.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SUBC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 185 "subc.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    20,     2,     2,     2,     2,    14,     2,
      24,    26,    15,    18,    10,    19,    27,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
       2,    11,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,     2,    25,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    12,    13,    16,    17,    21,
      22,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    70,    85,    86,    90,    97,   105,   106,
     107,   118,   119,   120,   122,   123,   126,   126,   140,   145,
     164,   184,   183,   209,   210,   213,   214,   218,   224,   232,
     233,   236,   242,   248,   249,   253,   253,   262,   265,   266,
     268,   273,   274,   275,   276,   276,   294,   296,   299,   299,
     305,   311,   305,   319,   325,   330,   319,   341,   344,   347,
     347,   354,   363,   364,   370,   370,   405,   408,   411,   411,
     418,   421,   424,   424,   431,   436,   436,   455,   455,   467,
     467,   474,   474,   481,   484,   485,   486,   490,   495,   508,
     514,   520,   534,   548,   560,   572,   576,   580,   587,   590,
     593,   593,   608,   620,   622,   642
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTEGER_CONST", "CHAR_CONST",
  "STRING_CONST", "STRING", "WRITE_STRING", "WRITE_INT", "','", "'='",
  "LOGICAL_OR", "LOGICAL_AND", "'&'", "'*'", "EQUOP", "RELOP", "'+'",
  "'-'", "'!'", "INCOP", "DECOP", "'['", "'('", "']'", "')'", "'.'",
  "STRUCTOP", "THEN", "ELSE", "INT", "CHAR", "STRUCT", "RETURN", "IF",
  "WHILE", "FOR", "BREAK", "CONTINUE", "VOID", "Nu", "';'", "'{'", "'}'",
  "$accept", "program", "$@1", "ext_def_list", "ext_def", "type_specifier",
  "TYPE", "struct_specifier", "@2", "func_decl", "@3", "pointers",
  "param_list", "param_decl", "def_list", "def", "compound_stmt", "$@4",
  "local_defs", "stmt_list", "if_mid", "stmt", "$@5", "$@6", "@7", "$@8",
  "@9", "$@10", "$@11", "$@12", "expr_e", "expr", "$@13", "or_expr",
  "or_list", "$@14", "and_expr", "and_list", "$@15", "binary", "@16",
  "@17", "$@18", "$@19", "unary", "$@20", "args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      44,    61,   265,   266,    38,    42,   267,   268,    43,    45,
      33,   269,   270,    91,    40,    93,    41,    46,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,    59,   123,   125
};
# endif

#define YYPACT_NINF -100

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-100)))

#define YYTABLE_NINF -65

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -100,    25,  -100,  -100,    58,  -100,  -100,    10,  -100,  -100,
       1,  -100,  -100,     9,   -10,  -100,  -100,    45,  -100,  -100,
    -100,    -7,     5,    58,  -100,  -100,    46,     6,  -100,     2,
      12,  -100,  -100,    33,    38,  -100,    66,    58,  -100,    71,
    -100,   110,  -100,    55,  -100,    86,     8,  -100,     7,  -100,
    -100,  -100,    84,    92,     0,     0,     0,     0,     0,     0,
       0,    81,   102,  -100,   104,    85,    91,  -100,  -100,  -100,
    -100,   152,  -100,    98,  -100,   129,  -100,   130,    87,    48,
    -100,   139,    58,  -100,   146,  -100,   151,     0,    72,    72,
      72,    72,    72,    72,   133,    34,  -100,     0,     0,   138,
       0,  -100,  -100,   134,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,     0,   137,   162,   165,   158,   147,  -100,
     150,  -100,   153,  -100,  -100,   135,   154,     0,   136,  -100,
    -100,     0,     0,     0,     0,     0,     0,   156,  -100,     0,
    -100,  -100,     0,   178,   141,   159,  -100,  -100,  -100,   166,
    -100,   152,  -100,    72,    87,   103,    93,  -100,  -100,  -100,
    -100,    13,  -100,   171,  -100,  -100,  -100,     0,  -100,     0,
    -100,  -100,   152,   142,  -100,  -100,  -100,     0,   172,  -100,
     152,  -100
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,     3,    14,    15,     0,    12,     4,
      24,    11,    13,     0,    18,    23,     9,     0,     8,    30,
      10,     0,     0,    37,    35,    30,     0,    21,     6,    24,
       0,    29,    39,     0,     0,    19,     0,     0,    33,     0,
      34,     0,    17,     0,    20,    24,     0,    25,     0,    88,
      86,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,     0,    50,     0,     0,     0,   103,    46,    36,
      42,     0,    38,     0,    66,    67,    70,    71,    74,    83,
       7,     0,     0,    22,     0,    31,     0,     0,    95,    96,
      89,    90,    93,    94,     0,    83,    43,     0,     0,     0,
      63,    57,    58,    47,    41,    68,    72,    77,    75,    79,
      81,    91,    92,     0,   100,     0,     0,     0,    27,    26,
       0,    59,     0,    84,    85,     0,     0,     0,     0,    62,
      48,     0,     0,     0,     0,     0,     0,     0,   102,     0,
      98,    99,     0,     0,     0,     0,    61,    45,    40,     0,
      53,     0,    69,    83,    73,    78,    76,    80,    82,    97,
     104,     0,    65,     0,    32,    60,    51,    63,    49,     0,
     101,    28,     0,     0,   105,    52,    54,    63,     0,    55,
       0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,  -100,  -100,  -100,    -2,  -100,  -100,  -100,   193,
    -100,    -3,  -100,   117,   175,  -100,   188,  -100,  -100,  -100,
    -100,   -70,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
     -99,   -60,  -100,  -100,  -100,  -100,    73,  -100,  -100,     3,
    -100,  -100,  -100,  -100,   -48,  -100,  -100
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     9,    29,    11,    12,    21,    30,
      37,    17,    46,    47,    23,    31,    70,    32,    24,    41,
      71,    72,    97,   151,    99,   172,   167,   177,   180,   145,
     128,    73,   117,    74,    75,   131,    76,    77,   132,    78,
     134,   133,   135,   136,    79,   139,   161
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      94,   103,    10,    49,    50,    51,    88,    89,    90,    91,
      92,    93,    95,    14,    54,    55,    15,    15,    82,    56,
      57,    58,    59,   169,    60,     3,    39,   122,    26,    27,
      84,    27,    35,   -16,    83,    45,    25,   125,   126,   170,
     129,    67,    81,    16,    38,   -64,    36,    28,    22,    85,
      34,    18,    19,   137,    40,   111,   112,   113,   114,   -64,
     124,   115,   116,    43,     5,     6,     7,   149,   173,   111,
     112,   113,   114,     8,    48,   115,   116,    42,   178,   160,
      45,   168,   162,   153,   153,   153,   153,   153,   153,     5,
       6,     7,    44,   111,   112,   113,   114,    80,     8,   115,
     116,    15,   175,   107,   108,   109,   110,   129,    86,   174,
     181,   109,   110,    49,    50,    51,    87,   129,    52,    53,
     108,   109,   110,    96,    54,    55,    98,   101,   100,    56,
      57,    58,    59,   102,    60,   154,   155,   156,   157,   158,
     104,   105,   118,   106,    61,    62,    63,    64,    65,    66,
     120,    67,    68,    19,    69,    49,    50,    51,   121,   123,
      52,    53,   127,   138,   130,   140,    54,    55,   141,   142,
     143,    56,    57,    58,    59,   144,    60,   147,   150,   146,
     148,   159,   163,   164,   176,   165,    61,    62,    63,    64,
      65,    66,   166,    67,    68,    19,   171,    13,   179,   119,
      33,    20,     0,     0,   152
};

static const yytype_int16 yycheck[] =
{
      60,    71,     4,     3,     4,     5,    54,    55,    56,    57,
      58,    59,    60,     3,    14,    15,    15,    15,    10,    19,
      20,    21,    22,    10,    24,     0,    29,    87,    23,    24,
      23,    24,    26,    43,    26,    37,    43,    97,    98,    26,
     100,    41,    45,    42,    42,    11,    40,    42,     3,    42,
       4,    42,    43,   113,    42,    21,    22,    23,    24,    11,
      26,    27,    28,    25,    31,    32,    33,   127,   167,    21,
      22,    23,    24,    40,     3,    27,    28,    44,   177,   139,
      82,   151,   142,   131,   132,   133,   134,   135,   136,    31,
      32,    33,    26,    21,    22,    23,    24,    42,    40,    27,
      28,    15,   172,    16,    17,    18,    19,   167,    24,   169,
     180,    18,    19,     3,     4,     5,    24,   177,     8,     9,
      17,    18,    19,    42,    14,    15,    24,    42,    24,    19,
      20,    21,    22,    42,    24,   132,   133,   134,   135,   136,
      42,    12,     3,    13,    34,    35,    36,    37,    38,    39,
       4,    41,    42,    43,    44,     3,     4,     5,     7,    26,
       8,     9,    24,    26,    30,     3,    14,    15,     3,    11,
      23,    19,    20,    21,    22,    25,    24,    42,    42,    26,
      26,    25,     4,    42,    42,    26,    34,    35,    36,    37,
      38,    39,    26,    41,    42,    43,    25,     4,    26,    82,
      25,    13,    -1,    -1,   131
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,     0,    48,    31,    32,    33,    40,    49,
      50,    51,    52,    54,     3,    15,    42,    56,    42,    43,
      61,    53,     3,    59,    63,    43,    23,    24,    42,    50,
      54,    60,    62,    59,     4,    26,    40,    55,    42,    56,
      42,    64,    44,    25,    26,    50,    57,    58,     3,     3,
       4,     5,     8,     9,    14,    15,    19,    20,    21,    22,
      24,    34,    35,    36,    37,    38,    39,    41,    42,    44,
      61,    65,    66,    76,    78,    79,    81,    82,    84,    89,
      42,    56,    10,    26,    23,    42,    24,    24,    89,    89,
      89,    89,    89,    89,    76,    89,    42,    67,    24,    69,
      24,    42,    42,    66,    42,    12,    13,    16,    17,    18,
      19,    21,    22,    23,    24,    27,    28,    77,     3,    58,
       4,     7,    76,    26,    26,    76,    76,    24,    75,    76,
      30,    80,    83,    86,    85,    87,    88,    76,    26,    90,
       3,     3,    11,    23,    25,    74,    26,    42,    26,    76,
      42,    68,    81,    89,    84,    84,    84,    84,    84,    25,
      76,    91,    76,     4,    42,    26,    26,    71,    66,    10,
      26,    25,    70,    75,    76,    66,    42,    72,    75,    26,
      73,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    47,    46,    48,    48,    49,    49,    49,    49,
      49,    50,    50,    50,    51,    51,    53,    52,    52,    54,
      54,    55,    54,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    60,    60,    62,    61,    63,    64,    64,
      65,    66,    66,    66,    67,    66,    66,    66,    68,    66,
      69,    70,    66,    71,    72,    73,    66,    66,    66,    74,
      66,    66,    75,    75,    77,    76,    76,    78,    80,    79,
      79,    81,    83,    82,    82,    85,    84,    86,    84,    87,
      84,    88,    84,    84,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      90,    89,    89,    89,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     4,     7,     2,     2,
       2,     1,     1,     1,     1,     1,     0,     6,     2,     5,
       6,     0,     7,     1,     0,     1,     3,     3,     6,     2,
       0,     4,     7,     2,     2,     0,     5,     1,     2,     0,
       4,     2,     1,     2,     0,     4,     1,     2,     0,     5,
       0,     0,     7,     0,     0,     0,    12,     2,     2,     0,
       5,     4,     1,     0,     0,     4,     1,     1,     0,     4,
       1,     1,     0,     4,     1,     0,     4,     0,     4,     0,
       4,     0,     4,     1,     3,     3,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     4,     3,     3,
       0,     5,     3,     1,     1,     3
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
#line 70 "subc.y" /* yacc.c:1646  */
    {     
			printf("\tshift_sp 1\n");
			printf("\tpush_const EXIT\n");
			printf("\tpush_reg fp\n");
		   	printf("\tpush_reg sp\n");
		   	printf("\tpop_reg fp\n");
			printf("\tjump main\n");
			printf("EXIT:\n");
			printf("\texit\n");
		}
#line 1409 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 79 "subc.y" /* yacc.c:1646  */
    {
			printf("Lglob.	data %d\n", Global_offset());
		}
#line 1417 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 90 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[-2].intVal)) 
				declare((yyvsp[-1].idptr), makevardecl(makeptrdecl((yyvsp[-3].declptr))));
			else 
				declare((yyvsp[-1].idptr), makevardecl((yyvsp[-3].declptr))); 
			//Lglob_inc(1);
		}
#line 1429 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 97 "subc.y" /* yacc.c:1646  */
    {

			if((yyvsp[-5].intVal)) 
				declare((yyvsp[-4].idptr), makeconstdecl(makearraydecl(yylval.intVal,makevardecl(makeptrdecl((yyvsp[-6].declptr))))));
			else 
				declare((yyvsp[-4].idptr), makeconstdecl(makearraydecl(yylval.intVal,makevardecl((yyvsp[-6].declptr)))));
			//Lglob_inc(yylval.intVal);
		}
#line 1442 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 106 "subc.y" /* yacc.c:1646  */
    { }
#line 1448 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 107 "subc.y" /* yacc.c:1646  */
    { 
			pop_scope(); 
			printf("%s_final:\n", (yyvsp[-1].idptr)->name);
			printf("\tpush_reg fp\n");
			printf("\tpop_reg sp\n");
			printf("\tpop_reg fp\n");
			printf("\tpop_reg pc\n");
			printf("%s_end:\n", (yyvsp[-1].idptr)->name);
		}
#line 1462 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 118 "subc.y" /* yacc.c:1646  */
    {(yyval.declptr)=(yyvsp[0].declptr);}
#line 1468 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 119 "subc.y" /* yacc.c:1646  */
    {(yyval.declptr)=find("void", 4);}
#line 1474 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 120 "subc.y" /* yacc.c:1646  */
    { (yyval.declptr)=(yyvsp[0].declptr);}
#line 1480 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 122 "subc.y" /* yacc.c:1646  */
    {(yyval.declptr)=find("int", 3);}
#line 1486 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 123 "subc.y" /* yacc.c:1646  */
    {(yyval.declptr)=find("char",4);}
#line 1492 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 126 "subc.y" /* yacc.c:1646  */
    {
			(yyval.declptr)=find((yyvsp[0].idptr)->name, strlen((yyvsp[0].idptr)->name));

			push_scope();
		}
#line 1502 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 131 "subc.y" /* yacc.c:1646  */
    {
			///????/////
			ste *fields = pop_scope();

			cascade_struct(fields);

			declare((yyvsp[-4].idptr), makestructdecl(fields));
			(yyval.declptr) = find((yyvsp[-4].idptr)->name, strlen((yyvsp[-4].idptr)->name));
		}
#line 1516 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 140 "subc.y" /* yacc.c:1646  */
    {
			(yyval.declptr) = find((yyvsp[0].idptr)->name, strlen((yyvsp[0].idptr)->name));
		}
#line 1524 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 146 "subc.y" /* yacc.c:1646  */
    {
			struct decl *proc_decl = makeprocdecl();
			declare((yyvsp[-2].idptr), proc_decl);
			push_scope();

			struct id *returnid = enter(0, "returnid", 8);
			if((yyvsp[-3].intVal)==1)	 declare(returnid, makevardecl(makeptrdecl((yyvsp[-4].declptr))));
			else		 declare(returnid, makevardecl((yyvsp[-4].declptr)));

			struct ste *formals;
			formals = pop_scope();
			proc_decl->returntype = formals->decl;
			proc_decl->formals = NULL;
			push_scope();
			push_declare(formals);  
			printf("%s:\n", (yyvsp[-2].idptr)->name);
			(yyval.idptr) = (yyvsp[-2].idptr);
		}
#line 1547 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 165 "subc.y" /* yacc.c:1646  */
    {
			struct decl *proc_decl = makeprocdecl();
			declare((yyvsp[-3].idptr), proc_decl);
			push_scope();

			struct id *returnid = enter(0, "returnid", 8);
			if((yyvsp[-4].intVal)==1)	 declare(returnid, makevardecl(makeptrdecl((yyvsp[-5].declptr))));
			else		 declare(returnid, makevardecl((yyvsp[-5].declptr)));

			struct ste *formals;
			formals = pop_scope();
			proc_decl->returntype = formals->decl;
			proc_decl->formals = NULL;
			push_scope();
			push_declare(formals);  
			printf("%s:\n", (yyvsp[-3].idptr)->name);
			(yyval.idptr) = (yyvsp[-3].idptr);
		}
#line 1570 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 184 "subc.y" /* yacc.c:1646  */
    {
			struct decl *proc_decl = makeprocdecl();
			declare((yyvsp[-1].idptr), proc_decl);
			push_scope();

			struct id *returnid = enter(0, "returnid", 8);
			if((yyvsp[-2].intVal)==1)	 declare(returnid, makevardecl(makeptrdecl((yyvsp[-3].declptr))));
			else		 declare(returnid, makevardecl((yyvsp[-3].declptr)));
			(yyval.declptr) = proc_decl;
		}
#line 1585 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 194 "subc.y" /* yacc.c:1646  */
    {
			struct ste *formals;
			struct decl *proc_decl = (yyvsp[-2].declptr);
			formals = pop_scope();
			
			proc_decl->returntype = get_returnid(formals);
			proc_decl->formals = formals;
			push_scope();
			push_declare(formals);  

			printf("%s:\n", (yyvsp[-4].idptr)->name);
			(yyval.idptr)=(yyvsp[-4].idptr);
		}
#line 1603 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 209 "subc.y" /* yacc.c:1646  */
    {(yyval.intVal)=1;}
#line 1609 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 210 "subc.y" /* yacc.c:1646  */
    {(yyval.intVal)=0;}
#line 1615 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 218 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[-1].intVal)) 
				declare((yyvsp[0].idptr), makevardecl(makeptrdecl((yyvsp[-2].declptr))));
			else 
				declare((yyvsp[0].idptr), makevardecl((yyvsp[-2].declptr))); 
		}
#line 1626 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 224 "subc.y" /* yacc.c:1646  */
    {
			if((yyvsp[-4].intVal)) 
				declare((yyvsp[-3].idptr), makeconstdecl(makearraydecl(yylval.intVal,makevardecl(makeptrdecl((yyvsp[-5].declptr))))));
			else 
				declare((yyvsp[-3].idptr), makeconstdecl(makearraydecl(yylval.intVal,makevardecl((yyvsp[-5].declptr)))));
		}
#line 1637 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 232 "subc.y" /* yacc.c:1646  */
    {(yyval.intVal)=1;}
#line 1643 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 233 "subc.y" /* yacc.c:1646  */
    {(yyval.intVal)=0;}
#line 1649 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 236 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[-2].intVal)) 
				declare((yyvsp[-1].idptr), makevardecl(makeptrdecl((yyvsp[-3].declptr))));
			else 
				declare((yyvsp[-1].idptr), makevardecl((yyvsp[-3].declptr))); 
		}
#line 1660 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 242 "subc.y" /* yacc.c:1646  */
    {
			if((yyvsp[-5].intVal)) 
				declare((yyvsp[-4].idptr), makeconstdecl(makearraydecl(yylval.intVal,makevardecl(makeptrdecl((yyvsp[-6].declptr))))));
			else 
				declare((yyvsp[-4].idptr), makeconstdecl(makearraydecl(yylval.intVal,makevardecl((yyvsp[-6].declptr)))));
		}
#line 1671 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 253 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[0].intVal)==1) {
				if(Local_offset()-Local_args() > 0)
					printf("\tshift_sp %d\n", Local_offset()-Local_args());
				func_start();
			}
		}
#line 1683 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 262 "subc.y" /* yacc.c:1646  */
    {(yyval.intVal)=(yyvsp[0].intVal);}
#line 1689 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 268 "subc.y" /* yacc.c:1646  */
    { 
			(yyval.intVal) = if_cnt++;
			printf("\tbranch_false ELSE_%d\n", (yyval.intVal));
		}
#line 1698 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 276 "subc.y" /* yacc.c:1646  */
    { 
			/*
			printf("\tpush_reg fp\n");
			printf("\tpush_const -1\n");
			printf("\tadd\n");
			printf("\tpush_const -1\n");
			printf("\tadd\n");
			*/
			func_return();
		}
#line 1713 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 285 "subc.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1].declptr)->type->typeclass != 4) {
				if((yyvsp[-1].declptr)->declclass==0) printf("\tfetch\n");
				printf("\tassign\n");
			}
			else { //Struct
				printf("\tassign\n");
			}
		}
#line 1727 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 296 "subc.y" /* yacc.c:1646  */
    {
			printf("ELSE_%d:\n", (yyvsp[-1].intVal) );
		}
#line 1735 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 299 "subc.y" /* yacc.c:1646  */
    {
			printf("\tjump AFTER_%d\n", (yyvsp[-2].intVal) );
			printf("ELSE_%d:\n", (yyvsp[-2].intVal) );
		}
#line 1744 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 302 "subc.y" /* yacc.c:1646  */
    {
			printf("AFTER_%d:\n", (yyvsp[-4].intVal) );
		}
#line 1752 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 305 "subc.y" /* yacc.c:1646  */
    { 
			(yyval.intVal) = while_cnt;
			set_while_stack(while_cnt);
			while_cnt++;
			printf("WHILE_START_%d:\n", (yyval.intVal));
		}
#line 1763 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 311 "subc.y" /* yacc.c:1646  */
    {  
			printf("\tbranch_false WHILE_END_%d\n", (yyvsp[-3].intVal));
		}
#line 1771 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 314 "subc.y" /* yacc.c:1646  */
    { 
			printf("\tjump WHILE_START_%d\n", (yyvsp[-5].intVal));
			printf("WHILE_END_%d:\n", (yyvsp[-5].intVal));
			free_while_stack();
		}
#line 1781 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 319 "subc.y" /* yacc.c:1646  */
    {
			(yyval.intVal) = while_cnt;
			set_while_stack(while_cnt);
			while_cnt++;
			printf("FOR_CHECK_%d:\n", (yyval.intVal));

		}
#line 1793 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 325 "subc.y" /* yacc.c:1646  */
    {
			printf("\tbranch_false WHILE_END_%d\n", (yyvsp[-2].intVal));
			printf("\tjump FOR_STMT_%d\n", (yyvsp[-2].intVal));
			printf("WHILE_START_%d:\n", (yyvsp[-2].intVal));

		}
#line 1804 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 330 "subc.y" /* yacc.c:1646  */
    {
			printf("\tjump FOR_MID_%d\n", (yyvsp[-5].intVal));
			printf("FOR_STMT_%d:\n", (yyvsp[-5].intVal));

		}
#line 1814 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 334 "subc.y" /* yacc.c:1646  */
    {
			printf("\tjump WHILE_START_%d\n", (yyvsp[-7].intVal));
			printf("FOR_MID_%d:\n", (yyvsp[-7].intVal));
			printf("\tjump FOR_CHECK_%d\n", (yyvsp[-7].intVal));
			printf("WHILE_END_%d:\n", (yyvsp[-7].intVal));
			free_while_stack();
		}
#line 1826 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 341 "subc.y" /* yacc.c:1646  */
    {
			printf("\tjump WHILE_END_%d\n", get_while_stack());
		}
#line 1834 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 344 "subc.y" /* yacc.c:1646  */
    {
			printf("\tjump WHILE_START_%d\n", get_while_stack());
		}
#line 1842 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 347 "subc.y" /* yacc.c:1646  */
    {
			printf("str_%d. string ", string_cnt);
			printf("%s\n", (yyvsp[0].stringVal));
			printf("\tpush_const str_%d\n", string_cnt++);
			printf("\twrite_string\n");

		}
#line 1854 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 353 "subc.y" /* yacc.c:1646  */
    {}
#line 1860 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 354 "subc.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1].declptr)->declclass==0) printf("\tfetch\n"); //VAR
			printf("\twrite_int\n");
		}
#line 1869 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 363 "subc.y" /* yacc.c:1646  */
    {(yyval.declptr)=(yyvsp[0].declptr);}
#line 1875 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 370 "subc.y" /* yacc.c:1646  */
    { /* ASSIGN */
			if((yyvsp[0].declptr)->type->typeclass != 4) { // not struct
				printf("\tpush_reg sp\n");
				printf("\tfetch\n");
			}			

		}
#line 1887 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 376 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[-3].declptr)->type->typeclass != 4) {
				if((yyvsp[0].declptr)->declclass==0) printf("\tfetch\n"); //VAR
				printf("\tassign\n");
				printf("\tfetch\n");
				printf("\tshift_sp -1\n");
			}
			else {
				for(int i=0; i < (yyvsp[-3].declptr)->size; i++) {
					printf("\tpush_reg sp\n"); //for VAR
					printf("\tpush_const -1\n");
					printf("\tadd\n");
					printf("\tfetch\n");
					printf("\tpush_const %d\n", i);
					printf("\tadd\n");

					printf("\tpush_reg sp\n"); //for VAL
					printf("\tpush_const -1\n");
					printf("\tadd\n");
					printf("\tfetch\n");
					printf("\tpush_const %d\n", i);
					printf("\tadd\n");

					printf("\tfetch\n");
					printf("\tassign\n");
				}
				printf("\tshift_sp -2\n");
			}
		}
#line 1921 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 405 "subc.y" /* yacc.c:1646  */
    {(yyval.declptr) = (yyvsp[0].declptr);}
#line 1927 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 408 "subc.y" /* yacc.c:1646  */
    {(yyval.declptr) = (yyvsp[0].declptr);}
#line 1933 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 411 "subc.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1].declptr)->declclass==0) printf("\tfetch\n");
		}
#line 1941 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 413 "subc.y" /* yacc.c:1646  */
    {
			if((yyvsp[0].declptr)->declclass==0) printf("\tfetch\n");
			printf("\tor\n");
			(yyval.declptr)=makenumconstdecl(find("int",3), 0);
		}
#line 1951 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 418 "subc.y" /* yacc.c:1646  */
    {(yyval.declptr) = (yyvsp[0].declptr);}
#line 1957 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 421 "subc.y" /* yacc.c:1646  */
    {(yyval.declptr) = (yyvsp[0].declptr);}
#line 1963 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 424 "subc.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1].declptr)->declclass==0) printf("\tfetch\n");
		}
#line 1971 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 426 "subc.y" /* yacc.c:1646  */
    {
			if((yyvsp[0].declptr)->declclass==0) printf("\tfetch\n");
			printf("\tand\n");
			(yyval.declptr)=makenumconstdecl(find("int",3), 0);
		}
#line 1981 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 431 "subc.y" /* yacc.c:1646  */
    {
			(yyval.declptr) = (yyvsp[0].declptr); 
		}
#line 1989 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 436 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[-1].declptr)->declclass==0) printf("\tfetch\n");
			if(!strcmp(yylval.stringVal, ">"))
				(yyval.intVal) = 0;
			if(!strcmp(yylval.stringVal, ">="))
				(yyval.intVal) = 1;
			if(!strcmp(yylval.stringVal, "<"))
				(yyval.intVal) = 2;
			if(!strcmp(yylval.stringVal, "<="))
				(yyval.intVal) = 3;
		}
#line 2005 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 446 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[0].declptr)->declclass==0) printf("\tfetch\n");
			if((yyvsp[-1].intVal)==0) printf("\tgreater\n");
			if((yyvsp[-1].intVal)==1) printf("\tgreater_equal\n");
			if((yyvsp[-1].intVal)==2) printf("\tless\n");
			if((yyvsp[-1].intVal)==3) printf("\tless_equal\n");
			
			(yyval.declptr) = makenumconstdecl((yyvsp[-3].declptr),0);
		}
#line 2019 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 455 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[-1].declptr)->declclass==0) printf("\tfetch\n");
			if(!strcmp(yylval.stringVal, "=="))
				(yyval.intVal) = 0;
			if(!strcmp(yylval.stringVal, "!="))
				(yyval.intVal) = 1;
		}
#line 2031 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 461 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[0].declptr)->declclass==0) printf("\tfetch\n");
			if((yyvsp[-1].intVal)==0) printf("\tequal\n");
			if((yyvsp[-1].intVal)==1) printf("\tnot_equal\n");
			(yyval.declptr) = makenumconstdecl((yyvsp[-3].declptr),0);
		}
#line 2042 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 467 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[-1].declptr)->declclass==0) printf("\tfetch\n");
		}
#line 2050 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 469 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[0].declptr)->declclass==0) printf("\tfetch\n");
			printf("\tadd\n");
			(yyval.declptr) = makenumconstdecl((yyvsp[-3].declptr),0);
		}
#line 2060 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 474 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[-1].declptr)->declclass==0) printf("\tfetch\n");
		}
#line 2068 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 476 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[0].declptr)->declclass==0) printf("\tfetch\n");
			printf("\tsub\n");
			(yyval.declptr) = makenumconstdecl((yyvsp[-3].declptr),0);
		}
#line 2078 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 481 "subc.y" /* yacc.c:1646  */
    { (yyval.declptr) = (yyvsp[0].declptr);}
#line 2084 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 484 "subc.y" /* yacc.c:1646  */
    {(yyval.declptr) = (yyvsp[-1].declptr);}
#line 2090 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 485 "subc.y" /* yacc.c:1646  */
    {(yyval.declptr) = (yyvsp[-1].declptr);}
#line 2096 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 486 "subc.y" /* yacc.c:1646  */
    {
			(yyval.declptr) = makenumconstdecl((yyval.declptr)=find("int", 3), yylval.intVal);
			printf("\tpush_const %d\n", yylval.intVal);
		}
#line 2105 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 490 "subc.y" /* yacc.c:1646  */
    {
			(yyval.declptr) = makenumconstdecl((yyval.declptr)=find("char", 4), (yylval.intVal));
			printf("\tpush_const %d\n", (yylval.intVal));
		}
#line 2114 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 495 "subc.y" /* yacc.c:1646  */
    { 
			(yyval.declptr) = find((yyvsp[0].idptr)->name,strlen((yyvsp[0].idptr)->name)); 
			if((yyval.declptr)->declclass==0 || (yyval.declptr)->declclass==1) { //VAR or CONST
				if((yyval.declptr)->scope->level==0)
					printf("\tpush_const Lglob+%d\n", offset((yyval.declptr),1));
				else {
					printf("\tpush_reg fp\n");
					printf("\tpush_const %d\n", offset((yyval.declptr),0));
					printf("\tadd\n");

				}
			}
		}
#line 2132 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 508 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[0].declptr)->declclass==0) printf("\tfetch\n"); //VAR 
			printf("\tpush_const -1\n");
			printf("\tmul\n");
			(yyval.declptr)=makenumconstdecl((yyvsp[0].declptr)->type, 0); 
		}
#line 2143 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 514 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[0].declptr)->declclass==0) printf("\tfetch\n"); //VAR 
			printf("\tpush_const 0\n");
			printf("\tnot_equal\n");
			(yyval.declptr)=makenumconstdecl((yyvsp[0].declptr)->type, 0); 
		}
#line 2154 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 520 "subc.y" /* yacc.c:1646  */
    { 
			(yyval.declptr) = makenumconstdecl((yyvsp[-1].declptr)->type, 0);
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tfetch\n");
			printf("\tpush_const 1\n");
			printf("\tadd\n");
			printf("\tassign\n");
			printf("\tfetch\n");
			printf("\tpush_const 1\n");
			printf("\tsub\n");
		}
#line 2173 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 534 "subc.y" /* yacc.c:1646  */
    { 
			(yyval.declptr) = makenumconstdecl((yyvsp[-1].declptr)->type, 0);
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tfetch\n");
			printf("\tpush_const 1\n");
			printf("\tsub\n");
			printf("\tassign\n");
			printf("\tfetch\n");
			printf("\tpush_const 1\n");
			printf("\tadd\n");
		}
#line 2192 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 548 "subc.y" /* yacc.c:1646  */
    { 
			(yyval.declptr) = makenumconstdecl((yyvsp[0].declptr)->type, 0);
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tfetch\n");
			printf("\tpush_const 1\n");
			printf("\tadd\n");
			printf("\tassign\n");
			printf("\tfetch\n");
		}
#line 2209 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 560 "subc.y" /* yacc.c:1646  */
    { 
			(yyval.declptr) = makenumconstdecl((yyvsp[0].declptr)->type, 0);
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tfetch\n");
			printf("\tpush_const 1\n");
			printf("\tsub\n");
			printf("\tassign\n");
			printf("\tfetch\n");
		}
#line 2226 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 572 "subc.y" /* yacc.c:1646  */
    { 
			(yyval.declptr) = makenumconstdecl((yyvsp[0].declptr)->type, 0);
			//if VAR, then treat VAR as CONST makes addr
		}
#line 2235 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 576 "subc.y" /* yacc.c:1646  */
    { 
			(yyval.declptr)=makevardecl((yyvsp[0].declptr)->type->ptrto);
			printf("\tfetch\n");
		}
#line 2244 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 580 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[-1].declptr)->declclass==0) printf("\tfetch\n");
			(yyval.declptr) = arrayaccess((yyvsp[-3].declptr)); 
			printf("\tpush_const %d\n", (yyval.declptr)->size);
			printf("\tmul\n");
			printf("\tadd\n");
		}
#line 2256 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 587 "subc.y" /* yacc.c:1646  */
    { 
			(yyval.declptr) = structaccess((yyvsp[-2].declptr),(yyvsp[0].idptr)); 
		}
#line 2264 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 590 "subc.y" /* yacc.c:1646  */
    { 
			(yyval.declptr) = structptraccess((yyvsp[-2].declptr),(yyvsp[0].idptr)); 
		}
#line 2272 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 593 "subc.y" /* yacc.c:1646  */
    {
			//printf("\tshift_sp %d\n", $1->returntype->type->size);
			printf("\tshift_sp 1\n");
			printf("\tpush_const label_%d\n", ++func_cnt);
			printf("\tpush_reg fp\n");
		}
#line 2283 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 598 "subc.y" /* yacc.c:1646  */
    {
			printf("\tpush_reg sp\n");
			printf("\tpush_const -%d\n", arg_size((yyvsp[-4].declptr)));
			printf("\tadd\n");
			printf("\tpop_reg fp\n");
			jump((yyvsp[-4].declptr));
			
			if(check_ptr((yyvsp[-4].declptr)->returntype)) (yyval.declptr) = (yyvsp[-4].declptr)->returntype;
			else (yyval.declptr) = makenumconstdecl((yyvsp[-4].declptr)->returntype->type, 0); 
		}
#line 2298 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 608 "subc.y" /* yacc.c:1646  */
    { 
			printf("\tshift_sp 1\n");
			printf("\tpush_const label_%d\n", ++func_cnt);
			printf("\tpush_reg fp\n");

			printf("\tpush_reg sp\n");
			printf("\tpop_reg fp\n");
			jump((yyvsp[-2].declptr));

			if(check_ptr((yyvsp[-2].declptr)->returntype)) (yyval.declptr) = (yyvsp[-2].declptr)->returntype;
			else (yyval.declptr) = makenumconstdecl((yyvsp[-2].declptr)->returntype->type, 0); 
		}
#line 2315 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 620 "subc.y" /* yacc.c:1646  */
    {(yyval.declptr)=find("null", 4); }
#line 2321 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 622 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[0].declptr)->declclass==0) { //VAR
				if((yyvsp[0].declptr)->type->typeclass==4) { //Struct
					for(int i=1; i<(yyvsp[0].declptr)->size; i++) {
						printf("\tpush_reg sp\n");
						printf("\tpush_const -%d\n", i-1);
						printf("\tadd\n");
						printf("\tfetch\n");

						printf("\tpush_const %d\n", i);
						printf("\tadd\n");
						printf("\tfetch\n");
					}
					printf("\tshift_sp -%d\n", (yyvsp[0].declptr)->size-1);
					printf("\tfetch\n");
					printf("\tshift_sp %d\n", (yyvsp[0].declptr)->size-1);
				}
				else printf("\tfetch\n");  //VAR only
			}
		}
#line 2346 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 642 "subc.y" /* yacc.c:1646  */
    { 
			if((yyvsp[0].declptr)->declclass==0) { //VAR
				if((yyvsp[0].declptr)->type->typeclass==4) { //Struct
					for(int i=1; i<(yyvsp[0].declptr)->size; i++) {
						printf("\tpush_reg sp\n");
						printf("\tpush_const -%d\n", i-1);
						printf("\tadd\n");
						printf("\tfetch\n");

						printf("\tpush_const %d\n", i);
						printf("\tadd\n");
						printf("\tfetch\n");
					}
					printf("\tshift_sp -%d\n", (yyvsp[0].declptr)->size-1);
					printf("\tfetch\n");
					printf("\tshift_sp %d\n", (yyvsp[0].declptr)->size-1);

				}
				else printf("\tfetch\n");  //VAR only
			}
		}
#line 2372 "subc.tab.c" /* yacc.c:1646  */
    break;


#line 2376 "subc.tab.c" /* yacc.c:1646  */
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
#line 667 "subc.y" /* yacc.c:1906  */


/*  Additional C Codes here */


int    yyerror (char* s)
{
		fprintf(stderr, "%s\n", s);
}

