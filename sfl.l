%{
#include <stdio.h>
#include "sfl.y.h"
#include "../ast/ast.h"

void yyerror(const char *s);
%}

%option yylineno

%%

[ \t]                       ; 
\n                          { return T_NEWLINE; }
"//".*                      ;  // comentariu

0|[1-9][0-9]*           { yylval.integer = atoi(yytext); return DIGIT; }
"true"                  { yylval.integer = 1; return DIGIT; }
"false"                 { yylval.integer = 0; return DIGIT; }
\"(\\.|[^"])*\"         { yylval.str = strdup(yytext); return STRING_LITERAL; }
[0-9]+\.[0-9]+          { yylval.str = strdup(yytext); return FLOAT_LITERAL; }

"{"                     { return T_OBRACE; }
"}"                     { return T_CBRACE; }
"("                     { return T_OPAREN; }
")"                     { return T_CPAREN; }

"=="                    { return T_EQ; }
"="                     { return T_ASSIGN; }
"!="                    { return T_NEQ; }
">="                    { return T_GTE; }
"<="                    { return T_LTE; }
">"                     { return T_GT; }
"<"                     { return T_LT; }
"&&"                    { return T_AND; }
"||"                    { return T_OR; }
"!"                     { return T_NOT; }

";"                     { return T_SEMICOLON; }
","                     { return T_COMMA; }
":"                     { return T_COLON; }

"+"                     { return T_PLUS;}
"-"                     { return T_MINUS; }
"/"                     { return T_DIV; }
"%"                     { return T_MOD; }
"*"                     { return T_MUL; }
"^"                     { return T_POW; }

"->"                    { return T_LAMBDA; }

"int"                   { return T_INT; }
"bool"                  { return T_BOOL; }
"string"                { return T_STRING; }
"print"                 { return T_PRINT; }
"return"                { return T_RETURN; }
"if"                    { return T_IF; }
"then"                  { return T_THEN; }
"else"                  { return T_ELSE; }
"func"                  { return T_FUNC; }
"let"                   { return T_LET; }
"include"               { return T_INCLUDE; }
"main"                  { return T_MAIN;}
"float"                 { return T_FLOAT;}
"double"                { return T_DOUBLE;}
"mut"                   { return T_MUT;}

[A-Za-z_][A-Za-z0-9_.]*  { yylval.str = strdup(yytext); return IDENTIFIER; }

.                       { yyerror(yytext); }

%%