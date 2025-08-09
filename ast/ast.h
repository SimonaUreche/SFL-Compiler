#pragma once
#include <stdio.h>
#include "expr.h"
#include "decl.h"
#include "func.h"
#include "instructions.h"

typedef struct FunctionNode FunctionNode;

typedef struct IncludeNode {
    char* path;
    int is_system; //0 = "header.h", 1 = <header.h>
    struct IncludeNode* next;//mai multe incude
} IncludeNode;

typedef struct AST {
    InstructionNode* instructions;
    FunctionNode* functions;
    InstructionNode* main_block;
    IncludeNode* includes;
} AST;

/* ---------------- */
/* Constructors */
/* ---------------- */

AST* AST_create();

/* ----------- */
/* Methods */
/* ----------- */

void AST_add_declaration(AST* self, DeclarationNode* declaration);
void AST_add_expression(AST* self, ExpressionNode* expression);
void AST_add_function(AST* self, FunctionNode* function);

void AST_set_main_block(AST* self, InstructionNode* main_block);
void AST_add_include(AST* self, const char* path, int is_system);

void AST_execute(AST* self, FILE* outputFile);
void AST_free(AST* self);

FunctionNode* AST_find_function(AST* self, const char* name);
