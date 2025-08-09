#include "engine.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

extern AST* ast; //am nevoie pentru functiile deja declarata=e

static int indent_level = 0;
static int lambda_counter = 0; //pt generare functii lambda
static int lambda_call_counter = 0;

typedef struct LambdaGenerated {
    char* name;
    LambdaNode lambda; //param+corp
    struct LambdaGenerated* next;
} LambdaGenerated;

typedef struct ParameterStack { //structura pe care o folosesc pt a retine parametrii unei functii
    char* name; //doar numele param din functia curenta
    struct ParameterStack* next;
} ParameterStack;

typedef struct IdentifierString { //structura pt variabile mutabile/imutabile
    char* name;
    char* type;
    struct IdentifierString* next;
    int is_mutable;
} IdentifierString;

static LambdaGenerated* lambda_list = NULL;
IdentifierString* declared_identifiers = NULL;
static ParameterStack* parameter_stack = NULL;


void execute_expression(ExpressionNode* expression, FILE* outputFile);
void execute_declaration(DeclarationNode* declaration, FILE* outputFile);
void execute_function(FunctionNode* func, FILE* outputFile);

void store_lambda_for_codegen(const char* name, LambdaNode lambda) {
    //nou lambda generator cu nume unic si stocam toate lambda in lambda_list
    LambdaGenerated* node = malloc(sizeof(LambdaGenerated));
    node->name = strdup(name);
    node->lambda.param_name = strdup(lambda.param_name);
    node->lambda.body = lambda.body;
    node->next = lambda_list;
    lambda_list = node;
} //stocheaza un lambda definit

static void print_indent(FILE* outputFile) {
    for (int i = 0; i < indent_level; i++) {
        fprintf(outputFile, "    ");
    }
}

static void increase_indent() {
    indent_level++;
}

static void decrease_indent() {
    indent_level--;
}

static void print_newline(FILE* outputFile) {
    fprintf(outputFile, "\n");
}


int is_declared(const char* name) { //verifica daca o variabila a fost sau nu inca declarata
    IdentifierString* current = declared_identifiers;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

const char* get_identifier_type(const char* name) { //returneaza tipul identificatorului
    IdentifierString* current = declared_identifiers;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->type;
        }
        current = current->next;
    }
    return NULL;
}

//------------------STIVA CU PARAMS ACTIVI IN FUNCTIA CURENTA
static void push_parameter(const char* name) {
    ParameterStack* new_param = malloc(sizeof(ParameterStack));
    new_param->name = strdup(name);
    new_param->next = parameter_stack;
    parameter_stack = new_param;
}

static void pop_parameter() {
    if (parameter_stack) {
        ParameterStack* temp = parameter_stack;
        parameter_stack = parameter_stack->next;
        free(temp->name);
        free(temp);
    }
}

static int is_parameter(const char* name) {//DOAR PARAMETRII ACCEPTATI
    ParameterStack* current = parameter_stack;
    while (current) {
        if (strcmp(current->name, name) == 0) { //verifica daca e param
            return 1;
        }
        current = current->next;
    }
    return 0;
}

static void clear_parameter_stack() {
    while (parameter_stack) {
        pop_parameter();
    }
}
//-----------------------
static int in_function_body = 0;

char* infer_expression_type(ExpressionNode* expression) {
    if (expression == NULL) {
        return strdup("int"); 
    }
    switch (expression->type) {
        case IMMEDIATE_IDENTIFIER:
            if (in_function_body && !is_parameter(expression->data.identifier)) {
                fprintf(stderr, "ERROR: Function can only access its parameters. Variable '%s' is not a parameter.\n", 
                    expression->data.identifier);
                exit(15);
            }

            if (is_declared(expression->data.identifier)) { //Cautam in lista de variabile declarate
                expression->inferred_type = strdup(get_identifier_type(expression->data.identifier));
                return expression->inferred_type;
            }

            expression->inferred_type = strdup("int");
            return expression->inferred_type;

        case IMMEDIATE_NUMBER:
            expression->inferred_type = strdup("int");
            return expression->inferred_type;

        case IMMEDIATE_FLOAT:
            expression->inferred_type = strdup("float");
            return expression->inferred_type;

        case IMMEDIATE_DOUBLE:
            expression->inferred_type = strdup("double");
            return expression->inferred_type;

        case IMMEDIATE_STRING:
            expression->inferred_type = strdup("string");
            return expression->inferred_type;

        case OPERATION_PLUS:
        case OPERATION_MINUS:
        case OPERATION_MUL:
        case OPERATION_DIV:
        case OPERATION_MOD:
        case OPERATION_POW:
        case OPERATION_UNARY_MINUS:
            expression->inferred_type = strdup("int");
            return expression->inferred_type;

        case OPERATION_FUNCTION_CALL: {
            FunctionNode* func = AST_find_function(ast, expression->data.function_call.function_name);
            if (!func) {
                fprintf(stderr, "ERROR: Function '%s' not found!\n", expression->data.function_call.function_name);
                exit(12);
            }

            ParameterNode* param = func->parameters;
            ExpressionNode* arg = expression->data.function_call.arguments;
            
            int param_count = 0;
            int arg_count = 0;

            while (param) {
                param_count++;
                param = param->next;
            }
            while (arg) {
                arg_count++;
                arg = arg->next;
            }

            if (param_count != arg_count) {
                fprintf(stderr, "ERROR: Function '%s' expects %d arguments but got %d!\n", 
                    expression->data.function_call.function_name, param_count, arg_count);
                exit(13);
            }

            param = func->parameters;
            arg = expression->data.function_call.arguments;

            while (param && arg) {
                char* arg_type = infer_expression_type(arg);
                if (strcmp(param->type, arg_type) != 0) {
                    fprintf(stderr, "ERROR: Argument type mismatch in function '%s': expected %s but got %s!\n",
                        expression->data.function_call.function_name, param->type, arg_type);
                    free(arg_type);
                    exit(14);
                }

                free(arg_type);
                param = param->next;
                arg = arg->next;
            }

            expression->inferred_type = strdup(func->return_type);
            return expression->inferred_type;
        }

        case OPERATION_IF: { //tipul ramurii then
            InstructionNode* thenList = expression->data.if_expr.thenInstructions;
            while (thenList) {
                if (thenList->type == INSTRUCTION_EXPRESSION && thenList->data.expression) {
                    expression->inferred_type = infer_expression_type(thenList->data.expression);
                    return expression->inferred_type;
                }
                thenList = thenList->next;
            }
            expression->inferred_type = strdup("int");
            return expression->inferred_type;
        }

        case OPERATION_PRINT:
        case OPERATION_RETURN:
            return infer_expression_type(expression->data.single);

        default:
            fprintf(stderr, "ERROR: Unrecognized ExpressionNode type: %d!\n", expression->type);
            exit(10);
    }
}


void execute(AST* ast, FILE* outputFile) {
    if (ast == NULL) return;

    //incude
    IncludeNode* inc = ast->includes;
    while (inc) {
        if (inc->is_system) {
            fprintf(outputFile, "#include <%s.h>\n", inc->path);
        } else {
            fprintf(outputFile, "#include \"%s.h\"\n", inc->path);
        }
        inc = inc->next;
    }
    fprintf(outputFile, "\n");

    //functii
    for (FunctionNode* func = ast->functions; func != NULL; func = func->next) {
        execute_function(func, outputFile); //pentru fiecare functie apelam execute_function
        print_newline(outputFile);
    }

    if (ast->main_block) { //stocam lamba0=-urile din main block
        InstructionNode* current = ast->main_block;
        while (current != NULL) {
            if (current->type == INSTRUCTION_EXPRESSION && 
                current->data.expression->type == OPERATION_LAMBDA) {
                
                //preluam lambda
                ExpressionNode* lambda_expr = current->data.expression;

                //generez nume unic
                char func_name[64];
                snprintf(func_name, sizeof(func_name), "lambda_%d", lambda_counter++);

                //+salvam in lista de lambda
                store_lambda_for_codegen(func_name, lambda_expr->data.lambda);
            }
            current = current->next;
        }
    }

    //generarea functii
    LambdaGenerated* current_lambda = lambda_list;
    while (current_lambda) {

        const char* param_type = "int";
        char* inferred = infer_expression_type(current_lambda->lambda.body);
        if (inferred) {
            param_type = inferred;
        }

        //definim declaratia functiei 
        fprintf(outputFile, "%s %s(%s %s) {\n",
            param_type,
            current_lambda->name,
            param_type,
            current_lambda->lambda.param_name
        );

        increase_indent();
        print_indent(outputFile);
        fprintf(outputFile, "return ");
        execute_expression(current_lambda->lambda.body, outputFile);
        fprintf(outputFile, ";\n");
        decrease_indent();

        fprintf(outputFile, "}\n\n");

        current_lambda = current_lambda->next;
    }

    //main
    if (ast->main_block) {
        fprintf(outputFile, "int main() {\n");
        increase_indent();

        InstructionNode* current = ast->main_block;
        while (current != NULL) {
            switch (current->type) {
                case INSTRUCTION_DECLARATION:
                    execute_declaration(current->data.declaration, outputFile);
                    break;

                case INSTRUCTION_EXPRESSION:
                    print_indent(outputFile);
                    if (current->data.expression->type == OPERATION_LAMBDA) {
                        ExpressionNode* lambda_expr = current->data.expression;
                        char func_name[64];
                        snprintf(func_name, sizeof(func_name), "lambda_%d", lambda_call_counter);

                        const char* param_name = lambda_expr->data.lambda.param_name;
                        const char* param_type = "int";

                        char* inferred_type = infer_expression_type(lambda_expr->data.lambda.body);
                        if (inferred_type) {
                            param_type = inferred_type;
                        }

                        if (is_declared(param_name)) {
                            fprintf(outputFile, "%s = %s(%s);\n", param_name, func_name, param_name);
                        } else {
                            fprintf(outputFile, "%s %s = %s(%s);\n", param_type, param_name, func_name, param_name);
                            
                            IdentifierString* new_node = malloc(sizeof(IdentifierString));
                            new_node->name = strdup(param_name);
                            new_node->type = strdup(param_type);
                            new_node->is_mutable = 1; 
                            new_node->next = declared_identifiers;
                            declared_identifiers = new_node;
                        }

                        lambda_call_counter++;
                    } else if (current->data.expression->type == OPERATION_IF) {
                        execute_expression(current->data.expression, outputFile);
                    } else {
                        execute_expression(current->data.expression, outputFile);
                        fprintf(outputFile, ";\n");
                    }
                    break;
            }
            current = current->next;
        }

        print_indent(outputFile);
        fprintf(outputFile, "return 0;\n");

        decrease_indent();
        fprintf(outputFile, "}\n\n");
    }
}

void execute_declaration(DeclarationNode* declaration, FILE* outputFile) {
    if (declaration == NULL) return;

    const char* c_type = NULL;
    const char* default_value = "0";
    if (strcmp(declaration->type, "int") == 0) {
        c_type = "int";
        default_value = "0";
    } else if (strcmp(declaration->type, "bool") == 0) {
        c_type = "bool";
        default_value = "false";
    } else if (strcmp(declaration->type, "string") == 0) {
        c_type = "char*";
        default_value = "\"\"";
    } else if (strcmp(declaration->type, "float") == 0) {
        c_type = "float";
        default_value = "0.0f";
    } else if (strcmp(declaration->type, "double") == 0) {
        c_type = "double";
        default_value = "0.0";
    } else {
        c_type = "int"; 
    }

    print_indent(outputFile);
    if (is_declared(declaration->identifier)) {
        IdentifierString* current = declared_identifiers;
        while (current != NULL) {
            if (strcmp(current->name, declaration->identifier) == 0) {
                if (!current->is_mutable) {
                    fprintf(stderr, "ERROR: Cannot reassign immutable variable '%s'\n", declaration->identifier);
                    exit(1);
                }
                break;
            }
            current = current->next;
        }
        fprintf(outputFile, "%s = ", declaration->identifier);
    } else {
        fprintf(outputFile, "%s %s = ", c_type, declaration->identifier);
        IdentifierString* new_node = malloc(sizeof(IdentifierString));
        new_node->name = strdup(declaration->identifier);
        new_node->type = strdup(declaration->type);
        new_node->is_mutable = declaration->is_mutable;
        new_node->next = declared_identifiers;
        declared_identifiers = new_node;
    }
    
    if (declaration->assigned_expression == NULL) {
        fprintf(outputFile, "%s", default_value);
    } else {
        execute_expression(declaration->assigned_expression, outputFile);
    }
    fprintf(outputFile, ";\n");
}

void execute_function(FunctionNode* func, FILE* outputFile) {
    if (func == NULL) return;

    clear_parameter_stack();

    ParameterNode* param = func->parameters;
    while (param) {
        push_parameter(param->name);
        param = param->next;
    }

    const char* return_type = func->return_type ? func->return_type : "int";
    fprintf(outputFile, "%s %s(", return_type, func->name);

    param = func->parameters;
    while (param != NULL) {
        fprintf(outputFile, "%s %s", param->type, param->name);
        if (param->next != NULL) {
            fprintf(outputFile, ", ");
        }
        param = param->next;
    }

    fprintf(outputFile, ") {\n");
    increase_indent();

    in_function_body = 1;

    InstructionNode* current = func->body;
    while (current != NULL) {
        switch (current->type) {
            case INSTRUCTION_DECLARATION:
                fprintf(stderr, "ERROR: Functions cannot declare variables. Found declaration of '%s'.\n",
                    current->data.declaration->identifier);
                exit(16);
            case INSTRUCTION_EXPRESSION:
                print_indent(outputFile);
                if (current->data.expression->type == OPERATION_IF) {
                    execute_expression(current->data.expression, outputFile);
                } else {
                    execute_expression(current->data.expression, outputFile);
                    fprintf(outputFile, ";\n");
                }
                break;

        }
        current = current->next;
    }

    in_function_body = 0;

    decrease_indent();
    fprintf(outputFile, "}\n");

    clear_parameter_stack();
}

void execute_expression(ExpressionNode* expression, FILE* outputFile) {
    if (expression == NULL) return;

    IdentifierString* current;

    switch (expression->type) {
        case IMMEDIATE_NUMBER:
            fprintf(outputFile, "%d", expression->data.immediate_value);
            break;

        case IMMEDIATE_FLOAT:
            fprintf(outputFile, "%.2ff", expression->data.float_value);
            break;

        case IMMEDIATE_DOUBLE:
            fprintf(outputFile, "%.2f", expression->data.double_value);
            break;

        case IMMEDIATE_IDENTIFIER:
            fprintf(outputFile, "%s", expression->data.identifier);
            break;

        case IMMEDIATE_STRING:
            fprintf(outputFile, "%s", expression->data.string_literal);
            break;

        case OPERATION_FUNCTION_CALL:
            fprintf(outputFile, "%s(", expression->data.function_call.function_name);
            ExpressionNode* arg = expression->data.function_call.arguments;
            while (arg) {
                execute_expression(arg, outputFile);
                if (arg->next) {
                    fprintf(outputFile, ", ");
                }
                arg = arg->next;
            }
            fprintf(outputFile, ")");
            break;

        case OPERATION_PRINT:
            if (expression->data.single) {
                const char* type = infer_expression_type(expression->data.single);
                if (strcmp(type, "string") == 0) {
                    fprintf(outputFile, "printf(\"%%s\\n\", ");
                    execute_expression(expression->data.single, outputFile);
                    fprintf(outputFile, ")");
                } else if (strcmp(type, "bool") == 0) {
                    fprintf(outputFile, "printf(\"%%d\\n\", ");
                    execute_expression(expression->data.single, outputFile);
                    fprintf(outputFile, ")");
                } else if (strcmp(type, "float") == 0) {
                    fprintf(outputFile, "printf(\"%%.2f\\n\", ");
                    execute_expression(expression->data.single, outputFile);
                    fprintf(outputFile, ")");
                } else if (strcmp(type, "double") == 0) {
                    fprintf(outputFile, "printf(\"%%.2lf\\n\", ");
                    execute_expression(expression->data.single, outputFile);
                    fprintf(outputFile, ")");
                } else {
                    fprintf(outputFile, "printf(\"%%d\\n\", ");
                    execute_expression(expression->data.single, outputFile);
                    fprintf(outputFile, ")");
                }
            }
            break;

        case OPERATION_RETURN:
            if (expression->data.single) {
                fprintf(outputFile, "return ");
                execute_expression(expression->data.single, outputFile);
            }
            break;

        case OPERATION_PLUS:
            fprintf(outputFile, "(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, " + ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_MINUS:
            fprintf(outputFile, "(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, " - ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_MUL:
            fprintf(outputFile, "(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, " * ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_DIV:
            fprintf(outputFile, "(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, " / ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_MOD:
            fprintf(outputFile, "(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, " %% ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_POW:
            fprintf(outputFile, "pow(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, ", ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_UNARY_MINUS:
            fprintf(outputFile, "-(");
            execute_expression(expression->data.unary.operand, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_NOT:
            fprintf(outputFile, "!(");
            execute_expression(expression->data.unary.operand, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_GT:
            fprintf(outputFile, "(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, " > ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_LT:
            fprintf(outputFile, "(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, " < ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_GTE:
            fprintf(outputFile, "(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, " >= ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_LTE:
            fprintf(outputFile, "(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, " <= ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_EQ:
            fprintf(outputFile, "(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, " == ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_NEQ:
            fprintf(outputFile, "(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, " != ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_AND:
            fprintf(outputFile, "(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, " && ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_OR:
            fprintf(outputFile, "(");
            execute_expression(expression->data.binary.left, outputFile);
            fprintf(outputFile, " || ");
            execute_expression(expression->data.binary.right, outputFile);
            fprintf(outputFile, ")");
            break;

        case OPERATION_IF:
            fprintf(outputFile, "if (");
            execute_expression(expression->data.if_expr.condition, outputFile);
            fprintf(outputFile, ") {\n");
            increase_indent();
            
            InstructionNode* thenInstr = expression->data.if_expr.thenInstructions;
            while (thenInstr != NULL) {
                if (thenInstr->type == INSTRUCTION_EXPRESSION) {
                    print_indent(outputFile);
                    ExpressionNode* expr = thenInstr->data.expression;

                    if (expr->type == OPERATION_IF) {
                        execute_expression(expr, outputFile);  
                    } else {
                        execute_expression(expr, outputFile);
                        fprintf(outputFile, ";\n");
                    }
                }
                else if (thenInstr->type == INSTRUCTION_DECLARATION) {
                    execute_declaration(thenInstr->data.declaration, outputFile);
                }
                thenInstr = thenInstr->next;
            }
            
            decrease_indent();
            print_indent(outputFile);
            fprintf(outputFile, "} else {\n");
            increase_indent();

            InstructionNode* elseInstr = expression->data.if_expr.elseInstructions;
            while (elseInstr != NULL) {
                if (elseInstr->type == INSTRUCTION_EXPRESSION) {
                    print_indent(outputFile);
                    execute_expression(elseInstr->data.expression, outputFile);
                    fprintf(outputFile, ";\n");
                } else if (elseInstr->type == INSTRUCTION_DECLARATION) {
                    execute_declaration(elseInstr->data.declaration, outputFile);
                }
                elseInstr = elseInstr->next;
            }
            
            decrease_indent();
            print_indent(outputFile);
            fprintf(outputFile, "}\n");
            break;

        case OPERATION_ASSIGNMENT: {
            current = declared_identifiers;
            while (current != NULL) {
                if (strcmp(current->name, expression->data.assignment.identifier) == 0) {
                    if (!current->is_mutable) {
                        fprintf(stderr, "ERROR: Cannot reassign immutable variable '%s'\n", 
                            expression->data.assignment.identifier);
                        exit(1);
                    }
                    break;
                }
                current = current->next;
            }
            fprintf(outputFile, "%s = ", expression->data.assignment.identifier);
            execute_expression(expression->data.assignment.value, outputFile);
            break;
        }
        
        default:
            fprintf(stderr, "ERROR: Unrecognized ExpressionNode type: %d!\n", expression->type);
            exit(10);
    }
}