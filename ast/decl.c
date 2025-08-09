#include "decl.h"
#include <stdlib.h>
#include <string.h>

DeclarationNode* DeclarationNode_create(
    const char* type,
    const char* identifier,
    ExpressionNode* assigned_expression,
    int lineno
) {
    DeclarationNode* node = malloc(sizeof(DeclarationNode));
    node->type = strdup(type);
    node->identifier = strdup(identifier);
    node->assigned_expression = assigned_expression;
    node->is_mutable = 0;
    node->lineno = lineno;
    node->next = NULL;
    return node;
}

void DeclarationNode_free(DeclarationNode* self) {
    if (self == NULL) return;
    free(self->type);
    free(self->identifier);
    ExpressionNode_free(self->assigned_expression);
    DeclarationNode_free(self->next);
    free(self);
}
