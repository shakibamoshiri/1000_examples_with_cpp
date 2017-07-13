/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::function::target
//  get pointer to target

#include <iostream>
#include <functional>


int plus ( const int x, const int y ){
    return x + y;
}

int minus ( const int x, const int y ){
    return x - y;
}

int main(){

    std::function< int( int, int ) > user_plus = plus;

    // usage by invoke operator ()
    std::cout << user_plus( 3 , 5 ) << '\n';

    // usage by invoke target
    std::cout << ( *user_plus.target< int( * )( int, int ) >() )( 3, 5 ) << '\n';

    // change the target directly:
    *user_plus.target< int( * )( int, int ) >() = minus;
    std::cout << user_plus( 3 , 5 ) << '\n';



}

/* output

8
8
-2

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.

*/
