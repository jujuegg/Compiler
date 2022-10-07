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
#line 1 "B083040019.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex();
extern char token[80];
extern char FullLine[1024];
extern char errChar[5];
extern int declaretype;
char id[5][10] = {'\0'};
int type[5];
int idcount = 0;
int two_id = 0;
int flag = 0, flag2 = 0;
int Ltype,Rtype;
extern unsigned charCount, lineCount, ErrorChar, ErrorChar2;

void yyerror(const char* message) 
{
    printf("Line %2d: Syntax error, ",lineCount);
	if(!strcmp(errChar,"end"))
		printf("\".\" expected but \"end of file\" found\n");
}
void clear_FullLine()
{
	for(int i = 0 ; i < strlen(FullLine) ; ++i)
			FullLine[i] = '\0';
}
void PRINT()
{
	int flag = 0;
	for(int i = 0 ; i < strlen(FullLine) ; ++i)
		if(FullLine[i] != ' ' && FullLine[i] != '\t')
			flag = 1;
	if(flag)
	{
		printf("Line %2d: %s\n",lineCount, FullLine);
		fflush(stdout);
	}
	clear_FullLine();
}
int Var_is_Declared(char* var)
{
	for(int i = 0 ; i < 5 ; ++i)
	{
		if(!strcmp(var,id[i]))
			return 1;
	}
	return 0;
}
int DataType(char* var)
{
	for(int i = 0 ; i < 5 ; ++i)
	{
		if(!strcmp(var,id[i]))
			return type[i];
	}
	if(var[0] == '\'')
		return 4;
}
void ILL_EXP()
{
	printf("Line %2d, Char %d: Error: Illegal expression\n",lineCount, ErrorChar);
	clear_FullLine();
}
void ID_NOT_FOUND()
{
	printf("Line %2d, Char %d: Error: Identifier not found \"%s\"\n",lineCount, ErrorChar2, token);
	clear_FullLine();
}
void DeclareERR()
{
	printf("Line %2d, Char %d: Error: \":\" expected but \"%s\" found\n",lineCount, ErrorChar, errChar);
	clear_FullLine();
}
void TypeWrong(int LType, int RType, int errtype)
{
	char L[10] = {'\0'};
	char R[10] = {'\0'};
	switch(LType)
	{
		case 1: strcpy(L,"INTEGER"); break;
		case 2: strcat(L,"DOUBLE"); break;
		case 3: strcat(L,"FLOAT"); break;
		case 4: strcat(L,"STRING"); break;
	}
	switch(RType)
	{
		case 1: strcpy(R,"INTEGER"); break;
		case 2: strcat(R,"DOUBLE"); break;
		case 3: strcat(R,"FLOAT"); break;
		case 4: strcat(R,"STRING"); break;
	}
	if (errtype == 0)
		printf("Line %2d, Char %d: Error: Operator is not overloaded: \"%s\" + \"%s\"\n",lineCount, ErrorChar2, L, R);
	else if (errtype ==1)
		printf("Line %2d, Char %d: Error: Incompatible types: got \"%s\" expected \"%s\"\n",lineCount, ErrorChar2, R, L);
	clear_FullLine();
}
void MissRP(char* next)
{
	printf("\")\" expected but \"%s\" found\n",next);
	clear_FullLine();
}
void MissSMC(char* next)
{
	printf("\";\" expected but \"%s\" found\n",next);
	clear_FullLine();
}
void MissSDOT(char* next)
{
	printf("\".\" expected but \"%s\" found\n",next);
	clear_FullLine();
}

#line 182 "y.tab.c" /* yacc.c:339  */

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
    PLUS = 258,
    MINUS = 259,
    MUL = 260,
    DIV = 261,
    LP = 262,
    RP = 263,
    LMP = 264,
    RMP = 265,
    SEMICOLON = 266,
    COLON = 267,
    DOT = 268,
    COMMA = 269,
    ASSIGN = 270,
    EQ = 271,
    GT = 272,
    LT = 273,
    LE = 274,
    GE = 275,
    NEWLINE = 276,
    ABSOLUTE = 277,
    AND = 278,
    BEGIN_ = 279,
    BREAK = 280,
    CASE = 281,
    CONST = 282,
    CONTINUE = 283,
    DO = 284,
    ELSE = 285,
    END = 286,
    FOR = 287,
    FUNCTION = 288,
    IF = 289,
    MOD = 290,
    NIL = 291,
    NOT = 292,
    OBJECT = 293,
    OF = 294,
    OR = 295,
    PROGRAM = 296,
    THEN = 297,
    TO = 298,
    WHILE = 299,
    ARRAY = 300,
    INTEGER = 301,
    DOUBLE = 302,
    WRITE = 303,
    WRITELN = 304,
    STRING = 305,
    FLOAT = 306,
    READ = 307,
    VAR = 308,
    NUMBER = 309,
    ID = 310,
    STR = 311
  };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define MUL 260
#define DIV 261
#define LP 262
#define RP 263
#define LMP 264
#define RMP 265
#define SEMICOLON 266
#define COLON 267
#define DOT 268
#define COMMA 269
#define ASSIGN 270
#define EQ 271
#define GT 272
#define LT 273
#define LE 274
#define GE 275
#define NEWLINE 276
#define ABSOLUTE 277
#define AND 278
#define BEGIN_ 279
#define BREAK 280
#define CASE 281
#define CONST 282
#define CONTINUE 283
#define DO 284
#define ELSE 285
#define END 286
#define FOR 287
#define FUNCTION 288
#define IF 289
#define MOD 290
#define NIL 291
#define NOT 292
#define OBJECT 293
#define OF 294
#define OR 295
#define PROGRAM 296
#define THEN 297
#define TO 298
#define WHILE 299
#define ARRAY 300
#define INTEGER 301
#define DOUBLE 302
#define WRITE 303
#define WRITELN 304
#define STRING 305
#define FLOAT 306
#define READ 307
#define VAR 308
#define NUMBER 309
#define ID 310
#define STR 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 116 "B083040019.y" /* yacc.c:355  */

    float 	floatVal;
    int 	intVal;

#line 339 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 356 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   125,   125,   125,   125,   125,   127,   127,   129,   130,
     133,   130,   134,   136,   134,   137,   137,   141,   142,   144,
     145,   147,   148,   149,   150,   152,   152,   154,   155,   155,
     155,   156,   156,   158,   159,   161,   162,   163,   165,   165,
     167,   169,   169,   170,   170,   172,   174,   174,   176,   176,
     180,   181,   183,   185,   186,   188,   189,   191,   192,   194,
     194,   194,   194,   194,   196,   197,   197,   202,   204,   205,
     206,   207,   209,   209,   209,   209,   215,   216,   216,   218,
     218,   218,   220,   220,   222,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "MUL", "DIV", "LP",
  "RP", "LMP", "RMP", "SEMICOLON", "COLON", "DOT", "COMMA", "ASSIGN", "EQ",
  "GT", "LT", "LE", "GE", "NEWLINE", "ABSOLUTE", "AND", "BEGIN_", "BREAK",
  "CASE", "CONST", "CONTINUE", "DO", "ELSE", "END", "FOR", "FUNCTION",
  "IF", "MOD", "NIL", "NOT", "OBJECT", "OF", "OR", "PROGRAM", "THEN", "TO",
  "WHILE", "ARRAY", "INTEGER", "DOUBLE", "WRITE", "WRITELN", "STRING",
  "FLOAT", "READ", "VAR", "NUMBER", "ID", "STR", "$accept", "Program",
  "$@1", "$@2", "DeclarationPart", "$@3", "Declarations", "$@4", "$@5",
  "$@6", "$@7", "$@8", "IDlist", "Type", "Standardtype", "CodePart", "$@9",
  "StatementList", "$@10", "$@11", "$@12", "Statement",
  "StructedStatement", "CompoundStatement", "$@13", "ConditionalStatement",
  "IfStatement", "$@14", "$@15", "LoopStatement", "ForStatement", "$@16",
  "SimpleStatement", "$@17", "WriteFunction", "ParameterList", "Variable",
  "Expression", "RelationalOperator", "SimpleExpression", "$@18", "term",
  "factor", "group", "$@19", "Sign", "NL", "NLs", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -120

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define YYTABLE_NINF -66

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -36,   -48,    26,    22,  -120,  -120,    28,  -120,     6,    43,
    -120,    42,  -120,    28,  -120,    76,  -120,    28,  -120,    45,
    -120,    28,  -120,    33,     7,  -120,    30,    49,  -120,  -120,
    -120,    14,  -120,  -120,    50,    14,    90,  -120,    89,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,    91,
    -120,    75,    18,  -120,  -120,    56,   102,  -120,  -120,  -120,
    -120,    39,  -120,  -120,    30,  -120,    21,    28,    97,    73,
      14,    14,   105,   103,   106,    14,  -120,  -120,  -120,  -120,
    -120,    14,   116,    14,    14,    14,  -120,    66,  -120,   111,
     112,  -120,  -120,  -120,    14,  -120,    20,    81,   114,  -120,
      14,    28,    18,    81,    14,  -120,  -120,  -120,   115,    28,
    -120,  -120,    28,    12,    82,    28,    28,  -120,    14,  -120,
      28,  -120,  -120,    18,   117,  -120,    28,    28,  -120,  -120,
      14,     3,     3,    81,  -120,    77,  -120,  -120,    98,  -120,
    -120,    99,   122,  -120,     3,    95,    28,  -120,    36,     3,
    -120,  -120
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     0,     1,     2,    82,    84,     0,    83,
       6,     0,    85,    82,    25,     0,     8,    82,     3,     7,
      27,    82,    17,     0,    79,     4,     0,     0,    12,    80,
      81,    79,    38,    26,     0,    79,     0,    51,    55,    73,
      28,    34,    36,    37,    40,    35,    45,    33,    50,    75,
      31,    57,    64,    68,    74,     0,     0,    21,    22,    24,
      23,     0,    19,    18,     0,    75,     0,    82,     0,     0,
      79,    79,     0,     0,     0,    79,    59,    60,    61,    62,
      63,    79,     0,    79,    79,    79,    72,     0,    15,     0,
       0,    77,    76,    27,    79,    41,     0,    53,     0,    29,
      79,    82,    67,    58,    79,    69,    70,    71,     0,    82,
      10,    13,    82,    79,     0,    82,    82,    52,    79,    56,
      82,    49,    32,    66,     0,    16,    82,    82,    78,    39,
      79,     0,     0,    54,    30,     0,    11,    14,     0,    42,
      48,     0,     0,    46,     0,     0,    82,    44,     0,     0,
      20,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,    71,   -12,  -120,  -120,    44,  -120,  -120,
    -120,  -119,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,   -23,   -29,  -120,   -61,
    -120,   -72,   -11,  -120,  -120,  -120,   -13,  -120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    21,    11,    13,    19,    89,   126,    64,
     127,   109,    23,    61,    62,    15,    17,    24,    72,   120,
      74,    40,    41,    42,    67,    43,    44,   115,   116,    45,
      46,   146,    47,    73,    48,    96,    65,    50,    81,    51,
      82,    52,    53,    54,   112,    55,     8,     9
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,    49,    66,   102,    20,     1,    69,     3,    25,    97,
      29,    30,   139,   141,    31,    29,    30,    29,    30,    31,
     103,    31,    91,    83,    84,   147,     4,    32,   117,    92,
     151,    32,   123,     5,   118,    34,    32,    35,    33,    34,
      88,    35,    98,   129,    34,    26,    35,    27,    28,     7,
      -9,    36,    37,    85,    93,    36,    37,   133,    38,    10,
      36,    37,    38,    39,    12,   114,    14,    38,    39,    38,
      39,   121,   105,   106,   107,    56,    57,    58,   -65,    75,
      59,    60,    57,    58,   -65,    75,    59,    60,   122,    18,
      49,    76,    77,    78,    79,    80,   125,    70,    71,   128,
      22,   138,   131,   132,    63,    68,   -48,   134,   140,   140,
      86,    87,    94,   136,   137,    95,    99,   101,   100,   104,
     108,   140,   110,   111,   119,   130,   140,   143,   124,   144,
     135,   142,   145,   149,   148,    90,   150,   113
};

static const yytype_uint8 yycheck[] =
{
      13,    24,    31,    75,    17,    41,    35,    55,    21,    70,
       3,     4,   131,   132,     7,     3,     4,     3,     4,     7,
      81,     7,     1,     5,     6,   144,     0,    24,     8,     8,
     149,    24,   104,    11,    14,    32,    24,    34,    31,    32,
       1,    34,    71,    31,    32,    12,    34,    14,    15,    21,
      11,    48,    49,    35,    67,    48,    49,   118,    55,    53,
      48,    49,    55,    56,    21,    94,    24,    55,    56,    55,
      56,   100,    83,    84,    85,    45,    46,    47,     3,     4,
      50,    51,    46,    47,     3,     4,    50,    51,   101,    13,
     113,    16,    17,    18,    19,    20,   109,     7,     9,   112,
      55,   130,   115,   116,    55,    55,    15,   120,   131,   132,
      54,     9,    15,   126,   127,    42,    11,    11,    15,     3,
      54,   144,    11,    11,    10,    43,   149,    29,    13,    30,
      13,    54,    10,   146,    39,    64,   148,    93
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    58,    55,     0,    11,    59,    21,   103,   104,
      53,    61,    21,    62,    24,    72,   103,    73,    13,    63,
     103,    60,    55,    69,    74,   103,    12,    14,    15,     3,
       4,     7,    24,    31,    32,    34,    48,    49,    55,    56,
      78,    79,    80,    82,    83,    86,    87,    89,    91,    93,
      94,    96,    98,    99,   100,   102,    45,    46,    47,    50,
      51,    70,    71,    55,    66,    93,    94,    81,    55,    94,
       7,     9,    75,    90,    77,     4,    16,    17,    18,    19,
      20,    95,    97,     5,     6,    35,    54,     9,     1,    64,
      70,     1,     8,   103,    15,    42,    92,    96,    94,    11,
      15,    11,    98,    96,     3,    99,    99,    99,    54,    68,
      11,    11,   101,    74,    94,    84,    85,     8,    14,    10,
      76,    94,   103,    98,    13,   103,    65,    67,   103,    31,
      43,   103,   103,    96,   103,    13,   103,   103,    94,    78,
      93,    78,    54,    29,    30,    10,    88,    78,    39,   103,
      71,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    59,    60,    58,    58,    62,    61,    63,    64,
      65,    63,    66,    67,    63,    68,    63,    69,    69,    70,
      70,    71,    71,    71,    71,    73,    72,    74,    75,    76,
      74,    77,    74,    78,    78,    79,    79,    79,    81,    80,
      82,    84,    83,    85,    83,    86,    88,    87,    90,    89,
      89,    89,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    95,    95,    95,    96,    97,    96,    96,    98,    98,
      98,    98,    99,    99,    99,    99,   100,   101,   100,   102,
     102,   102,   103,   103,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,    10,     0,     0,     4,     0,     0,
       0,     8,     0,     0,     8,     0,     7,     1,     3,     1,
       9,     1,     1,     1,     1,     0,     5,     0,     0,     0,
       6,     0,     5,     1,     1,     1,     1,     1,     0,     5,
       1,     0,     6,     0,     8,     1,     0,    10,     0,     4,
       1,     1,     4,     1,     3,     1,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     0,     4,     3,     1,     3,
       3,     3,     2,     1,     1,     1,     3,     0,     5,     0,
       1,     1,     0,     1,     1,     2
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
#line 125 "B083040019.y" /* yacc.c:1646  */
    {PRINT();}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 125 "B083040019.y" /* yacc.c:1646  */
    {PRINT();}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 125 "B083040019.y" /* yacc.c:1646  */
    {printf("done1\n");}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 127 "B083040019.y" /* yacc.c:1646  */
    {PRINT();}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 130 "B083040019.y" /* yacc.c:1646  */
    { type[idcount] = declaretype;
												if(two_id == 1){
													type[idcount-1] = declaretype;}
												++idcount; }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 133 "B083040019.y" /* yacc.c:1646  */
    {PRINT();}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 134 "B083040019.y" /* yacc.c:1646  */
    {	DeclareERR();
											memset(id[idcount],0,10);
											if(two_id == 1) {memset(id[idcount-1],0,10);}	}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 136 "B083040019.y" /* yacc.c:1646  */
    {clear_FullLine();}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 137 "B083040019.y" /* yacc.c:1646  */
    {	MissSMC(errChar);
														memset(id[idcount],0,10);
														if(two_id == 1) {memset(id[idcount-1],0,10);}	}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 141 "B083040019.y" /* yacc.c:1646  */
    {strcpy(id[idcount],token); two_id = 0;}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 142 "B083040019.y" /* yacc.c:1646  */
    {strcpy(id[++idcount],token); two_id = 1;}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 152 "B083040019.y" /* yacc.c:1646  */
    {PRINT();}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 155 "B083040019.y" /* yacc.c:1646  */
    {if(flag2==1){clear_FullLine();}flag2=0;}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 155 "B083040019.y" /* yacc.c:1646  */
    {if(flag==1){clear_FullLine();}PRINT(); flag = 0;}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 156 "B083040019.y" /* yacc.c:1646  */
    {ILL_EXP();}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 165 "B083040019.y" /* yacc.c:1646  */
    {PRINT();}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 169 "B083040019.y" /* yacc.c:1646  */
    {PRINT();flag2=0;}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 170 "B083040019.y" /* yacc.c:1646  */
    {PRINT();}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 174 "B083040019.y" /* yacc.c:1646  */
    {PRINT();}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 176 "B083040019.y" /* yacc.c:1646  */
    {	if(!Var_is_Declared(token)){ID_NOT_FOUND();flag=1;}
							else {Ltype = DataType(token);}	}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 177 "B083040019.y" /* yacc.c:1646  */
    {	if((Ltype != Rtype) && flag != 1)
																						TypeWrong(Ltype, Rtype, 1);
																					Ltype = 0; Rtype = 0;	}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 197 "B083040019.y" /* yacc.c:1646  */
    {	if(Var_is_Declared(token))
										Ltype = DataType(token);}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 199 "B083040019.y" /* yacc.c:1646  */
    {	if(Var_is_Declared(token))
									Rtype = DataType(token);
									if(Ltype!=Rtype){TypeWrong(Ltype, Rtype, 0);}	}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 209 "B083040019.y" /* yacc.c:1646  */
    {Rtype=1;}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 209 "B083040019.y" /* yacc.c:1646  */
    {Rtype=4;}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 209 "B083040019.y" /* yacc.c:1646  */
    {	if(!Var_is_Declared(token))
												{
													ID_NOT_FOUND();
													flag2 = 1;
												}	}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 216 "B083040019.y" /* yacc.c:1646  */
    {MissRP(errChar);}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1725 "y.tab.c" /* yacc.c:1646  */
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
#line 224 "B083040019.y" /* yacc.c:1906  */

int main() {
    yyparse();
    return 0;
}
