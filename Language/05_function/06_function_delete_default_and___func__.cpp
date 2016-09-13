/*
Function:
    declaring function
    default argument
    variadic argument
    lambda function
    operator overloading
    address of overloading function
***************************************
    Declaring Function
**********************
    function definition
syntax:
1   ctor-initializer ( optional ) compound-statement
2   function-try-block
3   = delete
4   = default
1. regular function body
2. function try block
3. explicitly deleted function definition
4. explicitly defaulted function definition, only allowed for special member function.


int print ( const char*){
    return ...
}

first:  int is declaration-specifier-sequence
second: ( const char* ) is declarator
third:  { return ... } is body

*/

#include <iostream>
#include <string>
#include <array>

void print() {
    std::cout<<__func__<<std::endl;
}
void print(const char*) = delete;

struct S {
    void print();
};
//void S::print() = delete; // error
// The deleted definition of a function must be the first declaration
// in a translation unit: a previously-declared function cannot be
// redeclared as delete.


int main(){
    print();
    // error
    // print("");

    /* __func__ */
    // within the function body, the function-local predefined variable
    // __func__ is defined as if by
    static const char __func__[] = "function-name";
    // This variable has block scope and static storage duration
    // so you can not use it as parameter list
    struct B {
        const char* name_func;
        B() : name_func(__func__) {} // okay, because initializer-list is part of function body not parameter list
    };
    void f(const char* name_f = __func__ ); // error, parameter list is a part of declarator
}










