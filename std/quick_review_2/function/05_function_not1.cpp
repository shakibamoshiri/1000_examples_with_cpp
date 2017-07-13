/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::not1
//  Returns negation of an unary function object.

#include <iostream>
#include <functional>
#include <algorithm>

struct is_odd{
    bool operator()( const int& x ) const { return x % 2 == 1; };
    typedef int argument_type;
};

int main(){

    int array[] = { 1,2,3,4,5 };
    const int* c_begin_array_ = array;
    const int* c_end_array_   = array + 5;

    const int c_count_odd_  = std::count_if( c_begin_array_, c_end_array_, is_odd() );
    const int c_count_even_ = std::count_if( c_begin_array_, c_end_array_, std::not1( is_odd() ) );

    std::cout << "odd number == " << c_count_odd_ << '\n';
    std::cout << "even number == " << c_count_even_ << '\n';

}

/* output

odd number == 3
even number == 2

Process returned 0 (0x0)   execution time : 0.038 s
Press ENTER to continue.



*/
