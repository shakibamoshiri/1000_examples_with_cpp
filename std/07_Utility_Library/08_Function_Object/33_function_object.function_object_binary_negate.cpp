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
/// binary_negate


#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>


struct same : std::binary_function< int, int, bool >{
    bool operator() (int first, int second) const { return first == second; }
};

int main() {
    std::vector< int > v1, v2;
    std::vector< bool > v3( v1.size() );

    for( int index = 0; index < 10; v1.push_back( ++index ) );  // filling from 1 to 10
    for( int index = 10; index > 0; v2.push_back( --index ) );  // filling from 9 to 0

    std::binary_negate< same > not_same(( same() ));    // two parentheses is necessary!

    std::transform( v1.begin(), v1.end(),
                   v2.begin(),
                   v3.begin(),
                   not_same );

    std::cout.setf( std::ios_base::boolalpha );
    for( int index = 0; index < 10; ++index ) std::cout << v1[ index ] << " : "
                                                        << v2[ index ] << " : "
                                                        << v3[ index ] << std::endl;


}


/* output for me:

1 : 9 : true
2 : 8 : true
3 : 7 : true
4 : 6 : true
5 : 5 : false       <------
6 : 4 : true
7 : 3 : true
8 : 2 : true
9 : 1 : true
10 : 0 : true

*/


