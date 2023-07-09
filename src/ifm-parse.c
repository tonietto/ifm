/*
 * This file is part of IFM (Interactive Fiction Mapper), copyright (C)
 * Glenn Hutchings 1997-2015.
 *
 * IFM comes with ABSOLUTELY NO WARRANTY.  This is free software, and you
 * are welcome to redistribute it under certain conditions; see the file
 * COPYING for details.
 */

/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ifm-parse.y" /* yacc.c:337  */

/* Input parser */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vars.h>

#include "ifm-main.h"
#include "ifm-map.h"
#include "ifm-util.h"
#include "ifm-vars.h"

#define SET_LIST(object, attr, list) {                                  \
        vlist *l = vh_pget(object, attr);                               \
        if (l == NULL) {                                                \
            vh_pstore(object, attr, list);                              \
            list = NULL;                                                \
        } else {                                                        \
            vl_append(l, list);                                         \
            vl_destroy(list);                                           \
            list = NULL;                                                \
        }                                                               \
}

#define ATTR(name) \
        (implicit ? "LINK_" #name : #name)

#define RESET RESET_IT; RESET_THEM

#define RESET_IT                                                        \
        RESET_VAR(itroom);                                              \
        RESET_VAR(ititem);                                              \
        RESET_VAR(ittask)

#define RESET_THEM                                                      \
        { if (themitems != NULL) vl_destroy(themitems); themitems = NULL; }

#define RESET_VAR(var) if (var != NULL) { vs_destroy(var); var = NULL; }

#define WARN_IGNORED(attr)                                              \
        warn("attribute '%s' ignored -- no implicit link", #attr)

#define CHANGE_ERROR(attr)                                              \
        err("can't modify '%s' attribute", #attr)

static vhash *curobj = NULL;    /* Current object */

static vlist *currooms = NULL;  /* Current room list */
static vlist *curitems = NULL;  /* Current item list */
static vlist *curtasks = NULL;  /* Current task list */

static vhash *lastroom = NULL;  /* Last room mentioned */
static vhash *lastitem = NULL;  /* Last item mentioned */
static vhash *lasttask = NULL;  /* Last task mentioned */

static vscalar *itroom = NULL;  /* Room referred to by 'it' */
static vscalar *ititem = NULL;  /* Item referred to by 'it' */
static vscalar *ittask = NULL;  /* Task referred to by 'it' */

static vlist *themitems = NULL; /* Items referred to by 'them' */

static int roomid = 0;          /* Current room ID */
static int itemid = 0;          /* Current item ID */

static vlist *curdirs = NULL;   /* Current direction list */

static int modify = 0;          /* Modification flag */
static int implicit = 0;        /* Implicit-link flag */
static int allflag = 0;         /* All-items flag */
static int repeat = 0;          /* String repeat count */
static int instyle = 0;         /* Set variable in different style? */

extern int yylex(void);

void
init_parser(void)
{
    curobj = NULL;
    currooms = curitems = curtasks = NULL;
    lastroom = lastitem = lasttask = NULL;
    itroom = ititem = ittask = NULL;
    themitems = NULL;

    roomid = itemid = 0;
    curdirs = NULL;

    modify = implicit = allflag = repeat = instyle = 0;
}

#line 165 "ifm-parse.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
#ifndef YY_YY_IFM_PARSE_H_INCLUDED
# define YY_YY_IFM_PARSE_H_INCLUDED
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
    ROOM = 258,
    ITEM = 259,
    LINK = 260,
    FROM = 261,
    TAG = 262,
    TO = 263,
    DIR = 264,
    ONEWAY = 265,
    HIDDEN = 266,
    NODROP = 267,
    NOTE = 268,
    TASK = 269,
    AFTER = 270,
    NEED = 271,
    GET = 272,
    SCORE = 273,
    JOIN = 274,
    GO = 275,
    REQUIRE = 276,
    ANY = 277,
    LAST = 278,
    START = 279,
    GOTO = 280,
    MAP = 281,
    EXIT = 282,
    GIVEN = 283,
    LOST = 284,
    KEEP = 285,
    LENGTH = 286,
    TITLE = 287,
    LOSE = 288,
    SAFE = 289,
    BEFORE = 290,
    FOLLOW = 291,
    CMD = 292,
    LEAVE = 293,
    UNDEF = 294,
    FINISH = 295,
    GIVE = 296,
    DROP = 297,
    ALL = 298,
    EXCEPT = 299,
    IT = 300,
    UNTIL = 301,
    TIMES = 302,
    NOLINK = 303,
    NOPATH = 304,
    NONE = 305,
    STYLE = 306,
    ENDSTYLE = 307,
    WITH = 308,
    IGNORE = 309,
    DO = 310,
    THEM = 311,
    NORTH = 312,
    EAST = 313,
    SOUTH = 314,
    WEST = 315,
    NORTHEAST = 316,
    NORTHWEST = 317,
    SOUTHEAST = 318,
    SOUTHWEST = 319,
    UP = 320,
    DOWN = 321,
    IN = 322,
    OUT = 323,
    INTEGER = 324,
    TRUE = 325,
    FALSE = 326,
    REAL = 327,
    STRING = 328,
    ID = 329
  };
#endif
/* Tokens.  */
#define ROOM 258
#define ITEM 259
#define LINK 260
#define FROM 261
#define TAG 262
#define TO 263
#define DIR 264
#define ONEWAY 265
#define HIDDEN 266
#define NODROP 267
#define NOTE 268
#define TASK 269
#define AFTER 270
#define NEED 271
#define GET 272
#define SCORE 273
#define JOIN 274
#define GO 275
#define REQUIRE 276
#define ANY 277
#define LAST 278
#define START 279
#define GOTO 280
#define MAP 281
#define EXIT 282
#define GIVEN 283
#define LOST 284
#define KEEP 285
#define LENGTH 286
#define TITLE 287
#define LOSE 288
#define SAFE 289
#define BEFORE 290
#define FOLLOW 291
#define CMD 292
#define LEAVE 293
#define UNDEF 294
#define FINISH 295
#define GIVE 296
#define DROP 297
#define ALL 298
#define EXCEPT 299
#define IT 300
#define UNTIL 301
#define TIMES 302
#define NOLINK 303
#define NOPATH 304
#define NONE 305
#define STYLE 306
#define ENDSTYLE 307
#define WITH 308
#define IGNORE 309
#define DO 310
#define THEM 311
#define NORTH 312
#define EAST 313
#define SOUTH 314
#define WEST 315
#define NORTHEAST 316
#define NORTHWEST 317
#define SOUTHEAST 318
#define SOUTHWEST 319
#define UP 320
#define DOWN 321
#define IN 322
#define OUT 323
#define INTEGER 324
#define TRUE 325
#define FALSE 326
#define REAL 327
#define STRING 328
#define ID 329

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 96 "ifm-parse.y" /* yacc.c:352  */

    int ival;
    double dval;
    char *sval;
    vscalar *vval;

#line 363 "ifm-parse.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_IFM_PARSE_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   606

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  202
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  329

#define YYUNDEFTOK  2
#define YYMAXUTOK   329

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    75,
       2,    76,     2,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   130,   131,   134,   135,   136,   137,   138,
     139,   140,   141,   148,   152,   158,   173,   172,   275,   274,
     289,   290,   293,   300,   318,   333,   346,   363,   380,   384,
     388,   392,   396,   400,   404,   408,   412,   416,   420,   426,
     430,   434,   439,   444,   449,   453,   456,   457,   460,   468,
     473,   480,   496,   495,   513,   512,   526,   527,   530,   537,
     541,   545,   549,   554,   558,   562,   566,   570,   574,   578,
     582,   586,   590,   594,   597,   598,   599,   612,   613,   614,
     617,   631,   636,   643,   659,   658,   672,   671,   685,   686,
     689,   694,   698,   702,   706,   710,   714,   718,   722,   728,
     732,   737,   742,   747,   754,   762,   761,   775,   774,   788,
     789,   792,   796,   800,   804,   808,   812,   816,   820,   824,
     830,   834,   839,   844,   849,   856,   864,   863,   882,   881,
     895,   896,   899,   906,   910,   914,   918,   922,   926,   932,
     939,   946,   954,   958,   963,   967,   971,   975,   979,   983,
     987,   991,   995,   999,  1003,  1008,  1012,  1016,  1019,  1020,
    1023,  1031,  1036,  1043,  1058,  1066,  1070,  1075,  1079,  1084,
    1088,  1095,  1096,  1107,  1111,  1115,  1121,  1122,  1125,  1136,
    1137,  1140,  1146,  1155,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1177,  1178,  1179,  1180,  1187,  1188,  1189,  1190,
    1193,  1198,  1205
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ROOM", "ITEM", "LINK", "FROM", "TAG",
  "TO", "DIR", "ONEWAY", "HIDDEN", "NODROP", "NOTE", "TASK", "AFTER",
  "NEED", "GET", "SCORE", "JOIN", "GO", "REQUIRE", "ANY", "LAST", "START",
  "GOTO", "MAP", "EXIT", "GIVEN", "LOST", "KEEP", "LENGTH", "TITLE",
  "LOSE", "SAFE", "BEFORE", "FOLLOW", "CMD", "LEAVE", "UNDEF", "FINISH",
  "GIVE", "DROP", "ALL", "EXCEPT", "IT", "UNTIL", "TIMES", "NOLINK",
  "NOPATH", "NONE", "STYLE", "ENDSTYLE", "WITH", "IGNORE", "DO", "THEM",
  "NORTH", "EAST", "SOUTH", "WEST", "NORTHEAST", "NORTHWEST", "SOUTHEAST",
  "SOUTHWEST", "UP", "DOWN", "IN", "OUT", "INTEGER", "TRUE", "FALSE",
  "REAL", "STRING", "ID", "';'", "'='", "$accept", "stmt_list", "stmt",
  "ctrl_stmt", "room_stmt", "$@1", "$@2", "room_attrs", "room_attr",
  "room_list", "room_elt", "room", "item_stmt", "$@3", "$@4", "item_attrs",
  "item_attr", "item_list", "item_list_all", "item_elt", "item",
  "link_stmt", "$@5", "$@6", "link_attrs", "link_attr", "join_stmt", "$@7",
  "$@8", "join_attrs", "join_attr", "task_stmt", "$@9", "$@10",
  "task_attrs", "task_attr", "task_list", "task_elt", "task", "vars_stmt",
  "set_var", "in_style", "style_stmt", "style_list", "style_elt",
  "dir_list", "dir_elt", "compass", "otherdir", "number", "strings", YY_NULLPTR
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
     325,   326,   327,   328,   329,    59,    61
};
# endif

#define YYPACT_NINF -215

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-215)))

#define YYTABLE_NINF -50

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -215,    30,  -215,  -215,    45,    91,    -5,   105,    18,   255,
     -61,    -9,   -53,   111,   -52,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,    68,    77,  -215,  -215,    68,    82,  -215,  -215,  -215,
    -215,    20,    35,    38,    54,    62,  -215,    29,   216,  -215,
    -215,  -215,  -215,  -215,    57,  -215,  -215,  -215,    57,  -215,
    -215,  -215,  -215,  -215,   223,    73,    73,    73,   182,   229,
     348,   378,   424,  -215,  -215,   266,   298,   499,  -215,    73,
      73,    73,   117,    67,    95,    97,    57,   100,   420,  -215,
    -215,   103,    85,    32,   119,    57,   280,  -215,   420,   121,
      85,    -3,   110,  -215,  -215,  -215,   122,  -215,  -215,  -215,
     125,  -215,   130,    85,    32,   136,  -215,  -215,   116,    85,
    -215,   122,  -215,    57,  -215,  -215,  -215,   133,   420,  -215,
    -215,    85,    32,   280,   139,    85,     2,   110,  -215,   122,
    -215,  -215,  -215,   138,   141,    85,    32,    32,   149,    57,
      32,  -215,    85,   -23,  -215,    32,   137,   122,  -215,    85,
      -7,  -215,  -215,  -215,   147,  -215,  -215,    85,    32,   526,
     154,    85,     5,   110,  -215,   122,  -215,  -215,  -215,   135,
     150,   151,   153,  -215,  -215,  -215,    57,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,    87,  -215,
     -41,  -215,  -215,  -215,  -215,    85,  -215,  -215,  -215,  -215,
    -215,  -215,    89,  -215,  -215,  -215,    57,  -215,  -215,  -215,
    -215,  -215,   420,  -215,    85,   156,   156,    47,  -215,   188,
      89,  -215,  -215,   122,  -215,  -215,  -215,    85,    89,  -215,
      85,    32,    85,   122,  -215,  -215,   420,    85,    89,  -215,
    -215,    85,   156,   156,  -215,  -215,   122,   456,  -215,  -215,
      85,    89,    89,  -215,  -215,    89,  -215,  -215,  -215,    89,
      85,    57,    69,   122,    85,  -215,  -215,  -215,    85,    89,
    -215,  -215,  -215,    85,   156,   156,  -215,  -215,   122,   531,
    -215,  -215,  -215,  -215,  -215,   161,  -215,   168,  -215,  -215,
    -215,  -215,  -215,   171,  -215,    32,  -215,    85,    89,  -215,
    -215,  -215,    85,   197,    85,    57,  -215,  -215,  -215,  -215,
    -215,  -215,    89,    85,    85,   200,    85,    85,    85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     5,     6,     7,     8,
       9,    10,    11,   164,    12,    16,    18,    52,    54,    51,
      50,    86,     0,   126,   128,   107,     0,   196,   198,   199,
     197,     0,     0,     0,     0,     0,   175,     0,     0,    20,
      20,    56,    56,    88,     0,   130,   130,   109,     0,    15,
      14,    13,   173,   174,     0,   171,   171,   171,     0,     0,
       0,     0,     0,    49,    84,     0,     0,     0,   105,   171,
     171,   171,     0,     0,     0,     0,     0,     0,     0,    29,
      30,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,     0,     0,    34,    31,    32,     0,    17,    21,    19,
       0,    61,     0,     0,     0,     0,    62,    63,    65,     0,
      72,     0,    64,     0,    53,    57,    55,     0,     0,    92,
      93,     0,     0,     0,     0,     0,     0,     0,    94,     0,
      87,    89,    88,     0,     0,     0,     0,     0,     0,     0,
       0,   151,     0,     0,   153,     0,     0,     0,   150,     0,
       0,   127,   131,   129,     0,   113,   114,     0,     0,     0,
       0,     0,     0,     0,   115,     0,   108,   110,   109,     0,
       0,     0,     0,   169,   167,   165,    26,    46,    48,    22,
     184,   185,   186,   187,   188,   189,   190,   191,    24,   179,
     181,    44,   163,   162,   161,    37,   158,   160,    83,    82,
      76,    81,    35,    74,    80,    40,    27,   194,   195,   192,
     193,    28,    25,    39,    36,     0,     0,   200,    41,    78,
      77,    38,   178,    45,   176,    58,    60,    70,    68,    71,
       0,     0,    69,    73,    59,   103,    90,    97,    95,    91,
      99,    96,     0,     0,   100,    98,   104,     0,   132,   156,
     133,   134,   136,   152,   146,   145,   147,   155,   154,   135,
       0,     0,   138,   157,   137,   149,   148,   124,   118,   116,
     111,   112,   120,   117,     0,     0,   121,   119,   125,     0,
     170,   168,   166,   172,    47,     0,   180,     0,   182,   159,
      75,    43,    42,     0,   201,     0,   177,    67,    66,   102,
     101,    85,   144,   142,     0,     0,   123,   122,   106,    23,
     183,   202,    79,     0,   139,   140,   143,     0,   141
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -215,  -215,  -215,  -215,  -215,  -215,  -215,   201,  -215,   155,
    -179,    -6,  -215,  -215,  -215,   202,  -215,   -89,   -34,  -141,
    -215,  -215,  -215,  -215,   126,  -215,  -215,  -215,  -215,    74,
    -215,  -215,  -215,  -215,   203,  -215,   -99,  -151,   106,  -215,
    -215,   263,  -215,   -74,  -214,   -14,  -111,    92,  -116,   -25,
    -127
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    15,    16,    17,    49,    50,    68,   108,   186,
     187,   188,    18,    51,    52,    70,   125,   230,   231,   213,
     214,    19,   142,    53,    72,   141,    20,   178,    57,    77,
     177,    21,    55,    56,    75,   162,   205,   206,   207,    22,
      23,    83,    24,   233,   234,   198,   199,   200,   221,    41,
     228
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,   224,    36,   225,   212,   226,   297,   294,   252,   254,
     253,   284,    42,   285,   237,   275,    29,   249,    29,   306,
     242,    44,    47,    67,    48,   238,   268,   267,   298,   306,
       2,     3,   247,     4,     5,     6,   251,   294,    30,    81,
      30,    29,   306,   248,     7,   286,   260,   243,    74,     8,
     227,     9,    78,   281,   299,   208,    10,   261,   262,   306,
     274,   265,    11,    30,    43,   256,   269,    73,   278,    31,
     227,   300,   283,   299,   306,   227,   -49,   209,   227,   279,
      29,    12,    13,   273,   222,    54,   299,   296,   210,   300,
      58,   299,    35,   295,   303,    59,   299,   300,   301,   302,
     299,   288,    30,   255,    14,    64,   211,   300,   202,   299,
      60,   296,   208,    61,   246,   314,   304,   244,    25,    26,
     300,   300,   272,   299,   300,   309,   310,   299,   300,    62,
     203,    73,   299,   208,   209,   296,   315,    63,   300,   287,
      82,   307,   183,   264,   190,   191,   192,   193,   194,   195,
     196,   197,   308,   229,   276,   209,   299,   316,   317,   204,
     208,   299,   240,   211,    27,    28,   210,   300,   182,   241,
     184,   312,   185,   299,   189,   299,   201,   299,    33,    34,
     229,   300,   209,   270,   211,    45,    46,    86,   215,    87,
     223,    88,    89,   210,    90,    91,   232,    92,    93,   235,
      94,    95,    96,   236,   271,   239,    97,   245,   250,    98,
     290,   211,   258,    99,   259,   324,   322,   100,   263,   101,
     102,   277,   103,   282,   326,   291,   292,   293,   328,   227,
     104,   105,   305,   106,    86,   319,    87,   320,    88,    89,
     321,    90,    91,   323,    92,    93,   327,    94,    95,    96,
     216,    69,   289,    97,    71,    65,    98,   107,   266,    76,
      99,   280,    79,     0,   100,   313,   101,   102,   257,   103,
       0,     0,     0,   143,     0,     0,     0,   104,   105,   144,
     106,   145,   146,   147,   148,    37,    38,    39,    40,    66,
       0,   149,    37,    38,    39,    40,    80,     0,     0,   150,
     151,     0,   152,   153,   109,   143,   154,   155,   156,   325,
       0,   144,     0,   145,   146,   147,   148,   157,     0,     0,
     158,   159,     0,   149,    37,    38,    39,    40,     0,    84,
      85,   150,   151,   160,   152,   153,     0,     0,   154,   155,
     156,   161,   179,   180,   181,   217,   218,   219,   220,   157,
       0,     0,   158,   159,     0,   110,     0,     0,     0,   111,
       0,   112,     0,   113,   114,   160,   115,     0,     0,     0,
       0,     0,     0,   163,     0,     0,   116,   117,   118,     0,
       0,     0,     0,   119,     0,   110,     0,     0,   120,   111,
       0,   112,     0,   113,   114,     0,   115,     0,     0,   121,
       0,     0,   122,     0,     0,     0,   116,   117,   118,     0,
       0,     0,     0,   119,     0,   123,     0,     0,   120,     0,
       0,     0,     0,   124,     0,     0,     0,     0,     0,   121,
       0,   127,   122,   128,   129,   130,     0,     0,     0,   131,
     132,     0,     0,     0,   133,   123,     0,     0,     0,     0,
       0,     0,     0,   126,     0,   134,     0,     0,     0,   135,
       0,   136,   137,   127,     0,   128,   129,   130,     0,     0,
       0,   131,   132,   138,     0,   139,   133,   190,   191,   192,
     193,   194,   195,   196,   197,     0,     0,   134,     0,     0,
       0,   135,     0,   136,   137,     0,     0,     0,     0,   140,
       0,     0,     0,     0,     0,   138,   164,   139,     0,   165,
     166,     0,     0,     0,   167,   168,     0,     0,     0,   169,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,   311,     0,     0,   171,     0,   172,   173,   164,     0,
       0,   165,   166,     0,     0,     0,   167,   168,   174,     0,
     175,   169,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,     0,     0,     0,   171,     0,   172,   173,
       0,     0,     0,     0,   176,     0,     0,     0,     0,     0,
     174,     0,   175,   190,   191,   192,   193,   194,   195,   196,
     197,   217,   218,   219,   220,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   318
};

static const yytype_int16 yycheck[] =
{
       6,   100,     8,     6,    93,     8,    47,   186,     6,   136,
       8,     6,    73,     8,   113,    22,    23,   133,    23,   233,
     119,    74,    74,    48,    76,   114,   153,    50,    69,   243,
       0,     1,   131,     3,     4,     5,   135,   216,    45,    64,
      45,    23,   256,   132,    14,   172,   145,   121,    54,    19,
      73,    21,    58,   169,   205,    23,    26,   146,   147,   273,
     159,   150,    32,    45,    73,   139,   155,    74,   167,    74,
      73,   212,   171,   224,   288,    73,     8,    45,    73,   168,
      23,    51,    52,   157,    98,     8,   237,   198,    56,   230,
       8,   242,    74,     6,    47,    75,   247,   238,   225,   226,
     251,   175,    45,   137,    74,    76,    74,   248,    23,   260,
      75,   222,    23,    75,   128,    46,    69,   123,    73,    74,
     261,   262,   156,   274,   265,   252,   253,   278,   269,    75,
      45,    74,   283,    23,    45,   246,    67,    75,   279,   173,
      67,   240,    75,   149,    57,    58,    59,    60,    61,    62,
      63,    64,   241,    43,   160,    45,   307,   284,   285,    74,
      23,   312,    46,    74,    73,    74,    56,   308,    51,    53,
      75,   270,    75,   324,    74,   326,    73,   328,    73,    74,
      43,   322,    45,    46,    74,    74,    75,     5,    69,     7,
      69,     9,    10,    56,    12,    13,    74,    15,    16,    74,
      18,    19,    20,    73,    67,    69,    24,    74,    69,    27,
      75,    74,    74,    31,    73,   314,   305,    35,    69,    37,
      38,    74,    40,    69,   323,    75,    75,    74,   327,    73,
      48,    49,    44,    51,     5,    74,     7,    69,     9,    10,
      69,    12,    13,    46,    15,    16,    46,    18,    19,    20,
      95,    50,   178,    24,    52,    39,    27,    75,   152,    56,
      31,   169,    39,    -1,    35,   271,    37,    38,   142,    40,
      -1,    -1,    -1,     7,    -1,    -1,    -1,    48,    49,    13,
      51,    15,    16,    17,    18,    69,    70,    71,    72,    73,
      -1,    25,    69,    70,    71,    72,    73,    -1,    -1,    33,
      34,    -1,    36,    37,    75,     7,    40,    41,    42,   315,
      -1,    13,    -1,    15,    16,    17,    18,    51,    -1,    -1,
      54,    55,    -1,    25,    69,    70,    71,    72,    -1,    66,
      67,    33,    34,    67,    36,    37,    -1,    -1,    40,    41,
      42,    75,    79,    80,    81,    65,    66,    67,    68,    51,
      -1,    -1,    54,    55,    -1,     7,    -1,    -1,    -1,    11,
      -1,    13,    -1,    15,    16,    67,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    -1,     7,    -1,    -1,    40,    11,
      -1,    13,    -1,    15,    16,    -1,    18,    -1,    -1,    51,
      -1,    -1,    54,    -1,    -1,    -1,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    -1,    67,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    51,
      -1,     7,    54,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    -1,    -1,    -1,    20,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    31,    -1,    -1,    -1,    35,
      -1,    37,    38,     7,    -1,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    49,    -1,    51,    20,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    31,    -1,    -1,
      -1,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    49,     7,    51,    -1,    10,
      11,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    75,    -1,    -1,    35,    -1,    37,    38,     7,    -1,
      -1,    10,    11,    -1,    -1,    -1,    15,    16,    49,    -1,
      51,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    37,    38,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    51,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    78,     0,     1,     3,     4,     5,    14,    19,    21,
      26,    32,    51,    52,    74,    79,    80,    81,    89,    98,
     103,   108,   116,   117,   119,    73,    74,    73,    74,    23,
      45,    74,    88,    73,    74,    74,    88,    69,    70,    71,
      72,   126,    73,    73,    74,    74,    75,    74,    76,    82,
      83,    90,    91,   100,     8,   109,   110,   105,     8,    75,
      75,    75,    75,    75,    76,    39,    73,   126,    84,    84,
      92,    92,   101,    74,    88,   111,   111,   106,    88,    39,
      73,   126,    67,   118,   118,   118,     5,     7,     9,    10,
      12,    13,    15,    16,    18,    19,    20,    24,    27,    31,
      35,    37,    38,    40,    48,    49,    51,    75,    85,    75,
       7,    11,    13,    15,    16,    18,    28,    29,    30,    35,
      40,    51,    54,    67,    75,    93,    75,     7,     9,    10,
      11,    15,    16,    20,    31,    35,    37,    38,    49,    51,
      75,   102,    99,     7,    13,    15,    16,    17,    18,    25,
      33,    34,    36,    37,    40,    41,    42,    51,    54,    55,
      67,    75,   112,    75,     7,    10,    11,    15,    16,    20,
      31,    35,    37,    38,    49,    51,    75,   107,   104,   118,
     118,   118,    51,    75,    75,    75,    86,    87,    88,    74,
      57,    58,    59,    60,    61,    62,    63,    64,   122,   123,
     124,    73,    23,    45,    74,   113,   114,   115,    23,    45,
      56,    74,    94,    96,    97,    69,    86,    65,    66,    67,
      68,   125,   122,    69,   113,     6,     8,    73,   127,    43,
      94,    95,    74,   120,   121,    74,    73,   113,    94,    69,
      46,    53,   113,   120,    88,    74,   122,   113,    94,   125,
      69,   113,     6,     8,   127,    95,   120,   101,    74,    73,
     113,    94,    94,    69,    88,    94,   115,    50,   127,    94,
      46,    67,    95,   120,   113,    22,    88,    74,   113,    94,
     124,   125,    69,   113,     6,     8,   127,    95,   120,   106,
      75,    75,    75,    74,    87,     6,   123,    47,    69,   114,
      96,   127,   127,    47,    69,    44,   121,   113,    94,   127,
     127,    75,   113,    88,    46,    67,   127,   127,    75,    74,
      69,    69,    94,    46,   113,    88,   113,    46,   113
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    82,    81,    83,    81,
      84,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    86,    86,    87,    88,
      88,    88,    90,    89,    91,    89,    92,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      96,    97,    97,    97,    99,    98,   100,    98,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   104,   103,   105,   103,   106,
     106,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   109,   108,   110,   108,
     111,   111,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     114,   115,   115,   115,   116,   117,   117,   117,   117,   117,
     117,   118,   118,   119,   119,   119,   120,   120,   121,   122,
     122,   123,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   125,   125,   125,   126,   126,   126,   126,
     127,   127,   127
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     0,     5,     0,     5,
       0,     2,     2,     4,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     2,     2,     1,     2,     1,     1,
       1,     1,     0,     5,     0,     5,     0,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     3,     3,     2,     2,
       2,     2,     1,     2,     1,     2,     1,     1,     1,     3,
       1,     1,     1,     1,     0,     7,     0,     5,     0,     2,
       2,     2,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     3,     3,     2,     2,     0,     7,     0,     5,     0,
       2,     2,     2,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     3,     3,     2,     2,     0,     5,     0,     5,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     4,
       4,     6,     3,     5,     3,     2,     2,     2,     2,     2,
       1,     1,     2,     1,     2,     2,     2,     2,     1,     2,
       1,     1,     1,     1,     1,     5,     6,     5,     6,     5,
       6,     0,     3,     3,     3,     2,     1,     2,     1,     1,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
        case 13:
#line 149 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_sstore(map, "TITLE", (yyvsp[-1].sval));
                }
#line 1761 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 14:
#line 153 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (sectnames == NULL)
                        sectnames = vl_create();
                    vl_spush(sectnames, (yyvsp[-1].sval));
                }
#line 1771 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 15:
#line 159 "ifm-parse.y" /* yacc.c:1652  */
    {
                    float version;
                    sscanf(VERSION, "%f", &version);
                    if ((yyvsp[-1].dval) - version > 0.001)
                        err("version %g of IFM is required (this is %s)",
                            (yyvsp[-1].dval), VERSION);
                }
#line 1783 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 16:
#line 173 "ifm-parse.y" /* yacc.c:1652  */
    {
                    curobj = vh_create();
		    vh_sstore(curobj, "DESC", (yyvsp[0].sval));
                    vh_istore(curobj, "ID", roomid++);
                    vh_pstore(curobj, "STYLE", current_styles());
                    vh_pstore(curobj, "LINK_STYLE", current_styles());
                    implicit = 0;
                    modify = 0;
		}
#line 1797 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 17:
#line 183 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vhash *near, *link, *sect = NULL;
                    vlist *list, *dirs;

                    /* Build new room */
                    vl_ppush(rooms, curobj);

                    if (startroom == NULL)
                        startroom = curobj;

                    /* Put it on appropriate section */
                    if ((near = vh_pget(curobj, "NEAR")) != NULL)
                        sect = vh_pget(near, "SECT");

                    if (sect == NULL) {
                        sect = vh_create();
                        vl_ppush(sects, sect);
                        vh_istore(sect, "NUM", vl_length(sects));
                        vh_pstore(sect, "ROOMS", vl_create());
                        vh_pstore(sect, "LINKS", vl_create());
                    }

                    vh_pstore(curobj, "SECT", sect);
                    list = vh_pget(sect, "ROOMS");
                    vl_punshift(list, curobj);

                    /* Build implicit link (if any) */
                    if ((dirs = vh_pget(curobj, "DIR")) != NULL) {
                        link = vh_create();
                        vh_pstore(curobj, "LINK", link);

                        vh_pstore(link, "FROM", near);
                        vh_pstore(link, "TO", curobj);

                        vh_istore(link, "GO",
                                  vh_iget(curobj, "GO"));
                        vh_istore(link, "ONEWAY",
                                  vh_iget(curobj, "ONEWAY"));
                        vh_istore(link, "NODROP",
                                  vh_iget(curobj, "NODROP"));
                        vh_istore(link, "NOLINK",
                                  vh_iget(curobj, "NOLINK"));
                        vh_istore(link, "NOPATH",
                                  vh_iget(curobj, "NOPATH"));
                        vh_istore(link, "LEN",
                                  vh_iget(curobj, "LEN"));
                        vh_pstore(link, "BEFORE",
                                  vh_pget(curobj, "LINK_BEFORE"));
                        vh_pstore(link, "AFTER",
                                  vh_pget(curobj, "LINK_AFTER"));
                        vh_pstore(link, "NEED",
                                  vh_pget(curobj, "LINK_NEED"));
                        vh_pstore(link, "LEAVE",
                                  vh_pget(curobj, "LINK_LEAVE"));
                        vh_istore(link, "LEAVEALL",
                                  vh_iget(curobj, "LINK_LEAVEALL"));
                        vh_pstore(link, "STYLE",
                                  vh_pget(curobj, "LINK_STYLE"));
                        vh_pstore(link, "FROM_CMD",
                                  vh_pget(curobj, "FROM_CMD"));
                        vh_pstore(link, "TO_CMD",
                                  vh_pget(curobj, "TO_CMD"));

                        if (vh_exists(curobj, "TAG"))
                            set_tag("link", vh_sgetref(curobj, "TAG"),
                                    link, linktags);

                        vh_pstore(link, "DIR", dirs);
                        vl_ppush(links, link);
                    }

                    /* Warn about ignored attributes */
                    if (dirs == NULL || vh_iget(curobj, "NOLINK")) {
                        if (vh_exists(curobj, "GO"))
                            WARN_IGNORED(go);
                        if (vh_exists(curobj, "ONEWAY"))
                            WARN_IGNORED(oneway);
                        if (vh_exists(curobj, "LEN"))
                            WARN_IGNORED(length);
                        if (vh_exists(curobj, "NOPATH"))
                            WARN_IGNORED(nopath);
                        if (vh_exists(curobj, "TO_CMD"))
                            WARN_IGNORED(cmd);
                    }

                    if (dirs == NULL && vh_iget(curobj, "NOLINK"))
                        WARN_IGNORED(nolink);

                    lastroom = curobj;
                    RESET;
                }
#line 1893 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 18:
#line 275 "ifm-parse.y" /* yacc.c:1652  */
    {
                    implicit = 0;
                    modify = 1;
                    if ((curobj = vh_pget(roomtags, (yyvsp[0].sval))) == NULL) {
                        err("room tag '%s' not yet defined", (yyvsp[0].sval));
                        curobj = vh_create();
                    }
                }
#line 1906 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 19:
#line 284 "ifm-parse.y" /* yacc.c:1652  */
    {
                    RESET;
                }
#line 1914 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 22:
#line 294 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (!modify)
                        set_tag("room", (yyvsp[0].sval), curobj, roomtags);
                    else
                        CHANGE_ERROR(tag);
		}
#line 1925 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 23:
#line 301 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vhash *room;

                    if (!modify) {
                        implicit = 1;

                        vh_pstore(curobj, "DIR", curdirs);
                        curdirs = NULL;

                        if ((room = vh_pget(roomtags, (yyvsp[0].sval))) != NULL)
                            vh_pstore(curobj, "NEAR", room);
                        else
                            err("room tag '%s' not yet defined", (yyvsp[0].sval));
                    } else {
                        CHANGE_ERROR(from);
                    }
		}
#line 1947 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 24:
#line 319 "ifm-parse.y" /* yacc.c:1652  */
    {
                    implicit = 1;

                    if (modify && !vh_exists(curobj, "DIR"))
                        CHANGE_ERROR(dir);

                    vh_pstore(curobj, "DIR", curdirs);
                    curdirs = NULL;

                    if (lastroom == NULL)
                        err("no last room");
                    else
                        vh_pstore(curobj, "NEAR", lastroom);
		}
#line 1966 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 25:
#line 334 "ifm-parse.y" /* yacc.c:1652  */
    {
                    viter iter;
                    int dir;

                    v_iterate(curdirs, iter) {
                        dir = vl_iter_ival(iter);
                        room_exit(curobj, dirinfo[dir].xoff,
                                  dirinfo[dir].yoff, 1);
                    }

                    curdirs = NULL;
		}
#line 1983 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 26:
#line 347 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vscalar *elt;
                    vhash *link;
                    viter iter;

                    v_iterate(currooms, iter) {
                        elt = vl_iter_val(iter);
                        link = vh_create();
                        vh_pstore(link, "FROM", curobj);
                        vh_store(link, "TO", vs_copy(elt));
                        vl_ppush(links, link);
                    }

                    vl_destroy(currooms);
                    currooms = NULL;
		}
#line 2004 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 27:
#line 364 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vscalar *elt;
                    vhash *join;
                    viter iter;

                    v_iterate(currooms, iter) {
                        elt = vl_iter_val(iter);
                        join = vh_create();
                        vh_pstore(join, "FROM", curobj);
                        vh_store(join, "TO", vs_copy(elt));
                        vl_ppush(joins, join);
                    }

                    vl_destroy(currooms);
                    currooms = NULL;
		}
#line 2025 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 28:
#line 381 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "GO", (yyvsp[0].ival));
		}
#line 2033 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 29:
#line 385 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "ONEWAY", 1);
		}
#line 2041 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 30:
#line 389 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "NODROP", 1);
		}
#line 2049 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 31:
#line 393 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "NOLINK", 1);
		}
#line 2057 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 32:
#line 397 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "NOPATH", 1);
		}
#line 2065 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 33:
#line 401 "ifm-parse.y" /* yacc.c:1652  */
    {
                    startroom = curobj;
		}
#line 2073 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 34:
#line 405 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "FINISH", 1);
                }
#line 2081 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 35:
#line 409 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, ATTR(NEED), curitems);
                }
#line 2089 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 36:
#line 413 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, ATTR(BEFORE), curtasks);
		}
#line 2097 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 37:
#line 417 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, ATTR(AFTER), curtasks);
		}
#line 2105 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 38:
#line 421 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (curitems != NULL)
                        SET_LIST(curobj, ATTR(LEAVE), curitems);
                    vh_istore(curobj, ATTR(LEAVEALL), allflag);
                }
#line 2115 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 39:
#line 427 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "LEN", (yyvsp[0].ival));
		}
#line 2123 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 40:
#line 431 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "SCORE", (yyvsp[0].ival));
		}
#line 2131 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 41:
#line 435 "ifm-parse.y" /* yacc.c:1652  */
    {
                    while (repeat-- > 0)
                        add_attr(curobj, "TO_CMD", (yyvsp[0].sval));
                }
#line 2140 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 42:
#line 440 "ifm-parse.y" /* yacc.c:1652  */
    {
                    while (repeat-- > 0)
                        add_attr(curobj, "TO_CMD", (yyvsp[0].sval));
                }
#line 2149 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 43:
#line 445 "ifm-parse.y" /* yacc.c:1652  */
    {
                    while (repeat-- > 0)
                        add_attr(curobj, "FROM_CMD", (yyvsp[0].sval));
                }
#line 2158 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 44:
#line 450 "ifm-parse.y" /* yacc.c:1652  */
    {
                    add_attr(curobj, "NOTE", (yyvsp[0].sval));
		}
#line 2166 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 48:
#line 461 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (currooms == NULL)
                        currooms = vl_create();
                    vl_push(currooms, (yyvsp[0].vval));
		}
#line 2176 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 49:
#line 469 "ifm-parse.y" /* yacc.c:1652  */
    {
                    (yyval.vval) = vs_screate((yyvsp[0].sval));
                    itroom = vs_copy((yyval.vval));
                }
#line 2185 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 50:
#line 474 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (itroom == NULL)
                        err("no room referred to by 'it'");
                    else
                        (yyval.vval) = vs_copy(itroom);
                }
#line 2196 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 51:
#line 481 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (lastroom == NULL) {
                        err("no room referred to by 'last'");
                    } else {
                        (yyval.vval) = vs_pcreate(lastroom);
                        itroom = vs_copy((yyval.vval));
                    }                        
                }
#line 2209 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 52:
#line 496 "ifm-parse.y" /* yacc.c:1652  */
    {
                    curobj = vh_create();
                    vh_sstore(curobj, "DESC", (yyvsp[0].sval));
                    vh_istore(curobj, "ID", itemid++);
                    vh_pstore(curobj, "STYLE", current_styles());
                    modify = 0;
                }
#line 2221 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 53:
#line 504 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (!vh_exists(curobj, "IN"))
                        vh_pstore(curobj, "IN", lastroom);

                    lastitem = curobj;
                    vl_ppush(items, curobj);
                    RESET;
		}
#line 2234 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 54:
#line 513 "ifm-parse.y" /* yacc.c:1652  */
    {
                    modify = 1;
                    if ((curobj = vh_pget(itemtags, (yyvsp[0].sval))) == NULL) {
                        err("item tag '%s' not yet defined", (yyvsp[0].sval));
                        curobj = vh_create();
                    }
                }
#line 2246 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 55:
#line 521 "ifm-parse.y" /* yacc.c:1652  */
    {
                    RESET;
                }
#line 2254 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 58:
#line 531 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (!modify)
                        set_tag("item", (yyvsp[0].sval), curobj, itemtags);
                    else
                        CHANGE_ERROR(tag);
		}
#line 2265 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 59:
#line 538 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_store(curobj, "IN", (yyvsp[0].vval));
		}
#line 2273 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 60:
#line 542 "ifm-parse.y" /* yacc.c:1652  */
    {
                    add_attr(curobj, "NOTE", (yyvsp[0].sval));
		}
#line 2281 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 61:
#line 546 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "HIDDEN", 1);
		}
#line 2289 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 62:
#line 550 "ifm-parse.y" /* yacc.c:1652  */
    {
                    obsolete("'given' attribute", "task 'give' attribute");
                    vh_istore(curobj, "GIVEN", 1);
		}
#line 2298 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 63:
#line 555 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "LOST", 1);
		}
#line 2306 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 64:
#line 559 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "IGNORE", 1);
		}
#line 2314 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 65:
#line 563 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "KEEP", 1);
		}
#line 2322 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 66:
#line 567 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "KEEP_WITH", curitems);
		}
#line 2330 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 67:
#line 571 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "KEEP_UNTIL", curtasks);
		}
#line 2338 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 68:
#line 575 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "NEED", curitems);
                }
#line 2346 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 69:
#line 579 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "BEFORE", curtasks);
                }
#line 2354 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 70:
#line 583 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "AFTER", curtasks);
                }
#line 2362 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 71:
#line 587 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "SCORE", (yyvsp[0].ival));
		}
#line 2370 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 72:
#line 591 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "FINISH", 1);
                }
#line 2378 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 76:
#line 600 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (themitems != NULL) {
                        if (curitems == NULL)
                            curitems = vl_copy(themitems);
                        else
                            vl_append(curitems, themitems);
                    } else {
                        err("no items referred to by 'them'");
                    }
                }
#line 2393 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 77:
#line 612 "ifm-parse.y" /* yacc.c:1652  */
    { allflag = 0; }
#line 2399 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 78:
#line 613 "ifm-parse.y" /* yacc.c:1652  */
    { allflag = 1; }
#line 2405 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 79:
#line 614 "ifm-parse.y" /* yacc.c:1652  */
    { allflag = 1; }
#line 2411 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 80:
#line 618 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (curitems == NULL)
                        curitems = vl_create();

                    vl_push(curitems, (yyvsp[0].vval));

                    if (themitems == NULL)
                        themitems = vl_create();

                    vl_push(themitems, vs_copy((yyvsp[0].vval)));
		}
#line 2427 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 81:
#line 632 "ifm-parse.y" /* yacc.c:1652  */
    {
                    (yyval.vval) = vs_screate((yyvsp[0].sval));
                    ititem = vs_copy((yyval.vval));
                }
#line 2436 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 82:
#line 637 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (ititem == NULL)
                        err("no item referred to by 'it'");
                    else
                        (yyval.vval) = vs_copy(ititem);
                }
#line 2447 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 83:
#line 644 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (lastitem == NULL) {
                        err("no item referred to by 'last'");
                    } else {
                        (yyval.vval) = vs_pcreate(lastitem);
                        ititem = vs_copy((yyval.vval));
                    }
                }
#line 2460 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 84:
#line 659 "ifm-parse.y" /* yacc.c:1652  */
    {
                    curobj = vh_create();
                    vh_store(curobj, "FROM", (yyvsp[-2].vval));
                    vh_store(curobj, "TO", (yyvsp[0].vval));
                    vh_pstore(curobj, "STYLE", current_styles());
                    modify = 0;
                }
#line 2472 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 85:
#line 667 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vl_ppush(links, curobj);
                    RESET;
		}
#line 2481 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 86:
#line 672 "ifm-parse.y" /* yacc.c:1652  */
    {
                    modify = 1;
                    if ((curobj = vh_pget(linktags, (yyvsp[0].sval))) == NULL) {
                        err("link tag '%s' not yet defined", (yyvsp[0].sval));
                        curobj = vh_create();
                    }
                }
#line 2493 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 87:
#line 680 "ifm-parse.y" /* yacc.c:1652  */
    {
                    RESET;
                }
#line 2501 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 90:
#line 690 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_pstore(curobj, "DIR", curdirs);
                    curdirs = NULL;
		}
#line 2510 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 91:
#line 695 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "GO", (yyvsp[0].ival));
		}
#line 2518 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 92:
#line 699 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "ONEWAY", 1);
		}
#line 2526 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 93:
#line 703 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "HIDDEN", 1);
		}
#line 2534 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 94:
#line 707 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "NOPATH", 1);
		}
#line 2542 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 95:
#line 711 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "NEED", curitems);
                }
#line 2550 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 96:
#line 715 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "BEFORE", curtasks);
		}
#line 2558 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 97:
#line 719 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "AFTER", curtasks);
		}
#line 2566 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 98:
#line 723 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (curitems != NULL)
                        SET_LIST(curobj, "LEAVE", curitems);
                    vh_istore(curobj, "LEAVEALL", allflag);
                }
#line 2576 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 99:
#line 729 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "LEN", (yyvsp[0].ival));
		}
#line 2584 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 100:
#line 733 "ifm-parse.y" /* yacc.c:1652  */
    {
                    while (repeat-- > 0)
                        add_attr(curobj, "TO_CMD", (yyvsp[0].sval));
                }
#line 2593 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 101:
#line 738 "ifm-parse.y" /* yacc.c:1652  */
    {
                    while (repeat-- > 0)
                        add_attr(curobj, "TO_CMD", (yyvsp[0].sval));
                }
#line 2602 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 102:
#line 743 "ifm-parse.y" /* yacc.c:1652  */
    {
                    while (repeat-- > 0)
                        add_attr(curobj, "FROM_CMD", (yyvsp[0].sval));
                }
#line 2611 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 103:
#line 748 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (!modify)
                        set_tag("link", (yyvsp[0].sval), curobj, linktags);
                    else
                        CHANGE_ERROR(tag);
		}
#line 2622 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 105:
#line 762 "ifm-parse.y" /* yacc.c:1652  */
    {
                    curobj = vh_create();
                    vh_store(curobj, "FROM", (yyvsp[-2].vval));
                    vh_store(curobj, "TO", (yyvsp[0].vval));
                    vh_pstore(curobj, "STYLE", current_styles());
                    modify = 0;
                }
#line 2634 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 106:
#line 770 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vl_ppush(joins, curobj);
                    RESET;
		}
#line 2643 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 107:
#line 775 "ifm-parse.y" /* yacc.c:1652  */
    {
                    modify = 1;
                    if ((curobj = vh_pget(jointags, (yyvsp[0].sval))) == NULL) {
                        err("join tag '%s' not yet defined", (yyvsp[0].sval));
                        curobj = vh_create();
                    }
                }
#line 2655 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 108:
#line 783 "ifm-parse.y" /* yacc.c:1652  */
    {
                    RESET;
                }
#line 2663 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 111:
#line 793 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "GO", (yyvsp[0].ival));
		}
#line 2671 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 112:
#line 797 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "GO", (yyvsp[0].ival));
		}
#line 2679 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 113:
#line 801 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "ONEWAY", 1);
		}
#line 2687 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 114:
#line 805 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "HIDDEN", 1);
		}
#line 2695 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 115:
#line 809 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "NOPATH", 1);
		}
#line 2703 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 116:
#line 813 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "NEED", curitems);
                }
#line 2711 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 117:
#line 817 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "BEFORE", curtasks);
		}
#line 2719 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 118:
#line 821 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "AFTER", curtasks);
		}
#line 2727 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 119:
#line 825 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (curitems != NULL)
                        SET_LIST(curobj, "LEAVE", curitems);
                    vh_istore(curobj, "LEAVEALL", allflag);
                }
#line 2737 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 120:
#line 831 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "LEN", (yyvsp[0].ival));
		}
#line 2745 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 121:
#line 835 "ifm-parse.y" /* yacc.c:1652  */
    {
                    while (repeat-- > 0)
                        add_attr(curobj, "TO_CMD", (yyvsp[0].sval));
                }
#line 2754 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 122:
#line 840 "ifm-parse.y" /* yacc.c:1652  */
    {
                    while (repeat-- > 0)
                        add_attr(curobj, "TO_CMD", (yyvsp[0].sval));
                }
#line 2763 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 123:
#line 845 "ifm-parse.y" /* yacc.c:1652  */
    {
                    while (repeat-- > 0)
                        add_attr(curobj, "FROM_CMD", (yyvsp[0].sval));
                }
#line 2772 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 124:
#line 850 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (!modify)
                        set_tag("join", (yyvsp[0].sval), curobj, jointags);
                    else
                        CHANGE_ERROR(tag);
		}
#line 2783 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 126:
#line 864 "ifm-parse.y" /* yacc.c:1652  */
    {
                    curobj = vh_create();
                    vh_sstore(curobj, "DESC", (yyvsp[0].sval));
                    vh_pstore(curobj, "STYLE", current_styles());
                    modify = 0;
                }
#line 2794 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 127:
#line 871 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (vh_iget(curobj, "NOROOM"))
                        vh_pstore(curobj, "IN", NULL);
                    else if (!vh_exists(curobj, "IN"))
                        vh_pstore(curobj, "IN", lastroom);

                    lasttask = curobj;
                    vl_ppush(tasks, curobj);
                    RESET;
		}
#line 2809 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 128:
#line 882 "ifm-parse.y" /* yacc.c:1652  */
    {
                    modify = 1;
                    if ((curobj = vh_pget(tasktags, (yyvsp[0].sval))) == NULL) {
                        err("task tag '%s' not yet defined", (yyvsp[0].sval));
                        curobj = vh_create();
                    }
                }
#line 2821 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 129:
#line 890 "ifm-parse.y" /* yacc.c:1652  */
    {
                    RESET;
                }
#line 2829 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 132:
#line 900 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (!modify)
                        set_tag("task", (yyvsp[0].sval), curobj, tasktags);
                    else
                        CHANGE_ERROR(tag);
		}
#line 2840 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 133:
#line 907 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "AFTER", curtasks);
		}
#line 2848 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 134:
#line 911 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "NEED", curitems);
		}
#line 2856 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 135:
#line 915 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "GIVE", curitems);
		}
#line 2864 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 136:
#line 919 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "GET", curitems);
		}
#line 2872 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 137:
#line 923 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "DO", curtasks);
		}
#line 2880 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 138:
#line 927 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (curitems != NULL)
                        SET_LIST(curobj, "DROP", curitems);
                    vh_istore(curobj, "DROPALL", allflag);
		}
#line 2890 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 139:
#line 933 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (curitems != NULL)
                        SET_LIST(curobj, "DROP", curitems);
                    vh_istore(curobj, "DROPALL", allflag);
                    SET_LIST(curobj, "DROPUNTIL", curtasks);
		}
#line 2901 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 140:
#line 940 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (curitems != NULL)
                        SET_LIST(curobj, "DROP", curitems);
                    vh_istore(curobj, "DROPALL", allflag);
                    vh_store(curobj, "DROPROOM", (yyvsp[0].vval));
		}
#line 2912 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 141:
#line 947 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (curitems != NULL)
                        SET_LIST(curobj, "DROP", curitems);
                    vh_istore(curobj, "DROPALL", allflag);
                    vh_store(curobj, "DROPROOM", (yyvsp[-2].vval));
                    SET_LIST(curobj, "DROPUNTIL", curtasks);
		}
#line 2924 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 142:
#line 955 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_store(curobj, "DROPROOM", (yyvsp[0].vval));
		}
#line 2932 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 143:
#line 959 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_store(curobj, "DROPROOM", (yyvsp[-2].vval));
                    SET_LIST(curobj, "DROPUNTIL", curtasks);
		}
#line 2941 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 144:
#line 964 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "DROPUNTIL", curtasks);
                }
#line 2949 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 145:
#line 968 "ifm-parse.y" /* yacc.c:1652  */
    {
                    SET_LIST(curobj, "LOSE", curitems);
		}
#line 2957 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 146:
#line 972 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_store(curobj, "GOTO", (yyvsp[0].vval));
                }
#line 2965 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 147:
#line 976 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_store(curobj, "FOLLOW", (yyvsp[0].vval));
                }
#line 2973 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 148:
#line 980 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_store(curobj, "IN", (yyvsp[0].vval));
		}
#line 2981 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 149:
#line 984 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "NOROOM", 1);
		}
#line 2989 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 150:
#line 988 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "IGNORE", 1);
		}
#line 2997 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 151:
#line 992 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "SAFE", 1);
                }
#line 3005 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 152:
#line 996 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "SCORE", (yyvsp[0].ival));
		}
#line 3013 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 153:
#line 1000 "ifm-parse.y" /* yacc.c:1652  */
    {
                    vh_istore(curobj, "FINISH", 1);
                }
#line 3021 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 154:
#line 1004 "ifm-parse.y" /* yacc.c:1652  */
    {
                    while (repeat-- > 0)
                        add_attr(curobj, "CMD", (yyvsp[0].sval));
                }
#line 3030 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 155:
#line 1009 "ifm-parse.y" /* yacc.c:1652  */
    {
                    add_attr(curobj, "CMD", NULL);
                }
#line 3038 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 156:
#line 1013 "ifm-parse.y" /* yacc.c:1652  */
    {
                    add_attr(curobj, "NOTE", (yyvsp[0].sval));
		}
#line 3046 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 160:
#line 1024 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (curtasks == NULL)
                        curtasks = vl_create();
                    vl_push(curtasks, (yyvsp[0].vval));
		}
#line 3056 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 161:
#line 1032 "ifm-parse.y" /* yacc.c:1652  */
    {
                    (yyval.vval) = vs_screate((yyvsp[0].sval));
                    ittask = vs_copy((yyval.vval));
                }
#line 3065 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 162:
#line 1037 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (ittask == NULL)
                        err("no task referred to by 'it'");
                    else
                        (yyval.vval) = vs_copy(ittask);
                }
#line 3076 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 163:
#line 1044 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (lasttask == NULL) {
                        err("no task referred to by 'last'");
                    } else {
                        (yyval.vval) = vs_pcreate(lasttask);
                        ittask = vs_copy((yyval.vval));
                    }
                }
#line 3089 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 164:
#line 1059 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (instyle)
                        pop_style(NULL);
                    instyle = 0;
                }
#line 3099 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 165:
#line 1067 "ifm-parse.y" /* yacc.c:1652  */
    {
                    var_set(NULL, (yyvsp[-4].sval), vs_dcreate((yyvsp[-2].dval)));
                }
#line 3107 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 166:
#line 1071 "ifm-parse.y" /* yacc.c:1652  */
    {
                    var_set((yyvsp[-5].sval), (yyvsp[-4].sval), vs_dcreate((yyvsp[-2].dval)));
                    obsolete("variable assignment", "dotted notation");
                }
#line 3116 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 167:
#line 1076 "ifm-parse.y" /* yacc.c:1652  */
    {
                    var_set(NULL, (yyvsp[-4].sval), vs_screate((yyvsp[-2].sval)));
                }
#line 3124 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 168:
#line 1080 "ifm-parse.y" /* yacc.c:1652  */
    {
                    var_set((yyvsp[-5].sval), (yyvsp[-4].sval), vs_screate((yyvsp[-2].sval)));
                    obsolete("variable assignment", "dotted notation");
                }
#line 3133 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 169:
#line 1085 "ifm-parse.y" /* yacc.c:1652  */
    {
                    var_set(NULL, (yyvsp[-4].sval), NULL);
                }
#line 3141 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 170:
#line 1089 "ifm-parse.y" /* yacc.c:1652  */
    {
                    var_set((yyvsp[-5].sval), (yyvsp[-4].sval), NULL);
                    obsolete("variable assignment", "dotted notation");
                }
#line 3150 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 172:
#line 1097 "ifm-parse.y" /* yacc.c:1652  */
    {
                    push_style((yyvsp[0].sval));
                    instyle++;
                }
#line 3159 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 173:
#line 1108 "ifm-parse.y" /* yacc.c:1652  */
    {
                    push_style((yyvsp[-1].sval));
                }
#line 3167 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 174:
#line 1112 "ifm-parse.y" /* yacc.c:1652  */
    {
                    pop_style((yyvsp[-1].sval));
                }
#line 3175 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 175:
#line 1116 "ifm-parse.y" /* yacc.c:1652  */
    {
                    pop_style(NULL);
                }
#line 3183 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 178:
#line 1126 "ifm-parse.y" /* yacc.c:1652  */
    {
                    add_attr(curobj, "STYLE", (yyvsp[0].sval));
                    ref_style((yyvsp[0].sval));
                }
#line 3192 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 181:
#line 1141 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (curdirs == NULL)
                        curdirs = vl_create();
                    vl_ipush(curdirs, (yyvsp[0].ival));
		}
#line 3202 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 182:
#line 1147 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (curdirs == NULL)
                        curdirs = vl_create();
                    if ((yyvsp[0].ival) <= 0)
                        err("invalid repeat count");
                    while ((yyvsp[0].ival)-- > 0)
                        vl_ipush(curdirs, (yyvsp[-1].ival));
                }
#line 3215 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 183:
#line 1156 "ifm-parse.y" /* yacc.c:1652  */
    {
                    if (curdirs == NULL)
                        curdirs = vl_create();
                    if ((yyvsp[0].ival) <= 0)
                        err("invalid repeat count");
                    while ((yyvsp[0].ival)-- > 0)
                        vl_ipush(curdirs, (yyvsp[-2].ival));
                    obsolete("'times' keyword", "just the repeat count");
                }
#line 3229 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 184:
#line 1167 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.ival) = D_NORTH;	    }
#line 3235 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 185:
#line 1168 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.ival) = D_EAST;	    }
#line 3241 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 186:
#line 1169 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.ival) = D_SOUTH;	    }
#line 3247 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 187:
#line 1170 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.ival) = D_WEST;	    }
#line 3253 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 188:
#line 1171 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.ival) = D_NORTHEAST; }
#line 3259 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 189:
#line 1172 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.ival) = D_NORTHWEST; }
#line 3265 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 190:
#line 1173 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.ival) = D_SOUTHEAST; }
#line 3271 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 191:
#line 1174 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.ival) = D_SOUTHWEST; }
#line 3277 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 192:
#line 1177 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.ival) = D_IN;   }
#line 3283 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 193:
#line 1178 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.ival) = D_OUT;  }
#line 3289 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 194:
#line 1179 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.ival) = D_UP;   }
#line 3295 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 195:
#line 1180 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.ival) = D_DOWN; }
#line 3301 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 196:
#line 1187 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.dval) = (yyvsp[0].ival); }
#line 3307 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 197:
#line 1188 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.dval) = (yyvsp[0].dval); }
#line 3313 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 198:
#line 1189 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.dval) =  1; }
#line 3319 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 199:
#line 1190 "ifm-parse.y" /* yacc.c:1652  */
    { (yyval.dval) =  0; }
#line 3325 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 200:
#line 1194 "ifm-parse.y" /* yacc.c:1652  */
    {
                    (yyval.sval) = (yyvsp[0].sval);
                    repeat = 1;
                }
#line 3334 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 201:
#line 1199 "ifm-parse.y" /* yacc.c:1652  */
    {
                    (yyval.sval) = (yyvsp[-1].sval);
                    repeat = (yyvsp[0].ival);
                    if ((yyvsp[0].ival) <= 0)
                        err("invalid repeat count");
                }
#line 3345 "ifm-parse.c" /* yacc.c:1652  */
    break;

  case 202:
#line 1206 "ifm-parse.y" /* yacc.c:1652  */
    {
                    (yyval.sval) = (yyvsp[-2].sval);
                    repeat = (yyvsp[0].ival);
                    if ((yyvsp[0].ival) <= 0)
                        err("invalid repeat count");
                    obsolete("'times' keyword", "just the repeat count");
                }
#line 3357 "ifm-parse.c" /* yacc.c:1652  */
    break;


#line 3361 "ifm-parse.c" /* yacc.c:1652  */
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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 1215 "ifm-parse.y" /* yacc.c:1918  */

