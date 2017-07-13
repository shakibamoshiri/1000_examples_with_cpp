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


void print( const int x ){
    std::cout << x << '\n';
}

int main(){

    std::function< int( int, int ) > fo_arr[] = { std::plus< int >(), std::multiplies< int >(), std::minus< int >() };

    for( const std::function< int( int, int ) >& fo : fo_arr ){
        std::cout << fo( 3, 4 ) << '\n';
    }

}

/* output

7
12
-1

Process returned 0 (0x0)   execution time : 0.024 s
Press ENTER to continue.


*/
