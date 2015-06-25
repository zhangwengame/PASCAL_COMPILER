/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "tiny.y" /* yacc.c:339  */

#define YYPARSER
#include "global.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#define YYSTYPE TreeNode *
static char * savedName;
static int savedLineNo;
static TreeNode* savedTree;
static int savedNum;
static int level=0;
static int yylex(){
    return getToken();
}

#line 83 "y.tab.c" /* yacc.c:339  */

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
    TOKEN_PROGRAM = 258,
    TOKEN_FUNCTION = 259,
    TOKEN_PROCEDURE = 260,
    TOKEN_CONST = 261,
    TOKEN_TYPE = 262,
    TOKEN_VAR = 263,
    TOKEN_IF = 264,
    TOKEN_THEN = 265,
    TOKEN_ELSE = 266,
    TOKEN_REPEAT = 267,
    TOKEN_UNTIL = 268,
    TOKEN_WHILE = 269,
    TOKEN_DO = 270,
    TOKEN_CASE = 271,
    TOKEN_TO = 272,
    TOKEN_DOWNTO = 273,
    TOKEN_FOR = 274,
    TOKEN_EQUAL = 275,
    TOKEN_UNEQUAL = 276,
    TOKEN_GE = 277,
    TOKEN_GT = 278,
    TOKEN_LE = 279,
    TOKEN_LT = 280,
    TOKEN_ASSIGN = 281,
    TOKEN_PLUS = 282,
    TOKEN_MINUS = 283,
    TOKEN_MUL = 284,
    TOKEN_DIV = 285,
    TOKEN_OR = 286,
    TOKEN_AND = 287,
    TOKEN_NOT = 288,
    TOKEN_MOD = 289,
    TOKEN_READ = 290,
    TOKEN_WRITE = 291,
    TOKEN_WRITELN = 292,
    TOKEN_LB = 293,
    TOKEN_RB = 294,
    TOKEN_SEMI = 295,
    TOKEN_DOT = 296,
    TOKEN_DOTDOT = 297,
    TOKEN_LP = 298,
    TOKEN_RP = 299,
    TOKEN_COMMA = 300,
    TOKEN_COLON = 301,
    TOKEN_INTEGER_TYPE = 302,
    TOKEN_BOOLEAN_TYPE = 303,
    TOKEN_CHAR_TYPE = 304,
    TOKEN_REAL_TYPE = 305,
    TOKEN_TRUE = 306,
    TOKEN_FALSE = 307,
    TOKEN_MAXINT = 308,
    TOKEN_ARRAY = 309,
    TOKEN_OF = 310,
    TOKEN_RECORD = 311,
    TOKEN_BEGIN = 312,
    TOKEN_END = 313,
    TOKEN_GOTO = 314,
    TOKEN_ID = 315,
    TOKEN_INT = 316,
    TOKEN_REAL = 317,
    TOKEN_CHAR = 318,
    TOKEN_STRING = 319,
    ERROR = 320,
    TOKEN_ABS = 321,
    TOKEN_CHR = 322,
    TOKEN_ODD = 323,
    TOKEN_ORD = 324,
    TOKEN_PRED = 325,
    TOKEN_SQR = 326,
    TOKEN_SQRT = 327,
    TOKEN_SUCC = 328
  };
#endif
/* Tokens.  */
#define TOKEN_PROGRAM 258
#define TOKEN_FUNCTION 259
#define TOKEN_PROCEDURE 260
#define TOKEN_CONST 261
#define TOKEN_TYPE 262
#define TOKEN_VAR 263
#define TOKEN_IF 264
#define TOKEN_THEN 265
#define TOKEN_ELSE 266
#define TOKEN_REPEAT 267
#define TOKEN_UNTIL 268
#define TOKEN_WHILE 269
#define TOKEN_DO 270
#define TOKEN_CASE 271
#define TOKEN_TO 272
#define TOKEN_DOWNTO 273
#define TOKEN_FOR 274
#define TOKEN_EQUAL 275
#define TOKEN_UNEQUAL 276
#define TOKEN_GE 277
#define TOKEN_GT 278
#define TOKEN_LE 279
#define TOKEN_LT 280
#define TOKEN_ASSIGN 281
#define TOKEN_PLUS 282
#define TOKEN_MINUS 283
#define TOKEN_MUL 284
#define TOKEN_DIV 285
#define TOKEN_OR 286
#define TOKEN_AND 287
#define TOKEN_NOT 288
#define TOKEN_MOD 289
#define TOKEN_READ 290
#define TOKEN_WRITE 291
#define TOKEN_WRITELN 292
#define TOKEN_LB 293
#define TOKEN_RB 294
#define TOKEN_SEMI 295
#define TOKEN_DOT 296
#define TOKEN_DOTDOT 297
#define TOKEN_LP 298
#define TOKEN_RP 299
#define TOKEN_COMMA 300
#define TOKEN_COLON 301
#define TOKEN_INTEGER_TYPE 302
#define TOKEN_BOOLEAN_TYPE 303
#define TOKEN_CHAR_TYPE 304
#define TOKEN_REAL_TYPE 305
#define TOKEN_TRUE 306
#define TOKEN_FALSE 307
#define TOKEN_MAXINT 308
#define TOKEN_ARRAY 309
#define TOKEN_OF 310
#define TOKEN_RECORD 311
#define TOKEN_BEGIN 312
#define TOKEN_END 313
#define TOKEN_GOTO 314
#define TOKEN_ID 315
#define TOKEN_INT 316
#define TOKEN_REAL 317
#define TOKEN_CHAR 318
#define TOKEN_STRING 319
#define ERROR 320
#define TOKEN_ABS 321
#define TOKEN_CHR 322
#define TOKEN_ODD 323
#define TOKEN_ORD 324
#define TOKEN_PRED 325
#define TOKEN_SQR 326
#define TOKEN_SQRT 327
#define TOKEN_SUCC 328

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 280 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   497

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  294

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    30,    30,    29,    36,    41,    50,    51,    62,    73,
      74,    76,    84,    83,    94,    95,    98,   109,   112,   118,
     125,   133,   132,   141,   142,   145,   156,   158,   165,   166,
     169,   182,   185,   194,   200,   206,   212,   220,   226,   232,
     240,   241,   244,   256,   259,   265,   266,   267,   269,   272,
     284,   286,   293,   301,   307,   312,   318,   326,   334,   341,
     345,   349,   353,   358,   370,   372,   376,   377,   379,   380,
     394,   393,   401,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   419,   427,   435,   440,   447,   448,   450,
     456,   457,   462,   467,   478,   479,   485,   491,   500,   509,
     513,   518,   524,   529,   533,   538,   549,   551,   552,   553,
     554,   555,   556,   557,   559,   560,   561,   562,   564,   565,
     566,   567,   568,   570,   572,   577,   578,   579,   582,   585,
     590,   595,   598,   601,   604,   607,   610,   613,   616
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_PROGRAM", "TOKEN_FUNCTION",
  "TOKEN_PROCEDURE", "TOKEN_CONST", "TOKEN_TYPE", "TOKEN_VAR", "TOKEN_IF",
  "TOKEN_THEN", "TOKEN_ELSE", "TOKEN_REPEAT", "TOKEN_UNTIL", "TOKEN_WHILE",
  "TOKEN_DO", "TOKEN_CASE", "TOKEN_TO", "TOKEN_DOWNTO", "TOKEN_FOR",
  "TOKEN_EQUAL", "TOKEN_UNEQUAL", "TOKEN_GE", "TOKEN_GT", "TOKEN_LE",
  "TOKEN_LT", "TOKEN_ASSIGN", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MUL",
  "TOKEN_DIV", "TOKEN_OR", "TOKEN_AND", "TOKEN_NOT", "TOKEN_MOD",
  "TOKEN_READ", "TOKEN_WRITE", "TOKEN_WRITELN", "TOKEN_LB", "TOKEN_RB",
  "TOKEN_SEMI", "TOKEN_DOT", "TOKEN_DOTDOT", "TOKEN_LP", "TOKEN_RP",
  "TOKEN_COMMA", "TOKEN_COLON", "TOKEN_INTEGER_TYPE", "TOKEN_BOOLEAN_TYPE",
  "TOKEN_CHAR_TYPE", "TOKEN_REAL_TYPE", "TOKEN_TRUE", "TOKEN_FALSE",
  "TOKEN_MAXINT", "TOKEN_ARRAY", "TOKEN_OF", "TOKEN_RECORD", "TOKEN_BEGIN",
  "TOKEN_END", "TOKEN_GOTO", "TOKEN_ID", "TOKEN_INT", "TOKEN_REAL",
  "TOKEN_CHAR", "TOKEN_STRING", "ERROR", "TOKEN_ABS", "TOKEN_CHR",
  "TOKEN_ODD", "TOKEN_ORD", "TOKEN_PRED", "TOKEN_SQR", "TOKEN_SQRT",
  "TOKEN_SUCC", "$accept", "program", "$@1", "routine", "routine_head",
  "routine_part", "function_decl", "function_head", "$@2", "parameters",
  "para_decl_list", "para_type_list", "procedure_decl", "procedure_head",
  "$@3", "var_part", "var_decl_list", "var_decl", "const_part",
  "const_expr_list", "const_expr", "const_value", "type_part",
  "type_decl_list", "type_definition", "type_decl", "record_type_decl",
  "field_decl_list", "field_decl", "array_type_decl", "simple_type_decl",
  "name_list", "ID", "routine_body", "compound_stmt", "stmt_list", "stmt",
  "$@4", "no_label_stmt", "assign_stmt", "goto_stmt", "if_stmt",
  "else_clause", "repeat_stmt", "while_stmt", "case_stmt",
  "case_expr_list", "case_expr", "for_stmt", "proc_stmt", "args_list",
  "expression", "expr", "term", "factor", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328
};
# endif

#define YYPACT_NINF -165

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-165)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,   -39,    27,  -165,  -165,   -15,    30,   -22,     2,     0,
      60,  -165,   -22,  -165,    67,  -165,  -165,  -165,  -165,   -22,
      86,  -165,   385,    14,   -22,  -165,    82,   -22,    42,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,    57,   279,  -165,   279,
     279,   -22,    69,    75,    94,  -165,    49,  -165,    55,  -165,
      89,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,   310,   -22,  -165,    24,  -165,    74,    99,    42,  -165,
     116,  -165,   123,  -165,   279,   279,   279,   128,   131,   139,
     143,   159,   160,   161,   162,  -165,   -19,   392,    25,    77,
    -165,   179,   435,   156,    90,   279,   279,   279,  -165,   148,
     279,   279,   -22,   279,  -165,   385,   -22,  -165,  -165,  -165,
    -165,   168,   -22,   166,   169,  -165,  -165,  -165,   171,  -165,
     -22,   310,  -165,  -165,  -165,  -165,    30,    30,  -165,  -165,
     208,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     -22,   279,   268,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   268,   381,   279,
     174,    32,   383,    34,    23,   383,   294,   184,    41,   182,
      56,   337,   -45,  -165,    76,   385,  -165,   -22,  -165,   181,
     183,   183,   185,   194,  -165,    81,    83,    87,    96,   102,
     104,   122,   124,   371,  -165,   140,   224,    25,    25,    25,
      25,    25,    25,    77,    77,    77,  -165,  -165,  -165,  -165,
     383,  -165,   191,   195,   367,  -165,   466,  -165,  -165,   279,
    -165,  -165,   217,   279,  -165,    91,  -165,   207,  -165,  -165,
     310,  -165,  -165,  -165,     6,   202,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,   268,
    -165,   268,   268,  -165,  -165,   279,   279,   383,   279,   383,
     385,  -165,   196,   209,   -22,     1,  -165,   144,   337,  -165,
     210,   213,   446,   457,   383,  -165,   310,  -165,   151,     6,
    -165,   337,  -165,  -165,  -165,   268,   268,  -165,   337,  -165,
    -165,  -165,  -165,  -165
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,    28,     0,     0,     0,
      40,    65,    29,    31,     0,     3,    68,     4,    66,     0,
      23,    30,     0,    90,    41,    43,     0,     0,     6,    37,
      38,    39,    33,    34,    35,    36,     0,     0,    68,     0,
       0,     0,     0,     0,   103,    67,     0,    70,    99,    74,
       0,    72,    73,    75,    76,    77,    78,    79,    80,    81,
      42,     0,    24,    26,     0,    64,     0,     0,     5,     9,
       0,    10,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,   123,     0,   113,   117,
     122,    90,     0,     0,     0,     0,     0,     0,    85,     0,
       0,     0,     0,     0,    69,     0,     0,    59,    60,    62,
      61,     0,     0,     0,     0,    47,    46,    45,    53,    25,
       0,     0,    12,    21,     7,     8,    28,    28,   128,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,     0,   106,     0,    90,    82,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,    44,     0,    63,     0,
      14,    14,     0,     0,   126,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,     0,    87,   111,   112,   107,
     108,   109,   110,   114,   115,   116,   118,   119,   121,   120,
      89,    91,     0,     0,     0,    94,     0,   101,   102,     0,
     104,    71,     0,     0,   100,     0,    54,     0,    48,    49,
       0,    55,    58,    27,     0,     0,    22,    11,    20,   131,
     132,   133,   134,   135,   136,   137,   138,   129,   124,    90,
      86,    90,    90,    92,    93,     0,     0,   105,     0,    84,
       0,    56,     0,     0,     0,     0,    17,     0,     0,    88,
       0,     0,     0,     0,    83,    57,     0,    51,     0,     0,
      15,     0,    13,    95,    96,    90,    90,    52,     0,    16,
      19,    97,    98,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -165,  -165,  -165,    73,  -165,  -165,   188,  -165,  -165,    78,
    -165,   -21,   197,  -165,  -165,  -165,  -165,   200,  -165,  -165,
     252,   -13,  -165,  -165,   242,  -115,  -165,  -165,    95,  -165,
    -164,  -104,    -7,  -165,   261,   233,  -113,  -165,   109,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,    62,  -165,  -165,
     157,   -36,   349,   -88,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     8,     9,    68,    69,    70,   180,   235,
     265,   266,    71,    72,   181,    28,    62,    63,    10,    12,
      13,    85,    20,    24,    25,   114,   115,   172,   173,   116,
     117,    64,    86,    17,    49,    23,    50,    99,    51,    52,
      53,    54,   250,    55,    56,    57,   214,   215,    58,    59,
     161,   162,    88,    89,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      14,    87,   170,    92,    93,    14,   179,   227,   174,    36,
     128,   129,    26,   228,   264,    11,    48,    26,     1,   139,
      65,     3,   140,    37,   141,     6,    38,     4,    39,   196,
      40,   160,    37,    41,    94,    38,     7,    39,    11,    40,
     130,   279,    41,    15,   211,   280,    66,    67,   113,    42,
      43,    44,   149,   150,   118,    65,   151,    16,    42,    43,
      44,   203,   204,   205,   165,   166,    11,    19,   174,   120,
     121,    16,    45,    46,    11,    47,   218,   219,   220,   219,
      16,   100,    46,    11,    48,   224,   219,    22,   206,   207,
     208,   209,   169,   101,    27,   167,   102,    73,   103,    65,
     226,   120,    61,   193,   282,    65,   152,   153,   113,   154,
      98,   155,    95,   178,   118,   263,   159,   290,    96,   260,
     210,   120,   230,   216,   293,   239,   219,   240,   219,   104,
     267,   241,   219,   194,   122,    48,   269,    97,   270,   271,
     242,   219,    29,    30,    31,   212,   243,   219,   244,   219,
      48,   213,    32,    33,    34,    35,   126,    48,   113,   123,
     278,   287,   231,   127,   118,    65,   245,   219,   246,   219,
     232,   131,   291,   292,   132,   267,   143,   144,   145,   146,
     147,   148,   133,   257,   248,   219,   134,   259,    37,   120,
     281,    38,   156,    39,   164,    40,   120,   288,    41,   182,
     183,   212,   135,   136,   137,   138,   171,   213,   175,   176,
     223,   158,   261,   177,    42,    43,    44,   113,   217,   272,
     273,   233,   274,   118,   225,   237,   234,    65,   143,   144,
     145,   146,   147,   148,   238,   249,    16,   251,    46,    11,
      47,   252,    48,   258,    48,    48,   262,   275,   268,   277,
     283,   276,   184,   284,   163,   113,   124,    65,   289,   236,
     168,   118,   119,   113,    21,   125,    60,   229,   113,   118,
      18,    91,    65,   221,   118,   113,   254,    37,    48,    48,
      38,   118,    39,     0,    40,     0,     0,    41,   185,   186,
     187,   188,   189,   190,   191,   192,     0,     0,   195,     0,
       0,     0,     0,    42,    43,    44,     0,    74,     0,     0,
       0,     0,    75,     0,   143,   144,   145,   146,   147,   148,
       0,     0,    76,     0,     0,    16,     0,    46,    11,    47,
      29,    30,    31,   222,     0,     0,     0,     0,   105,    11,
      32,    33,    34,    35,     0,    77,    78,    79,    80,    81,
      82,    83,    84,   106,     0,     0,     0,   107,   108,   109,
     110,    29,    30,    31,   111,   105,   112,     0,     0,     0,
      11,    32,    33,    34,    35,     0,     0,     0,     0,     0,
     106,     0,     0,     0,   107,   108,   109,   110,    29,    30,
      31,   143,   144,   145,   146,   147,   148,    11,    32,    33,
      34,    35,   142,   143,   144,   145,   146,   147,   148,     0,
     247,     0,   143,   144,   145,   146,   147,   148,    29,    30,
      31,     0,     0,     0,     0,   253,     0,    11,    32,    33,
      34,    35,    29,    30,    31,     0,    29,    30,    31,     0,
       0,    11,    32,    33,    34,    35,    32,    33,    34,    35,
     157,     0,     0,     0,     0,   143,   144,   145,   146,   147,
     148,   285,     0,     0,     0,     0,   143,   144,   145,   146,
     147,   148,   286,     0,     0,     0,     0,   143,   144,   145,
     146,   147,   148,   255,   256,     0,   143,   144,   145,   146,
     147,   148,   197,   198,   199,   200,   201,   202
};

static const yytype_int16 yycheck[] =
{
       7,    37,   106,    39,    40,    12,   121,   171,   112,    22,
      74,    75,    19,    58,     8,    60,    23,    24,     3,    38,
      27,    60,    41,     9,    43,    40,    12,     0,    14,   142,
      16,    95,     9,    19,    41,    12,     6,    14,    60,    16,
      76,    40,    19,    41,   157,    44,     4,     5,    61,    35,
      36,    37,    27,    28,    61,    62,    31,    57,    35,    36,
      37,   149,   150,   151,   100,   101,    60,     7,   172,    45,
      46,    57,    58,    59,    60,    61,    44,    45,    44,    45,
      57,    26,    59,    60,    91,    44,    45,    20,   152,   153,
     154,   155,   105,    38,     8,   102,    41,    40,    43,   106,
      44,    45,    20,   139,   268,   112,    29,    30,   121,    32,
      61,    34,    43,   120,   121,   230,    26,   281,    43,    28,
     156,    45,    46,   159,   288,    44,    45,    44,    45,    40,
     234,    44,    45,   140,    60,   142,   249,    43,   251,   252,
      44,    45,    51,    52,    53,   158,    44,    45,    44,    45,
     157,   158,    61,    62,    63,    64,    40,   164,   171,    60,
     264,   276,   175,    40,   171,   172,    44,    45,    44,    45,
     177,    43,   285,   286,    43,   279,    20,    21,    22,    23,
      24,    25,    43,   219,    44,    45,    43,   223,     9,    45,
      46,    12,    13,    14,    46,    16,    45,    46,    19,   126,
     127,   214,    43,    43,    43,    43,    38,   214,    42,    40,
      26,    55,   225,    42,    35,    36,    37,   230,    44,   255,
     256,    40,   258,   230,    42,    40,    43,   234,    20,    21,
      22,    23,    24,    25,    40,    11,    57,    46,    59,    60,
      61,    46,   249,    26,   251,   252,    39,   260,    46,    40,
      40,    55,    44,    40,    97,   268,    68,   264,   279,   181,
     103,   268,    62,   276,    12,    68,    24,   172,   281,   276,
       9,    38,   279,   164,   281,   288,   214,     9,   285,   286,
      12,   288,    14,    -1,    16,    -1,    -1,    19,   131,   132,
     133,   134,   135,   136,   137,   138,    -1,    -1,   141,    -1,
      -1,    -1,    -1,    35,    36,    37,    -1,    28,    -1,    -1,
      -1,    -1,    33,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    43,    -1,    -1,    57,    -1,    59,    60,    61,
      51,    52,    53,    39,    -1,    -1,    -1,    -1,    28,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    43,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    28,    56,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    20,    21,    22,    23,    24,    25,    60,    61,    62,
      63,    64,    10,    20,    21,    22,    23,    24,    25,    -1,
      39,    -1,    20,    21,    22,    23,    24,    25,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    -1,    60,    61,    62,
      63,    64,    51,    52,    53,    -1,    51,    52,    53,    -1,
      -1,    60,    61,    62,    63,    64,    61,    62,    63,    64,
      15,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    15,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    17,    18,    -1,    20,    21,    22,    23,
      24,    25,   143,   144,   145,   146,   147,   148
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    75,    60,     0,    76,    40,     6,    77,    78,
      92,    60,    93,    94,   106,    41,    57,   107,   108,     7,
      96,    94,    20,   109,    97,    98,   106,     8,    89,    51,
      52,    53,    61,    62,    63,    64,    95,     9,    12,    14,
      16,    19,    35,    36,    37,    58,    59,    61,   106,   108,
     110,   112,   113,   114,   115,   117,   118,   119,   122,   123,
      98,    20,    90,    91,   105,   106,     4,     5,    79,    80,
      81,    86,    87,    40,    28,    33,    43,    66,    67,    68,
      69,    70,    71,    72,    73,    95,   106,   125,   126,   127,
     128,   109,   125,   125,   106,    43,    43,    43,    61,   111,
      26,    38,    41,    43,    40,    28,    43,    47,    48,    49,
      50,    54,    56,    95,    99,   100,   103,   104,   106,    91,
      45,    46,    60,    60,    80,    86,    40,    40,   128,   128,
     125,    43,    43,    43,    43,    43,    43,    43,    43,    38,
      41,    43,    10,    20,    21,    22,    23,    24,    25,    27,
      28,    31,    29,    30,    32,    34,    13,    15,    55,    26,
     128,   124,   125,   124,    46,   125,   125,   106,   124,    95,
     105,    38,   101,   102,   105,    42,    40,    42,   106,    99,
      82,    88,    77,    77,    44,   124,   124,   124,   124,   124,
     124,   124,   124,   125,   106,   124,   110,   126,   126,   126,
     126,   126,   126,   127,   127,   127,   128,   128,   128,   128,
     125,   110,    95,   106,   120,   121,   125,    44,    44,    45,
      44,   112,    39,    26,    44,    42,    44,   104,    58,   102,
      46,    95,   106,    40,    43,    83,    83,    40,    40,    44,
      44,    44,    44,    44,    44,    44,    44,    39,    44,    11,
     116,    46,    46,    58,   121,    17,    18,   125,    26,   125,
      28,    95,    39,    99,     8,    84,    85,   105,    46,   110,
     110,   110,   125,   125,   125,    95,    55,    40,   105,    40,
      44,    46,   104,    40,    40,    15,    15,    99,    46,    85,
     104,   110,   110,   104
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    76,    75,    77,    78,    79,    79,    79,    79,
      79,    80,    82,    81,    83,    83,    84,    84,    85,    85,
      86,    88,    87,    89,    89,    90,    90,    91,    92,    92,
      93,    93,    94,    95,    95,    95,    95,    95,    95,    95,
      96,    96,    97,    97,    98,    99,    99,    99,   100,   101,
     101,   102,   103,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   107,   108,   109,   109,
     111,   110,   110,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   113,   113,   113,   114,   115,   116,   116,   117,
     117,   118,   119,   120,   120,   121,   121,   122,   122,   123,
     123,   123,   123,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   126,   126,   126,   126,   127,   127,
     127,   127,   127,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     2,     4,     0,     2,     2,     1,
       1,     4,     0,     6,     0,     3,     3,     1,     4,     3,
       4,     0,     4,     0,     2,     2,     1,     4,     0,     2,
       2,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     2,     1,     4,     1,     1,     1,     3,     2,
       1,     4,     6,     1,     3,     3,     4,     5,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     0,     3,
       0,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     6,     5,     2,     5,     0,     2,     4,
       0,     4,     5,     2,     1,     4,     4,     8,     8,     1,
       4,     4,     4,     1,     4,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     1,     4,     1,     3,     2,     2,     4,
       3,     4,     4,     4,     4,     4,     4,     4,     4
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
#line 30 "tiny.y" /* yacc.c:1646  */
    {   savedName = copyString(tokenString); }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 32 "tiny.y" /* yacc.c:1646  */
    {   (yyval) = (yyvsp[-1]);
                            (yyval)->attr.name=savedName;
                            savedTree = (yyval);
                        }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 37 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[-1]);
                            (yyval)->sibling=(yyvsp[0]);
                        }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 42 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval) = newNode(DECL_ROUTINEHEAD);
                            (yyval) ->child[0]=(yyvsp[-3]);
                            (yyval) ->child[1]=(yyvsp[-2]);
                            (yyval) ->child[2]=(yyvsp[-1]);
                            (yyval) ->child[3]=(yyvsp[0]);
                        }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 50 "tiny.y" /* yacc.c:1646  */
    {   (yyval)= NULL;}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 52 "tiny.y" /* yacc.c:1646  */
    {   YYSTYPE t=(yyvsp[-1]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[0]);
                                (yyval)=(yyvsp[-1]);
                            }
                            else
                                (yyval)=(yyvsp[0]);
                        }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 63 "tiny.y" /* yacc.c:1646  */
    {   YYSTYPE t=(yyvsp[-1]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[0]);
                                (yyval)=(yyvsp[-1]);
                            }
                            else
                                (yyval)=(yyvsp[0]);
                        }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 73 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 74 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 77 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(DECL_FUNCTION);
                            (yyval)->child[0]=(yyvsp[-3]);
                            (yyval)->child[1]=(yyvsp[-1]);
                        }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 84 "tiny.y" /* yacc.c:1646  */
    {   savedName=copyString(tokenString);}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 86 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(DECL_FUNCTIONHEAD);
                            (yyval)->attr.name=savedName;
                            (yyval)->child[0]=(yyvsp[-2]);
                            (yyval)->child[1]=(yyvsp[0]);
                        }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 94 "tiny.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 96 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 99 "tiny.y" /* yacc.c:1646  */
    {   YYSTYPE t=(yyvsp[-2]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[0]);
                                (yyval)=(yyvsp[-2]);
                            }
                            else
                                (yyval)=(yyvsp[0]);
                        }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 110 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[0]); }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 113 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(DECL_VAR_PARA);
                            (yyval)->child[0]=(yyvsp[-2]);
                            (yyval)->child[1]=(yyvsp[0]);
                        }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 119 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(DECL_VAL_PARA);
                            (yyval)->child[0]=(yyvsp[-2]);
                            (yyval)->child[1]=(yyvsp[0]);
                        }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 126 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(DECL_PROCEDURE);
                            (yyval)->child[0]=(yyvsp[-3]);
                            (yyval)->child[1]=(yyvsp[-1]);
                        }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 133 "tiny.y" /* yacc.c:1646  */
    {   savedName=copyString(tokenString);}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 135 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(DECL_PROCEDUREHEAD);
                            (yyval)->attr.name=savedName;
                            (yyval)->child[0]=(yyvsp[0]);
                        }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 141 "tiny.y" /* yacc.c:1646  */
    {   (yyval) = NULL;}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 143 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[0]);}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 146 "tiny.y" /* yacc.c:1646  */
    {   YYSTYPE t = (yyvsp[-1]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[0]);
                                (yyval)=(yyvsp[-1]);
                            }
                            else
                                (yyval)=(yyvsp[0]);
                        }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 156 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 159 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(DECL_VAR);
                            (yyval)->child[0]=(yyvsp[-3]);
                            (yyval)->child[1]=(yyvsp[-1]);
                        }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 165 "tiny.y" /* yacc.c:1646  */
    {   (yyval) = NULL; }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 167 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[0]); }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 170 "tiny.y" /* yacc.c:1646  */
    {
                            YYSTYPE t = (yyvsp[-1]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling = (yyvsp[0]);
                                (yyval)=(yyvsp[0]);
                            }
                            else
                                (yyval)=(yyvsp[-1]);
                        }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 183 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[0]); }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 186 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval) = newNode(DECL_CONST);
                            (yyval)->attr.name = copyString((yyvsp[-3])->attr.name);
                            freeNode((yyvsp[-3]));
                            (yyval)->child[0]=(yyvsp[-1]);
                            (yyval)->type=(yyvsp[-1])->type;
                        }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 195 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval) = newNode(EXP_CONST);
                            (yyval)->type = EXPTYPE_INT;
                            (yyval)->attr.val = atoi(tokenString);
                        }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 201 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval) = newNode(EXP_CONST);
                            (yyval)->type = EXPTYPE_REAL;
                            (yyval)->attr.real_val = atof(tokenString);
                        }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 207 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval) = newNode(EXP_CONST);
                            (yyval)->type = EXPTYPE_CHAR;
                            (yyval)->attr.char_val = tokenString[1];
                        }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 213 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval) = newNode(EXP_CONST);
                            (yyval)->type=EXPTYPE_STRING;
                            (yyval)->attr.string_val = (char*)malloc(strlen(tokenString)-1);
                            memmove((yyval)->attr.string_val,tokenString+1,strlen(tokenString)-2);
                            (yyval)->attr.string_val[strlen(tokenString)-2]='\0';
                        }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 221 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(EXP_CONST);
                            (yyval)->type=EXPTYPE_BOOL;
                            (yyval)->attr.val=1;
                        }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 227 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(EXP_CONST);
                            (yyval)->type=EXPTYPE_BOOL;
                            (yyval)->attr.val=0;
                        }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 233 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(EXP_CONST);
                            (yyval)->type=EXPTYPE_INT;
                            (yyval)->attr.val=2147483647;
                        }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 240 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=NULL;}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 242 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[0]);}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 245 "tiny.y" /* yacc.c:1646  */
    {
                            YYSTYPE t=(yyvsp[-1]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[0]);
                                (yyval)=(yyvsp[-1]);
                            }
                            else
                              (yyval)=(yyvsp[0]);
                        }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 257 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[0]);}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 260 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(DECL_TYPE);
                            (yyval)->child[0]=(yyvsp[-3]);
                            (yyval)->child[1]=(yyvsp[-1]);
                        }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 265 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 266 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 267 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 270 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[-1]); }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 273 "tiny.y" /* yacc.c:1646  */
    {
                            YYSTYPE t=(yyvsp[-1]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[0]);
                                (yyval)=(yyvsp[-1]);
                            }
                            else
                              (yyval)=(yyvsp[0]);
                        }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 284 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 287 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(TYPE_RECORD);
                            (yyval)->child[0]=(yyvsp[-3]);
                            (yyval)->child[1]=(yyvsp[-1]);
                        }
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 294 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(TYPE_ARRAY);
                            (yyval)->child[0]=(yyvsp[-3]);
                            (yyval)->child[1]=(yyvsp[0]);
                            (yyval)->type=EXPTYPE_ARRAY;
                        }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 302 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(TYPE_SIMPLE_ID);
                            (yyval)->attr.name = copyString((yyvsp[0])->attr.name);
                            free((yyvsp[0]));
                        }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 308 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(TYPE_SIMPLE_ENUM);
                            (yyval)->child[0]=(yyvsp[-1]);
                            (yyval)->type=EXPTYPE_SIMPLE_ENUM;
                        }
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 313 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(TYPE_SIMPLE_LIMIT);
                            (yyval)->child[0]=(yyvsp[-2]);
                            (yyval)->child[1]=(yyvsp[0]);
                            (yyval)->type=EXPTYPE_SIMPLE_LIMIT;
                        }
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 319 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(TYPE_SIMPLE_LIMIT);
                            (yyval)->child[0]=(yyvsp[-2]);
                            (yyval)->child[0]->attr.val *= -1;
                            (yyval)->child[1]=(yyvsp[0]);
                            (yyval)->type=EXPTYPE_SIMPLE_LIMIT;
                        }
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 327 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(TYPE_SIMPLE_LIMIT);
                            (yyval)->child[0]=(yyvsp[-3]);
                            (yyval)->child[0]->attr.val *=-1;
                            (yyval)->child[1]=(yyvsp[0]);
                            (yyval)->child[1]->attr.val *=-1;
                            (yyval)->type=EXPTYPE_SIMPLE_LIMIT;
                        }
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 335 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(TYPE_SIMPLE_LIMIT);
                            (yyval)->child[0]=(yyvsp[-2]);
                            (yyval)->child[1]=(yyvsp[0]);
                            (yyval)->type=EXPTYPE_SIMPLE_LIMIT;
                        }
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 342 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(TYPE_SIMPLE_SYS);
                            (yyval)->type=EXPTYPE_INT;
                        }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 346 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(TYPE_SIMPLE_SYS);
                            (yyval)->type=EXPTYPE_BOOL;
                        }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 350 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(TYPE_SIMPLE_SYS);
                            (yyval)->type=EXPTYPE_REAL;
                        }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 354 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(TYPE_SIMPLE_SYS);
                            (yyval)->type=EXPTYPE_CHAR;
                        }
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 359 "tiny.y" /* yacc.c:1646  */
    {
                            YYSTYPE t=(yyvsp[-2]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[0]);
                                (yyval)=(yyvsp[-2]);
                            }
                            else
                                (yyval)=(yyvsp[-2]);
                        }
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 370 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[0]); }
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 373 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(EXP_ID);
                            (yyval)->attr.name=copyString(tokenString);
                        }
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 376 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 377 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 379 "tiny.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 381 "tiny.y" /* yacc.c:1646  */
    {
                            YYSTYPE t=(yyvsp[-2]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[-1]);
                                (yyval)=(yyvsp[-2]);
                            }
                            else
                                (yyval)=(yyvsp[-1]);
                        }
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 394 "tiny.y" /* yacc.c:1646  */
    {   savedNum= atoi(tokenString);}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 396 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(STMT_LABEL);
                            (yyval)->attr.val=savedNum;
                            (yyval)->child[0]=(yyvsp[0]);
                        }
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 402 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[0]);}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 404 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 405 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 406 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 407 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 408 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 409 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 410 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 411 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 412 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 414 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(STMT_ASSIGN);
                            (yyval)->child[0]=(yyvsp[-2]);
                            (yyval)->child[1]=(yyvsp[0]);
                            (yyval)->attr.op=TOKEN_ID;
                        }
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 420 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(STMT_ASSIGN);
                            (yyval)->child[0]=(yyvsp[-5]);
                            ((yyval)->child[0])->child[0]=(yyvsp[-3]);
                            (yyval)->child[1]=(yyvsp[0]);
                            (yyval)->attr.op=TOKEN_ARRAY;
                        }
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 428 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(STMT_ASSIGN);
                            (yyval)->child[0]=(yyvsp[-4]);
                            ((yyval)->child[0])->child[0]=(yyvsp[-2]);
                            (yyval)->child[1]=(yyvsp[0]);
                            (yyval)->attr.op=TOKEN_RECORD;
                        }
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 436 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(STMT_GOTO);
                            (yyval)->attr.val=atoi(tokenString);
                        }
#line 2347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 441 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(STMT_IF);
                            (yyval)->child[0]=(yyvsp[-3]);
                            (yyval)->child[1]=(yyvsp[-1]);
                            (yyval)->child[2]=(yyvsp[0]);
                        }
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 447 "tiny.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 448 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 451 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(STMT_REPEAT);
                            (yyval)->child[0]=(yyvsp[-2]);
                            (yyval)->child[1]=(yyvsp[0]);
                        }
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 458 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(STMT_WHILE);
                            (yyval)->child[0]=(yyvsp[-2]);
                            (yyval)->child[1]=(yyvsp[0]);
                        }
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 463 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(STMT_CASE);
                            (yyval)->child[0]=(yyvsp[-3]);
                            (yyval)->child[1]=(yyvsp[-1]);
                        }
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 468 "tiny.y" /* yacc.c:1646  */
    {   YYSTYPE t=(yyvsp[-1]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[0]);
                                (yyval)=(yyvsp[-1]);
                            }
                            else
                                (yyval)=(yyvsp[0]);
                        }
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 478 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 480 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(EXP_CASE);
                            (yyval)->child[0]=(yyvsp[-3]);
                            (yyval)->child[1]=(yyvsp[-1]);
                        }
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 486 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(EXP_CASE);
                            (yyval)->child[0]=(yyvsp[-3]);
                            (yyval)->child[1]=(yyvsp[-1]);
                        }
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 492 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(STMT_FOR);
                            (yyval)->child[0]=(yyvsp[-6]);
                            (yyval)->child[1]=(yyvsp[-4]);
                            (yyval)->child[2]=(yyvsp[-2]);
                            (yyval)->child[3]=(yyvsp[0]);
                            (yyval)->attr.op=TOKEN_TO;
                        }
#line 2451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 501 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(STMT_FOR);
                            (yyval)->child[0]=(yyvsp[-6]);
                            (yyval)->child[1]=(yyvsp[-4]);
                            (yyval)->child[2]=(yyvsp[-2]);
                            (yyval)->child[3]=(yyvsp[0]);
                            (yyval)->attr.op=TOKEN_DOWNTO;
                        }
#line 2464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 510 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(STMT_PROC_ID);
                            (yyval)->attr.name=copyString((yyvsp[0])->attr.name);
                        }
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 514 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(STMT_PROC_ID);
                            (yyval)->attr.name=copyString((yyvsp[-3])->attr.name);
                            (yyval)->child[0]=(yyvsp[-1]);
                        }
#line 2481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 519 "tiny.y" /* yacc.c:1646  */
    {
                            (yyval)=newNode(STMT_PROC_SYS);
                            (yyval)->attr.op=TOKEN_READ;
                            (yyval)->child[0]=(yyvsp[-1]);
                        }
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 525 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(STMT_PROC_SYS);
                            (yyval)->attr.op=TOKEN_WRITE;
                            (yyval)->child[0]=(yyvsp[-1]);
                        }
#line 2500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 530 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(STMT_PROC_SYS);
                            (yyval)->attr.op=TOKEN_WRITELN;
                        }
#line 2508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 534 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(STMT_PROC_SYS);
                            (yyval)->attr.op=TOKEN_WRITELN;
                            (yyval)->child[0]=(yyvsp[-1]);
                        }
#line 2517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 539 "tiny.y" /* yacc.c:1646  */
    {   YYSTYPE t=(yyvsp[-2]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[0]);
                                (yyval)=(yyvsp[-2]);
                            }
                            else
                                (yyval)=(yyvsp[0]);
                        }
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 549 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 551 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[-2]),(yyvsp[0]),TOKEN_GE); }
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 552 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[-2]),(yyvsp[0]),TOKEN_GT); }
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 553 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[-2]),(yyvsp[0]),TOKEN_LE); }
#line 2556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 554 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[-2]),(yyvsp[0]),TOKEN_LT); }
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 555 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[-2]),(yyvsp[0]),TOKEN_EQUAL); }
#line 2568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 556 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[-2]),(yyvsp[0]),TOKEN_UNEQUAL); }
#line 2574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 557 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[0]);}
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 559 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[-2]),(yyvsp[0]),TOKEN_PLUS); }
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 560 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[-2]),(yyvsp[0]),TOKEN_MINUS); }
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 561 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[-2]),(yyvsp[0]),TOKEN_OR); }
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 562 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[0]);}
#line 2604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 564 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[-2]),(yyvsp[0]),TOKEN_MUL); }
#line 2610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 565 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[-2]),(yyvsp[0]),TOKEN_DIV); }
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 566 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[-2]),(yyvsp[0]),TOKEN_MOD); }
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 567 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[-2]),(yyvsp[0]),TOKEN_AND); }
#line 2628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 568 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 571 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 573 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newNode(EXP_FUNC_ID);
                            (yyval)->attr.name=copyString((yyvsp[-3])->attr.name);
                            (yyval)->child[0]=(yyvsp[-1]);
                        }
#line 2649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 577 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 578 "tiny.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 580 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[0]),NULL,TOKEN_NOT);
                        }
#line 2668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 583 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newOpExpNode((yyvsp[0]),NULL,TOKEN_MINUS);
                        }
#line 2675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 586 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[-3]);
                            (yyval)->child[0]=(yyvsp[-1]);
                            (yyval)->type=EXPTYPE_ARRAY;
                        }
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 591 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[-2]);
                            (yyval)->child[0]=(yyvsp[0]);
                            (yyval)->type=EXPTYPE_RECORD;
                        }
#line 2693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 596 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newFuncSysExpNode(TOKEN_ABS,(yyvsp[-1]));
                        }
#line 2700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 599 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newFuncSysExpNode(TOKEN_CHR,(yyvsp[-1]));
                        }
#line 2707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 602 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newFuncSysExpNode(TOKEN_ODD,(yyvsp[-1]));
                        }
#line 2714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 605 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newFuncSysExpNode(TOKEN_ORD,(yyvsp[-1]));
                        }
#line 2721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 608 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newFuncSysExpNode(TOKEN_PRED,(yyvsp[-1]));
                        }
#line 2728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 611 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newFuncSysExpNode(TOKEN_SQR,(yyvsp[-1]));
                        }
#line 2735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 614 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newFuncSysExpNode(TOKEN_SQRT,(yyvsp[-1]));
                        }
#line 2742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 617 "tiny.y" /* yacc.c:1646  */
    {   (yyval)=newFuncSysExpNode(TOKEN_SUCC,(yyvsp[-1]));
                        }
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2753 "y.tab.c" /* yacc.c:1646  */
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
#line 620 "tiny.y" /* yacc.c:1906  */


int yyerror(char* message){
    fprintf(listing, "Syntax error at line %d: %s\n",lineno,message);
   // printToken(yychar, tokenString);
    return 0;
}


TreeNode * parse(){
    yyparse();
    return savedTree;

}
