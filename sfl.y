%{
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
%}

%union {
    int integer;
    char* str;
    struct ExpressionNode* expressionNode;
    struct DeclarationNode* decl;
    struct FunctionNode* function;
    struct ParameterNode* param;
    struct InstructionNode* instr;
}

%token T_NEWLINE
%token <integer> DIGIT
%token <str> IDENTIFIER
%token <str> STRING_LITERAL
%token <str> FLOAT_LITERAL

%token T_OBRACE T_CBRACE T_OPAREN T_CPAREN
%token T_EQ T_ASSIGN T_SEMICOLON
%token T_INT T_FLOAT T_DOUBLE T_BOOL T_STRING  T_LET
%token T_PRINT T_RETURN
%token T_IF T_THEN T_ELSE
%token T_NEQ T_GTE T_LTE T_GT T_LT T_AND T_OR T_NOT
%token T_LAMBDA T_FUNC T_INCLUDE T_MAIN T_MUT
%token T_COMMA T_COLON T_PLUS T_MINUS T_MUL T_DIV T_MOD T_POW

%left T_OR
%left T_AND
%nonassoc T_EQ T_NEQ T_GT T_LT T_GTE T_LTE
%left T_PLUS T_MINUS
%left T_MUL T_DIV T_MOD
%right T_POW
%nonassoc T_NOT UMINUS T_ELSE

%type <str> type include_directive
%type <instr> instructions instruction function_body 
%type <expressionNode> expr expr_list
%type <decl> declaration
%type <function> function_declaration
%type <param> param param_list

%start file_content

%%

file_content:
    /* empty */     { printf("File is empty!"); }
    | file_elements //declaratii/includes
    | main_block //partea de main
    | file_elements main_block //ambele
    ;

file_elements:
    file_element
    | file_element file_elements
    ;

main_block:
    T_MAIN T_OBRACE { in_if_block = 1; } instructions T_CBRACE {
        in_if_block = 0;
        AST_set_main_block(ast, $4);  
    }
    ;

file_element:
    include_directive
    | function_declaration 
    | instruction T_NEWLINE
    | T_NEWLINE
    ;

instructions:
    instruction                         { $$ = $1; }
    | instruction T_NEWLINE instructions {
        InstructionNode* tail = $1;         //$1 = prima instructiune
        while (tail->next) tail = tail->next;
        tail->next = $3;               // $3 restul instructiunilor
        $$ = $1;                       // $$ devine capul noi liste
    }
    | T_NEWLINE instructions            { $$ = $2; }
    ;

instruction: //fiecare instructiune e transformata intr un instrution node care e adaugat la ast
    declaration T_SEMICOLON {
        $$ = InstructionNode_create_declaration($1, yylineno);
        if (!in_if_block) {
            AST_add_declaration(ast, $1);
        }
    }
    ;

    | expr T_SEMICOLON {
        $$ = InstructionNode_create_expression($1, yylineno); //creez InstructionNode si aici pt ca am nevoie de $$ 
                                                            //care va merge intr o lista de instructiuni
        if (!in_if_block) {
            AST_add_expression(ast, $1);
        }
    }
    ;

    | T_PRINT expr T_SEMICOLON {
        ExpressionNode* printExpr = ExpressionNode_create_print($2, yylineno);
        $$ = InstructionNode_create_expression(printExpr, yylineno);
        if (!in_if_block) {
            AST_add_expression(ast, printExpr);
        }
    }
    | T_RETURN expr T_SEMICOLON {
        ExpressionNode* retExpr = ExpressionNode_create_return($2, yylineno);
        $$ = InstructionNode_create_expression(retExpr, yylineno);
        if (!in_if_block) {
            AST_add_expression(ast, retExpr);
        }
    }
    | T_IF expr T_THEN T_OBRACE { in_if_block = 1; } instructions T_CBRACE opt_newlines T_ELSE T_OBRACE { in_if_block = 1; } instructions T_CBRACE {
        in_if_block = 0;
        ExpressionNode* ifExpr = ExpressionNode_create_if_block($2, $6, $12, yylineno);
        $$ = InstructionNode_create_expression(ifExpr, yylineno);
        AST_add_expression(ast, ifExpr);
    }
    ;

opt_newlines:
    /* empty */ { }
    | T_NEWLINE opt_newlines { }
    ;
    
declaration:
    T_LET IDENTIFIER T_COLON type T_ASSIGN expr {
        DeclarationNode *d = DeclarationNode_create($4, $2, $6, yylineno);
        d->is_mutable = 0;  
        $$ = d;
    }
    | T_MUT IDENTIFIER T_COLON type T_ASSIGN expr {
        DeclarationNode *d = DeclarationNode_create($4, $2, $6, yylineno);
        d->is_mutable = 1; 
        $$ = d;
    }
    ; 

type:
    T_INT       { $$ = "int"; }
    | T_FLOAT   { $$ = "float"; }
    | T_DOUBLE  { $$ = "double"; }
    | T_BOOL    { $$ = "bool"; }
    | T_STRING  { $$ = "string"; }
    ;

expr:
    DIGIT                         { $$ = ExpressionNode_create_number($1, yylineno); }
    | FLOAT_LITERAL               { $$ = ExpressionNode_create_float(atof($1), yylineno); }
    | IDENTIFIER                  { $$ = ExpressionNode_create_identifier($1, yylineno); }
    | IDENTIFIER T_ASSIGN expr    { $$ = ExpressionNode_create_assignment($1, $3, yylineno); }
    | IDENTIFIER T_OPAREN expr_list T_CPAREN { $$ = ExpressionNode_create_function_call($1, $3, yylineno);}
    | expr T_PLUS expr            { $$ = ExpressionNode_create_operation(OPERATION_PLUS, $1, $3, yylineno); }
    | expr T_MINUS expr           { $$ = ExpressionNode_create_operation(OPERATION_MINUS, $1, $3, yylineno); }
    | expr T_MUL expr             { $$ = ExpressionNode_create_operation(OPERATION_MUL, $1, $3, yylineno); }
    | expr T_DIV expr             { $$ = ExpressionNode_create_operation(OPERATION_DIV, $1, $3, yylineno); }
    | expr T_MOD expr             { $$ = ExpressionNode_create_operation(OPERATION_MOD, $1, $3, yylineno); }
    | expr T_POW expr             { $$ = ExpressionNode_create_operation(OPERATION_POW, $1, $3, yylineno); }
    | expr T_GT expr             { $$ = ExpressionNode_create_operation(OPERATION_GT, $1, $3, yylineno); }
    | expr T_LT expr             { $$ = ExpressionNode_create_operation(OPERATION_LT, $1, $3, yylineno); }
    | expr T_GTE expr            { $$ = ExpressionNode_create_operation(OPERATION_GTE, $1, $3, yylineno); }
    | expr T_LTE expr            { $$ = ExpressionNode_create_operation(OPERATION_LTE, $1, $3, yylineno); }
    | expr T_EQ expr             { $$ = ExpressionNode_create_operation(OPERATION_EQ, $1, $3, yylineno); }
    | expr T_NEQ expr            { $$ = ExpressionNode_create_operation(OPERATION_NEQ, $1, $3, yylineno); }
    | expr T_AND expr            { $$ = ExpressionNode_create_operation(OPERATION_AND, $1, $3, yylineno); }
    | expr T_OR expr             { $$ = ExpressionNode_create_operation(OPERATION_OR, $1, $3, yylineno); }
    | T_NOT expr                 { $$ = ExpressionNode_create_operation(OPERATION_NOT, $2, NULL, yylineno); }
    | T_MINUS expr %prec UMINUS   { $$ = ExpressionNode_create_operation(OPERATION_UNARY_MINUS, $2, NULL, yylineno); }
    | T_OPAREN expr T_CPAREN      { $$ = $2; }
    | STRING_LITERAL              { $$ = ExpressionNode_create_string($1, yylineno); }
    | IDENTIFIER T_LAMBDA expr    {$$ = ExpressionNode_create_lambda($1, $3, yylineno);}
    ; 

expr_list:
    /* empty */                  { $$ = NULL; }
    | expr                       { $$ = $1; }
    | expr T_COMMA expr_list     {
        $1->next = $3;
        $$ = $1;
    }
    ;

function_declaration:
    T_FUNC IDENTIFIER T_OPAREN param_list T_CPAREN T_COLON type T_OBRACE function_body T_CBRACE{
        FunctionNode* f = FunctionNode_create_with_params_and_return_type($2, $4, $7, $9, yylineno);
        AST_add_function(ast, f);
        $$ = f;
    }
    ;

param_list:
    /* empty */                         { $$ = NULL; }
    | param                             { $$ = $1; }
    | param T_COMMA param_list          {
        $1->next = $3;
        $$ = $1;
    }
    ;

param:
    IDENTIFIER T_COLON type     { $$ = ParameterNode_create($1, $3); }
    ;

function_body:
    instructions { $$ = $1; }
    ;

include_directive:
    T_INCLUDE IDENTIFIER T_NEWLINE {
        int is_system = (strchr($2, '.') == NULL); //daca exista . nume e include local, altfel e de sistem
        AST_add_include(ast, $2, is_system);
        $$ = NULL; // se adauga pur si simplu in ast nu e un nod legat de restul structurii
    }
    ;

%%

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