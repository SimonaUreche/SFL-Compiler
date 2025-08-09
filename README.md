# SFL Compiler

A simple compiler for the **Simona Functional Language (SFL)**, written in C using **Bison** and **Flex**.  
The compiler translates SFL source code into standard C code, which can then be compiled and executed.

## 🚀 Features

- Variable declarations (`let`, `mut`) with types: `int`, `float`, `double`, `bool`, `string`
- Functions with parameters and return types
- Conditional structures: `if ... then ... else`
- Arithmetic and logical operators
- Value printing (`print`)
- Support for **lambda expressions**
- Automatic conversion from SFL code to C code

## 📦 Example Input

```sfl
func sum(a: int, b: int): int {
    return a + b;
}

main {
    let x: int = 5;
    print sum(x, 10);
}
