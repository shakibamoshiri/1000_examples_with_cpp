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
//  noexcept specifier c++11

//  noexcept
//  noexcept( expression )

//  noexcept == noexcept( true )


/******************/
#include <iostream>
/******************/

void f(int f, int s) noexcept;

int main(){

    f( 1, 3);

}

void f( int first, int second ) noexcept ( 1 == 2 ) {
/// error: declaration of ‘void f(int, int) noexcept (false)’ has a different exception specifier|
}

/* output:



*/
