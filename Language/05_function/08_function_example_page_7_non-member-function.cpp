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

// declaration in namespace ( file ) scope
// ( the definition is provided later )
int f1();

// simple function with a default argument, returning nothing
// using const here is necessary
// or can using &&
void f0 (const std::string& arg="word"){
    std::cout<<"Hello, "<<arg<<std::endl;
}

// function returning a pointer to f0
auto fp11() -> void (*)(const std::string&){
    return f0;
}

// function returning a pointer to f0, prefix c++ style
void (*fp03())(const std::string&){
    return f0;
}

int main(){

    f0();
    fp11()("test");
    fp03()("again");
    int f2(std::string);    // declaration in function scope
    std::cout<<f2("bad12")<<std::endl;

}
// simple non-member function returning int
int f1(){
    return 43;
}
// function with an exception specification and a function try block
int f2( std::string str ) noexcept try {
    return std::stoi(str);
}
catch ( const std::exception& e){
    std::cerr<<"stoi() filed\n";
    return 0;
}








