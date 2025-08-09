/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sfl.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast/ast.h"
#include "../ast/expr.h"
#include "../ast/decl.h"
#include "../ast/func.h"
#include "../ast/instructions.h"

void yyerror(const char *s);
int yylex();
int yyparse();

extern int yylineno;
extern FILE* yyin;

AST* ast; //arborele care va fi construit
int in_if_block = 0;//flag pt a decide daca suntem sau nu in if

#line 92 "build/sfl.y.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "sfl.y.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_NEWLINE = 3,                  /* T_NEWLINE  */
  YYSYMBOL_DIGIT = 4,                      /* DIGIT  */
  YYSYMBOL_IDENTIFIER = 5,                 /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 7,              /* FLOAT_LITERAL  */
  YYSYMBOL_T_OBRACE = 8,                   /* T_OBRACE  */
  YYSYMBOL_T_CBRACE = 9,                   /* T_CBRACE  */
  YYSYMBOL_T_OPAREN = 10,                  /* T_OPAREN  */
  YYSYMBOL_T_CPAREN = 11,                  /* T_CPAREN  */
  YYSYMBOL_T_EQ = 12,                      /* T_EQ  */
  YYSYMBOL_T_ASSIGN = 13,                  /* T_ASSIGN  */
  YYSYMBOL_T_SEMICOLON = 14,               /* T_SEMICOLON  */
  YYSYMBOL_T_INT = 15,                     /* T_INT  */
  YYSYMBOL_T_FLOAT = 16,                   /* T_FLOAT  */
  YYSYMBOL_T_DOUBLE = 17,                  /* T_DOUBLE  */
  YYSYMBOL_T_BOOL = 18,                    /* T_BOOL  */
  YYSYMBOL_T_STRING = 19,                  /* T_STRING  */
  YYSYMBOL_T_LET = 20,                     /* T_LET  */
  YYSYMBOL_T_PRINT = 21,                   /* T_PRINT  */
  YYSYMBOL_T_RETURN = 22,                  /* T_RETURN  */
  YYSYMBOL_T_IF = 23,                      /* T_IF  */
  YYSYMBOL_T_THEN = 24,                    /* T_THEN  */
  YYSYMBOL_T_ELSE = 25,                    /* T_ELSE  */
  YYSYMBOL_T_NEQ = 26,                     /* T_NEQ  */
  YYSYMBOL_T_GTE = 27,                     /* T_GTE  */
  YYSYMBOL_T_LTE = 28,                     /* T_LTE  */
  YYSYMBOL_T_GT = 29,                      /* T_GT  */
  YYSYMBOL_T_LT = 30,                      /* T_LT  */
  YYSYMBOL_T_AND = 31,                     /* T_AND  */
  YYSYMBOL_T_OR = 32,                      /* T_OR  */
  YYSYMBOL_T_NOT = 33,                     /* T_NOT  */
  YYSYMBOL_T_LAMBDA = 34,                  /* T_LAMBDA  */
  YYSYMBOL_T_FUNC = 35,                    /* T_FUNC  */
  YYSYMBOL_T_INCLUDE = 36,                 /* T_INCLUDE  */
  YYSYMBOL_T_MAIN = 37,                    /* T_MAIN  */
  YYSYMBOL_T_MUT = 38,                     /* T_MUT  */
  YYSYMBOL_T_COMMA = 39,                   /* T_COMMA  */
  YYSYMBOL_T_COLON = 40,                   /* T_COLON  */
  YYSYMBOL_T_PLUS = 41,                    /* T_PLUS  */
  YYSYMBOL_T_MINUS = 42,                   /* T_MINUS  */
  YYSYMBOL_T_MUL = 43,                     /* T_MUL  */
  YYSYMBOL_T_DIV = 44,                     /* T_DIV  */
  YYSYMBOL_T_MOD = 45,                     /* T_MOD  */
  YYSYMBOL_T_POW = 46,                     /* T_POW  */
  YYSYMBOL_UMINUS = 47,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_file_content = 49,              /* file_content  */
  YYSYMBOL_file_elements = 50,             /* file_elements  */
  YYSYMBOL_main_block = 51,                /* main_block  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_file_element = 53,              /* file_element  */
  YYSYMBOL_instructions = 54,              /* instructions  */
  YYSYMBOL_instruction = 55,               /* instruction  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_57_3 = 57,                      /* $@3  */
  YYSYMBOL_opt_newlines = 58,              /* opt_newlines  */
  YYSYMBOL_declaration = 59,               /* declaration  */
  YYSYMBOL_type = 60,                      /* type  */
  YYSYMBOL_expr = 61,                      /* expr  */
  YYSYMBOL_expr_list = 62,                 /* expr_list  */
  YYSYMBOL_function_declaration = 63,      /* function_declaration  */
  YYSYMBOL_param_list = 64,                /* param_list  */
  YYSYMBOL_param = 65,                     /* param  */
  YYSYMBOL_function_body = 66,             /* function_body  */
  YYSYMBOL_include_directive = 67          /* include_directive  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   364

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    68,    69,    70,    74,    75,    79,    79,
      86,    87,    88,    89,    93,    94,   100,   104,   112,   121,
     128,   135,   135,   135,   144,   145,   149,   154,   162,   163,
     164,   165,   166,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   197,   198,   199,
     206,   214,   215,   216,   223,   227,   231
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_NEWLINE", "DIGIT",
  "IDENTIFIER", "STRING_LITERAL", "FLOAT_LITERAL", "T_OBRACE", "T_CBRACE",
  "T_OPAREN", "T_CPAREN", "T_EQ", "T_ASSIGN", "T_SEMICOLON", "T_INT",
  "T_FLOAT", "T_DOUBLE", "T_BOOL", "T_STRING", "T_LET", "T_PRINT",
  "T_RETURN", "T_IF", "T_THEN", "T_ELSE", "T_NEQ", "T_GTE", "T_LTE",
  "T_GT", "T_LT", "T_AND", "T_OR", "T_NOT", "T_LAMBDA", "T_FUNC",
  "T_INCLUDE", "T_MAIN", "T_MUT", "T_COMMA", "T_COLON", "T_PLUS",
  "T_MINUS", "T_MUL", "T_DIV", "T_MOD", "T_POW", "UMINUS", "$accept",
  "file_content", "file_elements", "main_block", "$@1", "file_element",
  "instructions", "instruction", "$@2", "$@3", "opt_newlines",
  "declaration", "type", "expr", "expr_list", "function_declaration",
  "param_list", "param", "function_body", "include_directive", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-50)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      55,   -50,   -50,    -4,   -50,   -50,    21,     2,    21,    21,
      21,    21,     3,     6,    -7,    13,    21,    19,   -13,   -50,
      79,    26,    23,   144,   -50,   -50,    21,    21,    21,   136,
       0,   179,   186,   214,   -50,    28,    52,   -50,    16,   -50,
     -50,   -50,   -50,   -50,   -50,    21,   -50,    21,    21,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    21,
     222,    53,   250,   250,   -50,    -2,   -50,   -50,    58,    63,
     -50,   119,    -2,   278,   278,   278,   278,   278,   278,   285,
     257,   -10,   -10,    24,    24,    24,    24,    21,   -50,   -50,
     -50,   -50,   -50,   -50,    56,   -50,    31,    61,    34,   119,
      65,    76,    67,   -50,    21,   119,    -2,    47,    63,   -50,
     -50,   119,    21,   250,    85,   -50,    -2,   -50,   -50,   250,
      92,    88,    92,    78,   119,   -50,    96,   -50,    98,   -50,
     -50,   119,    99,   -50
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    13,    33,    35,    55,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       6,     0,     0,     0,    11,    10,    57,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     8,     0,    53,
       1,     5,     7,    12,    17,     0,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,    36,    56,    54,     0,    19,    20,     0,    61,
      66,     0,     0,    48,    49,    46,    47,    44,    45,    50,
      51,    38,    39,    40,    41,    42,    43,    57,    37,    28,
      29,    30,    31,    32,     0,    21,     0,     0,    62,     0,
       0,    14,     0,    59,     0,     0,     0,     0,    61,    16,
       9,     0,     0,    26,     0,    64,     0,    63,    15,    27,
      24,     0,    24,     0,     0,    25,     0,    65,     0,    22,
      60,     0,     0,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,    89,    87,   -50,   -50,   233,    12,   -50,   -50,
     -12,   -50,   -49,    -6,    29,   -50,     5,   -50,   -50,   -50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    17,    18,    19,    71,    20,   100,   101,   105,   131,
     123,    22,    94,    23,    61,    24,    97,    98,   128,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    37,    31,    32,    33,    34,    26,    30,    35,    27,
      39,    36,    21,    89,    90,    91,    92,    93,    38,    40,
      60,    62,    63,   102,    14,     2,     3,     4,     5,    43,
      28,     6,    21,    56,    57,    58,    59,    44,    69,    73,
      65,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    11,    70,    72,   115,     1,     2,
       3,     4,     5,    16,    88,     6,    95,   121,    96,   104,
      59,   106,   107,   108,   110,     7,     8,     9,    10,   111,
     112,    60,     1,     2,     3,     4,     5,   116,    11,     6,
      12,    13,    14,    15,   120,   122,   124,    16,   113,     7,
       8,     9,    10,   126,   129,    41,   119,   130,   133,    42,
     125,     0,    11,   117,    12,    13,   103,    15,     0,     0,
       0,    16,    99,     2,     3,     4,     5,     0,     0,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     9,    10,     0,     0,     0,     0,    64,    45,     0,
       0,     0,    11,     0,     0,     0,    45,    15,    46,     0,
       0,    16,    47,    48,    49,    50,    51,    52,    53,     0,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    54,    55,    56,    57,    58,
      59,    45,     0,    66,     0,     0,     0,     0,    45,     0,
      67,     0,     0,     0,     0,    47,    48,    49,    50,    51,
      52,    53,    47,    48,    49,    50,    51,    52,    53,     0,
      54,    55,    56,    57,    58,    59,    45,    54,    55,    56,
      57,    58,    59,     0,    45,     0,     0,     0,    68,     0,
      47,    48,    49,    50,    51,    52,    53,     0,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    87,    45,    54,    55,    56,    57,    58,    59,    45,
       0,     0,     0,     0,     0,     0,    47,    48,    49,    50,
      51,    52,    53,    47,    48,    49,    50,    51,    52,     0,
      -1,    54,    55,    56,    57,    58,    59,    45,    54,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,     0,
       0,    47,    48,    49,    50,    51,     0,     0,     0,    54,
      55,    56,    57,    58,    59,     0,    54,    55,    56,    57,
      58,    59,   109,     0,     0,     0,     0,     0,   114,     0,
       0,     0,     0,     0,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,     0,     0,     0,   132
};

static const yytype_int16 yycheck[] =
{
       6,     8,     8,     9,    10,    11,    10,     5,     5,    13,
      16,     5,     0,    15,    16,    17,    18,    19,     5,     0,
      26,    27,    28,    72,    37,     4,     5,     6,     7,     3,
      34,    10,    20,    43,    44,    45,    46,    14,    10,    45,
      40,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    33,     3,    40,   106,     3,     4,
       5,     6,     7,    42,    11,    10,     8,   116,     5,    13,
      46,    40,    11,    39,     9,    20,    21,    22,    23,     3,
      13,    87,     3,     4,     5,     6,     7,    40,    33,    10,
      35,    36,    37,    38,     9,     3,     8,    42,   104,    20,
      21,    22,    23,    25,     8,    18,   112,     9,     9,    20,
     122,    -1,    33,   108,    35,    36,    87,    38,    -1,    -1,
      -1,    42,     3,     4,     5,     6,     7,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    11,    12,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    12,    38,    14,    -1,
      -1,    42,    26,    27,    28,    29,    30,    31,    32,    -1,
      26,    27,    28,    29,    30,    31,    32,    41,    42,    43,
      44,    45,    46,    -1,    -1,    41,    42,    43,    44,    45,
      46,    12,    -1,    14,    -1,    -1,    -1,    -1,    12,    -1,
      14,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    26,    27,    28,    29,    30,    31,    32,    -1,
      41,    42,    43,    44,    45,    46,    12,    41,    42,    43,
      44,    45,    46,    -1,    12,    -1,    -1,    -1,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    -1,    26,    27,
      28,    29,    30,    31,    32,    41,    42,    43,    44,    45,
      46,    39,    12,    41,    42,    43,    44,    45,    46,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    26,    27,    28,    29,    30,    31,    -1,
      12,    41,    42,    43,    44,    45,    46,    12,    41,    42,
      43,    44,    45,    46,    26,    27,    28,    29,    30,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    -1,    41,    42,    43,    44,
      45,    46,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,
      -1,    -1,    -1,    -1,   131
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    10,    20,    21,    22,
      23,    33,    35,    36,    37,    38,    42,    49,    50,    51,
      53,    55,    59,    61,    63,    67,    10,    13,    34,    61,
       5,    61,    61,    61,    61,     5,     5,     8,     5,    61,
       0,    51,    50,     3,    14,    12,    14,    26,    27,    28,
      29,    30,    31,    32,    41,    42,    43,    44,    45,    46,
      61,    62,    61,    61,    11,    40,    14,    14,    24,    10,
       3,    52,    40,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    39,    11,    15,
      16,    17,    18,    19,    60,     8,     5,    64,    65,     3,
      54,    55,    60,    62,    13,    56,    40,    11,    39,    54,
       9,     3,    13,    61,    54,    60,    40,    64,    54,    61,
       9,    60,     3,    58,     8,    58,    25,    54,    66,     8,
       9,    57,    54,     9
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    49,    49,    50,    50,    52,    51,
      53,    53,    53,    53,    54,    54,    54,    55,    55,    55,
      55,    56,    57,    55,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    62,
      63,    64,    64,    64,    65,    66,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     2,     0,     5,
       1,     1,     2,     1,     1,     3,     2,     2,     2,     3,
       3,     0,     0,    13,     0,     2,     6,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     1,     3,     0,     1,     3,
      10,     0,     1,     3,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 2: /* file_content: %empty  */
#line 67 "sfl.y"
                    { printf("File is empty!"); }
#line 1278 "build/sfl.y.c"
    break;

  case 8: /* $@1: %empty  */
#line 79 "sfl.y"
                    { in_if_block = 1; }
#line 1284 "build/sfl.y.c"
    break;

  case 9: /* main_block: T_MAIN T_OBRACE $@1 instructions T_CBRACE  */
#line 79 "sfl.y"
                                                               {
        in_if_block = 0;
        AST_set_main_block(ast, (yyvsp[-1].instr));  
    }
#line 1293 "build/sfl.y.c"
    break;

  case 14: /* instructions: instruction  */
#line 93 "sfl.y"
                                        { (yyval.instr) = (yyvsp[0].instr); }
#line 1299 "build/sfl.y.c"
    break;

  case 15: /* instructions: instruction T_NEWLINE instructions  */
#line 94 "sfl.y"
                                         {
        InstructionNode* tail = (yyvsp[-2].instr);         //$1 = prima instructiune
        while (tail->next) tail = tail->next;
        tail->next = (yyvsp[0].instr);               // $3 restul instructiunilor
        (yyval.instr) = (yyvsp[-2].instr);                       // $$ devine capul noi liste
    }
#line 1310 "build/sfl.y.c"
    break;

  case 16: /* instructions: T_NEWLINE instructions  */
#line 100 "sfl.y"
                                        { (yyval.instr) = (yyvsp[0].instr); }
#line 1316 "build/sfl.y.c"
    break;

  case 17: /* instruction: declaration T_SEMICOLON  */
#line 104 "sfl.y"
                            {
        (yyval.instr) = InstructionNode_create_declaration((yyvsp[-1].decl), yylineno);
        if (!in_if_block) {
            AST_add_declaration(ast, (yyvsp[-1].decl));
        }
    }
#line 1327 "build/sfl.y.c"
    break;

  case 18: /* instruction: expr T_SEMICOLON  */
#line 112 "sfl.y"
                       {
        (yyval.instr) = InstructionNode_create_expression((yyvsp[-1].expressionNode), yylineno); //creez InstructionNode si aici pt ca am nevoie de $$ 
                                                            //care va merge intr o lista de instructiuni
        if (!in_if_block) {
            AST_add_expression(ast, (yyvsp[-1].expressionNode));
        }
    }
#line 1339 "build/sfl.y.c"
    break;

  case 19: /* instruction: T_PRINT expr T_SEMICOLON  */
#line 121 "sfl.y"
                               {
        ExpressionNode* printExpr = ExpressionNode_create_print((yyvsp[-1].expressionNode), yylineno);
        (yyval.instr) = InstructionNode_create_expression(printExpr, yylineno);
        if (!in_if_block) {
            AST_add_expression(ast, printExpr);
        }
    }
#line 1351 "build/sfl.y.c"
    break;

  case 20: /* instruction: T_RETURN expr T_SEMICOLON  */
#line 128 "sfl.y"
                                {
        ExpressionNode* retExpr = ExpressionNode_create_return((yyvsp[-1].expressionNode), yylineno);
        (yyval.instr) = InstructionNode_create_expression(retExpr, yylineno);
        if (!in_if_block) {
            AST_add_expression(ast, retExpr);
        }
    }
#line 1363 "build/sfl.y.c"
    break;

  case 21: /* $@2: %empty  */
#line 135 "sfl.y"
                                { in_if_block = 1; }
#line 1369 "build/sfl.y.c"
    break;

  case 22: /* $@3: %empty  */
#line 135 "sfl.y"
                                                                                                        { in_if_block = 1; }
#line 1375 "build/sfl.y.c"
    break;

  case 23: /* instruction: T_IF expr T_THEN T_OBRACE $@2 instructions T_CBRACE opt_newlines T_ELSE T_OBRACE $@3 instructions T_CBRACE  */
#line 135 "sfl.y"
                                                                                                                                                   {
        in_if_block = 0;
        ExpressionNode* ifExpr = ExpressionNode_create_if_block((yyvsp[-11].expressionNode), (yyvsp[-7].instr), (yyvsp[-1].instr), yylineno);
        (yyval.instr) = InstructionNode_create_expression(ifExpr, yylineno);
        AST_add_expression(ast, ifExpr);
    }
#line 1386 "build/sfl.y.c"
    break;

  case 24: /* opt_newlines: %empty  */
#line 144 "sfl.y"
                { }
#line 1392 "build/sfl.y.c"
    break;

  case 25: /* opt_newlines: T_NEWLINE opt_newlines  */
#line 145 "sfl.y"
                             { }
#line 1398 "build/sfl.y.c"
    break;

  case 26: /* declaration: T_LET IDENTIFIER T_COLON type T_ASSIGN expr  */
#line 149 "sfl.y"
                                                {
        DeclarationNode *d = DeclarationNode_create((yyvsp[-2].str), (yyvsp[-4].str), (yyvsp[0].expressionNode), yylineno);
        d->is_mutable = 0;  
        (yyval.decl) = d;
    }
#line 1408 "build/sfl.y.c"
    break;

  case 27: /* declaration: T_MUT IDENTIFIER T_COLON type T_ASSIGN expr  */
#line 154 "sfl.y"
                                                  {
        DeclarationNode *d = DeclarationNode_create((yyvsp[-2].str), (yyvsp[-4].str), (yyvsp[0].expressionNode), yylineno);
        d->is_mutable = 1; 
        (yyval.decl) = d;
    }
#line 1418 "build/sfl.y.c"
    break;

  case 28: /* type: T_INT  */
#line 162 "sfl.y"
                { (yyval.str) = "int"; }
#line 1424 "build/sfl.y.c"
    break;

  case 29: /* type: T_FLOAT  */
#line 163 "sfl.y"
                { (yyval.str) = "float"; }
#line 1430 "build/sfl.y.c"
    break;

  case 30: /* type: T_DOUBLE  */
#line 164 "sfl.y"
                { (yyval.str) = "double"; }
#line 1436 "build/sfl.y.c"
    break;

  case 31: /* type: T_BOOL  */
#line 165 "sfl.y"
                { (yyval.str) = "bool"; }
#line 1442 "build/sfl.y.c"
    break;

  case 32: /* type: T_STRING  */
#line 166 "sfl.y"
                { (yyval.str) = "string"; }
#line 1448 "build/sfl.y.c"
    break;

  case 33: /* expr: DIGIT  */
#line 170 "sfl.y"
                                  { (yyval.expressionNode) = ExpressionNode_create_number((yyvsp[0].integer), yylineno); }
#line 1454 "build/sfl.y.c"
    break;

  case 34: /* expr: FLOAT_LITERAL  */
#line 171 "sfl.y"
                                  { (yyval.expressionNode) = ExpressionNode_create_float(atof((yyvsp[0].str)), yylineno); }
#line 1460 "build/sfl.y.c"
    break;

  case 35: /* expr: IDENTIFIER  */
#line 172 "sfl.y"
                                  { (yyval.expressionNode) = ExpressionNode_create_identifier((yyvsp[0].str), yylineno); }
#line 1466 "build/sfl.y.c"
    break;

  case 36: /* expr: IDENTIFIER T_ASSIGN expr  */
#line 173 "sfl.y"
                                  { (yyval.expressionNode) = ExpressionNode_create_assignment((yyvsp[-2].str), (yyvsp[0].expressionNode), yylineno); }
#line 1472 "build/sfl.y.c"
    break;

  case 37: /* expr: IDENTIFIER T_OPAREN expr_list T_CPAREN  */
#line 174 "sfl.y"
                                             { (yyval.expressionNode) = ExpressionNode_create_function_call((yyvsp[-3].str), (yyvsp[-1].expressionNode), yylineno);}
#line 1478 "build/sfl.y.c"
    break;

  case 38: /* expr: expr T_PLUS expr  */
#line 175 "sfl.y"
                                  { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_PLUS, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1484 "build/sfl.y.c"
    break;

  case 39: /* expr: expr T_MINUS expr  */
#line 176 "sfl.y"
                                  { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_MINUS, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1490 "build/sfl.y.c"
    break;

  case 40: /* expr: expr T_MUL expr  */
#line 177 "sfl.y"
                                  { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_MUL, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1496 "build/sfl.y.c"
    break;

  case 41: /* expr: expr T_DIV expr  */
#line 178 "sfl.y"
                                  { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_DIV, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1502 "build/sfl.y.c"
    break;

  case 42: /* expr: expr T_MOD expr  */
#line 179 "sfl.y"
                                  { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_MOD, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1508 "build/sfl.y.c"
    break;

  case 43: /* expr: expr T_POW expr  */
#line 180 "sfl.y"
                                  { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_POW, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1514 "build/sfl.y.c"
    break;

  case 44: /* expr: expr T_GT expr  */
#line 181 "sfl.y"
                                 { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_GT, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1520 "build/sfl.y.c"
    break;

  case 45: /* expr: expr T_LT expr  */
#line 182 "sfl.y"
                                 { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_LT, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1526 "build/sfl.y.c"
    break;

  case 46: /* expr: expr T_GTE expr  */
#line 183 "sfl.y"
                                 { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_GTE, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1532 "build/sfl.y.c"
    break;

  case 47: /* expr: expr T_LTE expr  */
#line 184 "sfl.y"
                                 { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_LTE, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1538 "build/sfl.y.c"
    break;

  case 48: /* expr: expr T_EQ expr  */
#line 185 "sfl.y"
                                 { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_EQ, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1544 "build/sfl.y.c"
    break;

  case 49: /* expr: expr T_NEQ expr  */
#line 186 "sfl.y"
                                 { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_NEQ, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1550 "build/sfl.y.c"
    break;

  case 50: /* expr: expr T_AND expr  */
#line 187 "sfl.y"
                                 { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_AND, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1556 "build/sfl.y.c"
    break;

  case 51: /* expr: expr T_OR expr  */
#line 188 "sfl.y"
                                 { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_OR, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1562 "build/sfl.y.c"
    break;

  case 52: /* expr: T_NOT expr  */
#line 189 "sfl.y"
                                 { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_NOT, (yyvsp[0].expressionNode), NULL, yylineno); }
#line 1568 "build/sfl.y.c"
    break;

  case 53: /* expr: T_MINUS expr  */
#line 190 "sfl.y"
                                  { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_UNARY_MINUS, (yyvsp[0].expressionNode), NULL, yylineno); }
#line 1574 "build/sfl.y.c"
    break;

  case 54: /* expr: T_OPAREN expr T_CPAREN  */
#line 191 "sfl.y"
                                  { (yyval.expressionNode) = (yyvsp[-1].expressionNode); }
#line 1580 "build/sfl.y.c"
    break;

  case 55: /* expr: STRING_LITERAL  */
#line 192 "sfl.y"
                                  { (yyval.expressionNode) = ExpressionNode_create_string((yyvsp[0].str), yylineno); }
#line 1586 "build/sfl.y.c"
    break;

  case 56: /* expr: IDENTIFIER T_LAMBDA expr  */
#line 193 "sfl.y"
                                  {(yyval.expressionNode) = ExpressionNode_create_lambda((yyvsp[-2].str), (yyvsp[0].expressionNode), yylineno);}
#line 1592 "build/sfl.y.c"
    break;

  case 57: /* expr_list: %empty  */
#line 197 "sfl.y"
                                 { (yyval.expressionNode) = NULL; }
#line 1598 "build/sfl.y.c"
    break;

  case 58: /* expr_list: expr  */
#line 198 "sfl.y"
                                 { (yyval.expressionNode) = (yyvsp[0].expressionNode); }
#line 1604 "build/sfl.y.c"
    break;

  case 59: /* expr_list: expr T_COMMA expr_list  */
#line 199 "sfl.y"
                                 {
        (yyvsp[-2].expressionNode)->next = (yyvsp[0].expressionNode);
        (yyval.expressionNode) = (yyvsp[-2].expressionNode);
    }
#line 1613 "build/sfl.y.c"
    break;

  case 60: /* function_declaration: T_FUNC IDENTIFIER T_OPAREN param_list T_CPAREN T_COLON type T_OBRACE function_body T_CBRACE  */
#line 206 "sfl.y"
                                                                                               {
        FunctionNode* f = FunctionNode_create_with_params_and_return_type((yyvsp[-8].str), (yyvsp[-6].param), (yyvsp[-3].str), (yyvsp[-1].instr), yylineno);
        AST_add_function(ast, f);
        (yyval.function) = f;
    }
#line 1623 "build/sfl.y.c"
    break;

  case 61: /* param_list: %empty  */
#line 214 "sfl.y"
                                        { (yyval.param) = NULL; }
#line 1629 "build/sfl.y.c"
    break;

  case 62: /* param_list: param  */
#line 215 "sfl.y"
                                        { (yyval.param) = (yyvsp[0].param); }
#line 1635 "build/sfl.y.c"
    break;

  case 63: /* param_list: param T_COMMA param_list  */
#line 216 "sfl.y"
                                        {
        (yyvsp[-2].param)->next = (yyvsp[0].param);
        (yyval.param) = (yyvsp[-2].param);
    }
#line 1644 "build/sfl.y.c"
    break;

  case 64: /* param: IDENTIFIER T_COLON type  */
#line 223 "sfl.y"
                                { (yyval.param) = ParameterNode_create((yyvsp[-2].str), (yyvsp[0].str)); }
#line 1650 "build/sfl.y.c"
    break;

  case 65: /* function_body: instructions  */
#line 227 "sfl.y"
                 { (yyval.instr) = (yyvsp[0].instr); }
#line 1656 "build/sfl.y.c"
    break;

  case 66: /* include_directive: T_INCLUDE IDENTIFIER T_NEWLINE  */
#line 231 "sfl.y"
                                   {
        int is_system = (strchr((yyvsp[-1].str), '.') == NULL); //daca exista . nume e include local, altfel e de sistem
        AST_add_include(ast, (yyvsp[-1].str), is_system);
        (yyval.str) = NULL; // se adauga pur si simplu in ast nu e un nod legat de restul structurii
    }
#line 1666 "build/sfl.y.c"
    break;


#line 1670 "build/sfl.y.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 238 "sfl.y"


void yyerror(const char* s) {
    fprintf(stderr, "Unrecognized characters on line %d: %s\n", yylineno, s);
    exit(1);
}

int main(int argc, char** argv) {
    char* inputFileName = NULL;
    if (argc > 1) {
        inputFileName = argv[1];
        FILE *fp = fopen(argv[1], "r");
        if (!fp) {
            perror("Failed to open file");
            exit(2);
        }
        yyin = fp;
    } else {
        fprintf(stderr, "File argument not provided\n");
        exit(3);
    }
    ast = AST_create();
    yyparse();

    // create output file name from input file name
    // append ".c" at the end of input file name
        int inputFileNameSize = strlen(inputFileName);
    int outputFileNameSize = inputFileNameSize + 3;
    char* outputFileName = malloc(outputFileNameSize);
    memcpy(outputFileName, inputFileName, inputFileNameSize);
    outputFileName[outputFileNameSize - 3] = '.';
    outputFileName[outputFileNameSize - 2] = 'c';
    outputFileName[outputFileNameSize - 1] = '\0';

    FILE* outputFile = fopen(outputFileName, "w");
    AST_execute(ast, outputFile);

    AST_free(ast);
    fclose(yyin);
    fclose(outputFile);
    free(outputFileName);
    return 0;
}
