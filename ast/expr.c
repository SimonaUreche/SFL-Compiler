#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "expr.h"
#include "instructions.h" 

static ExpressionNode* alloc_node(ExpressionType type, int lineno) {
    ExpressionNode* node = malloc(sizeof(ExpressionNode));
    node->type = type;
    node->inferred_type = NULL;
    node->lineno = lineno;
    node->next = NULL;
    return node;
}

ExpressionNode* ExpressionNode_create_operation(
    ExpressionType type, 
    ExpressionNode* left, 
    ExpressionNode* right, 
    int lineno
) {
    ExpressionNode* node = alloc_node(type, lineno);
    node->data.binary.left = left;
    node->data.binary.right = right;
    return node;
}

ExpressionNode* ExpressionNode_create_unary(
    ExpressionType type, 
    ExpressionNode* operand, 
    int lineno
) {
    ExpressionNode* node = alloc_node(type, lineno);
    node->data.unary.operand = operand;
    return node;
}

ExpressionNode* ExpressionNode_create_number(
    int value, 
    int lineno
) {
    ExpressionNode* node = malloc(sizeof(ExpressionNode));
    node->type = IMMEDIATE_NUMBER;
    node->data.immediate_value = value;
    node->inferred_type = "int";
    node->lineno = lineno;
    return node;
}

ExpressionNode* ExpressionNode_create_float(
    float value, 
    int lineno
) {
    ExpressionNode* node = malloc(sizeof(ExpressionNode));
    node->type = IMMEDIATE_FLOAT;
    node->data.float_value = value;
    node->inferred_type = "float";
    node->lineno = lineno;
    return node;
}

ExpressionNode* ExpressionNode_create_double(
    double value, 
    int lineno
) {
    ExpressionNode* node = malloc(sizeof(ExpressionNode));
    node->type = IMMEDIATE_DOUBLE;
    node->data.double_value = value;
    node->inferred_type = "double";
    node->lineno = lineno;
    return node;
}

ExpressionNode* ExpressionNode_create_identifier(
    const char* identifier, 
    int lineno
) {
    ExpressionNode* node = malloc(sizeof(ExpressionNode));
    node->type = IMMEDIATE_IDENTIFIER;
    node->data.identifier = strdup(identifier);
    node->inferred_type = "int";  
    node->lineno = lineno;
    return node;
}

ExpressionNode* ExpressionNode_create_print(
    ExpressionNode* value, 
    int lineno
) {
    ExpressionNode* node = alloc_node(OPERATION_PRINT, lineno);
    node->data.single = value;
    return node;
}

ExpressionNode* ExpressionNode_create_return(
    ExpressionNode* value, 
    int lineno
) {
    ExpressionNode* node = alloc_node(OPERATION_RETURN, lineno);
    node->data.single = value;
    return node;
}

ExpressionNode* ExpressionNode_create_if_block(
    ExpressionNode* cond, 
    InstructionNode* thenList, 
    InstructionNode* elseList, 
    int lineno) {
    ExpressionNode* node = calloc(1, sizeof(ExpressionNode));
    node->type = OPERATION_IF;
    node->data.if_expr.condition = cond;
    node->data.if_expr.thenInstructions = thenList;
    node->data.if_expr.elseInstructions = elseList;
    node->lineno = lineno;
    node->inferred_type = "int";
    node->next = NULL;
    return node;
}


ExpressionNode* ExpressionNode_create_string(
    const char* string_literal, 
    int lineno
) {
    ExpressionNode* node = malloc(sizeof(ExpressionNode));
    node->type = IMMEDIATE_STRING;
    node->data.string_literal = strdup(string_literal);
    node->inferred_type = "string";
    node->lineno = lineno;
    return node;
}

ExpressionNode* ExpressionNode_create_function_call(const char* function_name, ExpressionNode* arguments, int lineno) {
    ExpressionNode* node = (ExpressionNode*)malloc(sizeof(ExpressionNode));
    node->type = OPERATION_FUNCTION_CALL;
    node->lineno = lineno;
    node->next = NULL;
    node->inferred_type = NULL;
    
    node->data.function_call.function_name = strdup(function_name);
    node->data.function_call.arguments = arguments;
    
    return node;
}

ExpressionNode* ExpressionNode_create_assignment(const char* identifier, ExpressionNode* value, int lineno) {
    ExpressionNode* node = malloc(sizeof(ExpressionNode));
    node->type = OPERATION_ASSIGNMENT;
    node->data.assignment.identifier = strdup(identifier);
    node->data.assignment.value = value;
    node->next = NULL;
    node->inferred_type = NULL;
    node->lineno = lineno;
    return node;
}

ExpressionNode* ExpressionNode_create_lambda(
    const char* param_name,
    ExpressionNode* body,
    int lineno
) {
    ExpressionNode* node = malloc(sizeof(ExpressionNode));
    node->type = OPERATION_LAMBDA;
    node->data.lambda.param_name = strdup(param_name);
    node->data.lambda.body = body;
    node->lineno = lineno;
    node->next = NULL;
    return node;
}

void ExpressionNode_free(ExpressionNode* self) {
    if (self == NULL) return;
    
    switch (self->type) {
        case IMMEDIATE_STRING:
        case IMMEDIATE_IDENTIFIER:
            free(self->data.string_literal);
            break;
        case OPERATION_PLUS:
        case OPERATION_MINUS:
        case OPERATION_MUL:
        case OPERATION_DIV:
        case OPERATION_MOD:
        case OPERATION_POW:
        case OPERATION_GT:
        case OPERATION_LT:
        case OPERATION_GTE:
        case OPERATION_LTE:
        case OPERATION_EQ:
        case OPERATION_NEQ:
        case OPERATION_AND:
        case OPERATION_OR:
            ExpressionNode_free(self->data.binary.left);
            ExpressionNode_free(self->data.binary.right);
            break;
        case OPERATION_UNARY_MINUS:
        case OPERATION_NOT:
            ExpressionNode_free(self->data.unary.operand);
            break;
        case OPERATION_FUNCTION_CALL:
            free(self->data.function_call.function_name);
            ExpressionNode_free(self->data.function_call.arguments);
            break;
        case OPERATION_IF:
            ExpressionNode_free(self->data.if_expr.condition);
            InstructionNode_free(self->data.if_expr.thenInstructions);
            InstructionNode_free(self->data.if_expr.elseInstructions);
            break;
        case OPERATION_PRINT:
        case OPERATION_RETURN:
            ExpressionNode_free(self->data.single);
            break;
        case OPERATION_ASSIGNMENT:
            free(self->data.assignment.identifier);
            ExpressionNode_free(self->data.assignment.value);
            break;
        default:
            break;
    }
    
    free(self->inferred_type);
    ExpressionNode_free(self->next);
    free(self);
}