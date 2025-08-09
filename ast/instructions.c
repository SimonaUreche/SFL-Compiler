#include <stdlib.h>
#include "instructions.h"
#include "expr.h"
#include "decl.h"

InstructionNode* InstructionNode_create_expression(ExpressionNode* expr, int lineno) {
    InstructionNode* node = malloc(sizeof(InstructionNode));
    node->type = INSTRUCTION_EXPRESSION;
    node->data.expression = expr;
    node->next = NULL;
    node->lineno = lineno;
    return node;
}

InstructionNode* InstructionNode_create_declaration(DeclarationNode* decl, int lineno) {
    InstructionNode* node = malloc(sizeof(InstructionNode));
    node->type = INSTRUCTION_DECLARATION;
    node->data.declaration = decl;
    node->next = NULL;
    node->lineno = lineno;
    return node;
}

void InstructionNode_free_list(InstructionNode* node) {
    while (node) {
        InstructionNode* next = node->next;
        
        if (node->type == INSTRUCTION_DECLARATION) {
        } else if (node->type == INSTRUCTION_EXPRESSION) {
        }
        
        free(node);
        node = next;
    }
}

void InstructionNode_free(InstructionNode* self) {
    if (self == NULL) return;
    
    switch (self->type) {
        case INSTRUCTION_EXPRESSION:
            ExpressionNode_free(self->data.expression);
            break;
        case INSTRUCTION_DECLARATION:
            DeclarationNode_free(self->data.declaration);
            break;
    }
    
    InstructionNode_free(self->next);
    free(self);
}