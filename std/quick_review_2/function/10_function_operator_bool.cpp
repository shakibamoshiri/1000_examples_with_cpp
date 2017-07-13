/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::function::operator bool
//  Check if the object is callable

#include <iostream>
#include <functional>


void print( const int x ){
    std::cout << x << '\n';
}

int main(){

    std::function< int( int, int ) > first, second;
    first = std::plus< int >(); // 3 + 3

    first.swap( second );

    std::cout << "first is: " << ( first ? "callable" : "not callable" ) << '\n';
    std::cout << "second is: " <<  ( second ? "callable" : "not callable" ) << '\n';

}

/* output

first is: not callable
second is: callable

Process returned 0 (0x0)   execution time : 0.079 s
Press ENTER to continue.

*/
