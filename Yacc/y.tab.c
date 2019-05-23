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
int Function_status;	//-1 for not a function, 0 for declare, 1 for define
int dump_flag,function_flag;
char Variable[30],Type[10],Kind[10],Error_ID[30];
char Par[10][10],Par_id[10][30];
struct SYMBOL_TABLE sym_table[SCOPE][ENTRY];

/* Symbol table function - you can add new function if needed. */
void create_symbol();
int insert_symbol();
int lookup_symbol(char *id);
void dump_symbol(int index);


#line 111 "y.tab.c" /* yacc.c:339  */

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
#line 50 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* string;
    bool boolean;

#line 264 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 281 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   393

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  246

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
       0,    88,    88,    89,    93,    96,    97,   101,   102,   106,
     115,   127,   128,   129,   133,   137,   138,   139,   140,   144,
     145,   146,   147,   148,   152,   163,   174,   174,   184,   184,
     199,   204,   212,   213,   214,   215,   216,   217,   221,   222,
     226,   227,   231,   232,   236,   237,   241,   241,   262,   262,
     285,   286,   290,   291,   292,   296,   297,   301,   310,   322,
     323,   324,   328,   329,   333,   334,   338,   339,   340,   344,
     345,   346,   347,   348,   349,   353,   354,   358,   359,   363,
     364,   365,   369,   370,   371,   372,   373,   377,   378,   379,
     383,   384,   385,   386,   390,   391,   392,   398,   399,   400,
     401,   402,   403,   404,   408,   409,   413,   414,   418,   419,
     423,   424,   425,   429,   430,   431,   432,   433,   437,   438,
     439,   443,   444,   445,   446,   450,   451,   452,   456,   457,
     461,   462,   463,   467,   471,   472,   473,   474,   475,   476,
     477,   481,   482,   483,   487,   487,   507,   507,   530,   531,
     535,   536,   537,   541,   542,   543
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
  "$@3", "$@4", "block_item_list", "block_item", "local_declaration",
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
  "loop_statement", "loop_selection_statement", "loop_compound_statement",
  "$@5", "$@6", "loop_block_item_list", "loop_block_item",
  "loop_jump_statement", YY_NULLPTR
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

#define YYPACT_NINF -207

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-207)))

#define YYTABLE_NINF -145

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     123,  -207,  -207,  -207,  -207,  -207,  -207,  -207,    19,  -207,
    -207,   -30,  -207,  -207,  -207,  -207,  -207,    -1,    31,  -207,
     327,    90,    18,  -207,    71,    71,    71,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,    29,    87,    62,   178,   119,   354,
    -207,  -207,    84,    98,   130,   154,  -207,  -207,  -207,   134,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,  -207,   159,  -207,   155,   256,  -207,    87,
      62,   178,   178,   119,   119,   119,   119,   354,   354,  -207,
    -207,  -207,   186,  -207,  -207,   159,   169,   205,   222,  -207,
    -207,  -207,   273,   273,   279,   223,   239,   259,    85,  -207,
     337,  -207,   101,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
     191,  -207,  -207,  -207,    77,  -207,   264,   270,   152,   324,
     175,   367,  -207,  -207,   213,  -207,  -207,   128,  -207,  -207,
     189,    47,     5,   279,   279,  -207,  -207,   257,  -207,  -207,
    -207,  -207,  -207,   253,   279,  -207,     4,   103,  -207,  -207,
    -207,   279,  -207,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,  -207,  -207,  -207,  -207,
     269,   274,   219,   220,  -207,  -207,   254,  -207,   285,   263,
    -207,  -207,   270,   152,   324,   324,   175,   175,   175,   175,
     367,   367,  -207,  -207,  -207,   265,   268,   159,   291,  -207,
     299,   299,   285,  -207,  -207,  -207,   316,  -207,  -207,  -207,
     304,   313,  -207,    -5,   347,   160,  -207,  -207,  -207,   319,
     329,   330,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,    54,  -207,  -207,   279,  -207,  -207,  -207,  -207,
     255,   291,   344,   132,  -207,  -207
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    42,    43,    19,    20,    21,    22,    23,     0,     2,
       5,     0,     4,     6,     1,     3,     7,    11,     0,     9,
       0,     0,     0,     8,     0,     0,     0,    17,    18,    13,
      15,    16,    12,   128,    14,   106,   108,   110,   113,   118,
     121,   125,    26,     0,     0,    11,    10,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,    30,    28,     0,   129,   107,
     109,   111,   112,   114,   115,   116,   117,   119,   120,   122,
     123,   124,    48,    27,    25,     0,     0,     0,     0,    29,
      31,    47,     0,     0,     0,     0,     0,     0,     0,    62,
      97,   100,     0,    54,    52,    33,    39,    36,    37,    32,
       0,    50,    53,    38,     0,    64,    66,    75,    77,    79,
      82,    87,    90,    94,     0,    34,    35,    97,    95,    96,
       0,     0,     0,     0,     0,    44,    45,    69,    70,    71,
      72,    73,    74,     0,     0,    55,    59,     0,    57,    49,
      51,     0,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   101,   105,
       0,     0,     0,     0,    68,    98,     0,    67,     0,     0,
      56,    65,    76,    78,    80,    81,    83,    84,    85,    86,
      88,    89,    91,    92,    93,     0,     0,     0,     0,    99,
       0,     0,     0,    61,   100,    60,    59,    58,    41,    40,
     130,   146,   133,     0,     0,     0,   132,   131,   145,     0,
       0,     0,   152,   138,   139,   155,   151,   135,   137,   150,
     136,   134,     0,   148,   140,     0,   153,   154,   147,   149,
       0,     0,   141,     0,   142,   143
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,   371,  -207,  -207,   358,   203,   -20,    46,   -85,
    -207,  -207,  -207,  -207,   284,  -206,   -61,  -152,   -62,  -207,
    -207,  -207,   275,   -88,  -207,   204,   -77,   -83,  -130,  -207,
    -207,   231,   233,    74,   206,    91,   -80,  -207,   -84,   -25,
     336,   338,   208,   294,   232,   -17,  -207,   177,   -70,  -207,
     145,  -182,  -207,  -207,  -207,   161,  -207
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    18,    19,    32,   101,   102,    12,
      64,    85,    44,   104,   105,   106,    13,   108,   109,    87,
      88,   110,   111,   112,   147,   148,   113,   114,   115,   144,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    34,
      35,    36,    37,    38,    39,    40,    41,   125,   126,   229,
     230,   231,   214,   215,   232,   233,   234
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,    49,    83,   103,    33,    33,    33,    47,    48,   223,
     131,   130,   128,   129,   177,    20,   212,    16,    17,    14,
     178,   181,    82,    89,    21,   103,   223,   107,    96,    21,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    79,    80,    81,    11,   170,   205,   107,
     172,   173,    50,   171,    11,   166,   167,    92,    93,   242,
     176,   245,    22,   225,     1,     2,    45,    43,     3,     4,
       5,     6,     7,   169,    24,    25,    52,    53,    23,    94,
     225,   211,   238,   192,   193,   194,    95,   219,    92,    93,
      97,    98,   220,   221,    27,    28,    26,    30,    31,     1,
       2,    99,   100,     3,     4,     5,     6,     7,   151,    51,
      94,    27,    28,    86,    30,    31,    42,    95,   131,   130,
     128,   129,    58,    59,   152,    27,    28,   226,    30,    31,
     222,    63,   135,   100,   179,   210,  -104,  -104,   227,     3,
       4,     5,     6,     7,   226,   228,    65,   222,   145,   146,
     180,   216,   240,   143,   224,   227,    66,    50,   204,   211,
      68,    67,   228,    92,    93,   219,   155,   156,     1,     2,
      20,   224,     3,     4,     5,     6,     7,    49,   161,   162,
     204,   204,   204,    47,    48,    94,    82,   211,    54,    55,
      56,    57,    95,   219,    92,    93,    97,    98,   220,   221,
      27,    28,    84,    30,    31,     1,     2,    99,   100,     3,
       4,     5,     6,     7,   -46,   168,    94,    90,    82,   149,
     151,   166,   167,    95,    96,    92,    93,    97,    98,   184,
     185,    27,    28,    91,    30,    31,     1,     2,    99,   100,
       3,     4,     5,     6,     7,   197,   198,    94,   132,    82,
     151,   151,   190,   191,    95,    96,    92,    93,    97,    98,
      71,    72,    27,    28,   133,    30,    31,     1,     2,    99,
     100,     3,     4,     5,     6,     7,    92,    93,    94,   175,
     199,   241,    92,    93,   134,   151,   151,   153,   200,   201,
      77,    78,   154,    27,    28,   195,    30,    31,    94,   174,
     196,   100,   200,   201,    94,     3,     4,     5,     6,     7,
     202,   206,   208,    27,    28,   209,    30,    31,   211,    27,
      28,   127,    30,    31,   202,    27,    28,   100,    30,    31,
      24,    25,   178,   100,   157,   158,   159,   160,   213,    27,
      28,  -144,    30,    31,   235,  -104,  -104,   127,    73,    74,
      75,    76,    26,   137,   138,   139,   140,   141,   142,    60,
      61,    62,   143,   186,   187,   188,   189,    27,    28,    29,
      30,    31,   163,   164,   165,   218,   236,   237,   243,    15,
      46,   203,   136,   207,   182,   150,    69,   183,   244,    70,
     217,     0,     0,   239
};

static const yytype_int16 yycheck[] =
{
      20,    26,    64,    88,    24,    25,    26,    24,    25,   215,
      94,    94,    92,    93,   144,    16,   198,    47,    48,     0,
      16,   151,    27,    85,    25,   110,   232,    88,    33,    25,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    60,    61,    62,     0,    42,   178,   110,
     133,   134,    23,    48,     8,     8,     9,     3,     4,   241,
     143,   243,    31,   215,    45,    46,    48,    21,    49,    50,
      51,    52,    53,    26,     3,     4,    14,    15,    47,    25,
     232,    27,    28,   163,   164,   165,    32,    33,     3,     4,
      36,    37,    38,    39,    40,    41,    25,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    31,    22,
      25,    40,    41,    67,    43,    44,    26,    32,   202,   202,
     200,   201,     3,     4,    47,    40,    41,   215,    43,    44,
     215,    47,    47,    48,    31,   197,     8,     9,   215,    49,
      50,    51,    52,    53,   232,   215,    48,   232,    47,    48,
      47,   213,   235,    25,   215,   232,    26,    23,   178,    27,
      26,    31,   232,     3,     4,    33,    14,    15,    45,    46,
      16,   232,    49,    50,    51,    52,    53,   202,     3,     4,
     200,   201,   202,   200,   201,    25,    27,    27,    10,    11,
      12,    13,    32,    33,     3,     4,    36,    37,    38,    39,
      40,    41,    47,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    28,    26,    25,    48,    27,    28,
      31,     8,     9,    32,    33,     3,     4,    36,    37,   155,
     156,    40,    41,    28,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    26,    26,    25,    25,    27,
      31,    31,   161,   162,    32,    33,     3,     4,    36,    37,
      52,    53,    40,    41,    25,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     3,     4,    25,    26,
      26,    26,     3,     4,    25,    31,    31,    23,     3,     4,
      58,    59,    22,    40,    41,    26,    43,    44,    25,    42,
      26,    48,     3,     4,    25,    49,    50,    51,    52,    53,
      25,    48,    47,    40,    41,    47,    43,    44,    27,    40,
      41,    48,    43,    44,    25,    40,    41,    48,    43,    44,
       3,     4,    16,    48,    10,    11,    12,    13,    34,    40,
      41,    28,    43,    44,    25,     8,     9,    48,    54,    55,
      56,    57,    25,    16,    17,    18,    19,    20,    21,     5,
       6,     7,    25,   157,   158,   159,   160,    40,    41,    42,
      43,    44,     5,     6,     7,    28,    47,    47,    34,     8,
      22,   178,    98,   179,   153,   110,    50,   154,   243,    51,
     213,    -1,    -1,   232
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,    49,    50,    51,    52,    53,    55,    56,
      57,    62,    63,    70,     0,    56,    47,    48,    58,    59,
      16,    25,    31,    47,     3,     4,    25,    40,    41,    42,
      43,    44,    60,    61,    93,    94,    95,    96,    97,    98,
      99,   100,    26,    62,    66,    48,    59,    99,    99,    93,
      23,    22,    14,    15,    10,    11,    12,    13,     3,     4,
       5,     6,     7,    47,    64,    48,    26,    31,    26,    94,
      95,    96,    96,    97,    97,    97,    97,    98,    98,    99,
      99,    99,    27,    72,    47,    65,    62,    73,    74,    72,
      48,    28,     3,     4,    25,    32,    33,    36,    37,    47,
      48,    61,    62,    63,    67,    68,    69,    70,    71,    72,
      75,    76,    77,    80,    81,    82,    84,    85,    86,    87,
      88,    89,    90,    91,    92,   101,   102,    48,    90,    90,
      81,    92,    25,    25,    25,    47,    68,    16,    17,    18,
      19,    20,    21,    25,    83,    47,    48,    78,    79,    28,
      76,    31,    47,    23,    22,    14,    15,    10,    11,    12,
      13,     3,     4,     5,     6,     7,     8,     9,    26,    26,
      42,    48,    81,    81,    42,    26,    81,    82,    16,    31,
      47,    82,    85,    86,    87,    87,    88,    88,    88,    88,
      89,    89,    90,    90,    90,    26,    26,    26,    26,    26,
       3,     4,    25,    60,    61,    82,    48,    79,    47,    47,
      72,    27,   105,    34,   106,   107,    72,   101,    28,    33,
      38,    39,    63,    69,    70,    71,    77,    80,   102,   103,
     104,   105,   108,   109,   110,    25,    47,    47,    28,   109,
      81,    26,   105,    34,   104,   105
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    57,    57,    58,
      58,    59,    59,    59,    60,    61,    61,    61,    61,    62,
      62,    62,    62,    62,    63,    63,    64,    63,    65,    63,
      66,    66,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    73,    72,    74,    72,
      75,    75,    76,    76,    76,    77,    77,    78,    78,    79,
      79,    79,    80,    80,    81,    81,    82,    82,    82,    83,
      83,    83,    83,    83,    83,    84,    84,    85,    85,    86,
      86,    86,    87,    87,    87,    87,    87,    88,    88,    88,
      89,    89,    89,    89,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    95,    96,    96,    96,    96,    96,    97,    97,
      97,    98,    98,    98,    98,    99,    99,    99,   100,   100,
     101,   101,   101,   102,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   104,   106,   105,   107,   105,   108,   108,
     109,   109,   109,   110,   110,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     3,     1,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     6,     0,     6,     0,     7,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     1,     1,     2,     2,     0,     3,     0,     4,
       1,     2,     1,     1,     1,     2,     3,     1,     3,     1,
       3,     3,     1,     2,     1,     3,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     1,     3,     4,
       1,     3,     2,     2,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     1,     3,
       5,     7,     7,     5,     1,     1,     1,     1,     1,     1,
       1,     5,     7,     7,     0,     3,     0,     4,     1,     2,
       1,     1,     1,     2,     2,     1
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
#line 93 "compiler_hw2.y" /* yacc.c:1646  */
    {/*Par_count, Par*/}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 106 "compiler_hw2.y" /* yacc.c:1646  */
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
#line 115 "compiler_hw2.y" /* yacc.c:1646  */
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
#line 127 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[0].string));}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 128 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[-2].string));}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 129 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[-2].string));}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 144 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 145 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 146 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 147 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 148 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Type,(yyvsp[0].string)); (yyval.string)=(yyvsp[0].string);}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 152 "compiler_hw2.y" /* yacc.c:1646  */
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
#line 163 "compiler_hw2.y" /* yacc.c:1646  */
    {
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
#line 174 "compiler_hw2.y" /* yacc.c:1646  */
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
#line 184 "compiler_hw2.y" /* yacc.c:1646  */
    {
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
	}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 199 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Par[Par_count],Type);
		/*used for the local variable of function later*/
		strcpy(Par_id[Par_count++],(yyvsp[0].string));
	}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 204 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Par[Par_count],Type);
		/*used for the local variable of function later*/
		strcpy(Par_id[Par_count++],(yyvsp[0].string));
	}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 241 "compiler_hw2.y" /* yacc.c:1646  */
    {
		create_symbol();
		/*for function parameter*/
		if(function_flag){
			int i;
			for(i=0;i<sym_table[Scope-1][order[Scope-1][Index[Scope-1]]].par_count;++i){
				strcpy(Variable,Par_id[i]);
				strcpy(Kind,"parameter");
				strcpy(Type,Par[i]);
				Par_count=0;
				Result=insert_symbol();
				if(Result!=0 && Error==-1){	//redefine variable
					Error=Result;
					strcpy(Error_ID,Variable);
				}
			}
			function_flag=0;
		}
	}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 259 "compiler_hw2.y" /* yacc.c:1646  */
    {
		dump_flag=1;
	}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 262 "compiler_hw2.y" /* yacc.c:1646  */
    {
		create_symbol();
		if(function_flag){
			int i;
			for(i=0;i<sym_table[Scope-1][order[Scope-1][Index[Scope-1]]].par_count;++i){
				strcpy(Variable,Par_id[i]);
				strcpy(Kind,"parameter");
				strcpy(Type,Par[i]);
				Par_count=0;
				Result=insert_symbol();
				if(Result!=0 && Error==-1){	//redefine variable
					Error=Result;
					strcpy(Error_ID,Variable);
				}
			}
			function_flag=0;
		}
	}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 279 "compiler_hw2.y" /* yacc.c:1646  */
    {
		dump_flag=1;
	}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 301 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Kind,"variable");
		Par_count=0;
		Result=insert_symbol();
		if(Result!=0){	//redeclared
			Error=Result;
			strcpy(Error_ID,Variable);
		}
	}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 310 "compiler_hw2.y" /* yacc.c:1646  */
    {
		strcpy(Kind,"variable");
		Par_count=0;
		Result=insert_symbol();
		if(Result!=0){	//redeclared
			Error=Result;
			strcpy(Error_ID,Variable);
		}
	}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 322 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[0].string));}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 323 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[-2].string));}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 324 "compiler_hw2.y" /* yacc.c:1646  */
    {strcpy(Variable,(yyvsp[-2].string));}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 487 "compiler_hw2.y" /* yacc.c:1646  */
    {
		create_symbol();
		if(function_flag){
			int i;
			for(i=0;i<sym_table[Scope-1][order[Scope-1][Index[Scope-1]]].par_count;++i){
				strcpy(Variable,Par_id[i]);
				strcpy(Kind,"parameter");
				strcpy(Type,Par[i]);
				Par_count=0;
				Result=insert_symbol();
				if(Result!=0 && Error==-1){	//redefine variable
					Error=Result;
					strcpy(Error_ID,Variable);
				}
			}
			function_flag=0;
		}
	}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 504 "compiler_hw2.y" /* yacc.c:1646  */
    {
		dump_flag=1;
	}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 507 "compiler_hw2.y" /* yacc.c:1646  */
    {
		create_symbol();
		if(function_flag){
			int i;
			for(i=0;i<sym_table[Scope-1][order[Scope-1][Index[Scope-1]]].par_count;++i){
				strcpy(Variable,Par_id[i]);
				strcpy(Kind,"parameter");
				strcpy(Type,Par[i]);
				Par_count=0;
				Result=insert_symbol();
				if(Result!=0 && Error==-1){	//redefine variable
					Error=Result;
					strcpy(Error_ID,Variable);
				}
			}
			function_flag=0;
		}
	}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 524 "compiler_hw2.y" /* yacc.c:1646  */
    {
		dump_flag=1;
	}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1919 "y.tab.c" /* yacc.c:1646  */
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
#line 546 "compiler_hw2.y" /* yacc.c:1906  */

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
				return 4;	//redeclared function(don't care redefined in this version)
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

