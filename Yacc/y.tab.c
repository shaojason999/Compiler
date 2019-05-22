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
#line 2 "compiler_hw2.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define SCOPE 10
#define ENTRY 100

extern int yylineno;
extern int yylex();
extern void yyerror(char *s);
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

struct SYMBOL_TABLE{
	int index;
	char name[30];
	char kind[10];	// "function" or "parameter" or "variable"
	char type[10];	// "int" or float or bool or string or void
	int scope;
	int par_count;	// record how many parameters in par[]
	char par[10][10];
};

/*the current scope; the current max index of the current scope; where is the indexes(entry number)*/
int Scope, Index[SCOPE], order[SCOPE][ENTRY];

int Result,Error,Par_count;
char Variable[30],Type[10],Kind[10],Error_ID[30],Par[10][10];
struct SYMBOL_TABLE sym_table[SCOPE][ENTRY];

/* Symbol table function - you can add new function if needed. */
void create_symbol();
int insert_symbol();
int lookup_symbol(char *id);
void dump_symbol(int index);


#line 106 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ADD = 258,
    SUB = 259,
    MUL = 260,
    DIV = 261,
    MOD = 262,
    INC = 263,
    DEC = 264,
    MT = 265,
    LT = 266,
    MTE = 267,
    LTE = 268,
    EQ = 269,
    NE = 270,
    ASGN = 271,
    ADDASGN = 272,
    SUBASGN = 273,
    MULASGN = 274,
    DIVASGN = 275,
    MODASGN = 276,
    AND = 277,
    OR = 278,
    NOT = 279,
    LB = 280,
    RB = 281,
    LCB = 282,
    RCB = 283,
    LSB = 284,
    RSB = 285,
    COMMA = 286,
    PRINT = 287,
    IF = 288,
    ELSE = 289,
    FOR = 290,
    WHILE = 291,
    RET = 292,
    CONT = 293,
    BREAK = 294,
    TRUE = 295,
    FALSE = 296,
    STR_CONST = 297,
    I_CONST = 298,
    F_CONST = 299,
    C_COMMENT = 300,
    CPP_COMMENT = 301,
    SEMICOLON = 302,
    ID = 303,
    VOID = 304,
    INT = 305,
    FLOAT = 306,
    STRING = 307,
    BOOL = 308
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define MOD 262
#define INC 263
#define DEC 264
#define MT 265
#define LT 266
#define MTE 267
#define LTE 268
#define EQ 269
#define NE 270
#define ASGN 271
#define ADDASGN 272
#define SUBASGN 273
#define MULASGN 274
#define DIVASGN 275
#define MODASGN 276
#define AND 277
#define OR 278
#define NOT 279
#define LB 280
#define RB 281
#define LCB 282
#define RCB 283
#define LSB 284
#define RSB 285
#define COMMA 286
#define PRINT 287
#define IF 288
#define ELSE 289
#define FOR 290
#define WHILE 291
#define RET 292
#define CONT 293
#define BREAK 294
#define TRUE 295
#define FALSE 296
#define STR_CONST 297
#define I_CONST 298
#define F_CONST 299
#define C_COMMENT 300
#define CPP_COMMENT 301
#define SEMICOLON 302
#define ID 303
#define VOID 304
#define INT 305
#define FLOAT 306
#define STRING 307
#define BOOL 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 45 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* string;
    bool boolean;

#line 259 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 276 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   368

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  230

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
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    84,    88,    91,    92,    96,    97,   101,
     109,   120,   121,   122,   127,   131,   132,   133,   134,   138,
     139,   140,   141,   142,   146,   155,   164,   164,   173,   173,
     186,   189,   195,   196,   197,   198,   199,   200,   204,   205,
     209,   210,   214,   215,   219,   220,   224,   225,   229,   230,
     234,   235,   237,   241,   242,   246,   247,   251,   252,   253,
     257,   258,   262,   263,   267,   268,   269,   273,   274,   275,
     276,   277,   278,   282,   283,   287,   288,   292,   293,   294,
     298,   299,   300,   301,   302,   306,   307,   308,   312,   313,
     314,   315,   319,   320,   321,   327,   328,   329,   330,   331,
     332,   333,   337,   338,   342,   343,   347,   348,   352,   353,
     354,   358,   359,   360,   361,   362,   366,   367,   368,   372,
     373,   374,   375,   379,   380,   381,   385,   386,   390,   391,
     392,   396,   400,   401,   402,   403,   404,   405,   406,   410,
     411,   415,   416,   420,   421,   423,   427,   428,   429
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "MOD", "INC",
  "DEC", "MT", "LT", "MTE", "LTE", "EQ", "NE", "ASGN", "ADDASGN",
  "SUBASGN", "MULASGN", "DIVASGN", "MODASGN", "AND", "OR", "NOT", "LB",
  "RB", "LCB", "RCB", "LSB", "RSB", "COMMA", "PRINT", "IF", "ELSE", "FOR",
  "WHILE", "RET", "CONT", "BREAK", "TRUE", "FALSE", "STR_CONST", "I_CONST",
  "F_CONST", "C_COMMENT", "CPP_COMMENT", "SEMICOLON", "ID", "VOID", "INT",
  "FLOAT", "STRING", "BOOL", "$accept", "program", "external_declaration",
  "global_declaration", "global_declarator_list", "global_declarator",
  "only_const_operation", "const_without_str", "type", "function", "$@1",
  "$@2", "function_parameter_list", "statement", "statement_with_return",
  "print_statement", "comment", "jump_statement", "compound_statement",
  "block_item_list", "block_item", "local_declaration",
  "local_declarator_list", "local_declarator", "expression_statement",
  "expression_list", "assignment_expression", "assignment_operator",
  "logical_or_expression", "logical_and_expression", "equality_expression",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "prefix_expression", "postfix_expression",
  "bra_expression", "const_logical_or_expression",
  "const_logical_and_expression", "const_equality_expression",
  "const_relational_expression", "const_additive_expression",
  "const_multiplicative_expression", "const_prefix_expression",
  "const_postfix_expression", "selection_statement", "iteration_statement",
  "loop_statement", "loop_compound_statement", "loop_block_item_list",
  "loop_block_item", "loop_jump_statement", YY_NULLPTR
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

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -103

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     315,  -136,  -136,  -136,  -136,  -136,  -136,  -136,     6,  -136,
    -136,    26,  -136,  -136,  -136,  -136,  -136,    -1,    36,  -136,
     295,   -19,   -39,  -136,   301,   301,   301,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,     3,    15,   107,   125,   177,   141,
    -136,  -136,    67,    14,    92,    83,  -136,  -136,  -136,   129,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,  -136,   156,  -136,   109,   196,  -136,    15,
     107,   125,   125,   177,   177,   177,   177,   141,   141,  -136,
    -136,  -136,   157,  -136,  -136,   156,   120,   269,   269,   281,
    -136,   174,   189,   194,   219,  -136,   338,  -136,   148,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,   188,  -136,  -136,  -136,
      40,  -136,   207,   228,   197,   244,   214,   181,  -136,  -136,
     218,  -136,  -136,  -136,  -136,    11,  -136,  -136,    94,     9,
     -26,   281,   281,  -136,  -136,   216,  -136,  -136,  -136,  -136,
    -136,   239,   281,  -136,    52,    44,  -136,  -136,  -136,   281,
    -136,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,  -136,  -136,  -136,  -136,   235,   255,
     108,   118,  -136,  -136,   119,  -136,   249,   238,  -136,  -136,
     228,   197,   244,   244,   214,   214,   214,   214,   181,   181,
    -136,  -136,  -136,   241,   260,   156,   284,  -136,  -136,  -136,
     292,  -136,  -136,  -136,   282,    57,  -136,    86,  -136,   271,
     272,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,   126,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    42,    43,    19,    20,    21,    22,    23,     0,     2,
       5,     0,     4,     6,     1,     3,     7,    11,     0,     9,
       0,     0,     0,     8,     0,     0,     0,    17,    18,    13,
      15,    16,    12,   126,    14,   104,   106,   108,   111,   116,
     119,   123,    26,     0,     0,    11,    10,   124,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,    30,    28,     0,   127,   105,
     107,   109,   110,   112,   113,   114,   115,   117,   118,   120,
     121,   122,     0,    27,    25,     0,     0,     0,     0,     0,
      46,     0,     0,     0,     0,    60,    95,    98,     0,    52,
      50,    33,    39,    36,    37,    32,     0,    48,    51,    38,
       0,    62,    64,    73,    75,    77,    80,    85,    88,    92,
       0,    34,    35,    29,    31,    95,    93,    94,     0,     0,
       0,     0,     0,    44,    45,    67,    68,    69,    70,    71,
      72,     0,     0,    53,    57,     0,    55,    47,    49,     0,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,    99,   103,     0,     0,
       0,     0,    66,    96,     0,    65,     0,     0,    54,    63,
      74,    76,    78,    79,    81,    82,    83,    84,    86,    87,
      89,    90,    91,     0,     0,     0,     0,    97,    59,    58,
      57,    56,    41,    40,   128,     0,   131,     0,   139,     0,
       0,   145,   136,   137,   148,   132,   144,   133,   134,   135,
     143,     0,   141,   138,   130,   129,   146,   147,   140,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,   319,  -136,  -136,   306,  -136,   -12,     2,   -81,
    -136,  -136,  -136,  -136,   229,  -129,   -79,   -94,   -64,  -136,
     224,   -93,  -136,   154,   -89,   -78,   -61,  -136,  -136,   182,
     180,   142,   113,   143,   -83,  -136,   245,   314,   293,   297,
     248,   221,   256,     4,  -136,  -135,   -88,  -136,  -136,  -136,
     128,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    18,    19,    32,    97,    98,    12,
      64,    85,    44,   100,   101,   102,    13,   104,   105,   106,
     107,   108,   145,   146,   109,   110,   111,   142,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    34,    35,    36,
      37,    38,    39,    40,    41,   121,   122,   220,   206,   221,
     222,   223
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,    99,    11,   103,   126,   127,    14,    42,    33,    45,
      11,   128,    33,    33,    33,    20,   168,   164,   165,  -102,
    -102,   123,   169,    43,    21,    99,    50,   103,    47,    48,
       3,     4,     5,     6,     7,   167,   141,    51,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,     1,     2,   170,   171,     3,     4,     5,     6,     7,
      87,    88,    65,   174,    79,    80,    81,    22,   176,    86,
     218,   149,   225,    16,    17,   177,   212,    21,   190,   191,
     192,   175,    89,    23,    82,   208,   218,   150,   179,    91,
      92,   178,   212,    93,    94,   209,   210,    27,    28,    20,
      30,    31,     1,     2,    95,    96,     3,     4,     5,     6,
       7,   214,   216,    82,    63,   199,   217,   219,    66,    92,
     166,    52,    53,    67,   211,   149,   213,   214,   216,    87,
      88,   204,   217,   219,   195,    54,    55,    56,    57,   149,
     211,   215,   213,   224,   196,   197,    60,    61,    62,   149,
     149,    89,    50,    82,   228,    68,    84,   215,    91,    92,
      87,    88,    93,    94,   209,   210,    27,    28,   124,    30,
      31,     1,     2,    95,    96,     3,     4,     5,     6,     7,
      58,    59,    89,    82,    82,    90,   161,   162,   163,    91,
      92,    87,    88,    93,    94,   143,   144,    27,    28,   130,
      30,    31,     1,     2,    95,    96,     3,     4,     5,     6,
       7,   153,   154,    89,   131,    82,   147,   159,   160,   132,
      91,    92,    87,    88,    93,    94,   164,   165,    27,    28,
     151,    30,    31,     1,     2,    95,    96,     3,     4,     5,
       6,     7,    87,    88,    89,     3,     4,     5,     6,     7,
     152,    91,    87,    88,   155,   156,   157,   158,   172,    27,
      28,   193,    30,    31,    89,   173,   133,    96,   184,   185,
     186,   187,    87,    88,    89,    73,    74,    75,    76,    27,
      28,   194,    30,    31,    87,    88,   200,    96,   202,    27,
      28,   198,    30,    31,    89,   182,   183,    96,    24,    25,
      71,    72,   188,   189,    24,    25,    89,   203,   176,    27,
      28,   205,    30,    31,    77,    78,   207,   125,   226,   227,
      26,    27,    28,   134,    30,    31,    26,    15,    46,    96,
     148,   201,   181,   180,   129,    27,    28,    29,    30,    31,
      49,    27,    28,    69,    30,    31,  -102,  -102,    70,   229,
       0,     0,     0,     0,   135,   136,   137,   138,   139,   140,
       1,     2,     0,   141,     3,     4,     5,     6,     7
};

static const yytype_int16 yycheck[] =
{
      64,    82,     0,    82,    87,    88,     0,    26,    20,    48,
       8,    89,    24,    25,    26,    16,    42,     8,     9,     8,
       9,    85,    48,    21,    25,   106,    23,   106,    24,    25,
      49,    50,    51,    52,    53,    26,    25,    22,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    45,    46,   131,   132,    49,    50,    51,    52,    53,
       3,     4,    48,   141,    60,    61,    62,    31,    16,    67,
     205,    31,   207,    47,    48,    31,   205,    25,   161,   162,
     163,   142,    25,    47,    27,    28,   221,    47,   149,    32,
      33,    47,   221,    36,    37,    38,    39,    40,    41,    16,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,   205,   205,    27,    47,   176,   205,   205,    26,    33,
      26,    14,    15,    31,   205,    31,   205,   221,   221,     3,
       4,   195,   221,   221,    26,    10,    11,    12,    13,    31,
     221,   205,   221,   207,    26,    26,     5,     6,     7,    31,
      31,    25,    23,    27,    28,    26,    47,   221,    32,    33,
       3,     4,    36,    37,    38,    39,    40,    41,    48,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       3,     4,    25,    27,    27,    28,     5,     6,     7,    32,
      33,     3,     4,    36,    37,    47,    48,    40,    41,    25,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    14,    15,    25,    25,    27,    28,     3,     4,    25,
      32,    33,     3,     4,    36,    37,     8,     9,    40,    41,
      23,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     3,     4,    25,    49,    50,    51,    52,    53,
      22,    32,     3,     4,    10,    11,    12,    13,    42,    40,
      41,    26,    43,    44,    25,    26,    47,    48,   155,   156,
     157,   158,     3,     4,    25,    54,    55,    56,    57,    40,
      41,    26,    43,    44,     3,     4,    48,    48,    47,    40,
      41,    42,    43,    44,    25,   153,   154,    48,     3,     4,
      52,    53,   159,   160,     3,     4,    25,    47,    16,    40,
      41,    27,    43,    44,    58,    59,    34,    48,    47,    47,
      25,    40,    41,    94,    43,    44,    25,     8,    22,    48,
     106,   177,   152,   151,    89,    40,    41,    42,    43,    44,
      26,    40,    41,    50,    43,    44,     8,     9,    51,   221,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      45,    46,    -1,    25,    49,    50,    51,    52,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,    49,    50,    51,    52,    53,    55,    56,
      57,    62,    63,    70,     0,    56,    47,    48,    58,    59,
      16,    25,    31,    47,     3,     4,    25,    40,    41,    42,
      43,    44,    60,    61,    91,    92,    93,    94,    95,    96,
      97,    98,    26,    62,    66,    48,    59,    97,    97,    91,
      23,    22,    14,    15,    10,    11,    12,    13,     3,     4,
       5,     6,     7,    47,    64,    48,    26,    31,    26,    92,
      93,    94,    94,    95,    95,    95,    95,    96,    96,    97,
      97,    97,    27,    72,    47,    65,    62,     3,     4,    25,
      28,    32,    33,    36,    37,    47,    48,    61,    62,    63,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    78,
      79,    80,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    99,   100,    72,    48,    48,    88,    88,    79,    90,
      25,    25,    25,    47,    68,    16,    17,    18,    19,    20,
      21,    25,    81,    47,    48,    76,    77,    28,    74,    31,
      47,    23,    22,    14,    15,    10,    11,    12,    13,     3,
       4,     5,     6,     7,     8,     9,    26,    26,    42,    48,
      79,    79,    42,    26,    79,    80,    16,    31,    47,    80,
      83,    84,    85,    85,    86,    86,    86,    86,    87,    87,
      88,    88,    88,    26,    26,    26,    26,    26,    42,    80,
      48,    77,    47,    47,    72,    27,   102,    34,    28,    38,
      39,    63,    69,    70,    71,    72,    75,    78,    99,   100,
     101,   103,   104,   105,    72,    99,    47,    47,    28,   104
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    57,    57,    58,
      58,    59,    59,    59,    60,    61,    61,    61,    61,    62,
      62,    62,    62,    62,    63,    63,    64,    63,    65,    63,
      66,    66,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      78,    78,    79,    79,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    82,    82,    83,    83,    84,    84,    84,
      85,    85,    85,    85,    85,    86,    86,    86,    87,    87,
      87,    87,    88,    88,    88,    89,    89,    89,    89,    89,
      89,    89,    90,    90,    91,    91,    92,    92,    93,    93,
      93,    94,    94,    94,    94,    94,    95,    95,    95,    96,
      96,    96,    96,    97,    97,    97,    98,    98,    99,    99,
      99,   100,   101,   101,   101,   101,   101,   101,   101,   102,
     102,   103,   103,   104,   104,   104,   105,   105,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     3,     1,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     6,     0,     6,     0,     7,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     1,     1,     2,     2,     2,     3,     1,     2,
       1,     1,     1,     2,     3,     1,     3,     1,     3,     3,
       1,     2,     1,     3,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     1,     3,     4,     1,     3,
       2,     2,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     1,     3,     5,     7,
       7,     5,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     2,     1,     1,     1,     2,     2,     1
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
        case 4:
#line 88 "compiler_hw2.y" /* yacc.c:1646  */
    {/*Par_count, Par*/}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 101 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Kind,"variable");
		Par_count=0;
		Result=insert_symbol();
		if(Result==-1){	//redefined
			Error=2;
			strcpy(Error_ID,Variable);
		}}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 109 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Kind,"variable");
		Par_count=0;
		Result=insert_symbol();
		if(Result==-1){	//redefined
			Error=2;
			strcpy(Error_ID,Variable);
		}}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 120 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[0].string));}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 121 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[-2].string));}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 122 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[-2].string));}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 138 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 139 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 140 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 141 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 142 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 146 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Variable, (yyvsp[-3].string));
		strcpy(Kind,"function");
		Par_count=0;
		Result=insert_symbol();
		if(Result==-1){	//redeclare function
			Error=3;
			strcpy(Error_ID,Variable);
		}}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 155 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Variable, (yyvsp[-4].string));
		strcpy(Kind,"function");
		strcpy(Type,(yyvsp[-5].string));
		Result=insert_symbol();
		if(Result==-1){	//redeclare function
			Error=3;
			strcpy(Error_ID,Variable);
		}}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 164 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Variable,(yyvsp[-2].string));
		strcpy(Kind,"function");
		Result=insert_symbol();
		if(Result==-1){	//redeclare function
			Error=3;
			strcpy(Error_ID,Variable);
		}}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 173 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Variable,(yyvsp[-3].string));
		strcpy(Kind,"function");
		strcpy(Type,(yyvsp[-4].string));
		Result=insert_symbol();
		if(Result==-1){	//redeclare function
			Error=3;
			strcpy(Error_ID,Variable);
		}}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 186 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Par[Par_count++],Type);
		}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 189 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Par[Par_count++],Type);
		}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1712 "y.tab.c" /* yacc.c:1646  */
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
#line 432 "compiler_hw2.y" /* yacc.c:1906  */

/* C code section */

void Sem_Err()
{
	char *s;
	if(Error==0)
		s="Undeclared variable";
	else if(Error==1)
		s="Undeclared function";
	else if(Error==2)
		s="Redeclared variable";
	else if(Error==3)
		s="Redeclared function";
	
	printf("\n|-----------------------------------------------|\n");
	printf("| Error found in line %d: %s\n", yylineno, buf);
	printf("| %s %s", s, Error_ID);
	printf("\n|-----------------------------------------------|\n\n");


}

void yyerror(char *s)
{
	if(Error!=-1)
		Sem_Err();

	char temp[256];
	memset(temp,0,sizeof(temp));
	strncpy(temp,buf,strlen(buf)-1);	//discard the unmatched token
	printf("%d: %s",++yylineno,temp);
	printf("\n|-----------------------------------------------|\n");
	printf("| Error found in line %d: %s\n", yylineno, buf);
	printf("| %s", s);
	printf("\n|-----------------------------------------------|\n\n");
}

int hash(char *id, int num)
{
	/*sum of each char + num^2 (if collision)*/
	int i,sum=0;
	for(i=0;id[i]!='\0';++i)
		sum+=id[i];
	sum+=num*num;
	sum%=97;	//a prime number;
//printf("hash: %s %d %d %d \n\n",id,num,i,sum);
	return sum;
}

void create_symbol()
{
	++Scope;
	/*reset all*/
	int i,j;
	memset(sym_table[Scope],0,sizeof(sym_table[Scope]));
	for(i=0;i<ENTRY;++i){
		sym_table[Scope][i].index=-1;
		sym_table[Scope][i].scope=-1;
		sym_table[Scope][i].par_count=-1;
	}
}

int insert_symbol()
{
	int index,i,j;
	/*only find in this scope*/
	for(i=0;i<1000;++i){
		index=hash(Variable,i);
		if(sym_table[Scope][index].index==-1){	//found the empty entry
			sym_table[Scope][index].index=++Index[Scope];
			strcpy(sym_table[Scope][index].name,Variable);
			strcpy(sym_table[Scope][index].kind,Kind);
			strcpy(sym_table[Scope][index].type,Type);
			sym_table[Scope][index].scope=Scope;
			sym_table[Scope][index].par_count=Par_count;
			for(j=0;j<Par_count;++j)
				strcpy(sym_table[Scope][index].par[j],Par[j]);
			Par_count=0;
			order[Scope][Index[Scope]]=index;
			return 1;
		}
		else if(strcmp(sym_table[Scope][index].name,Variable)==0){	//already exists
			Par_count=0;
			return -1;
		}
	}
}

int lookup_symbol(char *id)
{
	int index,i,scope=Scope;
	for(;scope>=0;--scope){
		for(i=0;i<1000;++i){
			index=hash(id,i);
			if(sym_table[scope][index].index==-1)	//empty entry (not found)
				continue;
			else if(strcmp(sym_table[scope][index].name,id)==0)	//already exists
				return 1;
		}
		if(i==1000){
			printf("symbol table is too small\n");
			exit(-1);
		}
	}
	return -1;	//not found in any scope level
}

void dump_symbol(int index) {
    int i,j,entry;
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");

    for(i=0;i<=index;++i){
    	    entry=order[Scope][i];
	    printf("%-10d%-10s%-12s%-10s%-10d",
    		   i,sym_table[Scope][entry].name,sym_table[Scope][entry].kind,sym_table[Scope][entry].type,sym_table[Scope][entry].scope);
	    if(sym_table[Scope][entry].par_count!=-1)
	    	printf("%s",sym_table[Scope][entry].par[0]);
	    for(j=1;j<sym_table[Scope][entry].par_count;++j)
		    printf(", %s",sym_table[Scope][entry].par[j]);
	    printf("\n");
    }
//    --Scope;

}

void init()
{
	int i,j;
	yylineno = 0;
	Error=-1;
	for(i=0;i<SCOPE;++i)
		Index[i]=-1;
	for(i=0;i<SCOPE;++i)
		for(j=0;j<ENTRY;++j)
			order[i][j]=-1;
	/*
	strcpy(Variable,"");
	strcpy(Kind,"");
	strcpy(Type,"");
	for(i=0;i<10;++i)
		strcpy(Par[i],"");*/

	Scope=-1;
	Par_count=0;
}

int main(int argc, char** argv)
{
	init();
	create_symbol();

	yyparse();

	dump_symbol(Index[0]);

	printf("\nTotal lines: %d \n",yylineno);

	return 0;
}

