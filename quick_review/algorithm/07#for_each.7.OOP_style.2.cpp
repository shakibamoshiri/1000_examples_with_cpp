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
#include <vector>
#include <string>


// Objected Oriented Programming Style more specific

struct Algorithm {

    // foreach
    struct ForEach {
        template< class InputIterator, class UnaryFunction >
        UnaryFunction operator()( InputIterator first, InputIterator last, UnaryFunction function ){

            while( first != last ){
                function( *first );
                ++first;
            }
            return function;

        }

    }foreach;


}algo;

int main(){

    std::vector< int > vector{ 1, 2, 3, 4, 5, 500, 10000 };

    algo.foreach( vector.begin(),
                  vector.end(),
                  []( int element ){ std::cout << element << ' '; } );

    puts( "" );

    algo.foreach( vector.begin(),
                  vector.end(),
                  []( int& element ){ ++element; } );

    puts( "" );

    algo.foreach( vector.begin(),
                  vector.end(),
                  []( int element ){ std::cout << element << ' '; } );



}

/* output for me:

1 2 3 4 5 500 10000

2 3 4 5 6 501 10001

*/
