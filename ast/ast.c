#include "ast.h"
#include "../engine/engine.h"
#include <stdlib.h>
#include <string.h>

AST* AST_create() {
    AST* ast = malloc(sizeof(AST));
    ast->instructions = NULL;
    ast->functions = NULL;
    ast->main_block = NULL;
    ast->includes = NULL;
    return ast;
}


void AST_add_declaration(AST* self, DeclarationNode* declaration) {
    InstructionNode* new_node = InstructionNode_create_declaration(declaration, declaration->lineno);
    //creez nou instruction pentru instructiunile globale
    if (!self->instructions) {
        self->instructions = new_node;
        return;
    }
    
    InstructionNode* current = self->instructions;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
}

void AST_add_expression(AST* self, ExpressionNode* expression) {
    if (!expression) return;
    
    InstructionNode* new_node = InstructionNode_create_expression(expression, expression->lineno);
    
    if (!self->instructions) {
        self->instructions = new_node;
        return;
    }
    
    InstructionNode* current = self->instructions;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
}

void AST_add_function(AST* self, FunctionNode* function) {
    if (!self->functions) {
        self->functions = function;
        return;
    }
    //adauga o functie noua
    FunctionNode* current = self->functions;
    while (current->next) {
        current = current->next;
    }
    current->next = function;
}

void AST_execute(AST* self, FILE* outputFile) {
    execute(self, outputFile);
}

void AST_set_main_block(AST* self, InstructionNode* main_block) {
    self->main_block = main_block; //salveaza blocul de instructiuni din main
}

void AST_add_include(AST* self, const char* path, int is_system) {
    IncludeNode* new_include = malloc(sizeof(IncludeNode));
    new_include->path = strdup(path);
    new_include->is_system = is_system;
    new_include->next = NULL;

    if (!self->includes) {
        self->includes = new_include;
        return;
    }

    IncludeNode* current = self->includes;
    while (current->next) {
        current = current->next;
    }
    current->next = new_include;
}

void AST_free(AST* self) {
    if (!self) return;
    
    if (self->instructions) {
        InstructionNode_free_list(self->instructions);
    }
    
    if (self->main_block) {
        InstructionNode_free_list(self->main_block);
    }
    
    FunctionNode* func = self->functions;
    while (func) {
        FunctionNode* next = func->next;
        FunctionNode_free(func);
        func = next;
    }
    
    IncludeNode* inc = self->includes;
    while (inc) {
        IncludeNode* next = inc->next;
        free(inc->path);
        free(inc);
        inc = next;
    }
    
    free(self);
}

FunctionNode* AST_find_function(AST* self, const char* name) { //cauta o functie dupa nume in lista de functii
    if (!self || !name) return NULL; //in ast ul creat deja
    
    FunctionNode* current = self->functions;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}