#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declarations
typedef struct ExpressionNode ExpressionNode;
typedef struct InstructionNode InstructionNode;

typedef enum ExpressionType { //folosit pt expresii in sine
    /* operations */
    OPERATION_PLUS,
    OPERATION_MINUS,
    OPERATION_UNARY_MINUS,
    OPERATION_MUL,
    OPERATION_DIV,
    OPERATION_MOD,
    OPERATION_POW,
    OPERATION_PRINT,
    OPERATION_RETURN,
    OPERATION_IF,
    OPERATION_LAMBDA,
    OPERATION_GT,
    OPERATION_LT,
    OPERATION_GTE,
    OPERATION_LTE,
    OPERATION_EQ,
    OPERATION_NEQ,
    OPERATION_AND,
    OPERATION_OR,
    OPERATION_NOT,
    OPERATION_FUNCTION_CALL,
    OPERATION_ASSIGNMENT,

    /* immediate values */
    IMMEDIATE_NUMBER,
    IMMEDIATE_FLOAT,
    IMMEDIATE_DOUBLE,
    IMMEDIATE_STRING,
    IMMEDIATE_IDENTIFIER,
} ExpressionType;

typedef struct {
    char* param_name;
    struct ExpressionNode* body;
} LambdaNode;

typedef struct ExpressionNode {
    union {
        int immediate_value;            
        float float_value;
        double double_value;
        char* identifier;               
        char* string_literal;           

        struct {
            struct ExpressionNode* left;
            struct ExpressionNode* right;
        } binary;

        struct {
            struct ExpressionNode* operand;
        } unary;

        //if
        struct {
            struct ExpressionNode* condition;
            struct InstructionNode* thenInstructions;
            struct InstructionNode* elseInstructions;
        } if_expr;

        struct ExpressionNode* single;

        //function call
        struct {
            char* function_name;
            struct ExpressionNode* arguments;
        } function_call;

        struct {
            char* identifier;
            struct ExpressionNode* value;
        } assignment;

        LambdaNode lambda;
    } data;

    ExpressionType type;
    char* inferred_type;
    int lineno;
    struct ExpressionNode* next;
} ExpressionNode;

/* ------------ */
/* Constructors */
/* ------------ */

ExpressionNode* ExpressionNode_create_operation(
    ExpressionType type,
    ExpressionNode* left,
    ExpressionNode* right,
    int lineno
);

ExpressionNode* ExpressionNode_create_number(
    int value,
    int lineno
);

ExpressionNode* ExpressionNode_create_float(
    float value,
    int lineno
);

ExpressionNode* ExpressionNode_create_double(
    double value,
    int lineno
);

ExpressionNode* ExpressionNode_create_identifier(
    const char* name,
    int lineno
);

ExpressionNode* ExpressionNode_create_print(
    ExpressionNode* value, 
    int lineno
);

ExpressionNode* ExpressionNode_create_return(
    ExpressionNode* value, 
    int lineno
);

ExpressionNode* ExpressionNode_create_if_block(
    ExpressionNode* cond, 
    struct InstructionNode* thenList, 
    struct InstructionNode* elseList, 
    int lineno
);

ExpressionNode* ExpressionNode_create_string(
    const char* value,
    int lineno
);

ExpressionNode* ExpressionNode_create_unary(
    ExpressionType type, 
    ExpressionNode* operand, 
    int lineno
);

ExpressionNode* ExpressionNode_create_function_call(
    const char* function_name,
    ExpressionNode* arguments,
    int lineno
);

ExpressionNode* ExpressionNode_create_assignment(
    const char* identifier,
    ExpressionNode* value,
    int lineno
);

ExpressionNode* ExpressionNode_create_lambda(
    const char* param_name,
    ExpressionNode* body,
    int lineno
);

/* ------- */
/* Methods */
/* ------- */

void ExpressionNode_free(ExpressionNode* self);
