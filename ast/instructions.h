#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ExpressionNode ExpressionNode;
typedef struct DeclarationNode DeclarationNode;

typedef enum { //folosit pentru blocuri de cod, main, if
    INSTRUCTION_DECLARATION,
    INSTRUCTION_EXPRESSION
} InstructionType;

typedef struct InstructionNode {
    InstructionType type;
    union {
        struct DeclarationNode* declaration;
        struct ExpressionNode* expression;
    } data;
    int lineno;
    struct InstructionNode* next;
} InstructionNode;

InstructionNode* InstructionNode_create_declaration(struct DeclarationNode* declaration, int lineno);
InstructionNode* InstructionNode_create_expression(struct ExpressionNode* expression, int lineno);
void InstructionNode_free(InstructionNode* node);
void InstructionNode_free_list(InstructionNode* node); 