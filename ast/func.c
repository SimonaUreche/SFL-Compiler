#include <stdlib.h>
#include <string.h>
#include "func.h"

ParameterNode* ParameterNode_create(const char* name, const char* type) {
    ParameterNode* param = malloc(sizeof(ParameterNode));
    param->name = strdup(name);
    param->type = strdup(type);
    param->next = NULL;
    return param;
}

FunctionNode* FunctionNode_create_with_params_and_return_type(const char* name, ParameterNode* params, const char* return_type, InstructionNode* body, int lineno) {
    FunctionNode* fn = malloc(sizeof(FunctionNode));
    fn->name = strdup(name);
    fn->return_type = strdup(return_type);
    fn->parameters = params;
    fn->body = body;
    fn->next = NULL;
    fn->lineno = lineno;
    return fn;
}

void ParameterNode_free(ParameterNode* param) {
    while (param) {
        ParameterNode* next = param->next;
        free(param->name);
        free(param->type);
        free(param);
        param = next;
    }
}

void FunctionNode_free(FunctionNode* node) {
    if (!node) return;
    
    free(node->name);
    free(node->return_type);
    
    ParameterNode* param = node->parameters;
    while (param) {
        ParameterNode* next = param->next;
        free(param->name);
        free(param->type);
        free(param);
        param = next;
    }
    
    if (node->body) {
        InstructionNode_free_list(node->body);
    }
    
    free(node);
}
