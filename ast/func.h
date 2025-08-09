#pragma once
#include "expr.h"
#include "instructions.h"

typedef struct ParameterNode {
    char* name;
    char* type;
    struct ParameterNode* next;
} ParameterNode;

typedef struct FunctionNode {
    char* name;
    char* return_type;  
    ParameterNode* parameters;
    InstructionNode* body;
    struct FunctionNode* next;
    int lineno;
} FunctionNode;

ParameterNode* ParameterNode_create(const char* name, const char* type);
FunctionNode* FunctionNode_create_with_params_and_return_type(const char* name, ParameterNode* params, const char* return_type, InstructionNode* body, int lineno);

void FunctionNode_free(FunctionNode* node);
void ParameterNode_free(ParameterNode* param);