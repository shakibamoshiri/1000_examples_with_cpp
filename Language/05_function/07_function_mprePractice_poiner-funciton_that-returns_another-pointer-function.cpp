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

// regular function one and two that return int
int two() { return 11;}
int one() { return 10;}

// pointer-function that get 2 'pointer-function' and returns bigger ( one or two )
int  (*p2f ( int (*o)(), int (*t)() ) ) ()    {
    return o() > t() ? o : t;
}


typedef int (*func_t)();
/*
func_t p2f ( func_t o ){
    return t;
}
*/

/*
auto p2f ( int (*t)() ) -> int (*)() {
    return t;
}
*/


int main(){

    int (*three)() = p2f(one,two);
    std::cout<<three(); // output 11


}

// error: cannot convert ‘int (*)()’ to ‘int (**)()’ for argument ‘1’ to ‘int (* p2f (int (*)())) ()


// error: cannot convert ‘int (*)()’ to ‘int (**)()’ for argument ‘1’ to ‘int (* p2f (int (**)()))()







