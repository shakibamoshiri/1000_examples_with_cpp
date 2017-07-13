/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::reference_wrapper::operator &
//  cast to reference
//
// operator type&() const noexcept{}

#include <iostream>
#include <functional>   // reference_wrapper
#include <algorithm>

struct is_odd {
    int operator()( int x ) const {
        return ( x % 2 == 1 );
    }
    typedef int argument_type;
} obj;

int main(){
    int array[] = { 1,3,5,7, 2,4,6,8,10 };

    std::cout << std::count_if( std::begin( array ), std::end( array ), is_odd() ) << '\n';

    std::unary_negate< is_odd > is_not_odd( obj );

    std::cout << std::count_if( std::begin( array ), std::end( array ), is_not_odd ) << '\n';
}

/* output

4
5

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
