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
	int function_status;	//-1 for not a function, 0 for declared, 1 for defined, 2 for declared and defined
};

/*the current scope; the current max index of the current scope; where is the indexes(entry number)*/
int Scope, Index[SCOPE], order[SCOPE][ENTRY];

int Result,Par_count;
int Error;	//0 for no error, 1 for undeclared var, 2 for undeclared func, 3 for redeclared var, 4 for redeclaration func
int Function_status;	//-1 for not a function, 0 for declare, 1 for define, 2 for function call
int dump_flag,function_flag;
char Variable[30],Type[10],Kind[10],Error_ID[30];
char Par[10][10],Par_id[10][30];
struct SYMBOL_TABLE sym_table[SCOPE][ENTRY];

/* Symbol table function - you can add new function if needed. */
int find_the_function_index(char *);
void create_symbol();
int insert_symbol();
int lookup_symbol(char *id);
void dump_symbol(int index);


#line 112 "y.tab.c" /* yacc.c:339  */

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
#line 51 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* string;
    bool boolean;

#line 265 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 282 "y.tab.c" /* yacc.c:358  */

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
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

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
       0,    89,    89,    90,    94,    97,    98,   102,   103,   107,
     116,   128,   129,   130,   134,   138,   139,   140,   141,   145,
     146,   147,   148,   149,   153,   164,   175,   175,   185,   185,
     203,   208,   216,   217,   218,   219,   220,   221,   225,   226,
     230,   230,   237,   241,   242,   246,   247,   252,   252,   273,
     273,   297,   298,   302,   303,   304,   308,   309,   313,   322,
     334,   335,   336,   340,   341,   345,   346,   350,   351,   351,
     358,   358,   368,   369,   370,   371,   372,   373,   377,   378,
     382,   383,   387,   388,   389,   393,   394,   395,   396,   397,
     401,   402,   403,   407,   408,   409,   410,   414,   415,   416,
     422,   429,   429,   437,   437,   445,   446,   447,   448,   452,
     459,   463,   464,   468,   469,   473,   474,   475,   479,   480,
     481,   482,   483,   487,   488,   489,   493,   494,   495,   496,
     500,   501,   502,   506,   507,   511,   512,   513,   517,   521,
     522,   523,   524,   525,   526,   527,   531,   532,   533,   537,
     537,   558,   558,   582,   583,   587,   588,   589,   593,   594,
     595
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
  "print_statement", "$@3", "comment", "jump_statement",
  "compound_statement", "$@4", "$@5", "block_item_list", "block_item",
  "local_declaration", "local_declarator_list", "local_declarator",
  "expression_statement", "expression_list", "assignment_expression",
  "$@6", "$@7", "assignment_operator", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "prefix_expression",
  "postfix_expression", "$@8", "$@9", "bra_expression",
  "const_logical_or_expression", "const_logical_and_expression",
  "const_equality_expression", "const_relational_expression",
  "const_additive_expression", "const_multiplicative_expression",
  "const_prefix_expression", "const_postfix_expression",
  "selection_statement", "iteration_statement", "loop_statement",
  "loop_selection_statement", "loop_compound_statement", "$@10", "$@11",
  "loop_block_item_list", "loop_block_item", "loop_jump_statement", YY_NULLPTR
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

#define YYPACT_NINF -205

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-205)))

#define YYTABLE_NINF -150

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     134,  -205,  -205,  -205,  -205,  -205,  -205,  -205,     7,  -205,
    -205,   -30,  -205,  -205,  -205,  -205,  -205,     3,   -21,  -205,
       5,   -15,    65,  -205,   261,   261,   261,  -205,  -205,  -205,
    -205,  -205,  -205,  -205,    94,   120,   175,    68,   194,   250,
    -205,  -205,   104,   124,    63,   166,  -205,  -205,  -205,    67,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,  -205,   151,  -205,   177,   272,  -205,   120,
     175,    68,    68,   194,   194,   194,   194,   250,   250,  -205,
    -205,  -205,   181,  -205,  -205,   151,   192,   232,   198,  -205,
    -205,  -205,   249,   249,   255,   243,   246,   256,   229,  -205,
     106,  -205,   158,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
     167,  -205,  -205,  -205,   -16,  -205,   252,   257,   207,   216,
     233,   329,  -205,  -205,   254,  -205,  -205,    42,  -205,  -205,
      90,    46,   -26,   255,   255,  -205,  -205,   297,  -205,  -205,
    -205,  -205,  -205,   259,  -205,  -205,    58,    -6,  -205,  -205,
    -205,   255,  -205,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,  -205,  -205,  -205,  -205,
     265,  -205,   109,   113,   298,   268,   255,   255,   133,   293,
    -205,  -205,   257,   207,   216,   216,   233,   233,   233,   233,
     329,   329,  -205,  -205,  -205,   253,   316,   151,   317,  -205,
    -205,   162,  -205,  -205,  -205,   327,  -205,  -205,   299,   311,
     319,  -205,  -205,  -205,   101,   320,   116,  -205,  -205,  -205,
     324,   303,   304,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,  -205,  -205,    59,  -205,  -205,   255,  -205,  -205,  -205,
    -205,   165,   317,   318,   105,  -205,  -205
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    43,    44,    19,    20,    21,    22,    23,     0,     2,
       5,     0,     4,     6,     1,     3,     7,    11,     0,     9,
       0,     0,     0,     8,     0,     0,     0,    17,    18,    13,
      15,    16,    12,   133,    14,   111,   113,   115,   118,   123,
     126,   130,    26,     0,     0,    11,    10,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,    30,    28,     0,   134,   112,
     114,   116,   117,   119,   120,   121,   122,   124,   125,   127,
     128,   129,    49,    27,    25,     0,     0,     0,     0,    29,
      31,    48,     0,     0,     0,     0,     0,     0,     0,    63,
     100,   105,     0,    55,    53,    33,    39,    36,    37,    32,
       0,    51,    54,    38,     0,    65,    67,    78,    80,    82,
      85,    90,    93,    97,     0,    34,    35,   100,    98,    99,
       0,     0,     0,     0,     0,    45,    46,    72,    73,    74,
      75,    76,    77,   103,    68,    56,    60,     0,    58,    50,
      52,     0,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   108,   106,   110,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
      57,    66,    79,    81,    83,    84,    86,    87,    88,    89,
      91,    92,    94,    95,    96,     0,     0,     0,     0,    71,
     102,     0,    69,    62,    61,    60,    59,    42,     0,   135,
     151,   138,   104,    41,     0,     0,     0,   137,   136,   150,
       0,     0,     0,   157,   143,   144,   160,   156,   140,   142,
     155,   141,   139,     0,   153,   145,     0,   158,   159,   152,
     154,     0,     0,   146,     0,   147,   148
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -205,  -205,   345,  -205,  -205,   332,  -205,   258,     6,   -87,
    -205,  -205,  -205,  -205,   260,  -204,  -205,   -86,  -172,   -64,
    -205,  -205,  -205,   245,  -151,  -205,   178,  -145,   -91,  -138,
    -205,  -205,  -205,  -205,   203,   205,   111,   169,   126,   -88,
    -205,  -205,  -205,   266,   335,   312,   313,   285,   276,   248,
       8,  -205,   149,  -115,  -205,   121,  -178,  -205,  -205,  -205,
     135,  -205
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    18,    19,    32,   101,   102,    12,
      64,    85,    44,   104,   105,   106,   196,    13,   108,   109,
      87,    88,   110,   111,   112,   147,   148,   113,   114,   115,
     177,   174,   144,   116,   117,   118,   119,   120,   121,   122,
     123,   175,   176,   124,    34,    35,    36,    37,    38,    39,
      40,    41,   125,   126,   230,   231,   232,   215,   216,   233,
     234,   235
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,   103,   107,   130,   128,   129,    11,    14,    24,    25,
      22,    42,   224,   181,    11,   151,   170,    16,    17,    20,
     211,    89,   171,   103,   107,   179,    23,    43,    21,   224,
      26,   152,    47,    48,     3,     4,     5,     6,     7,   202,
     204,   180,   172,   173,   226,    27,    28,    29,    30,    31,
    -109,  -109,     1,     2,   166,   167,     3,     4,     5,     6,
       7,   226,    92,    93,   243,   227,   246,   143,    79,    80,
      81,   228,   169,    86,   178,   192,   193,   194,    54,    55,
      56,    57,   227,    21,    94,   201,   210,   239,   228,    66,
      50,    95,   220,    68,    67,    97,    98,   221,   222,    27,
      28,   229,    30,    31,     1,     2,    99,   100,     3,     4,
       5,     6,     7,    45,  -109,  -109,   168,    50,   229,    92,
      93,   151,   137,   138,   139,   140,   141,   142,    82,   223,
     225,   143,   210,   209,    96,   197,    92,    93,   220,   198,
     151,    94,    51,   210,   151,   241,   223,   225,    95,   220,
     217,    63,    97,    98,   221,   222,    27,    28,    94,    30,
      31,     1,     2,    99,   100,     3,     4,     5,     6,     7,
      92,    93,    65,    27,    28,   203,    30,    31,    82,     1,
       2,   100,    20,     3,     4,     5,     6,     7,   212,    52,
      53,   242,    94,   151,    82,   149,   151,    58,    59,    95,
      96,    92,    93,    97,    98,   145,   146,    27,    28,   -47,
      30,    31,     1,     2,    99,   100,     3,     4,     5,     6,
       7,   155,   156,    94,    84,    82,   157,   158,   159,   160,
      95,    96,    92,    93,    97,    98,   161,   162,    27,    28,
      90,    30,    31,     1,     2,    99,   100,     3,     4,     5,
       6,     7,    92,    93,    94,    60,    61,    62,    92,    93,
      91,    95,   166,   167,    24,    25,   184,   185,   132,    27,
      28,   133,    30,    31,    94,   153,   135,   100,    33,   154,
      94,   134,    33,    33,    33,  -101,    26,   190,   191,    27,
      28,   195,    30,    31,   200,    27,    28,   127,    30,    31,
     207,    27,    28,   100,    30,    31,    77,    78,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,     3,     4,     5,     6,     7,   186,   187,   188,   189,
      73,    74,    75,    76,   163,   164,   165,    71,    72,   -70,
     199,   205,   208,   178,   210,   214,   213,  -149,   219,   236,
     237,   238,   244,    15,    46,   150,   182,   206,   136,   183,
     131,    49,    69,   218,    70,   245,     0,     0,   240
};

static const yytype_int16 yycheck[] =
{
      64,    88,    88,    94,    92,    93,     0,     0,     3,     4,
      31,    26,   216,   151,     8,    31,    42,    47,    48,    16,
     198,    85,    48,   110,   110,    31,    47,    21,    25,   233,
      25,    47,    24,    25,    49,    50,    51,    52,    53,   177,
     178,    47,   133,   134,   216,    40,    41,    42,    43,    44,
       8,     9,    45,    46,     8,     9,    49,    50,    51,    52,
      53,   233,     3,     4,   242,   216,   244,    25,    60,    61,
      62,   216,    26,    67,    16,   163,   164,   165,    10,    11,
      12,    13,   233,    25,    25,   176,    27,    28,   233,    26,
      23,    32,    33,    26,    31,    36,    37,    38,    39,    40,
      41,   216,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    48,     8,     9,    26,    23,   233,     3,
       4,    31,    16,    17,    18,    19,    20,    21,    27,   216,
     216,    25,    27,   197,    33,    26,     3,     4,    33,    26,
      31,    25,    22,    27,    31,   236,   233,   233,    32,    33,
     214,    47,    36,    37,    38,    39,    40,    41,    25,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       3,     4,    48,    40,    41,    42,    43,    44,    27,    45,
      46,    48,    16,    49,    50,    51,    52,    53,    26,    14,
      15,    26,    25,    31,    27,    28,    31,     3,     4,    32,
      33,     3,     4,    36,    37,    47,    48,    40,    41,    28,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    14,    15,    25,    47,    27,    10,    11,    12,    13,
      32,    33,     3,     4,    36,    37,     3,     4,    40,    41,
      48,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     3,     4,    25,     5,     6,     7,     3,     4,
      28,    32,     8,     9,     3,     4,   155,   156,    25,    40,
      41,    25,    43,    44,    25,    23,    47,    48,    20,    22,
      25,    25,    24,    25,    26,    26,    25,   161,   162,    40,
      41,    26,    43,    44,    26,    40,    41,    48,    43,    44,
      47,    40,    41,    48,    43,    44,    58,    59,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    49,    50,    51,    52,    53,   157,   158,   159,   160,
      54,    55,    56,    57,     5,     6,     7,    52,    53,    42,
      42,    48,    26,    16,    27,    34,    47,    28,    28,    25,
      47,    47,    34,     8,    22,   110,   153,   179,    98,   154,
      94,    26,    50,   214,    51,   244,    -1,    -1,   233
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,    49,    50,    51,    52,    53,    55,    56,
      57,    62,    63,    71,     0,    56,    47,    48,    58,    59,
      16,    25,    31,    47,     3,     4,    25,    40,    41,    42,
      43,    44,    60,    61,    98,    99,   100,   101,   102,   103,
     104,   105,    26,    62,    66,    48,    59,   104,   104,    98,
      23,    22,    14,    15,    10,    11,    12,    13,     3,     4,
       5,     6,     7,    47,    64,    48,    26,    31,    26,    99,
     100,   101,   101,   102,   102,   102,   102,   103,   103,   104,
     104,   104,    27,    73,    47,    65,    62,    74,    75,    73,
      48,    28,     3,     4,    25,    32,    33,    36,    37,    47,
      48,    61,    62,    63,    67,    68,    69,    71,    72,    73,
      76,    77,    78,    81,    82,    83,    87,    88,    89,    90,
      91,    92,    93,    94,    97,   106,   107,    48,    93,    93,
      82,    97,    25,    25,    25,    47,    68,    16,    17,    18,
      19,    20,    21,    25,    86,    47,    48,    79,    80,    28,
      77,    31,    47,    23,    22,    14,    15,    10,    11,    12,
      13,     3,     4,     5,     6,     7,     8,     9,    26,    26,
      42,    48,    82,    82,    85,    95,    96,    84,    16,    31,
      47,    83,    88,    89,    90,    90,    91,    91,    91,    91,
      92,    92,    93,    93,    93,    26,    70,    26,    26,    42,
      26,    82,    83,    42,    83,    48,    80,    47,    26,    73,
      27,   110,    26,    47,    34,   111,   112,    73,   106,    28,
      33,    38,    39,    63,    69,    71,    72,    78,    81,   107,
     108,   109,   110,   113,   114,   115,    25,    47,    47,    28,
     114,    82,    26,   110,    34,   109,   110
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    57,    57,    58,
      58,    59,    59,    59,    60,    61,    61,    61,    61,    62,
      62,    62,    62,    62,    63,    63,    64,    63,    65,    63,
      66,    66,    67,    67,    67,    67,    67,    67,    68,    68,
      70,    69,    69,    71,    71,    72,    72,    74,    73,    75,
      73,    76,    76,    77,    77,    77,    78,    78,    79,    79,
      80,    80,    80,    81,    81,    82,    82,    83,    84,    83,
      85,    83,    86,    86,    86,    86,    86,    86,    87,    87,
      88,    88,    89,    89,    89,    90,    90,    90,    90,    90,
      91,    91,    91,    92,    92,    92,    92,    93,    93,    93,
      94,    95,    94,    96,    94,    94,    94,    94,    94,    97,
      97,    98,    98,    99,    99,   100,   100,   100,   101,   101,
     101,   101,   101,   102,   102,   102,   103,   103,   103,   103,
     104,   104,   104,   105,   105,   106,   106,   106,   107,   108,
     108,   108,   108,   108,   108,   108,   109,   109,   109,   111,
     110,   112,   110,   113,   113,   114,   114,   114,   115,   115,
     115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     3,     1,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     6,     0,     6,     0,     7,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     5,     1,     1,     2,     2,     0,     3,     0,
       4,     1,     2,     1,     1,     1,     2,     3,     1,     3,
       1,     3,     3,     1,     2,     1,     3,     1,     0,     4,
       0,     4,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       1,     0,     4,     0,     5,     1,     3,     2,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     1,     3,     5,     7,     7,     5,     1,
       1,     1,     1,     1,     1,     1,     5,     7,     7,     0,
       3,     0,     4,     1,     2,     1,     1,     1,     2,     2,
       1
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
#line 94 "compiler_hw2.y" /* yacc.c:1646  */
    {/*Par_count, Par*/}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 107 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Kind,"variable");
		Par_count=0;
		Result=insert_symbol();
		if(Result!=0){	//redeclared
			Error=Result;
			strcpy(Error_ID,Variable);
		}
	}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 116 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Kind,"variable");
		Par_count=0;
		Result=insert_symbol();
		if(Result!=0){	//redeclared
			Error=Result;
			strcpy(Error_ID,Variable);
		}
	}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 128 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[0].string));}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 129 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[-2].string));}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 130 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[-2].string));}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 145 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 146 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 147 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 148 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 149 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 153 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Variable, (yyvsp[-3].string));
		strcpy(Kind,"function");
		Par_count=0;
		Function_status=0;	//-1 for not a function, 0 for declare, 1 for define
		Result=insert_symbol();
		if(Result!=0){	//redeclare function
			Error=Result;
			strcpy(Error_ID,Variable);
		}
	}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 164 "compiler_hw2.y" /* yacc.c:1646  */
    {	//the check of the parameter list is belong to the compound_statement grammar
		strcpy(Variable, (yyvsp[-4].string));
		strcpy(Kind,"function");
		strcpy(Type,(yyvsp[-5].string));
		Function_status=0;	//-1 for not a function, 0 for declare, 1 for define
		Result=insert_symbol();
		if(Result!=0){	//redeclare function
			Error=Result;
			strcpy(Error_ID,Variable);
		}
	}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 175 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Variable,(yyvsp[-2].string));
		strcpy(Kind,"function");
		Function_status=1;	//-1 for not a function, 0 for declare, 1 for define
		Result=insert_symbol();
		if(Result!=0){	//redeclare function
			Error=Result;
			strcpy(Error_ID,Variable);
		}
	}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 185 "compiler_hw2.y" /* yacc.c:1646  */
    {
		int temp_count;
		temp_count=Par_count;
		strcpy(Variable,(yyvsp[-3].string));
		strcpy(Kind,"function");
		strcpy(Type,(yyvsp[-4].string));
		Function_status=1;	//-1 for not a function, 0 for declare, 1 for define
		Result=insert_symbol();
		if(Result!=0){	//redeclare function
			Error=Result;
			strcpy(Error_ID,Variable);
		}
		function_flag=1;
		Par_count=temp_count;
	}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 203 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Par[Par_count],Type);
		/*used for the local variable of function later*/
		strcpy(Par_id[Par_count++],(yyvsp[0].string));
	}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 208 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Par[Par_count],Type);
		/*used for the local variable of function later*/
		strcpy(Par_id[Par_count++],(yyvsp[0].string));
	}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 230 "compiler_hw2.y" /* yacc.c:1646  */
    {
		Result=lookup_symbol((yyvsp[0].string));
		if(Result!=0){
			Error=Result;
			strcpy(Error_ID,(yyvsp[0].string));
		}
	}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 252 "compiler_hw2.y" /* yacc.c:1646  */
    {
		create_symbol();
		if(function_flag){
			int i,count;
			count=Par_count;
			for(i=0;i<count;++i){
				strcpy(Variable,Par_id[i]);
				strcpy(Kind,"parameter");
				strcpy(Type,Par[i]);
				Par_count=0;
				Result=insert_symbol();
				if(Result!=0 && Error==0){	//redefine variable
					Error=Result;
					strcpy(Error_ID,Variable);
				}
			}
			function_flag=0;
		}
	}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 270 "compiler_hw2.y" /* yacc.c:1646  */
    {
		dump_flag=1;
	}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 273 "compiler_hw2.y" /* yacc.c:1646  */
    {
		create_symbol();
		if(function_flag){
			int i,count;
			count=Par_count;
			for(i=0;i<count;++i){
				strcpy(Variable,Par_id[i]);
				strcpy(Kind,"parameter");
				strcpy(Type,Par[i]);
				Par_count=0;
				Result=insert_symbol();
				if(Result!=0 && Error==0){	//redefine variable
					Error=Result;
					strcpy(Error_ID,Variable);
				}
			}
			function_flag=0;
		}
	}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 291 "compiler_hw2.y" /* yacc.c:1646  */
    {
		dump_flag=1;
	}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 313 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Kind,"variable");
		Par_count=0;
		Result=insert_symbol();
		if(Result!=0){	//redeclared
			Error=Result;
			strcpy(Error_ID,Variable);
		}
	}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 322 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Kind,"variable");
		Par_count=0;
		Result=insert_symbol();
		if(Result!=0){	//redeclared
			Error=Result;
			strcpy(Error_ID,Variable);
		}
	}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 334 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[0].string));}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 335 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[-2].string));}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 336 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[-2].string));}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 351 "compiler_hw2.y" /* yacc.c:1646  */
    {
		Result=lookup_symbol((yyvsp[-1].string));
		if(Result!=0){	//0 for no error
			Error=Result;
			strcpy(Error_ID,(yyvsp[-1].string));
		}
	}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 358 "compiler_hw2.y" /* yacc.c:1646  */
    {
		Result=lookup_symbol((yyvsp[-1].string));
		if(Result!=0){	//0 for no error
			Error=Result;
			strcpy(Error_ID,(yyvsp[-1].string));
		}
	}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 422 "compiler_hw2.y" /* yacc.c:1646  */
    {
		Result=lookup_symbol((yyvsp[0].string));
		if(Result!=0){
			Error=Result;
			strcpy(Error_ID,(yyvsp[0].string));
		}
	}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 429 "compiler_hw2.y" /* yacc.c:1646  */
    {
		Function_status=2;	//function call
		Result=lookup_symbol((yyvsp[-1].string));
		if(Result!=0){
			Error=Result;
			strcpy(Error_ID,(yyvsp[-1].string));
		}
	}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 437 "compiler_hw2.y" /* yacc.c:1646  */
    {
		Function_status=2;	//function call
		Result=lookup_symbol((yyvsp[-1].string));
		if(Result!=0){
			Error=Result;
			strcpy(Error_ID,(yyvsp[-1].string));
		}
	}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 452 "compiler_hw2.y" /* yacc.c:1646  */
    {
		Result=lookup_symbol((yyvsp[0].string));
		if(Result!=0){
			Error=Result;
			strcpy(Error_ID,(yyvsp[0].string));
		}
	}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 537 "compiler_hw2.y" /* yacc.c:1646  */
    {
		create_symbol();
		/*for function parameter*/
		if(function_flag){
			int i,index;
			for(i=0;i<sym_table[Scope-1][order[Scope-1][index]].par_count;++i){
				strcpy(Variable,Par_id[i]);
				strcpy(Kind,"parameter");
				strcpy(Type,Par[i]);
				Par_count=0;
				Result=insert_symbol();
				if(Result!=0 && Error==0){	//redefine variable
					Error=Result;
					strcpy(Error_ID,Variable);
				}
			}
			function_flag=0;
		}
	}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 555 "compiler_hw2.y" /* yacc.c:1646  */
    {
		dump_flag=1;
	}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 558 "compiler_hw2.y" /* yacc.c:1646  */
    {
		create_symbol();
		/*for function parameter*/
		if(function_flag){
			int i,index;
			for(i=0;i<sym_table[Scope-1][order[Scope-1][index]].par_count;++i){
				strcpy(Variable,Par_id[i]);
				strcpy(Kind,"parameter");
				strcpy(Type,Par[i]);
				Par_count=0;
				Result=insert_symbol();
				if(Result!=0 && Error==0){	//redefine variable
					Error=Result;
					strcpy(Error_ID,Variable);
				}
			}
			function_flag=0;
		}
	}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 576 "compiler_hw2.y" /* yacc.c:1646  */
    {
		dump_flag=1;
	}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2011 "y.tab.c" /* yacc.c:1646  */
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
#line 598 "compiler_hw2.y" /* yacc.c:1906  */

/* C code section */

void Sem_Err()
{
	char *s;
	if(Error==1)
		s="Undeclared variable";
	else if(Error==2)
		s="Undeclared function";
	else if(Error==3)
		s="Redeclared variable";
	else if(Error==4)
		s="Redeclared function";
	else if(Error==5)
		s="Redefined function";
	
	printf("\n|-----------------------------------------------|\n");
	if(buf[strlen(buf)-1]=='\n')
		printf("| Error found in line %d: %s", yylineno, buf);
	else
		printf("| Error found in line %d: %s\n", yylineno, buf);
	printf("| %s %s", s, Error_ID);
	printf("\n|-----------------------------------------------|\n\n");
}

void yyerror(char *s)
{
	char temp[256];
	memset(temp,0,sizeof(temp));
	if(Error!=0){
		printf("%d: %s\n",++yylineno,buf);
		Sem_Err();
	}
	else{
		strncpy(temp,buf,strlen(buf)-1);	//discard the unmatched token
		printf("%d: %s\n",++yylineno,temp);
	}
	printf("\n|-----------------------------------------------|\n");
	printf("| Error found in line %d: %s\n", yylineno, buf);
	printf("| %s", s);
	printf("\n|-----------------------------------------------|\n\n");

	exit(0);
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
		sym_table[Scope][i].function_status=-1;
	}
	Index[Scope]=-1;
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
			if(strcmp(Kind,"function")==0)
				sym_table[Scope][index].function_status=Function_status;
			Function_status=-1;
			Par_count=0;
			order[Scope][Index[Scope]]=index;
			return 0;
		}
		else if(strcmp(sym_table[Scope][index].name,Variable)==0){	//already exists
			Par_count=0;
			if(sym_table[Scope][index].function_status==-1){	//not a function
				return 3;	//redeclared variable
			}
			else if(sym_table[Scope][index].function_status==2){	//already declared and defined
				if(Function_status==0)
					return 4;	//redeclared function
				else if(Function_status==1)
					return 5;	//redefined function
			}
			else if(sym_table[Scope][index].function_status==1 && Function_status==1){
				return 5;	//redefined function
			}
			else if(sym_table[Scope][index].function_status==0 && Function_status==0){
				return 4;	//redeclared function
			}
			else if(sym_table[Scope][index].function_status==0 && Function_status==1){
				sym_table[Scope][index].function_status=2;	//declared and defined
				return 0;
			}
			else if(sym_table[Scope][index].function_status==1 && Function_status==0){
				sym_table[Scope][index].function_status=2;	//declared and defined
				return 0;
			}
		}
	}
}

int lookup_symbol(char *id)
{
	int index,i,scope=Scope;
	for(;scope>=0;--scope){
		for(i=0;i<ENTRY;++i){
			index=hash(id,i);
			if(sym_table[scope][index].index==-1)	//empty entry (not found)
				break;
			else if(strcmp(sym_table[scope][index].name,id)==0)	//already exists
				return 0;	//no error
		}
		if(i==ENTRY){
			printf("symbol table is too small\n");
			exit(-1);
		}
	}
	if(Function_status==2){	//function call
		return 2;	//undeclared function
	}
	else if(Function_status==-1){	//not a function(is a variable)
		return 1;	//undeclared variable (not found in any scope level)
	}
}

void dump_symbol(int index) {
	int i,j,entry;
	if(index>=0){
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
		printf("\n");
	}
	--Scope;
}

void init()
{
	int i,j;
	yylineno = 0;
	Error=0;	//no error
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
	Function_status=-1;
	dump_flag=0;
	function_flag=0;
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

