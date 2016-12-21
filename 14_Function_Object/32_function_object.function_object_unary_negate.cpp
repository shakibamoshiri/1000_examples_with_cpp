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
/// unary_negate


#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>


struct less_than_7 : std::unary_function< int, bool > {
    bool operator() (int temp) const { return temp < 7; }
};

int main() {
    std::vector< int > vector;

    for( int index = 0; index < 10; vector.push_back( ++index ));   // filing the vector from 1 to 10
    for( const int i : vector) std::cout << i << ' ';

    std::unary_negate< less_than_7 > not_less_than_7(( less_than_7()));

    std::cout << std::count_if( vector.begin(), vector.end(), not_less_than_7); // 7 itself, 8, 9, and 10

    // so the output is 4
    //
    // vector holds: 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10
    //
    // less_than_7 are                 7, 8, 9, 10  that the function returns true
    // and for these:1, 2, 3, 4, 5, 6               that the function returns false




}


/* output for me:



*/


