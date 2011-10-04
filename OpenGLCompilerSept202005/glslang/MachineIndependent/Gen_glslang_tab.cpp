/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 39 "glslang.y"


/* Based on:
ANSI C Yacc grammar

In 1985, Jeff Lee published his Yacc grammar (which is accompanied by a 
matching Lex specification) for the April 30, 1985 draft version of the 
ANSI C standard.  Tom Stockfisch reposted it to net.sources in 1987; that
original, as mentioned in the answer to question 17.25 of the comp.lang.c
FAQ, can be ftp'ed from ftp.uu.net, file usenet/net.sources/ansi.c.grammar.Z.
 
I intend to keep this version as close to the current C Standard grammar as 
possible; please let me know if you discover discrepancies. 

Jutta Degener, 1995 
*/

#include "SymbolTable.h"
#include "ParseHelper.h"
#include "../Public/ShaderLang.h"

#ifdef _WIN32
    #define YYPARSE_PARAM parseContext
    #define YYPARSE_PARAM_DECL TParseContext&
    #define YY_DECL int yylex(YYSTYPE* pyylval, TParseContext& parseContext)
    #define YYLEX_PARAM parseContext
#else
    #define YYPARSE_PARAM parseContextLocal
    #define parseContext (*((TParseContext*)(parseContextLocal)))
    #define YY_DECL int yylex(YYSTYPE* pyylval, void* parseContextLocal)
    #define YYLEX_PARAM (void*)(parseContextLocal)
    extern void yyerror(char*);    
#endif

#define FRAG_VERT_ONLY(S, L) {                                                  \
    if (parseContext.language != EShLangFragment &&                             \
        parseContext.language != EShLangVertex) {                               \
        parseContext.error(L, " supported in vertex/fragment shaders only ", S, "", "");   \
        parseContext.recover();                                                            \
    }                                                                           \
}

#define VERTEX_ONLY(S, L) {                                                     \
    if (parseContext.language != EShLangVertex) {                               \
        parseContext.error(L, " supported in vertex shaders only ", S, "", "");            \
        parseContext.recover();                                                            \
    }                                                                           \
}

#define FRAG_ONLY(S, L) {                                                       \
    if (parseContext.language != EShLangFragment) {                             \
        parseContext.error(L, " supported in fragment shaders only ", S, "", "");          \
        parseContext.recover();                                                            \
    }                                                                           \
}

#define PACK_ONLY(S, L) {                                                       \
    if (parseContext.language != EShLangPack) {                                 \
        parseContext.error(L, " supported in pack shaders only ", S, "", "");              \
        parseContext.recover();                                                            \
    }                                                                           \
}

#define UNPACK_ONLY(S, L) {                                                     \
    if (parseContext.language != EShLangUnpack) {                               \
        parseContext.error(L, " supported in unpack shaders only ", S, "", "");            \
        parseContext.recover();                                                            \
    }                                                                           \
}

#define PACK_UNPACK_ONLY(S, L) {                                                \
    if (parseContext.language != EShLangUnpack &&                               \
        parseContext.language != EShLangPack) {                                 \
        parseContext.error(L, " supported in pack/unpack shaders only ", S, "", "");       \
        parseContext.recover();                                                            \
    }                                                                           \
}


/* Line 268 of yacc.c  */
#line 151 "glslang.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ATTRIBUTE = 258,
     CONST_QUAL = 259,
     BOOL_TYPE = 260,
     FLOAT_TYPE = 261,
     INT_TYPE = 262,
     BREAK = 263,
     CONTINUE = 264,
     DO = 265,
     ELSE = 266,
     FOR = 267,
     IF = 268,
     DISCARD = 269,
     RETURN = 270,
     BVEC2 = 271,
     BVEC3 = 272,
     BVEC4 = 273,
     IVEC2 = 274,
     IVEC3 = 275,
     IVEC4 = 276,
     VEC2 = 277,
     VEC3 = 278,
     VEC4 = 279,
     MATRIX2 = 280,
     MATRIX3 = 281,
     MATRIX4 = 282,
     IN_QUAL = 283,
     OUT_QUAL = 284,
     INOUT_QUAL = 285,
     UNIFORM = 286,
     VARYING = 287,
     STRUCT = 288,
     VOID_TYPE = 289,
     WHILE = 290,
     SAMPLER1D = 291,
     SAMPLER2D = 292,
     SAMPLER3D = 293,
     SAMPLERCUBE = 294,
     SAMPLER1DSHADOW = 295,
     SAMPLER2DSHADOW = 296,
     SAMPLERRECTARB = 297,
     SAMPLERRECTSHADOWARB = 298,
     IDENTIFIER = 299,
     TYPE_NAME = 300,
     FLOATCONSTANT = 301,
     INTCONSTANT = 302,
     BOOLCONSTANT = 303,
     FIELD_SELECTION = 304,
     LEFT_OP = 305,
     RIGHT_OP = 306,
     INC_OP = 307,
     DEC_OP = 308,
     LE_OP = 309,
     GE_OP = 310,
     EQ_OP = 311,
     NE_OP = 312,
     AND_OP = 313,
     OR_OP = 314,
     XOR_OP = 315,
     MUL_ASSIGN = 316,
     DIV_ASSIGN = 317,
     ADD_ASSIGN = 318,
     MOD_ASSIGN = 319,
     LEFT_ASSIGN = 320,
     RIGHT_ASSIGN = 321,
     AND_ASSIGN = 322,
     XOR_ASSIGN = 323,
     OR_ASSIGN = 324,
     SUB_ASSIGN = 325,
     LEFT_PAREN = 326,
     RIGHT_PAREN = 327,
     LEFT_BRACKET = 328,
     RIGHT_BRACKET = 329,
     LEFT_BRACE = 330,
     RIGHT_BRACE = 331,
     DOT = 332,
     COMMA = 333,
     COLON = 334,
     EQUAL = 335,
     SEMICOLON = 336,
     BANG = 337,
     DASH = 338,
     TILDE = 339,
     PLUS = 340,
     STAR = 341,
     SLASH = 342,
     PERCENT = 343,
     LEFT_ANGLE = 344,
     RIGHT_ANGLE = 345,
     VERTICAL_BAR = 346,
     CARET = 347,
     AMPERSAND = 348,
     QUESTION = 349
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 117 "glslang.y"

    struct {
        TSourceLoc line;
        union {
            TString *string;
            float f;
            int i;
            bool b;
        };
        TSymbol* symbol;
    } lex;
    struct {
        TSourceLoc line;
        TOperator op;
        union {
            TIntermNode* intermNode;
            TIntermNodePair nodePair;
            TIntermTyped* intermTypedNode;
            TIntermAggregate* intermAggregate;
        };
        union {
            TPublicType type;
            TQualifier qualifier;
            TFunction* function;
            TParameter param;
            TTypeLine typeLine;
            TTypeList* typeList;
        };
    } interm;



/* Line 293 of yacc.c  */
#line 314 "glslang.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */

/* Line 343 of yacc.c  */
#line 148 "glslang.y"

#ifndef _WIN32
    extern int yylex(YYSTYPE*, void*);
#endif


/* Line 343 of yacc.c  */
#line 333 "glslang.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1334

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  208
/* YYNRULES -- Number of states.  */
#define YYNSTATES  315

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   349

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    17,    19,
      24,    26,    30,    33,    36,    38,    40,    42,    46,    49,
      52,    55,    57,    60,    64,    67,    69,    71,    73,    75,
      78,    81,    84,    86,    88,    90,    92,    94,    98,   102,
     106,   108,   112,   116,   118,   122,   126,   128,   132,   136,
     140,   144,   146,   150,   154,   156,   160,   162,   166,   168,
     172,   174,   178,   180,   184,   186,   190,   192,   198,   200,
     204,   206,   208,   210,   212,   214,   216,   218,   220,   222,
     224,   226,   228,   232,   234,   237,   240,   243,   245,   247,
     250,   254,   258,   261,   267,   271,   274,   278,   281,   282,
     284,   286,   288,   290,   292,   296,   302,   309,   317,   326,
     332,   334,   337,   342,   348,   355,   363,   368,   370,   373,
     375,   377,   379,   381,   383,   388,   390,   392,   394,   396,
     398,   400,   402,   404,   406,   408,   410,   412,   414,   416,
     418,   420,   422,   424,   426,   428,   430,   432,   434,   436,
     438,   440,   446,   451,   453,   456,   460,   462,   466,   468,
     473,   475,   477,   479,   481,   483,   485,   487,   489,   491,
     494,   495,   496,   502,   504,   506,   509,   513,   515,   518,
     520,   523,   529,   533,   535,   537,   542,   543,   550,   551,
     560,   561,   569,   571,   573,   575,   576,   579,   583,   586,
     589,   592,   596,   599,   601,   604,   606,   608,   609
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     167,     0,    -1,    44,    -1,    96,    -1,    47,    -1,    46,
      -1,    48,    -1,    71,   123,    72,    -1,    97,    -1,    98,
      73,    99,    74,    -1,   100,    -1,    98,    77,    49,    -1,
      98,    52,    -1,    98,    53,    -1,   123,    -1,   101,    -1,
     102,    -1,    98,    77,   102,    -1,   104,    72,    -1,   103,
      72,    -1,   105,    34,    -1,   105,    -1,   105,   121,    -1,
     104,    78,   121,    -1,   106,    71,    -1,   138,    -1,    44,
      -1,    49,    -1,    98,    -1,    52,   107,    -1,    53,   107,
      -1,   108,   107,    -1,    85,    -1,    83,    -1,    82,    -1,
      84,    -1,   107,    -1,   109,    86,   107,    -1,   109,    87,
     107,    -1,   109,    88,   107,    -1,   109,    -1,   110,    85,
     109,    -1,   110,    83,   109,    -1,   110,    -1,   111,    50,
     110,    -1,   111,    51,   110,    -1,   111,    -1,   112,    89,
     111,    -1,   112,    90,   111,    -1,   112,    54,   111,    -1,
     112,    55,   111,    -1,   112,    -1,   113,    56,   112,    -1,
     113,    57,   112,    -1,   113,    -1,   114,    93,   113,    -1,
     114,    -1,   115,    92,   114,    -1,   115,    -1,   116,    91,
     115,    -1,   116,    -1,   117,    58,   116,    -1,   117,    -1,
     118,    60,   117,    -1,   118,    -1,   119,    59,   118,    -1,
     119,    -1,   119,    94,   123,    79,   121,    -1,   120,    -1,
     107,   122,   121,    -1,    80,    -1,    61,    -1,    62,    -1,
      64,    -1,    63,    -1,    70,    -1,    65,    -1,    66,    -1,
      67,    -1,    68,    -1,    69,    -1,   121,    -1,   123,    78,
     121,    -1,   120,    -1,   126,    81,    -1,   134,    81,    -1,
     127,    72,    -1,   129,    -1,   128,    -1,   129,   131,    -1,
     128,    78,   131,    -1,   136,    44,    71,    -1,   138,    44,
      -1,   138,    44,    73,   124,    74,    -1,   137,   132,   130,
      -1,   132,   130,    -1,   137,   132,   133,    -1,   132,   133,
      -1,    -1,    28,    -1,    29,    -1,    30,    -1,   138,    -1,
     135,    -1,   134,    78,    44,    -1,   134,    78,    44,    73,
      74,    -1,   134,    78,    44,    73,   124,    74,    -1,   134,
      78,    44,    73,    74,    80,   145,    -1,   134,    78,    44,
      73,   124,    74,    80,   145,    -1,   134,    78,    44,    80,
     145,    -1,   136,    -1,   136,    44,    -1,   136,    44,    73,
      74,    -1,   136,    44,    73,   124,    74,    -1,   136,    44,
      73,    74,    80,   145,    -1,   136,    44,    73,   124,    74,
      80,   145,    -1,   136,    44,    80,   145,    -1,   138,    -1,
     137,   138,    -1,     4,    -1,     3,    -1,    32,    -1,    31,
      -1,   139,    -1,   139,    73,   124,    74,    -1,    34,    -1,
       6,    -1,     7,    -1,     5,    -1,    22,    -1,    23,    -1,
      24,    -1,    16,    -1,    17,    -1,    18,    -1,    19,    -1,
      20,    -1,    21,    -1,    25,    -1,    26,    -1,    27,    -1,
      36,    -1,    37,    -1,    38,    -1,    39,    -1,    40,    -1,
      41,    -1,    42,    -1,    43,    -1,   140,    -1,    45,    -1,
      33,    44,    75,   141,    76,    -1,    33,    75,   141,    76,
      -1,   142,    -1,   141,   142,    -1,   138,   143,    81,    -1,
     144,    -1,   143,    78,   144,    -1,    44,    -1,    44,    73,
     124,    74,    -1,   121,    -1,   125,    -1,   149,    -1,   148,
      -1,   146,    -1,   155,    -1,   156,    -1,   159,    -1,   166,
      -1,    75,    76,    -1,    -1,    -1,    75,   150,   154,   151,
      76,    -1,   153,    -1,   148,    -1,    75,    76,    -1,    75,
     154,    76,    -1,   147,    -1,   154,   147,    -1,    81,    -1,
     123,    81,    -1,    13,    71,   123,    72,   157,    -1,   147,
      11,   147,    -1,   147,    -1,   123,    -1,   136,    44,    80,
     145,    -1,    -1,    35,    71,   160,   158,    72,   152,    -1,
      -1,    10,   161,   147,    35,    71,   123,    72,    81,    -1,
      -1,    12,    71,   162,   163,   165,    72,   152,    -1,   155,
      -1,   146,    -1,   158,    -1,    -1,   164,    81,    -1,   164,
      81,   123,    -1,     9,    81,    -1,     8,    81,    -1,    15,
      81,    -1,    15,   123,    81,    -1,    14,    81,    -1,   168,
      -1,   167,   168,    -1,   169,    -1,   125,    -1,    -1,   126,
     170,   153,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   214,   214,   249,   252,   265,   270,   275,   281,   284,
     357,   360,   469,   479,   492,   500,   606,   609,   631,   635,
     642,   646,   653,   659,   668,   676,   740,   747,   757,   760,
     770,   780,   802,   803,   804,   805,   811,   812,   821,   830,
     842,   843,   851,   862,   863,   872,   884,   885,   895,   905,
     915,   928,   929,   940,   954,   955,   967,   968,   980,   981,
     993,   994,  1007,  1008,  1021,  1022,  1035,  1036,  1053,  1054,
    1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1082,  1085,  1096,  1104,  1105,  1113,  1149,  1152,  1159,
    1167,  1188,  1207,  1218,  1247,  1252,  1262,  1267,  1277,  1280,
    1283,  1286,  1292,  1299,  1302,  1313,  1331,  1352,  1385,  1421,
    1444,  1448,  1461,  1480,  1503,  1538,  1577,  1668,  1678,  1704,
    1707,  1713,  1721,  1729,  1732,  1747,  1751,  1755,  1759,  1768,
    1773,  1778,  1783,  1788,  1793,  1798,  1803,  1808,  1813,  1819,
    1825,  1831,  1836,  1841,  1846,  1851,  1856,  1861,  1871,  1881,
    1886,  1899,  1909,  1917,  1920,  1935,  1961,  1965,  1971,  1976,
    1989,  1993,  1997,  1998,  2004,  2005,  2006,  2007,  2008,  2012,
    2013,  2013,  2013,  2021,  2022,  2027,  2030,  2038,  2041,  2047,
    2048,  2052,  2060,  2064,  2074,  2079,  2096,  2096,  2101,  2101,
    2108,  2108,  2121,  2124,  2130,  2133,  2139,  2143,  2150,  2157,
    2164,  2171,  2182,  2191,  2195,  2202,  2205,  2211,  2211
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTE", "CONST_QUAL", "BOOL_TYPE",
  "FLOAT_TYPE", "INT_TYPE", "BREAK", "CONTINUE", "DO", "ELSE", "FOR", "IF",
  "DISCARD", "RETURN", "BVEC2", "BVEC3", "BVEC4", "IVEC2", "IVEC3",
  "IVEC4", "VEC2", "VEC3", "VEC4", "MATRIX2", "MATRIX3", "MATRIX4",
  "IN_QUAL", "OUT_QUAL", "INOUT_QUAL", "UNIFORM", "VARYING", "STRUCT",
  "VOID_TYPE", "WHILE", "SAMPLER1D", "SAMPLER2D", "SAMPLER3D",
  "SAMPLERCUBE", "SAMPLER1DSHADOW", "SAMPLER2DSHADOW", "SAMPLERRECTARB",
  "SAMPLERRECTSHADOWARB", "IDENTIFIER", "TYPE_NAME", "FLOATCONSTANT",
  "INTCONSTANT", "BOOLCONSTANT", "FIELD_SELECTION", "LEFT_OP", "RIGHT_OP",
  "INC_OP", "DEC_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "XOR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "ADD_ASSIGN",
  "MOD_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "SUB_ASSIGN", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET",
  "RIGHT_BRACKET", "LEFT_BRACE", "RIGHT_BRACE", "DOT", "COMMA", "COLON",
  "EQUAL", "SEMICOLON", "BANG", "DASH", "TILDE", "PLUS", "STAR", "SLASH",
  "PERCENT", "LEFT_ANGLE", "RIGHT_ANGLE", "VERTICAL_BAR", "CARET",
  "AMPERSAND", "QUESTION", "$accept", "variable_identifier",
  "primary_expression", "postfix_expression", "integer_expression",
  "function_call", "function_call_or_method", "function_call_generic",
  "function_call_header_no_parameters",
  "function_call_header_with_parameters", "function_call_header",
  "function_identifier", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_xor_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "function_prototype",
  "function_declarator", "function_header_with_parameters",
  "function_header", "parameter_declarator", "parameter_declaration",
  "parameter_qualifier", "parameter_type_specifier",
  "init_declarator_list", "single_declaration", "fully_specified_type",
  "type_qualifier", "type_specifier", "type_specifier_nonarray",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "initializer",
  "declaration_statement", "statement", "simple_statement",
  "compound_statement", "$@1", "$@2", "statement_no_new_scope",
  "compound_statement_no_new_scope", "statement_list",
  "expression_statement", "selection_statement",
  "selection_rest_statement", "condition", "iteration_statement", "$@3",
  "$@4", "$@5", "for_init_statement", "conditionopt", "for_rest_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "$@6", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    97,    97,    97,    97,    97,    98,    98,
      98,    98,    98,    98,    99,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   106,   106,   106,   107,   107,
     107,   107,   108,   108,   108,   108,   109,   109,   109,   109,
     110,   110,   110,   111,   111,   111,   112,   112,   112,   112,
     112,   113,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   117,   118,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   123,   123,   124,   125,   125,   126,   127,   127,   128,
     128,   129,   130,   130,   131,   131,   131,   131,   132,   132,
     132,   132,   133,   134,   134,   134,   134,   134,   134,   134,
     135,   135,   135,   135,   135,   135,   135,   136,   136,   137,
     137,   137,   137,   138,   138,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   140,   140,   141,   141,   142,   143,   143,   144,   144,
     145,   146,   147,   147,   148,   148,   148,   148,   148,   149,
     150,   151,   149,   152,   152,   153,   153,   154,   154,   155,
     155,   156,   157,   157,   158,   158,   160,   159,   161,   159,
     162,   159,   163,   163,   164,   164,   165,   165,   166,   166,
     166,   166,   166,   167,   167,   168,   168,   170,   169
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       1,     3,     2,     2,     1,     1,     1,     3,     2,     2,
       2,     1,     2,     3,     2,     1,     1,     1,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     2,     2,     1,     1,     2,
       3,     3,     2,     5,     3,     2,     3,     2,     0,     1,
       1,     1,     1,     1,     3,     5,     6,     7,     8,     5,
       1,     2,     4,     5,     6,     7,     4,     1,     2,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     4,     1,     2,     3,     1,     3,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     0,     5,     1,     1,     2,     3,     1,     2,     1,
       2,     5,     3,     1,     1,     4,     0,     6,     0,     8,
       0,     7,     1,     1,     1,     0,     2,     3,     2,     2,
       2,     3,     2,     1,     2,     1,     1,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   120,   119,   128,   126,   127,   132,   133,   134,   135,
     136,   137,   129,   130,   131,   138,   139,   140,   122,   121,
       0,   125,   141,   142,   143,   144,   145,   146,   147,   148,
     150,   206,   207,     0,    88,    98,     0,   103,   110,     0,
     117,   123,   149,     0,   203,   205,     0,     0,    84,     0,
      86,    98,    99,   100,   101,    89,     0,    98,     0,    85,
     111,   118,     0,     1,   204,     0,     0,     0,   153,     0,
     208,    90,    95,    97,   102,     0,   104,    91,     0,     0,
       2,     5,     4,     6,    27,     0,     0,     0,    34,    33,
      35,    32,     3,     8,    28,    10,    15,    16,     0,     0,
      21,     0,    36,     0,    40,    43,    46,    51,    54,    56,
      58,    60,    62,    64,    66,    83,     0,    25,     0,   158,
       0,   156,   152,   154,     0,     0,   188,     0,     0,     0,
       0,     0,   170,   175,   179,    36,    68,    81,     0,   161,
       0,   117,   164,   177,   163,   162,     0,   165,   166,   167,
     168,    92,    94,    96,     0,     0,   112,     0,   160,   116,
      29,    30,     0,    12,    13,     0,     0,    19,    18,     0,
     125,    22,    24,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   151,     0,     0,   155,   199,
     198,     0,   190,     0,   202,   200,     0,   186,   169,     0,
      71,    72,    74,    73,    76,    77,    78,    79,    80,    75,
      70,     0,     0,   180,   176,   178,     0,   105,     0,   109,
       0,   113,     7,     0,    14,    26,    11,    17,    23,    37,
      38,    39,    42,    41,    44,    45,    49,    50,    47,    48,
      52,    53,    55,    57,    59,    61,    63,    65,     0,     0,
     157,     0,     0,     0,   201,     0,   171,    69,    82,     0,
       0,   106,   114,     0,     9,     0,   159,     0,   193,   192,
     195,     0,   184,     0,     0,     0,    93,   107,     0,   115,
      67,     0,   194,     0,     0,   183,   181,     0,     0,   172,
     108,     0,   196,     0,     0,     0,   174,   187,   173,     0,
     197,   191,   182,   185,   189
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    92,    93,    94,   233,    95,    96,    97,    98,    99,
     100,   101,   135,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   136,   137,   221,   138,   116,
     139,   140,    33,    34,    35,    72,    55,    56,    73,    36,
      37,    38,    39,   117,    41,    42,    67,    68,   120,   121,
     159,   142,   143,   144,   145,   209,   285,   307,   308,   146,
     147,   148,   296,   284,   149,   265,   201,   262,   280,   293,
     294,   150,    43,    44,    45,    49
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -287
static const yytype_int16 yypact[] =
{
    1248,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,
     -34,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,
    -287,  -287,   -67,   -42,   -12,    23,    -7,  -287,    29,  1289,
    -287,    21,  -287,  1160,  -287,  -287,    33,  1289,  -287,    37,
    -287,    30,  -287,  -287,  -287,  -287,  1289,    74,    52,  -287,
      -1,  -287,   974,  -287,  -287,  1289,    96,   214,  -287,   302,
    -287,  -287,  -287,  -287,   103,  1289,   -62,  -287,   764,   974,
      80,  -287,  -287,  -287,  -287,   974,   974,   974,  -287,  -287,
    -287,  -287,  -287,  -287,   -37,  -287,  -287,  -287,    84,   -59,
    1044,    88,  -287,   974,    19,    28,   -13,   -26,    58,    68,
      70,    72,   106,   105,   -50,  -287,    92,  -287,  1114,    94,
      11,  -287,  -287,  -287,    89,    93,  -287,   102,   104,    95,
     834,   107,   101,  -287,  -287,   206,  -287,  -287,    12,  -287,
     -67,   108,  -287,  -287,  -287,  -287,   385,  -287,  -287,  -287,
    -287,   109,  -287,  -287,   904,   974,   100,   110,  -287,  -287,
    -287,  -287,   -30,  -287,  -287,   974,  1201,  -287,  -287,   974,
     114,  -287,  -287,  -287,   974,   974,   974,   974,   974,   974,
     974,   974,   974,   974,   974,   974,   974,   974,   974,   974,
     974,   974,   974,   974,  -287,  -287,   974,    96,  -287,  -287,
    -287,   468,  -287,   974,  -287,  -287,    20,  -287,  -287,   468,
    -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,
    -287,   974,   974,  -287,  -287,  -287,   974,   111,   113,  -287,
     974,   118,  -287,   115,   112,  -287,   117,  -287,  -287,  -287,
    -287,  -287,    19,    19,    28,    28,   -13,   -13,   -13,   -13,
     -26,   -26,    58,    68,    70,    72,   106,   105,    38,   119,
    -287,   159,   624,     4,  -287,   694,   468,  -287,  -287,   125,
     974,   120,  -287,   974,  -287,   974,  -287,   131,  -287,  -287,
     694,   468,   112,   160,   133,   127,  -287,  -287,   974,  -287,
    -287,   974,  -287,   130,   134,   197,  -287,   132,   551,  -287,
    -287,     6,   974,   551,   468,   974,  -287,  -287,  -287,   135,
     112,  -287,  -287,  -287,  -287
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -287,  -287,  -287,  -287,  -287,  -287,  -287,    47,  -287,  -287,
    -287,  -287,   -54,  -287,   -29,   -25,   -96,   -28,    27,    34,
      26,    35,    32,    25,  -287,   -57,   -78,  -287,   -84,   -55,
       2,     7,  -287,  -287,  -287,   149,   175,   171,   154,  -287,
    -287,  -197,   -31,     0,  -287,  -287,   177,   -61,  -287,    46,
    -120,   -18,  -121,  -286,  -287,  -287,  -287,   -58,   200,    49,
     -16,  -287,  -287,   -20,  -287,  -287,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,   218,  -287,  -287
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -88
static const yytype_int16 yytable[] =
{
      40,   158,    31,   162,    57,   115,   123,    32,   102,   192,
      46,   154,   306,   168,    48,   163,   164,   306,   155,   169,
      57,   115,   171,   157,   102,   225,     1,     2,   181,   182,
      50,   160,   161,     1,     2,   229,   165,   179,   180,    61,
     166,    47,   232,    40,   193,    31,   206,    66,   222,   173,
      32,    52,    53,    54,    18,    19,    74,   123,    52,    53,
      54,    18,    19,   183,   184,    66,    51,    66,   283,   141,
      77,    58,    78,    60,    59,    74,   281,   158,   309,    79,
     261,   234,   222,   283,   222,   246,   247,   248,   249,   197,
     222,   238,   198,   223,    62,   -87,    76,   115,   222,   228,
     102,   264,    52,    53,    54,   174,   175,   176,    65,   258,
     272,   177,    69,   178,   185,   186,   222,   275,    66,   263,
     239,   240,   241,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   115,
     119,   259,   102,   267,   268,   225,   141,   151,   242,   243,
     287,   -26,   158,   289,   244,   245,   167,   250,   251,   172,
     295,   187,   188,   189,   190,   191,   194,   196,   300,   115,
     199,   269,   102,   202,   200,   203,   204,   208,   207,   -25,
     230,   282,   226,   312,   231,   313,   -20,   271,   -27,   274,
     222,   270,   158,   276,   277,   158,   282,   290,   273,   286,
     288,   141,   291,   299,   297,   298,   303,   301,   304,   141,
     158,   302,   305,   237,   252,   254,   314,   257,   310,     3,
       4,     5,   253,   256,   152,   255,    71,   158,    75,   153,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,   118,   260,   278,   311,   279,    20,    21,    70,
      22,    23,    24,    25,    26,    27,    28,    29,   266,    30,
     292,    64,   141,     0,     0,   141,   141,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
     141,   141,     0,     0,     0,     0,   220,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,   141,     0,
       0,     0,     0,   141,   141,     1,     2,     3,     4,     5,
     124,   125,   126,     0,   127,   128,   129,   130,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,     0,     0,    18,    19,    20,    21,   131,    22,    23,
      24,    25,    26,    27,    28,    29,    80,    30,    81,    82,
      83,    84,     0,     0,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,     0,     0,   132,   133,     0,
       0,     0,     0,   134,    88,    89,    90,    91,     1,     2,
       3,     4,     5,   124,   125,   126,     0,   127,   128,   129,
     130,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     0,     0,     0,    18,    19,    20,    21,
     131,    22,    23,    24,    25,    26,    27,    28,    29,    80,
      30,    81,    82,    83,    84,     0,     0,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,     0,     0,     0,
     132,   224,     0,     0,     0,     0,   134,    88,    89,    90,
      91,     1,     2,     3,     4,     5,   124,   125,   126,     0,
     127,   128,   129,   130,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     0,     0,     0,    18,
      19,    20,    21,   131,    22,    23,    24,    25,    26,    27,
      28,    29,    80,    30,    81,    82,    83,    84,     0,     0,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,   132,     0,     0,     0,     0,     0,   134,
      88,    89,    90,    91,     1,     2,     3,     4,     5,   124,
     125,   126,     0,   127,   128,   129,   130,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
       0,     0,    18,    19,    20,    21,   131,    22,    23,    24,
      25,    26,    27,    28,    29,    80,    30,    81,    82,    83,
      84,     0,     0,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,    69,     1,     2,     3,
       4,     5,   134,    88,    89,    90,    91,     0,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,    18,    19,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    80,    30,
      81,    82,    83,    84,     0,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     1,     2,     3,
       4,     5,     0,     0,     0,   134,    88,    89,    90,    91,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,    18,    19,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    80,    30,
      81,    82,    83,    84,     0,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     3,
       4,     5,     0,     0,     0,     0,    88,    89,    90,    91,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,     0,     0,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    80,    30,
      81,    82,    83,    84,     0,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,   156,     3,
       4,     5,     0,     0,     0,     0,    88,    89,    90,    91,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,     0,     0,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    80,    30,
      81,    82,    83,    84,     0,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     3,
       4,     5,     0,     0,     0,   205,    88,    89,    90,    91,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,     0,     0,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    80,    30,
      81,    82,    83,    84,     0,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,   227,     3,
       4,     5,     0,     0,     0,     0,    88,    89,    90,    91,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,     0,     0,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    80,    30,
      81,    82,    83,    84,     0,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     3,
       4,     5,     0,     0,     0,     0,    88,    89,    90,    91,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,     0,     0,    20,   170,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    80,    30,
      81,    82,    83,    84,     0,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     3,
       4,     5,     0,     0,     0,     0,    88,    89,    90,    91,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,     0,     0,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    28,    29,     0,    30,
      63,     0,     0,     1,     2,     3,     4,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     0,     0,
     195,    18,    19,    20,    21,     0,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
       0,     0,     0,     0,    20,    21,     0,    22,    23,    24,
      25,    26,    27,    28,    29,   235,    30,     0,     0,     0,
     236,     1,     2,     3,     4,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     0,     0,     0,    18,
      19,    20,    21,     0,    22,    23,    24,    25,    26,    27,
      28,    29,     0,    30,     3,     4,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     0,     0,     0,
       0,     0,    20,    21,     0,    22,    23,    24,    25,    26,
      27,    28,    29,     0,    30
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-287))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    79,     0,    87,    35,    62,    67,     0,    62,    59,
      44,    73,   298,    72,    81,    52,    53,   303,    80,    78,
      51,    78,   100,    78,    78,   146,     3,     4,    54,    55,
      72,    85,    86,     3,     4,   155,    73,    50,    51,    39,
      77,    75,    72,    43,    94,    43,   130,    47,    78,   103,
      43,    28,    29,    30,    31,    32,    56,   118,    28,    29,
      30,    31,    32,    89,    90,    65,    78,    67,   265,    69,
      71,    78,    73,    44,    81,    75,    72,   155,    72,    80,
     201,   165,    78,   280,    78,   181,   182,   183,   184,    78,
      78,   169,    81,    81,    73,    72,    44,   154,    78,   154,
     154,    81,    28,    29,    30,    86,    87,    88,    75,   193,
     230,    83,    75,    85,    56,    57,    78,    79,   118,   203,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   196,
      44,   196,   196,   221,   222,   266,   146,    44,   177,   178,
     270,    71,   230,   273,   179,   180,    72,   185,   186,    71,
     281,    93,    92,    91,    58,    60,    74,    73,   288,   226,
      81,   226,   226,    71,    81,    71,    81,    76,    71,    71,
      80,   265,    73,   304,    74,   305,    72,    74,    71,    74,
      78,    80,   270,    74,    35,   273,   280,   275,    80,    74,
      80,   201,    71,    76,    44,    72,    72,   291,    11,   209,
     288,    81,    80,   166,   187,   189,    81,   192,   302,     5,
       6,     7,   188,   191,    75,   190,    51,   305,    57,    75,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    65,   197,   262,   303,   262,    33,    34,    49,
      36,    37,    38,    39,    40,    41,    42,    43,   209,    45,
     280,    43,   262,    -1,    -1,   265,   266,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
     280,   281,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   298,    -1,
      -1,    -1,    -1,   303,   304,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    75,    76,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    85,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    75,     3,     4,     5,
       6,     7,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,     5,
       6,     7,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,     5,
       6,     7,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,     5,
       6,     7,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,     5,
       6,     7,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,     5,
       6,     7,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,     5,
       6,     7,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    45,
       0,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      76,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    45,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      49,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    45,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    31,    32,
      33,    34,    36,    37,    38,    39,    40,    41,    42,    43,
      45,   125,   126,   127,   128,   129,   134,   135,   136,   137,
     138,   139,   140,   167,   168,   169,    44,    75,    81,   170,
      72,    78,    28,    29,    30,   131,   132,   137,    78,    81,
      44,   138,    73,     0,   168,    75,   138,   141,   142,    75,
     153,   131,   130,   133,   138,   132,    44,    71,    73,    80,
      44,    46,    47,    48,    49,    52,    53,    71,    82,    83,
      84,    85,    96,    97,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   124,   138,   141,    44,
     143,   144,    76,   142,     8,     9,    10,    12,    13,    14,
      15,    35,    75,    76,    81,   107,   120,   121,   123,   125,
     126,   138,   146,   147,   148,   149,   154,   155,   156,   159,
     166,    44,   130,   133,    73,    80,    74,   124,   121,   145,
     107,   107,   123,    52,    53,    73,    77,    72,    72,    78,
      34,   121,    71,   107,    86,    87,    88,    83,    85,    50,
      51,    54,    55,    89,    90,    56,    57,    93,    92,    91,
      58,    60,    59,    94,    74,    76,    73,    78,    81,    81,
      81,   161,    71,    71,    81,    81,   123,    71,    76,   150,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      80,   122,    78,    81,    76,   147,    73,    74,   124,   145,
      80,    74,    72,    99,   123,    44,    49,   102,   121,   107,
     107,   107,   109,   109,   110,   110,   111,   111,   111,   111,
     112,   112,   113,   114,   115,   116,   117,   118,   123,   124,
     144,   147,   162,   123,    81,   160,   154,   121,   121,   124,
      80,    74,   145,    80,    74,    79,    74,    35,   146,   155,
     163,    72,   123,   136,   158,   151,    74,   145,    80,   145,
     121,    71,   158,   164,   165,   147,   157,    44,    72,    76,
     145,   123,    81,    72,    11,    80,   148,   152,   153,    72,
     123,   152,   147,   145,    81
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 214 "glslang.y"
    {
        // The symbol table search was done in the lexical phase
        const TSymbol* symbol = (yyvsp[(1) - (1)].lex).symbol;
        const TVariable* variable;
        if (symbol == 0) {
            parseContext.error((yyvsp[(1) - (1)].lex).line, "undeclared identifier", (yyvsp[(1) - (1)].lex).string->c_str(), "");
            parseContext.recover();
            TType type(EbtFloat);
            TVariable* fakeVariable = new TVariable((yyvsp[(1) - (1)].lex).string, type);
            parseContext.symbolTable.insert(*fakeVariable);
            variable = fakeVariable;
        } else {
            // This identifier can only be a variable type symbol 
            if (! symbol->isVariable()) {
                parseContext.error((yyvsp[(1) - (1)].lex).line, "variable expected", (yyvsp[(1) - (1)].lex).string->c_str(), "");
                parseContext.recover();
            }
            variable = static_cast<const TVariable*>(symbol);
        }

        // don't delete $1.string, it's used by error recovery, and the pool
        // pop will reclaim the memory

        if (variable->getType().getQualifier() == EvqConst ) {
            constUnion* constArray = variable->getConstPointer();
            TType t(variable->getType());
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(constArray, t, (yyvsp[(1) - (1)].lex).line);        
        } else
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addSymbol(variable->getUniqueId(), 
                                                     variable->getName(), 
                                                     variable->getType(), (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 249 "glslang.y"
    {
        (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode);
    }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 252 "glslang.y"
    {
        //
        // INT_TYPE is only 16-bit plus sign bit for vertex/fragment shaders, 
        // check for overflow for constants
        //
        if (abs((yyvsp[(1) - (1)].lex).i) >= (1 << 16)) {
            parseContext.error((yyvsp[(1) - (1)].lex).line, " integer constant overflow", "", "");
            parseContext.recover();
        }
        constUnion *unionArray = new constUnion[1];
        unionArray->setIConst((yyvsp[(1) - (1)].lex).i);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtInt, EvqConst), (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 265 "glslang.y"
    {
        constUnion *unionArray = new constUnion[1];
        unionArray->setFConst((yyvsp[(1) - (1)].lex).f);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtFloat, EvqConst), (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 270 "glslang.y"
    {
        constUnion *unionArray = new constUnion[1];
        unionArray->setBConst((yyvsp[(1) - (1)].lex).b);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtBool, EvqConst), (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 275 "glslang.y"
    {
        (yyval.interm.intermTypedNode) = (yyvsp[(2) - (3)].interm.intermTypedNode);
    }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 281 "glslang.y"
    { 
        (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode);
    }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 284 "glslang.y"
    {
        if (!(yyvsp[(1) - (4)].interm.intermTypedNode)->isArray() && !(yyvsp[(1) - (4)].interm.intermTypedNode)->isMatrix() && !(yyvsp[(1) - (4)].interm.intermTypedNode)->isVector()) {
            if ((yyvsp[(1) - (4)].interm.intermTypedNode)->getAsSymbolNode())
                parseContext.error((yyvsp[(2) - (4)].lex).line, " left of '[' is not of type array, matrix, or vector ", (yyvsp[(1) - (4)].interm.intermTypedNode)->getAsSymbolNode()->getSymbol().c_str(), "");
            else
                parseContext.error((yyvsp[(2) - (4)].lex).line, " left of '[' is not of type array, matrix, or vector ", "expression", "");
            parseContext.recover();
        }
        if ((yyvsp[(1) - (4)].interm.intermTypedNode)->getType().getQualifier() == EvqConst && (yyvsp[(3) - (4)].interm.intermTypedNode)->getQualifier() == EvqConst) {
            if ((yyvsp[(1) - (4)].interm.intermTypedNode)->isArray()) { // constant folding for arrays
                (yyval.interm.intermTypedNode) = parseContext.addConstArrayNode((yyvsp[(3) - (4)].interm.intermTypedNode)->getAsConstantUnion()->getUnionArrayPointer()->getIConst(), (yyvsp[(1) - (4)].interm.intermTypedNode), (yyvsp[(2) - (4)].lex).line);
            } else if ((yyvsp[(1) - (4)].interm.intermTypedNode)->isVector()) {  // constant folding for vectors
                TVectorFields fields;                
                fields.num = 1;
                fields.offsets[0] = (yyvsp[(3) - (4)].interm.intermTypedNode)->getAsConstantUnion()->getUnionArrayPointer()->getIConst(); // need to do it this way because v.xy sends fields integer array
                (yyval.interm.intermTypedNode) = parseContext.addConstVectorNode(fields, (yyvsp[(1) - (4)].interm.intermTypedNode), (yyvsp[(2) - (4)].lex).line);
            } else if ((yyvsp[(1) - (4)].interm.intermTypedNode)->isMatrix()) { // constant folding for matrices
                (yyval.interm.intermTypedNode) = parseContext.addConstMatrixNode((yyvsp[(3) - (4)].interm.intermTypedNode)->getAsConstantUnion()->getUnionArrayPointer()->getIConst(), (yyvsp[(1) - (4)].interm.intermTypedNode), (yyvsp[(2) - (4)].lex).line);
            } 
        } else {
            if ((yyvsp[(3) - (4)].interm.intermTypedNode)->getQualifier() == EvqConst) {
                if (((yyvsp[(1) - (4)].interm.intermTypedNode)->isVector() || (yyvsp[(1) - (4)].interm.intermTypedNode)->isMatrix()) && (yyvsp[(1) - (4)].interm.intermTypedNode)->getType().getNominalSize() <= (yyvsp[(3) - (4)].interm.intermTypedNode)->getAsConstantUnion()->getUnionArrayPointer()->getIConst() && !(yyvsp[(1) - (4)].interm.intermTypedNode)->isArray() ) {
                    parseContext.error((yyvsp[(2) - (4)].lex).line, "", "[", "field selection out of range '%d'", (yyvsp[(3) - (4)].interm.intermTypedNode)->getAsConstantUnion()->getUnionArrayPointer()->getIConst());
                    parseContext.recover();
                } else {
                    if ((yyvsp[(1) - (4)].interm.intermTypedNode)->isArray()) {
                        if ((yyvsp[(1) - (4)].interm.intermTypedNode)->getType().getArraySize() == 0) {
                            if ((yyvsp[(1) - (4)].interm.intermTypedNode)->getType().getMaxArraySize() <= (yyvsp[(3) - (4)].interm.intermTypedNode)->getAsConstantUnion()->getUnionArrayPointer()->getIConst()) {
                                if (parseContext.arraySetMaxSize((yyvsp[(1) - (4)].interm.intermTypedNode)->getAsSymbolNode(), (yyvsp[(1) - (4)].interm.intermTypedNode)->getTypePointer(), (yyvsp[(3) - (4)].interm.intermTypedNode)->getAsConstantUnion()->getUnionArrayPointer()->getIConst(), true, (yyvsp[(2) - (4)].lex).line))
                                    parseContext.recover(); 
                            } else {
                                if (parseContext.arraySetMaxSize((yyvsp[(1) - (4)].interm.intermTypedNode)->getAsSymbolNode(), (yyvsp[(1) - (4)].interm.intermTypedNode)->getTypePointer(), 0, false, (yyvsp[(2) - (4)].lex).line))
                                    parseContext.recover(); 
                            }
                        } else if ( (yyvsp[(3) - (4)].interm.intermTypedNode)->getAsConstantUnion()->getUnionArrayPointer()->getIConst() >= (yyvsp[(1) - (4)].interm.intermTypedNode)->getType().getArraySize()) {
                            parseContext.error((yyvsp[(2) - (4)].lex).line, "", "[", "array index out of range '%d'", (yyvsp[(3) - (4)].interm.intermTypedNode)->getAsConstantUnion()->getUnionArrayPointer()->getIConst());
                            parseContext.recover();
                        }
                    }
                    (yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpIndexDirect, (yyvsp[(1) - (4)].interm.intermTypedNode), (yyvsp[(3) - (4)].interm.intermTypedNode), (yyvsp[(2) - (4)].lex).line);
                }
            } else {
                if ((yyvsp[(1) - (4)].interm.intermTypedNode)->isArray() && (yyvsp[(1) - (4)].interm.intermTypedNode)->getType().getArraySize() == 0) {
                    parseContext.error((yyvsp[(2) - (4)].lex).line, "", "[", "array must be redeclared with a size before being indexed with a variable");
                    parseContext.recover();
                }
                
                (yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpIndexIndirect, (yyvsp[(1) - (4)].interm.intermTypedNode), (yyvsp[(3) - (4)].interm.intermTypedNode), (yyvsp[(2) - (4)].lex).line);
            }
        } 
        if ((yyval.interm.intermTypedNode) == 0) {
            constUnion *unionArray = new constUnion[1];
            unionArray->setFConst(0.0f);
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtFloat, EvqConst), (yyvsp[(2) - (4)].lex).line);
        } else if ((yyvsp[(1) - (4)].interm.intermTypedNode)->isArray()) {
            if ((yyvsp[(1) - (4)].interm.intermTypedNode)->getType().getStruct())
                (yyval.interm.intermTypedNode)->setType(TType((yyvsp[(1) - (4)].interm.intermTypedNode)->getType().getStruct(), (yyvsp[(1) - (4)].interm.intermTypedNode)->getType().getTypeName()));
            else
                (yyval.interm.intermTypedNode)->setType(TType((yyvsp[(1) - (4)].interm.intermTypedNode)->getBasicType(), EvqTemporary, (yyvsp[(1) - (4)].interm.intermTypedNode)->getNominalSize(), (yyvsp[(1) - (4)].interm.intermTypedNode)->isMatrix()));
                
            if ((yyvsp[(1) - (4)].interm.intermTypedNode)->getType().getQualifier() == EvqConst)
                (yyval.interm.intermTypedNode)->getTypePointer()->changeQualifier(EvqConst);
        } else if ((yyvsp[(1) - (4)].interm.intermTypedNode)->isMatrix() && (yyvsp[(1) - (4)].interm.intermTypedNode)->getType().getQualifier() == EvqConst)         
            (yyval.interm.intermTypedNode)->setType(TType((yyvsp[(1) - (4)].interm.intermTypedNode)->getBasicType(), EvqConst, (yyvsp[(1) - (4)].interm.intermTypedNode)->getNominalSize()));     
        else if ((yyvsp[(1) - (4)].interm.intermTypedNode)->isMatrix())            
            (yyval.interm.intermTypedNode)->setType(TType((yyvsp[(1) - (4)].interm.intermTypedNode)->getBasicType(), EvqTemporary, (yyvsp[(1) - (4)].interm.intermTypedNode)->getNominalSize()));     
        else if ((yyvsp[(1) - (4)].interm.intermTypedNode)->isVector() && (yyvsp[(1) - (4)].interm.intermTypedNode)->getType().getQualifier() == EvqConst)          
            (yyval.interm.intermTypedNode)->setType(TType((yyvsp[(1) - (4)].interm.intermTypedNode)->getBasicType(), EvqConst));     
        else if ((yyvsp[(1) - (4)].interm.intermTypedNode)->isVector())       
            (yyval.interm.intermTypedNode)->setType(TType((yyvsp[(1) - (4)].interm.intermTypedNode)->getBasicType(), EvqTemporary));
        else
            (yyval.interm.intermTypedNode)->setType((yyvsp[(1) - (4)].interm.intermTypedNode)->getType()); 
    }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 357 "glslang.y"
    {
        (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode);
    }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 360 "glslang.y"
    {        
        if ((yyvsp[(1) - (3)].interm.intermTypedNode)->isArray()) {
            parseContext.error((yyvsp[(3) - (3)].lex).line, "cannot apply dot operator to an array", ".", "");
            parseContext.recover();
        }

        if ((yyvsp[(1) - (3)].interm.intermTypedNode)->isVector()) {
            TVectorFields fields;
            if (! parseContext.parseVectorFields(*(yyvsp[(3) - (3)].lex).string, (yyvsp[(1) - (3)].interm.intermTypedNode)->getNominalSize(), fields, (yyvsp[(3) - (3)].lex).line)) {
                fields.num = 1;
                fields.offsets[0] = 0;
                parseContext.recover();
            }

            if ((yyvsp[(1) - (3)].interm.intermTypedNode)->getType().getQualifier() == EvqConst) { // constant folding for vector fields
                (yyval.interm.intermTypedNode) = parseContext.addConstVectorNode(fields, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].lex).line);
                if ((yyval.interm.intermTypedNode) == 0) {
                    parseContext.recover();
                    (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
                }
                else
                    (yyval.interm.intermTypedNode)->setType(TType((yyvsp[(1) - (3)].interm.intermTypedNode)->getBasicType(), EvqConst, (int) (*(yyvsp[(3) - (3)].lex).string).size()));
            } else {
                if (fields.num == 1) {
                    constUnion *unionArray = new constUnion[1];
                    unionArray->setIConst(fields.offsets[0]);
                    TIntermTyped* index = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtInt, EvqConst), (yyvsp[(3) - (3)].lex).line);
                    (yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpIndexDirect, (yyvsp[(1) - (3)].interm.intermTypedNode), index, (yyvsp[(2) - (3)].lex).line);
                    (yyval.interm.intermTypedNode)->setType(TType((yyvsp[(1) - (3)].interm.intermTypedNode)->getBasicType()));
                } else {
                    TString vectorString = *(yyvsp[(3) - (3)].lex).string;
                    TIntermTyped* index = parseContext.intermediate.addSwizzle(fields, (yyvsp[(3) - (3)].lex).line);                
                    (yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpVectorSwizzle, (yyvsp[(1) - (3)].interm.intermTypedNode), index, (yyvsp[(2) - (3)].lex).line);
                    (yyval.interm.intermTypedNode)->setType(TType((yyvsp[(1) - (3)].interm.intermTypedNode)->getBasicType(),EvqTemporary, (int) vectorString.size()));  
                }
            }
        } else if ((yyvsp[(1) - (3)].interm.intermTypedNode)->isMatrix()) {
            TMatrixFields fields;
            if (! parseContext.parseMatrixFields(*(yyvsp[(3) - (3)].lex).string, (yyvsp[(1) - (3)].interm.intermTypedNode)->getNominalSize(), fields, (yyvsp[(3) - (3)].lex).line)) {
                fields.wholeRow = false;
                fields.wholeCol = false;
                fields.row = 0;
                fields.col = 0;
                parseContext.recover();
            }

            if (fields.wholeRow || fields.wholeCol) {
                parseContext.error((yyvsp[(2) - (3)].lex).line, " non-scalar fields not implemented yet", ".", "");
                parseContext.recover();
                constUnion *unionArray = new constUnion[1];
                unionArray->setIConst(0);
                TIntermTyped* index = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtInt, EvqConst), (yyvsp[(3) - (3)].lex).line);
                (yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpIndexDirect, (yyvsp[(1) - (3)].interm.intermTypedNode), index, (yyvsp[(2) - (3)].lex).line);                
                (yyval.interm.intermTypedNode)->setType(TType((yyvsp[(1) - (3)].interm.intermTypedNode)->getBasicType(), EvqTemporary, (yyvsp[(1) - (3)].interm.intermTypedNode)->getNominalSize()));
            } else {
                constUnion *unionArray = new constUnion[1];
                unionArray->setIConst(fields.col * (yyvsp[(1) - (3)].interm.intermTypedNode)->getNominalSize() + fields.row);
                TIntermTyped* index = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtInt, EvqConst), (yyvsp[(3) - (3)].lex).line);
                (yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpIndexDirect, (yyvsp[(1) - (3)].interm.intermTypedNode), index, (yyvsp[(2) - (3)].lex).line);                
                (yyval.interm.intermTypedNode)->setType(TType((yyvsp[(1) - (3)].interm.intermTypedNode)->getBasicType()));
            }
        } else if ((yyvsp[(1) - (3)].interm.intermTypedNode)->getBasicType() == EbtStruct) {
            bool fieldFound = false;
            TTypeList* fields = (yyvsp[(1) - (3)].interm.intermTypedNode)->getType().getStruct();
            if (fields == 0) {
                parseContext.error((yyvsp[(2) - (3)].lex).line, "structure has no fields", "Internal Error", "");
                parseContext.recover();
                (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
            } else {
                unsigned int i;
                for (i = 0; i < fields->size(); ++i) {
                    if ((*fields)[i].type->getFieldName() == *(yyvsp[(3) - (3)].lex).string) {
                        fieldFound = true;
                        break;
                    }                
                }
                if (fieldFound) {
                    if ((yyvsp[(1) - (3)].interm.intermTypedNode)->getType().getQualifier() == EvqConst) {
                        (yyval.interm.intermTypedNode) = parseContext.addConstStruct(*(yyvsp[(3) - (3)].lex).string, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line);
                        if ((yyval.interm.intermTypedNode) == 0) {
                            parseContext.recover();
                            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
                        }
                        else {
                            (yyval.interm.intermTypedNode)->setType(*(*fields)[i].type);
                            // change the qualifier of the return type, not of the structure field
                            // as the structure definition is shared between various structures.
                            (yyval.interm.intermTypedNode)->getTypePointer()->changeQualifier(EvqConst);
                        }
                    } else {
                        constUnion *unionArray = new constUnion[1];
                        unionArray->setIConst(i);
                        TIntermTyped* index = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtInt, EvqConst), (yyvsp[(3) - (3)].lex).line);
                        (yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpIndexDirectStruct, (yyvsp[(1) - (3)].interm.intermTypedNode), index, (yyvsp[(2) - (3)].lex).line);                
                        (yyval.interm.intermTypedNode)->setType(*(*fields)[i].type);
                    }
                } else {
                    parseContext.error((yyvsp[(2) - (3)].lex).line, " no such field in structure", (yyvsp[(3) - (3)].lex).string->c_str(), "");
                    parseContext.recover();
                    (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
                }
            }
        } else {
            parseContext.error((yyvsp[(2) - (3)].lex).line, " field selection requires structure, vector, or matrix on left hand side", (yyvsp[(3) - (3)].lex).string->c_str(), "");
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
        }
        // don't delete $3.string, it's from the pool
    }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 469 "glslang.y"
    {
        if (parseContext.lValueErrorCheck((yyvsp[(2) - (2)].lex).line, "++", (yyvsp[(1) - (2)].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addUnaryMath(EOpPostIncrement, (yyvsp[(1) - (2)].interm.intermTypedNode), (yyvsp[(2) - (2)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.unaryOpError((yyvsp[(2) - (2)].lex).line, "++", (yyvsp[(1) - (2)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (2)].interm.intermTypedNode);
        }
    }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 479 "glslang.y"
    {
        if (parseContext.lValueErrorCheck((yyvsp[(2) - (2)].lex).line, "--", (yyvsp[(1) - (2)].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addUnaryMath(EOpPostDecrement, (yyvsp[(1) - (2)].interm.intermTypedNode), (yyvsp[(2) - (2)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.unaryOpError((yyvsp[(2) - (2)].lex).line, "--", (yyvsp[(1) - (2)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (2)].interm.intermTypedNode);
        }
    }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 492 "glslang.y"
    {
        if (parseContext.integerErrorCheck((yyvsp[(1) - (1)].interm.intermTypedNode), "[]"))
            parseContext.recover();
        (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); 
    }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 500 "glslang.y"
    {
        TFunction* fnCall = (yyvsp[(1) - (1)].interm).function;
        TOperator op = fnCall->getBuiltInOp();
        
        if (op == EOpArrayLength) {
            if ((yyvsp[(1) - (1)].interm).intermNode->getAsTyped() == 0 || (yyvsp[(1) - (1)].interm).intermNode->getAsTyped()->getType().getArraySize() == 0) {
                parseContext.error((yyvsp[(1) - (1)].interm).line, "", fnCall->getName().c_str(), "array must be declared with a size before using this method");
                parseContext.recover();
            }

            constUnion *unionArray = new constUnion[1];
            unionArray->setIConst((yyvsp[(1) - (1)].interm).intermNode->getAsTyped()->getType().getArraySize());
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtInt, EvqConst), (yyvsp[(1) - (1)].interm).line);
        } else if (op != EOpNull) {
            //
            // Then this should be a constructor.
            // Don't go through the symbol table for constructors.  
            // Their parameters will be verified algorithmically.
            //
            TType type(EbtVoid);  // use this to get the type back
            if (parseContext.constructorErrorCheck((yyvsp[(1) - (1)].interm).line, (yyvsp[(1) - (1)].interm).intermNode, *fnCall, op, &type)) {
                (yyval.interm.intermTypedNode) = 0;
            } else {
                //
                // It's a constructor, of type 'type'.
                //
                (yyval.interm.intermTypedNode) = parseContext.addConstructor((yyvsp[(1) - (1)].interm).intermNode, &type, op, fnCall, (yyvsp[(1) - (1)].interm).line);
            }
            
            if ((yyval.interm.intermTypedNode) == 0) {        
                parseContext.recover();
                (yyval.interm.intermTypedNode) = parseContext.intermediate.setAggregateOperator(0, op, (yyvsp[(1) - (1)].interm).line);
            }
            (yyval.interm.intermTypedNode)->setType(type);
        } else {
            //
            // Not a constructor.  Find it in the symbol table.
            //
            const TFunction* fnCandidate;
            bool builtIn;
            fnCandidate = parseContext.findFunction((yyvsp[(1) - (1)].interm).line, fnCall, &builtIn);
            if (fnCandidate) {
                //
                // A declared function.  But, it might still map to a built-in
                // operation.
                //
                op = fnCandidate->getBuiltInOp();
                if (builtIn && op != EOpNull) {
                    //
                    // A function call mapped to a built-in operation.
                    //
                    if (fnCandidate->getParamCount() == 1) {
                        //
                        // Treat it like a built-in unary operator.
                        //
                        (yyval.interm.intermTypedNode) = parseContext.intermediate.addUnaryMath(op, (yyvsp[(1) - (1)].interm).intermNode, 0, parseContext.symbolTable);
                        if ((yyval.interm.intermTypedNode) == 0)  {
                            parseContext.error((yyvsp[(1) - (1)].interm).intermNode->getLine(), " wrong operand type", "Internal Error", 
                                "built in unary operator function.  Type: %s",
                                static_cast<TIntermTyped*>((yyvsp[(1) - (1)].interm).intermNode)->getCompleteString().c_str());
                            YYERROR;
                        }
                    } else {
                        (yyval.interm.intermTypedNode) = parseContext.intermediate.setAggregateOperator((yyvsp[(1) - (1)].interm).intermAggregate, op, (yyvsp[(1) - (1)].interm).line);
                    }
                } else {
                    // This is a real function call
                    
                    (yyval.interm.intermTypedNode) = parseContext.intermediate.setAggregateOperator((yyvsp[(1) - (1)].interm).intermAggregate, EOpFunctionCall, (yyvsp[(1) - (1)].interm).line);
                    (yyval.interm.intermTypedNode)->setType(fnCandidate->getReturnType());                   
                    
                    // this is how we know whether the given function is a builtIn function or a user defined function
                    // if builtIn == false, it's a userDefined -> could be an overloaded builtIn function also
                    // if builtIn == true, it's definitely a builtIn function with EOpNull
                    if (!builtIn) 
                        (yyval.interm.intermTypedNode)->getAsAggregate()->setUserDefined(); 
                    (yyval.interm.intermTypedNode)->getAsAggregate()->setName(fnCandidate->getMangledName());

                    TQualifier qual;
                    TQualifierList& qualifierList = (yyval.interm.intermTypedNode)->getAsAggregate()->getQualifier();
                    for (int i = 0; i < fnCandidate->getParamCount(); ++i) {
                        qual = (*fnCandidate)[i].type->getQualifier();
                        if (qual == EvqOut || qual == EvqInOut) {
                            if (parseContext.lValueErrorCheck((yyval.interm.intermTypedNode)->getLine(), "assign", (yyval.interm.intermTypedNode)->getAsAggregate()->getSequence()[i]->getAsTyped())) {
                                parseContext.error((yyvsp[(1) - (1)].interm).intermNode->getLine(), "Constant value cannot be passed for 'out' or 'inout' parameters.", "Error", "");
                                parseContext.recover();
                            }
                        }
                        qualifierList.push_back(qual);
                    }
                }
                (yyval.interm.intermTypedNode)->setType(fnCandidate->getReturnType());
            } else {
                // error message was put out by PaFindFunction()
                // Put on a dummy node for error recovery
                constUnion *unionArray = new constUnion[1];
                unionArray->setFConst(0.0f);
                (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtFloat, EvqConst), (yyvsp[(1) - (1)].interm).line);
                parseContext.recover();
            }
        }
        delete fnCall;
    }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 606 "glslang.y"
    {
        (yyval.interm) = (yyvsp[(1) - (1)].interm);
    }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 609 "glslang.y"
    {
        if ((yyvsp[(1) - (3)].interm.intermTypedNode)->isArray() && (yyvsp[(3) - (3)].interm).function->getName() == "length") {
            //
            // implement array.length()
            //
            if (parseContext.extensionErrorCheck((yyvsp[(3) - (3)].interm).line, "GL_3DL_array_objects")) {
                parseContext.recover();
                (yyval.interm) = (yyvsp[(3) - (3)].interm);
            } else {
                (yyval.interm) = (yyvsp[(3) - (3)].interm);
                (yyval.interm).intermNode = (yyvsp[(1) - (3)].interm.intermTypedNode);
                (yyval.interm).function->relateToOperator(EOpArrayLength);
            }
        } else {
            parseContext.error((yyvsp[(3) - (3)].interm).line, "methods are not supported", "", "");
            parseContext.recover();
            (yyval.interm) = (yyvsp[(3) - (3)].interm);
        }
    }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 631 "glslang.y"
    {
        (yyval.interm) = (yyvsp[(1) - (2)].interm);
        (yyval.interm).line = (yyvsp[(2) - (2)].lex).line;
    }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 635 "glslang.y"
    {
        (yyval.interm) = (yyvsp[(1) - (2)].interm);
        (yyval.interm).line = (yyvsp[(2) - (2)].lex).line;
    }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 642 "glslang.y"
    {
        (yyval.interm).function = (yyvsp[(1) - (2)].interm.function);
        (yyval.interm).intermNode = 0;
    }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 646 "glslang.y"
    {
        (yyval.interm).function = (yyvsp[(1) - (1)].interm.function);
        (yyval.interm).intermNode = 0;
    }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 653 "glslang.y"
    {
        TParameter param = { 0, new TType((yyvsp[(2) - (2)].interm.intermTypedNode)->getType()) };
        (yyvsp[(1) - (2)].interm.function)->addParameter(param);
        (yyval.interm).function = (yyvsp[(1) - (2)].interm.function);
        (yyval.interm).intermNode = (yyvsp[(2) - (2)].interm.intermTypedNode);
    }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 659 "glslang.y"
    {
        TParameter param = { 0, new TType((yyvsp[(3) - (3)].interm.intermTypedNode)->getType()) };
        (yyvsp[(1) - (3)].interm).function->addParameter(param);
        (yyval.interm).function = (yyvsp[(1) - (3)].interm).function;
        (yyval.interm).intermNode = parseContext.intermediate.growAggregate((yyvsp[(1) - (3)].interm).intermNode, (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line);
    }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 668 "glslang.y"
    {
        (yyval.interm.function) = (yyvsp[(1) - (2)].interm.function);
    }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 676 "glslang.y"
    {
        //
        // Constructor
        //
        if ((yyvsp[(1) - (1)].interm.type).array) {
            if (parseContext.extensionErrorCheck((yyvsp[(1) - (1)].interm.type).line, "GL_3DL_array_objects")) {
                parseContext.recover();
                (yyvsp[(1) - (1)].interm.type).setArray(false);
            }
        }

        if ((yyvsp[(1) - (1)].interm.type).userDef) {
            TString tempString = "";
            TType type((yyvsp[(1) - (1)].interm.type));
            TFunction *function = new TFunction(&tempString, type, EOpConstructStruct);
            (yyval.interm.function) = function;
        } else {
            TOperator op = EOpNull;
            switch ((yyvsp[(1) - (1)].interm.type).type) {
            case EbtFloat:
                if ((yyvsp[(1) - (1)].interm.type).matrix) {
                    switch((yyvsp[(1) - (1)].interm.type).size) {
                    case 2:                                     op = EOpConstructMat2;  break;
                    case 3:                                     op = EOpConstructMat3;  break;
                    case 4:                                     op = EOpConstructMat4;  break;
                    }         
                } else {      
                    switch((yyvsp[(1) - (1)].interm.type).size) {
                    case 1:                                     op = EOpConstructFloat; break;
                    case 2:                                     op = EOpConstructVec2;  break;
                    case 3:                                     op = EOpConstructVec3;  break;
                    case 4:                                     op = EOpConstructVec4;  break;
                    }       
                }  
                break;               
            case EbtInt:
                switch((yyvsp[(1) - (1)].interm.type).size) {
                case 1:                                         op = EOpConstructInt;   break;
                case 2:       FRAG_VERT_ONLY("ivec2", (yyvsp[(1) - (1)].interm.type).line); op = EOpConstructIVec2; break;
                case 3:       FRAG_VERT_ONLY("ivec3", (yyvsp[(1) - (1)].interm.type).line); op = EOpConstructIVec3; break;
                case 4:       FRAG_VERT_ONLY("ivec4", (yyvsp[(1) - (1)].interm.type).line); op = EOpConstructIVec4; break;
                }         
                break;    
            case EbtBool:
                switch((yyvsp[(1) - (1)].interm.type).size) {
                case 1:                                         op = EOpConstructBool;  break;
                case 2:       FRAG_VERT_ONLY("bvec2", (yyvsp[(1) - (1)].interm.type).line); op = EOpConstructBVec2; break;
                case 3:       FRAG_VERT_ONLY("bvec3", (yyvsp[(1) - (1)].interm.type).line); op = EOpConstructBVec3; break;
                case 4:       FRAG_VERT_ONLY("bvec4", (yyvsp[(1) - (1)].interm.type).line); op = EOpConstructBVec4; break;
                }         
                break;
            }
            if (op == EOpNull) {                    
                parseContext.error((yyvsp[(1) - (1)].interm.type).line, "cannot construct this type", TType::getBasicString((yyvsp[(1) - (1)].interm.type).type), "");
                parseContext.recover();
                (yyvsp[(1) - (1)].interm.type).type = EbtFloat;
                op = EOpConstructFloat;
            }            
            TString tempString = "";
            TType type((yyvsp[(1) - (1)].interm.type));
            TFunction *function = new TFunction(&tempString, type, op);
            (yyval.interm.function) = function;
        }
    }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 740 "glslang.y"
    {
        if (parseContext.reservedErrorCheck((yyvsp[(1) - (1)].lex).line, *(yyvsp[(1) - (1)].lex).string)) 
            parseContext.recover();
        TType type(EbtVoid);
        TFunction *function = new TFunction((yyvsp[(1) - (1)].lex).string, type);
        (yyval.interm.function) = function;
    }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 747 "glslang.y"
    {
        if (parseContext.reservedErrorCheck((yyvsp[(1) - (1)].lex).line, *(yyvsp[(1) - (1)].lex).string)) 
            parseContext.recover();
        TType type(EbtVoid);
        TFunction *function = new TFunction((yyvsp[(1) - (1)].lex).string, type);
        (yyval.interm.function) = function;
    }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 757 "glslang.y"
    {
        (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode);
    }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 760 "glslang.y"
    {
        if (parseContext.lValueErrorCheck((yyvsp[(1) - (2)].lex).line, "++", (yyvsp[(2) - (2)].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addUnaryMath(EOpPreIncrement, (yyvsp[(2) - (2)].interm.intermTypedNode), (yyvsp[(1) - (2)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.unaryOpError((yyvsp[(1) - (2)].lex).line, "++", (yyvsp[(2) - (2)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(2) - (2)].interm.intermTypedNode);
        }
    }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 770 "glslang.y"
    {
        if (parseContext.lValueErrorCheck((yyvsp[(1) - (2)].lex).line, "--", (yyvsp[(2) - (2)].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addUnaryMath(EOpPreDecrement, (yyvsp[(2) - (2)].interm.intermTypedNode), (yyvsp[(1) - (2)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.unaryOpError((yyvsp[(1) - (2)].lex).line, "--", (yyvsp[(2) - (2)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(2) - (2)].interm.intermTypedNode);
        }
    }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 780 "glslang.y"
    {
        if ((yyvsp[(1) - (2)].interm).op != EOpNull) {
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addUnaryMath((yyvsp[(1) - (2)].interm).op, (yyvsp[(2) - (2)].interm.intermTypedNode), (yyvsp[(1) - (2)].interm).line, parseContext.symbolTable);
            if ((yyval.interm.intermTypedNode) == 0) {
                char* errorOp = "";
                switch((yyvsp[(1) - (2)].interm).op) {
                case EOpNegative:   errorOp = "-"; break;
                case EOpLogicalNot: errorOp = "!"; break;
                case EOpBitwiseNot: errorOp = "~"; break;
				default: break;
                }
                parseContext.unaryOpError((yyvsp[(1) - (2)].interm).line, errorOp, (yyvsp[(2) - (2)].interm.intermTypedNode)->getCompleteString());
                parseContext.recover();
                (yyval.interm.intermTypedNode) = (yyvsp[(2) - (2)].interm.intermTypedNode);
            }
        } else
            (yyval.interm.intermTypedNode) = (yyvsp[(2) - (2)].interm.intermTypedNode);
    }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 802 "glslang.y"
    { (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpNull; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 803 "glslang.y"
    { (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpNegative; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 804 "glslang.y"
    { (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpLogicalNot; }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 805 "glslang.y"
    { PACK_UNPACK_ONLY("~", (yyvsp[(1) - (1)].lex).line);  
              (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpBitwiseNot; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 811 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 812 "glslang.y"
    {
        FRAG_VERT_ONLY("*", (yyvsp[(2) - (3)].lex).line);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpMul, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "*", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
        }
    }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 821 "glslang.y"
    {
        FRAG_VERT_ONLY("/", (yyvsp[(2) - (3)].lex).line); 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpDiv, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "/", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
        }
    }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 830 "glslang.y"
    {
        PACK_UNPACK_ONLY("%", (yyvsp[(2) - (3)].lex).line);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpMod, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "%", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
        }
    }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 842 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 843 "glslang.y"
    {  
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpAdd, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "+", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
        }
    }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 851 "glslang.y"
    {
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpSub, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "-", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
        } 
    }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 862 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 863 "glslang.y"
    {
        PACK_UNPACK_ONLY("<<", (yyvsp[(2) - (3)].lex).line);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpLeftShift, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "<<", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
        }
    }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 872 "glslang.y"
    {
        PACK_UNPACK_ONLY(">>", (yyvsp[(2) - (3)].lex).line);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpRightShift, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, ">>", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
        }
    }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 884 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 885 "glslang.y"
    { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpLessThan, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "<", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            constUnion *unionArray = new constUnion[1];
            unionArray->setBConst(false);
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtBool, EvqConst), (yyvsp[(2) - (3)].lex).line);
        }
    }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 895 "glslang.y"
    { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpGreaterThan, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, ">", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            constUnion *unionArray = new constUnion[1];
            unionArray->setBConst(false);
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtBool, EvqConst), (yyvsp[(2) - (3)].lex).line);
        }
    }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 905 "glslang.y"
    { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpLessThanEqual, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "<=", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            constUnion *unionArray = new constUnion[1];
            unionArray->setBConst(false);
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtBool, EvqConst), (yyvsp[(2) - (3)].lex).line);
        }
    }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 915 "glslang.y"
    { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpGreaterThanEqual, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, ">=", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            constUnion *unionArray = new constUnion[1];
            unionArray->setBConst(false);
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtBool, EvqConst), (yyvsp[(2) - (3)].lex).line);
        }
    }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 928 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 929 "glslang.y"
    {
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpEqual, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "==", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            constUnion *unionArray = new constUnion[1];
            unionArray->setBConst(false);
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtBool, EvqConst), (yyvsp[(2) - (3)].lex).line);
        } else if (((yyvsp[(1) - (3)].interm.intermTypedNode)->isArray() || (yyvsp[(3) - (3)].interm.intermTypedNode)->isArray()) && parseContext.extensionErrorCheck((yyvsp[(2) - (3)].lex).line, "GL_3DL_array_objects"))
            parseContext.recover();
    }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 940 "glslang.y"
    { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpNotEqual, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "!=", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            constUnion *unionArray = new constUnion[1];
            unionArray->setBConst(false);
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtBool, EvqConst), (yyvsp[(2) - (3)].lex).line);
        } else if (((yyvsp[(1) - (3)].interm.intermTypedNode)->isArray() || (yyvsp[(3) - (3)].interm.intermTypedNode)->isArray()) && parseContext.extensionErrorCheck((yyvsp[(2) - (3)].lex).line, "GL_3DL_array_objects"))
            parseContext.recover();
    }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 954 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 955 "glslang.y"
    {
        PACK_UNPACK_ONLY("&", (yyvsp[(2) - (3)].lex).line);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpAnd, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "&", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
        }
    }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 967 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 968 "glslang.y"
    {
        PACK_UNPACK_ONLY("^", (yyvsp[(2) - (3)].lex).line);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpExclusiveOr, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "^", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
        }
    }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 980 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 981 "glslang.y"
    {
        PACK_UNPACK_ONLY("|", (yyvsp[(2) - (3)].lex).line);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpInclusiveOr, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "|", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
        }
    }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 993 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 994 "glslang.y"
    {
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpLogicalAnd, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "&&", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            constUnion *unionArray = new constUnion[1];
            unionArray->setBConst(false);
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtBool, EvqConst), (yyvsp[(2) - (3)].lex).line);
        }
    }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 1007 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 1008 "glslang.y"
    { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpLogicalXor, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "^^", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            constUnion *unionArray = new constUnion[1];
            unionArray->setBConst(false);
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtBool, EvqConst), (yyvsp[(2) - (3)].lex).line);
        }
    }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 1021 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 1022 "glslang.y"
    { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpLogicalOr, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line, parseContext.symbolTable);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, "||", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            constUnion *unionArray = new constUnion[1];
            unionArray->setBConst(false);
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addConstantUnion(unionArray, TType(EbtBool, EvqConst), (yyvsp[(2) - (3)].lex).line);
        }
    }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 1035 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 1036 "glslang.y"
    {
       if (parseContext.boolErrorCheck((yyvsp[(2) - (5)].lex).line, (yyvsp[(1) - (5)].interm.intermTypedNode)))
            parseContext.recover();
       
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addSelection((yyvsp[(1) - (5)].interm.intermTypedNode), (yyvsp[(3) - (5)].interm.intermTypedNode), (yyvsp[(5) - (5)].interm.intermTypedNode), (yyvsp[(2) - (5)].lex).line);
        if ((yyvsp[(3) - (5)].interm.intermTypedNode)->getType() != (yyvsp[(5) - (5)].interm.intermTypedNode)->getType())
            (yyval.interm.intermTypedNode) = 0;
            
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (5)].lex).line, ":", (yyvsp[(3) - (5)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(5) - (5)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(5) - (5)].interm.intermTypedNode);
        }
    }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 1053 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 1054 "glslang.y"
    {        
        if (parseContext.lValueErrorCheck((yyvsp[(2) - (3)].interm).line, "assign", (yyvsp[(1) - (3)].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addAssign((yyvsp[(2) - (3)].interm).op, (yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].interm).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.assignError((yyvsp[(2) - (3)].interm).line, "assign", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(1) - (3)].interm.intermTypedNode);
        } else if (((yyvsp[(1) - (3)].interm.intermTypedNode)->isArray() || (yyvsp[(3) - (3)].interm.intermTypedNode)->isArray()) && parseContext.extensionErrorCheck((yyvsp[(2) - (3)].interm).line, "GL_3DL_array_objects"))
            parseContext.recover();
    }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 1068 "glslang.y"
    {                                    (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpAssign; }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 1069 "glslang.y"
    { FRAG_VERT_ONLY("*=", (yyvsp[(1) - (1)].lex).line);     (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpMulAssign; }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 1070 "glslang.y"
    { FRAG_VERT_ONLY("/=", (yyvsp[(1) - (1)].lex).line);     (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpDivAssign; }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 1071 "glslang.y"
    { PACK_UNPACK_ONLY("%=", (yyvsp[(1) - (1)].lex).line);   (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpModAssign; }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1072 "glslang.y"
    {                                    (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpAddAssign; }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 1073 "glslang.y"
    {                                    (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpSubAssign; }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 1074 "glslang.y"
    { PACK_UNPACK_ONLY("<<=", (yyvsp[(1) - (1)].lex).line);  (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpLeftShiftAssign; }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1075 "glslang.y"
    { PACK_UNPACK_ONLY("<<=", (yyvsp[(1) - (1)].lex).line);  (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpRightShiftAssign; }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1076 "glslang.y"
    { PACK_UNPACK_ONLY("&=",  (yyvsp[(1) - (1)].lex).line);  (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpAndAssign; }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 1077 "glslang.y"
    { PACK_UNPACK_ONLY("^=",  (yyvsp[(1) - (1)].lex).line);  (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpExclusiveOrAssign; }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 1078 "glslang.y"
    { PACK_UNPACK_ONLY("|=",  (yyvsp[(1) - (1)].lex).line);  (yyval.interm).line = (yyvsp[(1) - (1)].lex).line; (yyval.interm).op = EOpInclusiveOrAssign; }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 1082 "glslang.y"
    {
        (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode);
    }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1085 "glslang.y"
    {
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addComma((yyvsp[(1) - (3)].interm.intermTypedNode), (yyvsp[(3) - (3)].interm.intermTypedNode), (yyvsp[(2) - (3)].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[(2) - (3)].lex).line, ",", (yyvsp[(1) - (3)].interm.intermTypedNode)->getCompleteString(), (yyvsp[(3) - (3)].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[(3) - (3)].interm.intermTypedNode);
        }
    }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1096 "glslang.y"
    {
        if (parseContext.constErrorCheck((yyvsp[(1) - (1)].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode);
    }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 1104 "glslang.y"
    { (yyval.interm.intermNode) = 0; }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 1105 "glslang.y"
    { 
        if ((yyvsp[(1) - (2)].interm).intermAggregate)
            (yyvsp[(1) - (2)].interm).intermAggregate->setOperator(EOpSequence); 
        (yyval.interm.intermNode) = (yyvsp[(1) - (2)].interm).intermAggregate; 
    }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1113 "glslang.y"
    {
        //
        // Multiple declarations of the same function are allowed.
        //
        // If this is a definition, the definition production code will check for redefinitions 
        // (we don't know at this point if it's a definition or not).
        //
        // Redeclarations are allowed.  But, return types and parameter qualifiers must match.
        //        
        TFunction* prevDec = static_cast<TFunction*>(parseContext.symbolTable.find((yyvsp[(1) - (2)].interm.function)->getMangledName()));
        if (prevDec) {
            if (prevDec->getReturnType() != (yyvsp[(1) - (2)].interm.function)->getReturnType()) {
                parseContext.error((yyvsp[(2) - (2)].lex).line, "overloaded functions must have the same return type", (yyvsp[(1) - (2)].interm.function)->getReturnType().getBasicString(), "");
                parseContext.recover();
            }
            for (int i = 0; i < prevDec->getParamCount(); ++i) {
                if ((*prevDec)[i].type->getQualifier() != (*(yyvsp[(1) - (2)].interm.function))[i].type->getQualifier()) {
                    parseContext.error((yyvsp[(2) - (2)].lex).line, "overloaded functions must have the same parameter qualifiers", (*(yyvsp[(1) - (2)].interm.function))[i].type->getQualifierString(), "");
                    parseContext.recover();
                }
            }
        }
        
        //
        // If this is a redeclaration, it could also be a definition,
        // in which case, we want to use the variable names from this one, and not the one that's
        // being redeclared.  So, pass back up this declaration, not the one in the symbol table.
        //
        (yyval.interm).function = (yyvsp[(1) - (2)].interm.function);
        (yyval.interm).line = (yyvsp[(2) - (2)].lex).line;

        parseContext.symbolTable.insert(*(yyval.interm).function);
    }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1149 "glslang.y"
    {
        (yyval.interm.function) = (yyvsp[(1) - (1)].interm.function);
    }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1152 "glslang.y"
    { 
        (yyval.interm.function) = (yyvsp[(1) - (1)].interm.function);  
    }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1159 "glslang.y"
    {
        // Add the parameter 
        (yyval.interm.function) = (yyvsp[(1) - (2)].interm.function);
        if ((yyvsp[(2) - (2)].interm).param.type->getBasicType() != EbtVoid)
            (yyvsp[(1) - (2)].interm.function)->addParameter((yyvsp[(2) - (2)].interm).param);
        else
            delete (yyvsp[(2) - (2)].interm).param.type;
    }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1167 "glslang.y"
    {   
        //
        // Only first parameter of one-parameter functions can be void
        // The check for named parameters not being void is done in parameter_declarator 
        //
        if ((yyvsp[(3) - (3)].interm).param.type->getBasicType() == EbtVoid) {
            //
            // This parameter > first is void
            //
            parseContext.error((yyvsp[(2) - (3)].lex).line, "cannot be an argument type except for '(void)'", "void", "");
            parseContext.recover();
            delete (yyvsp[(3) - (3)].interm).param.type;
        } else {
            // Add the parameter 
            (yyval.interm.function) = (yyvsp[(1) - (3)].interm.function); 
            (yyvsp[(1) - (3)].interm.function)->addParameter((yyvsp[(3) - (3)].interm).param);
        }
    }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1188 "glslang.y"
    {
        if ((yyvsp[(1) - (3)].interm.type).qualifier != EvqGlobal && (yyvsp[(1) - (3)].interm.type).qualifier != EvqTemporary) {
            parseContext.error((yyvsp[(2) - (3)].lex).line, "no qualifiers allowed for function return", getQualifierString((yyvsp[(1) - (3)].interm.type).qualifier), "");
            parseContext.recover();
        }
        // make sure a sampler is not involved as well...
        if (parseContext.structQualifierErrorCheck((yyvsp[(2) - (3)].lex).line, (yyvsp[(1) - (3)].interm.type)))
            parseContext.recover();
        
        // Add the function as a prototype after parsing it (we do not support recursion) 
        TFunction *function;
        TType type((yyvsp[(1) - (3)].interm.type));
        function = new TFunction((yyvsp[(2) - (3)].lex).string, type);
        (yyval.interm.function) = function;
    }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1207 "glslang.y"
    {
        if ((yyvsp[(1) - (2)].interm.type).type == EbtVoid) {
            parseContext.error((yyvsp[(2) - (2)].lex).line, "illegal use of type 'void'", (yyvsp[(2) - (2)].lex).string->c_str(), "");
            parseContext.recover();
        }
        if (parseContext.reservedErrorCheck((yyvsp[(2) - (2)].lex).line, *(yyvsp[(2) - (2)].lex).string))
            parseContext.recover();
        TParameter param = {(yyvsp[(2) - (2)].lex).string, new TType((yyvsp[(1) - (2)].interm.type))};
        (yyval.interm).line = (yyvsp[(2) - (2)].lex).line;
        (yyval.interm).param = param;
    }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1218 "glslang.y"
    {
        // Check that we can make an array out of this type
        if (parseContext.arrayTypeErrorCheck((yyvsp[(3) - (5)].lex).line, (yyvsp[(1) - (5)].interm.type)))
            parseContext.recover();
            
        if (parseContext.reservedErrorCheck((yyvsp[(2) - (5)].lex).line, *(yyvsp[(2) - (5)].lex).string))
            parseContext.recover();
            
        int size;
        if (parseContext.arraySizeErrorCheck((yyvsp[(3) - (5)].lex).line, (yyvsp[(4) - (5)].interm.intermTypedNode), size))
            parseContext.recover();
        (yyvsp[(1) - (5)].interm.type).setArray(true, size);
             
        TType* type = new TType((yyvsp[(1) - (5)].interm.type));
        TParameter param = { (yyvsp[(2) - (5)].lex).string, type };
        (yyval.interm).line = (yyvsp[(2) - (5)].lex).line;
        (yyval.interm).param = param;
    }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1247 "glslang.y"
    {
        (yyval.interm) = (yyvsp[(3) - (3)].interm);
        if (parseContext.paramErrorCheck((yyvsp[(3) - (3)].interm).line, (yyvsp[(1) - (3)].interm.type).qualifier, (yyvsp[(2) - (3)].interm.qualifier), (yyval.interm).param.type))
            parseContext.recover();
    }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1252 "glslang.y"
    {
        (yyval.interm) = (yyvsp[(2) - (2)].interm);
        if (parseContext.parameterSamplerErrorCheck((yyvsp[(2) - (2)].interm).line, (yyvsp[(1) - (2)].interm.qualifier), *(yyvsp[(2) - (2)].interm).param.type))
            parseContext.recover();
        if (parseContext.paramErrorCheck((yyvsp[(2) - (2)].interm).line, EvqTemporary, (yyvsp[(1) - (2)].interm.qualifier), (yyval.interm).param.type))
            parseContext.recover();
    }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1262 "glslang.y"
    {
        (yyval.interm) = (yyvsp[(3) - (3)].interm);
        if (parseContext.paramErrorCheck((yyvsp[(3) - (3)].interm).line, (yyvsp[(1) - (3)].interm.type).qualifier, (yyvsp[(2) - (3)].interm.qualifier), (yyval.interm).param.type))
            parseContext.recover();
    }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1267 "glslang.y"
    {
        (yyval.interm) = (yyvsp[(2) - (2)].interm);
        if (parseContext.parameterSamplerErrorCheck((yyvsp[(2) - (2)].interm).line, (yyvsp[(1) - (2)].interm.qualifier), *(yyvsp[(2) - (2)].interm).param.type))
            parseContext.recover();
        if (parseContext.paramErrorCheck((yyvsp[(2) - (2)].interm).line, EvqTemporary, (yyvsp[(1) - (2)].interm.qualifier), (yyval.interm).param.type))
            parseContext.recover();
    }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1277 "glslang.y"
    {
        (yyval.interm.qualifier) = EvqIn;
    }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1280 "glslang.y"
    {
        (yyval.interm.qualifier) = EvqIn;
    }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1283 "glslang.y"
    {
        (yyval.interm.qualifier) = EvqOut;
    }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 1286 "glslang.y"
    {
        (yyval.interm.qualifier) = EvqInOut;
    }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 1292 "glslang.y"
    {
        TParameter param = { 0, new TType((yyvsp[(1) - (1)].interm.type)) };
        (yyval.interm).param = param;
    }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 1299 "glslang.y"
    {
        (yyval.interm) = (yyvsp[(1) - (1)].interm);
    }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 1302 "glslang.y"
    {
        (yyval.interm) = (yyvsp[(1) - (3)].interm);
        if (parseContext.structQualifierErrorCheck((yyvsp[(3) - (3)].lex).line, (yyval.interm).type))
            parseContext.recover();
        
        if (parseContext.nonInitConstErrorCheck((yyvsp[(3) - (3)].lex).line, *(yyvsp[(3) - (3)].lex).string, (yyval.interm).type))
            parseContext.recover();

        if (parseContext.nonInitErrorCheck((yyvsp[(3) - (3)].lex).line, *(yyvsp[(3) - (3)].lex).string, (yyval.interm).type))
            parseContext.recover();
    }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 1313 "glslang.y"
    {
        if (parseContext.structQualifierErrorCheck((yyvsp[(3) - (5)].lex).line, (yyvsp[(1) - (5)].interm).type))
            parseContext.recover();
            
        if (parseContext.nonInitConstErrorCheck((yyvsp[(3) - (5)].lex).line, *(yyvsp[(3) - (5)].lex).string, (yyvsp[(1) - (5)].interm).type))
            parseContext.recover();

        (yyval.interm) = (yyvsp[(1) - (5)].interm);
        
        if (parseContext.arrayTypeErrorCheck((yyvsp[(4) - (5)].lex).line, (yyvsp[(1) - (5)].interm).type) || parseContext.arrayQualifierErrorCheck((yyvsp[(4) - (5)].lex).line, (yyvsp[(1) - (5)].interm).type))
            parseContext.recover();
        else {
            (yyvsp[(1) - (5)].interm).type.setArray(true);
            TVariable* variable;
            if (parseContext.arrayErrorCheck((yyvsp[(4) - (5)].lex).line, *(yyvsp[(3) - (5)].lex).string, (yyvsp[(1) - (5)].interm).type, variable))
                parseContext.recover();
        }
    }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 1331 "glslang.y"
    {
        if (parseContext.structQualifierErrorCheck((yyvsp[(3) - (6)].lex).line, (yyvsp[(1) - (6)].interm).type))
            parseContext.recover();
            
        if (parseContext.nonInitConstErrorCheck((yyvsp[(3) - (6)].lex).line, *(yyvsp[(3) - (6)].lex).string, (yyvsp[(1) - (6)].interm).type))
            parseContext.recover();
        
        (yyval.interm) = (yyvsp[(1) - (6)].interm);

        if (parseContext.arrayTypeErrorCheck((yyvsp[(4) - (6)].lex).line, (yyvsp[(1) - (6)].interm).type) || parseContext.arrayQualifierErrorCheck((yyvsp[(4) - (6)].lex).line, (yyvsp[(1) - (6)].interm).type))
            parseContext.recover();
        else {
            int size;
            if (parseContext.arraySizeErrorCheck((yyvsp[(4) - (6)].lex).line, (yyvsp[(5) - (6)].interm.intermTypedNode), size))
                parseContext.recover();
            (yyvsp[(1) - (6)].interm).type.setArray(true, size);        
            TVariable* variable;
            if (parseContext.arrayErrorCheck((yyvsp[(4) - (6)].lex).line, *(yyvsp[(3) - (6)].lex).string, (yyvsp[(1) - (6)].interm).type, variable))
                parseContext.recover();
        }
    }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 1352 "glslang.y"
    {
        if (parseContext.structQualifierErrorCheck((yyvsp[(3) - (7)].lex).line, (yyvsp[(1) - (7)].interm).type))
            parseContext.recover();
            
        (yyval.interm) = (yyvsp[(1) - (7)].interm);
            
        TVariable* variable = 0;
        if (parseContext.arrayTypeErrorCheck((yyvsp[(4) - (7)].lex).line, (yyvsp[(1) - (7)].interm).type) || parseContext.arrayQualifierErrorCheck((yyvsp[(4) - (7)].lex).line, (yyvsp[(1) - (7)].interm).type))
            parseContext.recover();
        else {
			(yyvsp[(1) - (7)].interm).type.setArray(true, (yyvsp[(7) - (7)].interm.intermTypedNode)->getType().getArraySize());
            if (parseContext.arrayErrorCheck((yyvsp[(4) - (7)].lex).line, *(yyvsp[(3) - (7)].lex).string, (yyvsp[(1) - (7)].interm).type, variable))
                parseContext.recover();
        }

        if (parseContext.extensionErrorCheck((yyval.interm).line, "GL_3DL_array_objects"))
            parseContext.recover();
        else {
            TIntermNode* intermNode;
            if (!parseContext.executeInitializer((yyvsp[(3) - (7)].lex).line, *(yyvsp[(3) - (7)].lex).string, (yyvsp[(1) - (7)].interm).type, (yyvsp[(7) - (7)].interm.intermTypedNode), intermNode, variable)) {
                //
                // build the intermediate representation
                //
                if (intermNode)
                    (yyval.interm).intermAggregate = parseContext.intermediate.growAggregate((yyvsp[(1) - (7)].interm).intermNode, intermNode, (yyvsp[(6) - (7)].lex).line);
                else
                    (yyval.interm).intermAggregate = (yyvsp[(1) - (7)].interm).intermAggregate;
            } else {
                parseContext.recover();
                (yyval.interm).intermAggregate = 0;
            }
        }
    }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 1385 "glslang.y"
    {
        if (parseContext.structQualifierErrorCheck((yyvsp[(3) - (8)].lex).line, (yyvsp[(1) - (8)].interm).type))
            parseContext.recover();
            
        (yyval.interm) = (yyvsp[(1) - (8)].interm);
            
        TVariable* variable = 0;
        if (parseContext.arrayTypeErrorCheck((yyvsp[(4) - (8)].lex).line, (yyvsp[(1) - (8)].interm).type) || parseContext.arrayQualifierErrorCheck((yyvsp[(4) - (8)].lex).line, (yyvsp[(1) - (8)].interm).type))
            parseContext.recover();
        else {
            int size;
            if (parseContext.arraySizeErrorCheck((yyvsp[(4) - (8)].lex).line, (yyvsp[(5) - (8)].interm.intermTypedNode), size))
                parseContext.recover();
            (yyvsp[(1) - (8)].interm).type.setArray(true, size);
            if (parseContext.arrayErrorCheck((yyvsp[(4) - (8)].lex).line, *(yyvsp[(3) - (8)].lex).string, (yyvsp[(1) - (8)].interm).type, variable))
                parseContext.recover();
        }

        if (parseContext.extensionErrorCheck((yyval.interm).line, "GL_3DL_array_objects"))
            parseContext.recover();
        else {
            TIntermNode* intermNode;
            if (!parseContext.executeInitializer((yyvsp[(3) - (8)].lex).line, *(yyvsp[(3) - (8)].lex).string, (yyvsp[(1) - (8)].interm).type, (yyvsp[(8) - (8)].interm.intermTypedNode), intermNode, variable)) {
                //
                // build the intermediate representation
                //
                if (intermNode)
                    (yyval.interm).intermAggregate = parseContext.intermediate.growAggregate((yyvsp[(1) - (8)].interm).intermNode, intermNode, (yyvsp[(7) - (8)].lex).line);
                else
                    (yyval.interm).intermAggregate = (yyvsp[(1) - (8)].interm).intermAggregate;
            } else {
                parseContext.recover();
                (yyval.interm).intermAggregate = 0;
            }
        }
    }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 1421 "glslang.y"
    {
        if (parseContext.structQualifierErrorCheck((yyvsp[(3) - (5)].lex).line, (yyvsp[(1) - (5)].interm).type))
            parseContext.recover();
        
        (yyval.interm) = (yyvsp[(1) - (5)].interm);
        
        TIntermNode* intermNode;
        if (!parseContext.executeInitializer((yyvsp[(3) - (5)].lex).line, *(yyvsp[(3) - (5)].lex).string, (yyvsp[(1) - (5)].interm).type, (yyvsp[(5) - (5)].interm.intermTypedNode), intermNode)) {
            //
            // build the intermediate representation
            //
            if (intermNode)
                (yyval.interm).intermAggregate = parseContext.intermediate.growAggregate((yyvsp[(1) - (5)].interm).intermNode, intermNode, (yyvsp[(4) - (5)].lex).line);
            else
                (yyval.interm).intermAggregate = (yyvsp[(1) - (5)].interm).intermAggregate;
        } else {
            parseContext.recover();
            (yyval.interm).intermAggregate = 0;
        }
    }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 1444 "glslang.y"
    {
        (yyval.interm).type = (yyvsp[(1) - (1)].interm.type);
        (yyval.interm).intermAggregate = 0;
    }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 1448 "glslang.y"
    {
        (yyval.interm).intermAggregate = 0;
        (yyval.interm).type = (yyvsp[(1) - (2)].interm.type);

        if (parseContext.structQualifierErrorCheck((yyvsp[(2) - (2)].lex).line, (yyval.interm).type))
            parseContext.recover();
        
        if (parseContext.nonInitConstErrorCheck((yyvsp[(2) - (2)].lex).line, *(yyvsp[(2) - (2)].lex).string, (yyval.interm).type))
            parseContext.recover();

        if (parseContext.nonInitErrorCheck((yyvsp[(2) - (2)].lex).line, *(yyvsp[(2) - (2)].lex).string, (yyval.interm).type))
            parseContext.recover();
    }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 1461 "glslang.y"
    {
        (yyval.interm).intermAggregate = 0;
        if (parseContext.structQualifierErrorCheck((yyvsp[(2) - (4)].lex).line, (yyvsp[(1) - (4)].interm.type)))
            parseContext.recover();

        if (parseContext.nonInitConstErrorCheck((yyvsp[(2) - (4)].lex).line, *(yyvsp[(2) - (4)].lex).string, (yyvsp[(1) - (4)].interm.type)))
            parseContext.recover();

        (yyval.interm).type = (yyvsp[(1) - (4)].interm.type);

        if (parseContext.arrayTypeErrorCheck((yyvsp[(3) - (4)].lex).line, (yyvsp[(1) - (4)].interm.type)) || parseContext.arrayQualifierErrorCheck((yyvsp[(3) - (4)].lex).line, (yyvsp[(1) - (4)].interm.type)))
            parseContext.recover();
        else {
            (yyvsp[(1) - (4)].interm.type).setArray(true);        
            TVariable* variable;
            if (parseContext.arrayErrorCheck((yyvsp[(3) - (4)].lex).line, *(yyvsp[(2) - (4)].lex).string, (yyvsp[(1) - (4)].interm.type), variable))
                parseContext.recover();
        }
    }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 1480 "glslang.y"
    {
        (yyval.interm).intermAggregate = 0;
        if (parseContext.structQualifierErrorCheck((yyvsp[(2) - (5)].lex).line, (yyvsp[(1) - (5)].interm.type)))
            parseContext.recover();

        if (parseContext.nonInitConstErrorCheck((yyvsp[(2) - (5)].lex).line, *(yyvsp[(2) - (5)].lex).string, (yyvsp[(1) - (5)].interm.type)))
            parseContext.recover();
            
        (yyval.interm).type = (yyvsp[(1) - (5)].interm.type);

        if (parseContext.arrayTypeErrorCheck((yyvsp[(3) - (5)].lex).line, (yyvsp[(1) - (5)].interm.type)) || parseContext.arrayQualifierErrorCheck((yyvsp[(3) - (5)].lex).line, (yyvsp[(1) - (5)].interm.type)))
            parseContext.recover();
        else {
            int size;
            if (parseContext.arraySizeErrorCheck((yyvsp[(3) - (5)].lex).line, (yyvsp[(4) - (5)].interm.intermTypedNode), size))
                parseContext.recover();
            
            (yyvsp[(1) - (5)].interm.type).setArray(true, size);
            TVariable* variable;
            if (parseContext.arrayErrorCheck((yyvsp[(3) - (5)].lex).line, *(yyvsp[(2) - (5)].lex).string, (yyvsp[(1) - (5)].interm.type), variable))
                parseContext.recover();
        }
    }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 1503 "glslang.y"
    {
        (yyval.interm).intermAggregate = 0;

        if (parseContext.structQualifierErrorCheck((yyvsp[(2) - (6)].lex).line, (yyvsp[(1) - (6)].interm.type)))
            parseContext.recover();

        (yyval.interm).type = (yyvsp[(1) - (6)].interm.type);

        TVariable* variable = 0;
        if (parseContext.arrayTypeErrorCheck((yyvsp[(3) - (6)].lex).line, (yyvsp[(1) - (6)].interm.type)) || parseContext.arrayQualifierErrorCheck((yyvsp[(3) - (6)].lex).line, (yyvsp[(1) - (6)].interm.type)))
            parseContext.recover();
        else {
            (yyvsp[(1) - (6)].interm.type).setArray(true, (yyvsp[(6) - (6)].interm.intermTypedNode)->getType().getArraySize());
            if (parseContext.arrayErrorCheck((yyvsp[(3) - (6)].lex).line, *(yyvsp[(2) - (6)].lex).string, (yyvsp[(1) - (6)].interm.type), variable))
                parseContext.recover();
        }

        if (parseContext.extensionErrorCheck((yyval.interm).line, "GL_3DL_array_objects"))
            parseContext.recover();
        else {        
            TIntermNode* intermNode;
            if (!parseContext.executeInitializer((yyvsp[(2) - (6)].lex).line, *(yyvsp[(2) - (6)].lex).string, (yyvsp[(1) - (6)].interm.type), (yyvsp[(6) - (6)].interm.intermTypedNode), intermNode, variable)) {
                //
                // Build intermediate representation
                //
                if (intermNode)
                    (yyval.interm).intermAggregate = parseContext.intermediate.makeAggregate(intermNode, (yyvsp[(5) - (6)].lex).line);
                else
                    (yyval.interm).intermAggregate = 0;
            } else {
                parseContext.recover();
                (yyval.interm).intermAggregate = 0;
            }
        }
    }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1538 "glslang.y"
    {
        (yyval.interm).intermAggregate = 0;

        if (parseContext.structQualifierErrorCheck((yyvsp[(2) - (7)].lex).line, (yyvsp[(1) - (7)].interm.type)))
            parseContext.recover();

        (yyval.interm).type = (yyvsp[(1) - (7)].interm.type);

        TVariable* variable = 0;
        if (parseContext.arrayTypeErrorCheck((yyvsp[(3) - (7)].lex).line, (yyvsp[(1) - (7)].interm.type)) || parseContext.arrayQualifierErrorCheck((yyvsp[(3) - (7)].lex).line, (yyvsp[(1) - (7)].interm.type)))
            parseContext.recover();
        else {
            int size;
            if (parseContext.arraySizeErrorCheck((yyvsp[(3) - (7)].lex).line, (yyvsp[(4) - (7)].interm.intermTypedNode), size))
                parseContext.recover();
            
            (yyvsp[(1) - (7)].interm.type).setArray(true, size);
            if (parseContext.arrayErrorCheck((yyvsp[(3) - (7)].lex).line, *(yyvsp[(2) - (7)].lex).string, (yyvsp[(1) - (7)].interm.type), variable))
                parseContext.recover();
        }

        if (parseContext.extensionErrorCheck((yyval.interm).line, "GL_3DL_array_objects"))
            parseContext.recover();
        else {        
            TIntermNode* intermNode;
            if (!parseContext.executeInitializer((yyvsp[(2) - (7)].lex).line, *(yyvsp[(2) - (7)].lex).string, (yyvsp[(1) - (7)].interm.type), (yyvsp[(7) - (7)].interm.intermTypedNode), intermNode, variable)) {
                //
                // Build intermediate representation
                //
                if (intermNode)
                    (yyval.interm).intermAggregate = parseContext.intermediate.makeAggregate(intermNode, (yyvsp[(6) - (7)].lex).line);
                else
                    (yyval.interm).intermAggregate = 0;
            } else {
                parseContext.recover();
                (yyval.interm).intermAggregate = 0;
            }
        }        
    }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 1577 "glslang.y"
    {
        if (parseContext.structQualifierErrorCheck((yyvsp[(2) - (4)].lex).line, (yyvsp[(1) - (4)].interm.type)))
            parseContext.recover();

        (yyval.interm).type = (yyvsp[(1) - (4)].interm.type);

        TIntermNode* intermNode;
        if (!parseContext.executeInitializer((yyvsp[(2) - (4)].lex).line, *(yyvsp[(2) - (4)].lex).string, (yyvsp[(1) - (4)].interm.type), (yyvsp[(4) - (4)].interm.intermTypedNode), intermNode)) {
            //
            // Build intermediate representation
            //
            if (intermNode)
                (yyval.interm).intermAggregate = parseContext.intermediate.makeAggregate(intermNode, (yyvsp[(3) - (4)].lex).line);
            else
                (yyval.interm).intermAggregate = 0;
        } else {
            parseContext.recover();
            (yyval.interm).intermAggregate = 0;
        }
    }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 1668 "glslang.y"
    {
        (yyval.interm.type) = (yyvsp[(1) - (1)].interm.type);
                
        if ((yyvsp[(1) - (1)].interm.type).array) {
            if (parseContext.extensionErrorCheck((yyvsp[(1) - (1)].interm.type).line, "GL_3DL_array_objects")) {
                parseContext.recover();
                (yyvsp[(1) - (1)].interm.type).setArray(false);
            }
        }
    }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 1678 "glslang.y"
    {        
        if ((yyvsp[(2) - (2)].interm.type).array && parseContext.extensionErrorCheck((yyvsp[(2) - (2)].interm.type).line, "GL_3DL_array_objects")) {
            parseContext.recover();
            (yyvsp[(2) - (2)].interm.type).setArray(false);
        }
        if ((yyvsp[(2) - (2)].interm.type).array && parseContext.arrayQualifierErrorCheck((yyvsp[(2) - (2)].interm.type).line, (yyvsp[(1) - (2)].interm.type))) {
            parseContext.recover();
            (yyvsp[(2) - (2)].interm.type).setArray(false);
        }
        
        if ((yyvsp[(1) - (2)].interm.type).qualifier == EvqAttribute &&
            ((yyvsp[(2) - (2)].interm.type).type == EbtBool || (yyvsp[(2) - (2)].interm.type).type == EbtInt)) {
            parseContext.error((yyvsp[(2) - (2)].interm.type).line, "cannot be bool or int", getQualifierString((yyvsp[(1) - (2)].interm.type).qualifier), "");
            parseContext.recover();
        }
        if (((yyvsp[(1) - (2)].interm.type).qualifier == EvqVaryingIn || (yyvsp[(1) - (2)].interm.type).qualifier == EvqVaryingOut) &&
            ((yyvsp[(2) - (2)].interm.type).type == EbtBool || (yyvsp[(2) - (2)].interm.type).type == EbtInt)) {
            parseContext.error((yyvsp[(2) - (2)].interm.type).line, "cannot be bool or int", getQualifierString((yyvsp[(1) - (2)].interm.type).qualifier), "");
            parseContext.recover();
        }
        (yyval.interm.type) = (yyvsp[(2) - (2)].interm.type); 
        (yyval.interm.type).qualifier = (yyvsp[(1) - (2)].interm.type).qualifier;
    }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 1704 "glslang.y"
    {
        (yyval.interm.type).setBasic(EbtVoid, EvqConst, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 1707 "glslang.y"
    { 
        VERTEX_ONLY("attribute", (yyvsp[(1) - (1)].lex).line);
        if (parseContext.globalErrorCheck((yyvsp[(1) - (1)].lex).line, parseContext.symbolTable.atGlobalLevel(), "attribute"))
            parseContext.recover();
        (yyval.interm.type).setBasic(EbtVoid, EvqAttribute, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 1713 "glslang.y"
    {
        if (parseContext.globalErrorCheck((yyvsp[(1) - (1)].lex).line, parseContext.symbolTable.atGlobalLevel(), "varying"))
            parseContext.recover();
        if (parseContext.language == EShLangVertex)
            (yyval.interm.type).setBasic(EbtVoid, EvqVaryingOut, (yyvsp[(1) - (1)].lex).line);
        else
            (yyval.interm.type).setBasic(EbtVoid, EvqVaryingIn, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 1721 "glslang.y"
    {
        if (parseContext.globalErrorCheck((yyvsp[(1) - (1)].lex).line, parseContext.symbolTable.atGlobalLevel(), "uniform"))
            parseContext.recover();
        (yyval.interm.type).setBasic(EbtVoid, EvqUniform, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1729 "glslang.y"
    {
        (yyval.interm.type) = (yyvsp[(1) - (1)].interm.type);
    }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1732 "glslang.y"
    {
        (yyval.interm.type) = (yyvsp[(1) - (4)].interm.type);
        
        if (parseContext.arrayTypeErrorCheck((yyvsp[(2) - (4)].lex).line, (yyvsp[(1) - (4)].interm.type)))
            parseContext.recover();
        else {
            int size;
            if (parseContext.arraySizeErrorCheck((yyvsp[(2) - (4)].lex).line, (yyvsp[(3) - (4)].interm.intermTypedNode), size))
                parseContext.recover();
            (yyval.interm.type).setArray(true, size);
        }
    }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 1747 "glslang.y"
    {
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtVoid, qual, (yyvsp[(1) - (1)].lex).line); 
    }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 1751 "glslang.y"
    {
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtFloat, qual, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 1755 "glslang.y"
    {
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtInt, qual, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 1759 "glslang.y"
    {
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtBool, qual, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 1768 "glslang.y"
    {
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtFloat, qual, (yyvsp[(1) - (1)].lex).line);
        (yyval.interm.type).setAggregate(2);
    }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 1773 "glslang.y"
    {
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtFloat, qual, (yyvsp[(1) - (1)].lex).line);
        (yyval.interm.type).setAggregate(3);
    }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 1778 "glslang.y"
    {
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtFloat, qual, (yyvsp[(1) - (1)].lex).line);
        (yyval.interm.type).setAggregate(4);
    }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 1783 "glslang.y"
    {
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtBool, qual, (yyvsp[(1) - (1)].lex).line);
        (yyval.interm.type).setAggregate(2);
    }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 1788 "glslang.y"
    {
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtBool, qual, (yyvsp[(1) - (1)].lex).line);
        (yyval.interm.type).setAggregate(3);
    }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 1793 "glslang.y"
    {
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtBool, qual, (yyvsp[(1) - (1)].lex).line);
        (yyval.interm.type).setAggregate(4);
    }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 1798 "glslang.y"
    {
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtInt, qual, (yyvsp[(1) - (1)].lex).line);
        (yyval.interm.type).setAggregate(2);
    }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 1803 "glslang.y"
    {
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtInt, qual, (yyvsp[(1) - (1)].lex).line);
        (yyval.interm.type).setAggregate(3);
    }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 1808 "glslang.y"
    {
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtInt, qual, (yyvsp[(1) - (1)].lex).line);
        (yyval.interm.type).setAggregate(4);
    }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 1813 "glslang.y"
    {
        FRAG_VERT_ONLY("mat2", (yyvsp[(1) - (1)].lex).line); 
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtFloat, qual, (yyvsp[(1) - (1)].lex).line);
        (yyval.interm.type).setAggregate(2, true);
    }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 1819 "glslang.y"
    { 
        FRAG_VERT_ONLY("mat3", (yyvsp[(1) - (1)].lex).line); 
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtFloat, qual, (yyvsp[(1) - (1)].lex).line);
        (yyval.interm.type).setAggregate(3, true);
    }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 1825 "glslang.y"
    { 
        FRAG_VERT_ONLY("mat4", (yyvsp[(1) - (1)].lex).line);
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtFloat, qual, (yyvsp[(1) - (1)].lex).line);
        (yyval.interm.type).setAggregate(4, true);
    }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 1831 "glslang.y"
    {
        FRAG_VERT_ONLY("sampler1D", (yyvsp[(1) - (1)].lex).line);
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtSampler1D, qual, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 1836 "glslang.y"
    {
        FRAG_VERT_ONLY("sampler2D", (yyvsp[(1) - (1)].lex).line);
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtSampler2D, qual, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 1841 "glslang.y"
    {
        FRAG_VERT_ONLY("sampler3D", (yyvsp[(1) - (1)].lex).line);
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtSampler3D, qual, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 1846 "glslang.y"
    {
        FRAG_VERT_ONLY("samplerCube", (yyvsp[(1) - (1)].lex).line);
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtSamplerCube, qual, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 1851 "glslang.y"
    {
        FRAG_VERT_ONLY("sampler1DShadow", (yyvsp[(1) - (1)].lex).line);
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtSampler1DShadow, qual, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1856 "glslang.y"
    {
        FRAG_VERT_ONLY("sampler2DShadow", (yyvsp[(1) - (1)].lex).line);
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtSampler2DShadow, qual, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1861 "glslang.y"
    {
        // ARB_texture_rectangle

        FRAG_VERT_ONLY("samplerRectARB", (yyvsp[(1) - (1)].lex).line);
        if (parseContext.extensionErrorCheck((yyvsp[(1) - (1)].lex).line, "GL_ARB_texture_rectangle"))
            parseContext.recover();
        
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtSamplerRect, qual, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1871 "glslang.y"
    {
        // ARB_texture_rectangle

        FRAG_VERT_ONLY("samplerRectShadowARB", (yyvsp[(1) - (1)].lex).line);
        if (parseContext.extensionErrorCheck((yyvsp[(1) - (1)].lex).line, "GL_ARB_texture_rectangle"))
            parseContext.recover();

        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtSamplerRectShadow, qual, (yyvsp[(1) - (1)].lex).line);
    }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1881 "glslang.y"
    {
        FRAG_VERT_ONLY("struct", (yyvsp[(1) - (1)].interm.type).line);
        (yyval.interm.type) = (yyvsp[(1) - (1)].interm.type);
        (yyval.interm.type).qualifier = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
    }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1886 "glslang.y"
    {     
        //
        // This is for user defined type names.  The lexical phase looked up the 
        // type.
        //
        TType& structure = static_cast<TVariable*>((yyvsp[(1) - (1)].lex).symbol)->getType();
        TQualifier qual = parseContext.symbolTable.atGlobalLevel() ? EvqGlobal : EvqTemporary;
        (yyval.interm.type).setBasic(EbtStruct, qual, (yyvsp[(1) - (1)].lex).line);
        (yyval.interm.type).userDef = &structure;
    }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1899 "glslang.y"
    {
        TType* structure = new TType((yyvsp[(4) - (5)].interm.typeList), *(yyvsp[(2) - (5)].lex).string);
        TVariable* userTypeDef = new TVariable((yyvsp[(2) - (5)].lex).string, *structure, true);
        if (! parseContext.symbolTable.insert(*userTypeDef)) {
            parseContext.error((yyvsp[(2) - (5)].lex).line, "redefinition", (yyvsp[(2) - (5)].lex).string->c_str(), "struct");
            parseContext.recover();
        }
        (yyval.interm.type).setBasic(EbtStruct, EvqTemporary, (yyvsp[(1) - (5)].lex).line);
        (yyval.interm.type).userDef = structure;
    }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1909 "glslang.y"
    {
        TType* structure = new TType((yyvsp[(3) - (4)].interm.typeList), TString(""));
        (yyval.interm.type).setBasic(EbtStruct, EvqTemporary, (yyvsp[(1) - (4)].lex).line);
        (yyval.interm.type).userDef = structure;
    }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1917 "glslang.y"
    {
        (yyval.interm.typeList) = (yyvsp[(1) - (1)].interm.typeList);
    }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1920 "glslang.y"
    {
        (yyval.interm.typeList) = (yyvsp[(1) - (2)].interm.typeList);
        for (unsigned int i = 0; i < (yyvsp[(2) - (2)].interm.typeList)->size(); ++i) {
            for (unsigned int j = 0; j < (yyval.interm.typeList)->size(); ++j) {
                if ((*(yyval.interm.typeList))[j].type->getFieldName() == (*(yyvsp[(2) - (2)].interm.typeList))[i].type->getFieldName()) {
                    parseContext.error((*(yyvsp[(2) - (2)].interm.typeList))[i].line, "duplicate field name in structure:", "struct", (*(yyvsp[(2) - (2)].interm.typeList))[i].type->getFieldName().c_str());
                    parseContext.recover();
                }
            }
            (yyval.interm.typeList)->push_back((*(yyvsp[(2) - (2)].interm.typeList))[i]);
        }
    }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1935 "glslang.y"
    {
        (yyval.interm.typeList) = (yyvsp[(2) - (3)].interm.typeList);
        
        if (parseContext.voidErrorCheck((yyvsp[(1) - (3)].interm.type).line, (*(yyvsp[(2) - (3)].interm.typeList))[0].type->getFieldName(), (yyvsp[(1) - (3)].interm.type))) {
            parseContext.recover();
        }
        for (unsigned int i = 0; i < (yyval.interm.typeList)->size(); ++i) {
            //
            // Careful not to replace already know aspects of type, like array-ness
            //
            (*(yyval.interm.typeList))[i].type->setType((yyvsp[(1) - (3)].interm.type).type, (yyvsp[(1) - (3)].interm.type).size, (yyvsp[(1) - (3)].interm.type).matrix, (yyvsp[(1) - (3)].interm.type).userDef);

            // don't allow arrays of arrays
            if ((*(yyval.interm.typeList))[i].type->isArray()) {
                if (parseContext.arrayTypeErrorCheck((yyvsp[(1) - (3)].interm.type).line, (yyvsp[(1) - (3)].interm.type)))
                    parseContext.recover();
            }
            if ((yyvsp[(1) - (3)].interm.type).array)
                (*(yyval.interm.typeList))[i].type->setArraySize((yyvsp[(1) - (3)].interm.type).arraySize);
            if ((yyvsp[(1) - (3)].interm.type).userDef)
                (*(yyval.interm.typeList))[i].type->setTypeName((yyvsp[(1) - (3)].interm.type).userDef->getTypeName());
        }
    }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1961 "glslang.y"
    {
        (yyval.interm.typeList) = NewPoolTTypeList();
        (yyval.interm.typeList)->push_back((yyvsp[(1) - (1)].interm.typeLine));
    }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1965 "glslang.y"
    {
        (yyval.interm.typeList)->push_back((yyvsp[(3) - (3)].interm.typeLine));
    }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1971 "glslang.y"
    {
        (yyval.interm.typeLine).type = new TType(EbtVoid);
        (yyval.interm.typeLine).line = (yyvsp[(1) - (1)].lex).line;
        (yyval.interm.typeLine).type->setFieldName(*(yyvsp[(1) - (1)].lex).string);
    }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1976 "glslang.y"
    {
        (yyval.interm.typeLine).type = new TType(EbtVoid);
        (yyval.interm.typeLine).line = (yyvsp[(1) - (4)].lex).line;
        (yyval.interm.typeLine).type->setFieldName(*(yyvsp[(1) - (4)].lex).string);
        
        int size;
        if (parseContext.arraySizeErrorCheck((yyvsp[(2) - (4)].lex).line, (yyvsp[(3) - (4)].interm.intermTypedNode), size))
            parseContext.recover();
        (yyval.interm.typeLine).type->setArraySize(size);
    }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1989 "glslang.y"
    { (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1993 "glslang.y"
    { (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode); }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1997 "glslang.y"
    { (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermAggregate); }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1998 "glslang.y"
    { (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode); }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 2004 "glslang.y"
    { (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode); }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 2005 "glslang.y"
    { (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode); }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 2006 "glslang.y"
    { (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode); }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 2007 "glslang.y"
    { (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode); }
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 2008 "glslang.y"
    { (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode); }
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 2012 "glslang.y"
    { (yyval.interm.intermAggregate) = 0; }
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 2013 "glslang.y"
    { parseContext.symbolTable.push(); }
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 2013 "glslang.y"
    { parseContext.symbolTable.pop(); }
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 2013 "glslang.y"
    {
        if ((yyvsp[(3) - (5)].interm.intermAggregate) != 0)            
            (yyvsp[(3) - (5)].interm.intermAggregate)->setOperator(EOpSequence); 
        (yyval.interm.intermAggregate) = (yyvsp[(3) - (5)].interm.intermAggregate);
    }
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 2021 "glslang.y"
    { (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode); }
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 2022 "glslang.y"
    { (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode); }
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 2027 "glslang.y"
    { 
        (yyval.interm.intermNode) = 0; 
    }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 2030 "glslang.y"
    { 
        if ((yyvsp[(2) - (3)].interm.intermAggregate))
            (yyvsp[(2) - (3)].interm.intermAggregate)->setOperator(EOpSequence); 
        (yyval.interm.intermNode) = (yyvsp[(2) - (3)].interm.intermAggregate); 
    }
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 2038 "glslang.y"
    {
        (yyval.interm.intermAggregate) = parseContext.intermediate.makeAggregate((yyvsp[(1) - (1)].interm.intermNode), 0); 
    }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 2041 "glslang.y"
    { 
        (yyval.interm.intermAggregate) = parseContext.intermediate.growAggregate((yyvsp[(1) - (2)].interm.intermAggregate), (yyvsp[(2) - (2)].interm.intermNode), 0);
    }
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 2047 "glslang.y"
    { (yyval.interm.intermNode) = 0; }
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 2048 "glslang.y"
    { (yyval.interm.intermNode) = static_cast<TIntermNode*>((yyvsp[(1) - (2)].interm.intermTypedNode)); }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 2052 "glslang.y"
    { 
        if (parseContext.boolErrorCheck((yyvsp[(1) - (5)].lex).line, (yyvsp[(3) - (5)].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermNode) = parseContext.intermediate.addSelection((yyvsp[(3) - (5)].interm.intermTypedNode), (yyvsp[(5) - (5)].interm.nodePair), (yyvsp[(1) - (5)].lex).line);
    }
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 2060 "glslang.y"
    {
        (yyval.interm.nodePair).node1 = (yyvsp[(1) - (3)].interm.intermNode);
        (yyval.interm.nodePair).node2 = (yyvsp[(3) - (3)].interm.intermNode);
    }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 2064 "glslang.y"
    { 
        (yyval.interm.nodePair).node1 = (yyvsp[(1) - (1)].interm.intermNode);
        (yyval.interm.nodePair).node2 = 0;
    }
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 2074 "glslang.y"
    {
        (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode);
        if (parseContext.boolErrorCheck((yyvsp[(1) - (1)].interm.intermTypedNode)->getLine(), (yyvsp[(1) - (1)].interm.intermTypedNode)))
            parseContext.recover();          
    }
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 2079 "glslang.y"
    {
        TIntermNode* intermNode;
        if (parseContext.structQualifierErrorCheck((yyvsp[(2) - (4)].lex).line, (yyvsp[(1) - (4)].interm.type)))
            parseContext.recover();
        if (parseContext.boolErrorCheck((yyvsp[(2) - (4)].lex).line, (yyvsp[(1) - (4)].interm.type)))
            parseContext.recover();
        
        if (!parseContext.executeInitializer((yyvsp[(2) - (4)].lex).line, *(yyvsp[(2) - (4)].lex).string, (yyvsp[(1) - (4)].interm.type), (yyvsp[(4) - (4)].interm.intermTypedNode), intermNode))
            (yyval.interm.intermTypedNode) = (yyvsp[(4) - (4)].interm.intermTypedNode);
        else {
            parseContext.recover();
            (yyval.interm.intermTypedNode) = 0;
        }
    }
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 2096 "glslang.y"
    { parseContext.symbolTable.push(); ++parseContext.loopNestingLevel; }
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 2096 "glslang.y"
    { 
        parseContext.symbolTable.pop();
        (yyval.interm.intermNode) = parseContext.intermediate.addLoop((yyvsp[(6) - (6)].interm.intermNode), (yyvsp[(4) - (6)].interm.intermTypedNode), 0, true, (yyvsp[(1) - (6)].lex).line);
        --parseContext.loopNestingLevel;
    }
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 2101 "glslang.y"
    { ++parseContext.loopNestingLevel; }
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 2101 "glslang.y"
    {
        if (parseContext.boolErrorCheck((yyvsp[(8) - (8)].lex).line, (yyvsp[(6) - (8)].interm.intermTypedNode)))
            parseContext.recover();
                    
        (yyval.interm.intermNode) = parseContext.intermediate.addLoop((yyvsp[(3) - (8)].interm.intermNode), (yyvsp[(6) - (8)].interm.intermTypedNode), 0, false, (yyvsp[(4) - (8)].lex).line);
        --parseContext.loopNestingLevel;
    }
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 2108 "glslang.y"
    { parseContext.symbolTable.push(); ++parseContext.loopNestingLevel; }
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 2108 "glslang.y"
    {
        parseContext.symbolTable.pop();
        (yyval.interm.intermNode) = parseContext.intermediate.makeAggregate((yyvsp[(4) - (7)].interm.intermNode), (yyvsp[(2) - (7)].lex).line);
        (yyval.interm.intermNode) = parseContext.intermediate.growAggregate(
                (yyval.interm.intermNode),
                parseContext.intermediate.addLoop((yyvsp[(7) - (7)].interm.intermNode), reinterpret_cast<TIntermTyped*>((yyvsp[(5) - (7)].interm.nodePair).node1), reinterpret_cast<TIntermTyped*>((yyvsp[(5) - (7)].interm.nodePair).node2), true, (yyvsp[(1) - (7)].lex).line),
                (yyvsp[(1) - (7)].lex).line);
        (yyval.interm.intermNode)->getAsAggregate()->setOperator(EOpSequence);
        --parseContext.loopNestingLevel;
    }
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 2121 "glslang.y"
    {
        (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode); 
    }
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 2124 "glslang.y"
    {
        (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode);
    }
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 2130 "glslang.y"
    { 
        (yyval.interm.intermTypedNode) = (yyvsp[(1) - (1)].interm.intermTypedNode); 
    }
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 2133 "glslang.y"
    { 
        (yyval.interm.intermTypedNode) = 0; 
    }
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 2139 "glslang.y"
    { 
        (yyval.interm.nodePair).node1 = (yyvsp[(1) - (2)].interm.intermTypedNode);
        (yyval.interm.nodePair).node2 = 0;
    }
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 2143 "glslang.y"
    {
        (yyval.interm.nodePair).node1 = (yyvsp[(1) - (3)].interm.intermTypedNode);
        (yyval.interm.nodePair).node2 = (yyvsp[(3) - (3)].interm.intermTypedNode);
    }
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 2150 "glslang.y"
    {
        if (parseContext.loopNestingLevel <= 0) {
            parseContext.error((yyvsp[(1) - (2)].lex).line, "continue statement only allowed in loops", "", "");
            parseContext.recover();
        }        
        (yyval.interm.intermNode) = parseContext.intermediate.addBranch(EOpContinue, (yyvsp[(1) - (2)].lex).line);
    }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 2157 "glslang.y"
    {
        if (parseContext.loopNestingLevel <= 0) {
            parseContext.error((yyvsp[(1) - (2)].lex).line, "break statement only allowed in loops", "", "");
            parseContext.recover();
        }        
        (yyval.interm.intermNode) = parseContext.intermediate.addBranch(EOpBreak, (yyvsp[(1) - (2)].lex).line);
    }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 2164 "glslang.y"
    {
        (yyval.interm.intermNode) = parseContext.intermediate.addBranch(EOpReturn, (yyvsp[(1) - (2)].lex).line);
        if (parseContext.currentFunctionType->getBasicType() != EbtVoid) {
            parseContext.error((yyvsp[(1) - (2)].lex).line, "non-void function must return a value", "return", "");
            parseContext.recover();
        }
    }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 2171 "glslang.y"
    {        
        (yyval.interm.intermNode) = parseContext.intermediate.addBranch(EOpReturn, (yyvsp[(2) - (3)].interm.intermTypedNode), (yyvsp[(1) - (3)].lex).line);
        parseContext.functionReturnsValue = true;
        if (parseContext.currentFunctionType->getBasicType() == EbtVoid) {
            parseContext.error((yyvsp[(1) - (3)].lex).line, "void function cannot return a value", "return", "");
            parseContext.recover();
        } else if (*(parseContext.currentFunctionType) != (yyvsp[(2) - (3)].interm.intermTypedNode)->getType()) {
            parseContext.error((yyvsp[(1) - (3)].lex).line, "function return is not matching type:", "return", "");
            parseContext.recover();
        }
    }
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 2182 "glslang.y"
    {
        FRAG_ONLY("discard", (yyvsp[(1) - (2)].lex).line);
        (yyval.interm.intermNode) = parseContext.intermediate.addBranch(EOpKill, (yyvsp[(1) - (2)].lex).line);
    }
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 2191 "glslang.y"
    { 
        (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode); 
        parseContext.treeRoot = (yyval.interm.intermNode); 
    }
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 2195 "glslang.y"
    {
        (yyval.interm.intermNode) = parseContext.intermediate.growAggregate((yyvsp[(1) - (2)].interm.intermNode), (yyvsp[(2) - (2)].interm.intermNode), 0);
        parseContext.treeRoot = (yyval.interm.intermNode);
    }
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 2202 "glslang.y"
    { 
        (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode); 
    }
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 2205 "glslang.y"
    { 
        (yyval.interm.intermNode) = (yyvsp[(1) - (1)].interm.intermNode); 
    }
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 2211 "glslang.y"
    {
        TFunction& function = *((yyvsp[(1) - (1)].interm).function);
        TFunction* prevDec = static_cast<TFunction*>(parseContext.symbolTable.find(function.getMangledName()));
        //
        // Note:  'prevDec' could be 'function' if this is the first time we've seen function
        // as it would have just been put in the symbol table.  Otherwise, we're looking up
        // an earlier occurance.
        //
        if (prevDec->isDefined()) {
            //
            // Then this function already has a body.
            //
            parseContext.error((yyvsp[(1) - (1)].interm).line, "function already has a body", function.getName().c_str(), "");
            parseContext.recover();
        }
        prevDec->setDefined();
        
        //
        // Raise error message if main function takes any parameters or return anything other than void
        //
        if (function.getName() == "main") {
            if (function.getParamCount() > 0) {
                parseContext.error((yyvsp[(1) - (1)].interm).line, "function cannot take any parameter(s)", function.getName().c_str(), "");
                parseContext.recover();
            }
            if (function.getReturnType().getBasicType() != EbtVoid) {
                parseContext.error((yyvsp[(1) - (1)].interm).line, "", function.getReturnType().getBasicString(), "main function cannot return a value");
                parseContext.recover();
            }            
        }
   
        //
        // New symbol table scope for body of function plus its arguments
        //
        parseContext.symbolTable.push();
        
        //
        // Remember the return type for later checking for RETURN statements.
        //
        parseContext.currentFunctionType = &(prevDec->getReturnType());
        parseContext.functionReturnsValue = false;
        
        // 
        // Insert parameters into the symbol table.
        // If the parameter has no name, it's not an error, just don't insert it 
        // (could be used for unused args).
        //
        // Also, accumulate the list of parameters into the HIL, so lower level code
        // knows where to find parameters.
        //
        TIntermAggregate* paramNodes = new TIntermAggregate;
        for (int i = 0; i < function.getParamCount(); i++) {
            TParameter& param = function[i];
            if (param.name != 0) {
                TVariable *variable = new TVariable(param.name, *param.type);
                // 
                // Insert the parameters with name in the symbol table.
                //
                if (! parseContext.symbolTable.insert(*variable)) {
                    parseContext.error((yyvsp[(1) - (1)].interm).line, "redefinition", variable->getName().c_str(), "");
                    parseContext.recover();
                    delete variable;
                }
                //
                // Transfer ownership of name pointer to symbol table.
                //
                param.name = 0;
                
                //
                // Add the parameter to the HIL
                //                
                paramNodes = parseContext.intermediate.growAggregate(
                                               paramNodes, 
                                               parseContext.intermediate.addSymbol(variable->getUniqueId(),
                                                                       variable->getName(),
                                                                       variable->getType(), (yyvsp[(1) - (1)].interm).line), 
                                               (yyvsp[(1) - (1)].interm).line);
            } else {
                paramNodes = parseContext.intermediate.growAggregate(paramNodes, parseContext.intermediate.addSymbol(0, "", *param.type, (yyvsp[(1) - (1)].interm).line), (yyvsp[(1) - (1)].interm).line);
            }
        }
        parseContext.intermediate.setAggregateOperator(paramNodes, EOpParameters, (yyvsp[(1) - (1)].interm).line);
        (yyvsp[(1) - (1)].interm).intermAggregate = paramNodes;
        parseContext.loopNestingLevel = 0;
    }
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 2296 "glslang.y"
    {
        //?? Check that all paths return a value if return type != void ?
        //   May be best done as post process phase on intermediate code
        if (parseContext.currentFunctionType->getBasicType() != EbtVoid && ! parseContext.functionReturnsValue) {
            parseContext.error((yyvsp[(1) - (3)].interm).line, "function does not return a value:", "", (yyvsp[(1) - (3)].interm).function->getName().c_str());
            parseContext.recover();
        }
        parseContext.symbolTable.pop();
        (yyval.interm.intermNode) = parseContext.intermediate.growAggregate((yyvsp[(1) - (3)].interm).intermAggregate, (yyvsp[(3) - (3)].interm.intermNode), 0);
        parseContext.intermediate.setAggregateOperator((yyval.interm.intermNode), EOpFunction, (yyvsp[(1) - (3)].interm).line);
        (yyval.interm.intermNode)->getAsAggregate()->setName((yyvsp[(1) - (3)].interm).function->getMangledName().c_str());
        (yyval.interm.intermNode)->getAsAggregate()->setType((yyvsp[(1) - (3)].interm).function->getReturnType());
        
        // store the pragma information for debug and optimize and other vendor specific 
        // information. This information can be queried from the parse tree
        (yyval.interm.intermNode)->getAsAggregate()->setOptimize(parseContext.contextPragma.optimize);
        (yyval.interm.intermNode)->getAsAggregate()->setDebug(parseContext.contextPragma.debug);
        (yyval.interm.intermNode)->getAsAggregate()->addToPragmaTable(parseContext.contextPragma.pragmaTable);
    }
    break;



/* Line 1806 of yacc.c  */
#line 5161 "glslang.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 2317 "glslang.y"


