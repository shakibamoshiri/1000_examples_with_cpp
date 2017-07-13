/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::bind
//  template< class Fn, class... Args >
//  ???  bind( Fu&& function, Args&&... args ){}
//
//  template< class Ret, class Fn, class... Args >
//  ???  bind( Fu&& function, Args&&... args ){}
//
//  binds function arguments.


#include <iostream>
#include <functional>

double user_divide( double d1, double d2 ){
    return d1 / d2;
}

int main(){

    using namespace std::placeholders;

    // bind function:
    auto fo_1 = std::bind( user_divide, 10, 2 );        // returns 10 / 2
    std::cout << fo_1() << '\n';

    auto fo_2 = std::bind( user_divide, _1, _2 );       // returns first argument / second argument
    std::cout << fo_2( 10, 2 ) << '\n';

    auto fo_3 = std::bind( user_divide, _2, _1 );       // returns second argument / first argument
    std::cout << fo_3( 10, 2 ) << '\n';

    // specifying the return type:
    auto fo_4 = std::bind< int >( user_divide, 2, 10 );
    std::cout << fo_4() << '\n';

}
/* output

5
5
0.2
0

Process returned 0 (0x0)   execution time : 0.033 s
Press ENTER to continue.


*/
