/*
            Function Object
            ***************

4. Function objects (build-in)
    4.1 arithmetic  operations

    --------------------------------------------
    4.2 comparison  operations

    --------------------------------------------
    4.3 logical     operations

    --------------------------------------------
    4.4 bitwise     operations

    --------------------------------------------
    4.5 negators    operations

        unary_negatew       rapper function object returning the complement of the unary predicate it holds
        binary_negate       wrapper function object returning the complement of the binary predicate it holds
        not1                constructs custom std::unary_negate object
        not2                constructs custom std::binary_negate object
*/
/// not1


#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>

struct less_than_7 : std::unary_function< int, bool >{
    bool operator()( int argument ) const { return argument < 7; }
};


int main() {
    std::vector< int > vector( 10 );    // it holds 10 elements

    std::iota( vector.begin(), vector.end(), 0 );   // filling the vector from 0

    std::cout << count_if( begin( vector ), end( vector ), not1( less_than_7() ) ) << '\n';    // output is 3

    // same as above, but use a lambda function
    std::function< int( int ) > less_than_9 = []( int argument ){ return argument < 9; };
    std::cout << count_if( begin( vector ), end( vector ), not1( less_than_9 ) ) << '\n';       // output is 1



}


/* output for me:


*/


