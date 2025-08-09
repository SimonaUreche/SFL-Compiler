PROGRAM_NAME = sfl
LEX_FILE = sfl.l
YACC_FILE = sfl.y
SOURCE_FILES = ast/ast.c ast/decl.c ast/expr.c ast/func.c ast/instructions.c engine/engine.c

build: clean
	@lex -o build/$(LEX_FILE).c $(LEX_FILE)
	@yacc -o build/$(YACC_FILE).c -v -d $(YACC_FILE)
	@gcc -Iast -o build/$(PROGRAM_NAME) build/$(LEX_FILE).c build/$(YACC_FILE).c $(SOURCE_FILES) -ly -ll
	@echo "Build complete"

execute:
	@build/$(PROGRAM_NAME) $(TARGET)
	@echo "Executed target file"

clean:
	@rm -r build
	@mkdir build
	@echo "Cleaned build folder"