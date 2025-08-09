/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_SFL_Y_H_INCLUDED
# define YY_YY_BUILD_SFL_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_NEWLINE = 258,               /* T_NEWLINE  */
    DIGIT = 259,                   /* DIGIT  */
    IDENTIFIER = 260,              /* IDENTIFIER  */
    STRING_LITERAL = 261,          /* STRING_LITERAL  */
    FLOAT_LITERAL = 262,           /* FLOAT_LITERAL  */
    T_OBRACE = 263,                /* T_OBRACE  */
    T_CBRACE = 264,                /* T_CBRACE  */
    T_OPAREN = 265,                /* T_OPAREN  */
    T_CPAREN = 266,                /* T_CPAREN  */
    T_EQ = 267,                    /* T_EQ  */
    T_ASSIGN = 268,                /* T_ASSIGN  */
    T_SEMICOLON = 269,             /* T_SEMICOLON  */
    T_INT = 270,                   /* T_INT  */
    T_FLOAT = 271,                 /* T_FLOAT  */
    T_DOUBLE = 272,                /* T_DOUBLE  */
    T_BOOL = 273,                  /* T_BOOL  */
    T_STRING = 274,                /* T_STRING  */
    T_LET = 275,                   /* T_LET  */
    T_PRINT = 276,                 /* T_PRINT  */
    T_RETURN = 277,                /* T_RETURN  */
    T_IF = 278,                    /* T_IF  */
    T_THEN = 279,                  /* T_THEN  */
    T_ELSE = 280,                  /* T_ELSE  */
    T_NEQ = 281,                   /* T_NEQ  */
    T_GTE = 282,                   /* T_GTE  */
    T_LTE = 283,                   /* T_LTE  */
    T_GT = 284,                    /* T_GT  */
    T_LT = 285,                    /* T_LT  */
    T_AND = 286,                   /* T_AND  */
    T_OR = 287,                    /* T_OR  */
    T_NOT = 288,                   /* T_NOT  */
    T_LAMBDA = 289,                /* T_LAMBDA  */
    T_FUNC = 290,                  /* T_FUNC  */
    T_INCLUDE = 291,               /* T_INCLUDE  */
    T_MAIN = 292,                  /* T_MAIN  */
    T_MUT = 293,                   /* T_MUT  */
    T_COMMA = 294,                 /* T_COMMA  */
    T_COLON = 295,                 /* T_COLON  */
    T_PLUS = 296,                  /* T_PLUS  */
    T_MINUS = 297,                 /* T_MINUS  */
    T_MUL = 298,                   /* T_MUL  */
    T_DIV = 299,                   /* T_DIV  */
    T_MOD = 300,                   /* T_MOD  */
    T_POW = 301,                   /* T_POW  */
    UMINUS = 302                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_NEWLINE 258
#define DIGIT 259
#define IDENTIFIER 260
#define STRING_LITERAL 261
#define FLOAT_LITERAL 262
#define T_OBRACE 263
#define T_CBRACE 264
#define T_OPAREN 265
#define T_CPAREN 266
#define T_EQ 267
#define T_ASSIGN 268
#define T_SEMICOLON 269
#define T_INT 270
#define T_FLOAT 271
#define T_DOUBLE 272
#define T_BOOL 273
#define T_STRING 274
#define T_LET 275
#define T_PRINT 276
#define T_RETURN 277
#define T_IF 278
#define T_THEN 279
#define T_ELSE 280
#define T_NEQ 281
#define T_GTE 282
#define T_LTE 283
#define T_GT 284
#define T_LT 285
#define T_AND 286
#define T_OR 287
#define T_NOT 288
#define T_LAMBDA 289
#define T_FUNC 290
#define T_INCLUDE 291
#define T_MAIN 292
#define T_MUT 293
#define T_COMMA 294
#define T_COLON 295
#define T_PLUS 296
#define T_MINUS 297
#define T_MUL 298
#define T_DIV 299
#define T_MOD 300
#define T_POW 301
#define UMINUS 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "sfl.y"

    int integer;
    char* str;
    struct ExpressionNode* expressionNode;
    struct DeclarationNode* decl;
    struct FunctionNode* function;
    struct ParameterNode* param;
    struct InstructionNode* instr;

#line 171 "build/sfl.y.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_SFL_Y_H_INCLUDED  */
