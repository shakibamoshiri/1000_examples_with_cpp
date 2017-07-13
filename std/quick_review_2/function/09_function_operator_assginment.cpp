/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::function::operator=
//  Assigns a function object.

#include <iostream>
#include <functional>


int main(){

    std::function< int( int ) > first, second;
    first = std::negate< int >();                   // target
    second = first;                                 // copy

    first = std::function< int( int ) >( []( int x ){ return x + 1; } );    // move
    second = nullptr;

    std::cout << "first: " << first( 100 ) << '\n';


}

/* output
first: 101

Process returned 0 (0x0)   execution time : 0.009 s
Press ENTER to continue.


*/
