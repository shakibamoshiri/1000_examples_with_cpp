/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::function::operator () parentheses
//  call target

#include <iostream>
#include <functional>


int plus ( const int x, const int y ){
    return x + y;
}
int minus ( const int x, const int y ){
    return x - y;
}
int multiplies( const int x, const int y ){
    return x * y;
}

int main(){

    int ( *p[] )( int, int ) = { plus, minus, multiplies };

    for( int ( *temp )( int, int ) : p ){
        std::cout << temp( 3, 4 ) << '\n';
    }

}

/* output

7
-1
12

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.

*/
