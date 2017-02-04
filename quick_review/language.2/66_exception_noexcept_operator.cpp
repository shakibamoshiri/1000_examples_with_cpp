/*
            language 2
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. Classes
2. Templates
3. Exceptions
4. Statements
5. Miscellaneous

*/
/// 3. exception
//  noexcept operator c++11
//  It performs a compile-time check that return true
//  if an expression is declared to not throw any exceptions.

//  It returns pr-value of type boolean.

/******************/
#include <iostream>
/******************/

void one(){}

void two() noexcept( false ){}

void three() noexcept {}


int main(){

    std::boolalpha( std::cout );

    std::cout << noexcept( one() ) << '\n';     // may throw exception
    std::cout << noexcept( two() ) << '\n';     // may throw exception
    std::cout << noexcept( three() ) << '\n';   // no exception is thrown

}

/* output:

false
false
true

*/
