/*
            Algorithm
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********

Algorithm library has nine ( 9 ) types of operations:

    1)  Non-modifying sequence operations
    2)  Modifying sequence operations
    3)  Partitions operation
    4)  Sorting operations
    5)  Binary search operations( on sorted range )
    6)  Set operations ( on sorted range )
    7)  Heap operations
    8)  Minimum / Maximum operations
    9)  Numeric operations

*/
/// for_each( InputIterator, InputIterator, UnaryFunction ){}

#include <iostream>
#include <algorithm>


// custom implementation for for_each
//template< typename InputIterator, typename UnaryFunction >  // declaration
//UnaryFunction                                               // return type
//foreach( InputIterator first, InputIterator last, UnaryFunction function ){ // function and its arguments
//
//    for( ; first != last; ++first ){
//        function( *first );             // pass the first element as parameter to the function
//    }                                   // which function? That function the we will pass to the for_each
//    return function;
//}

int main(){

    int array[] = { 1, 2, 3, 4, 5 };

    void ( *lambda )( int ) = []( int element ){ std::cout << element << ' '; };

    // mini-foreach
    for( int element : array )
        lambda( element );  // 1 2 3 4 5
}

/* output for me:


*/
