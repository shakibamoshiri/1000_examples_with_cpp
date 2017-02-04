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


// Instead of Lambda expression we can use parentheses operator overloading
struct Print {
    template< typename Type >
    void operator()( Type element ){
        std::cout << element << ' ';
    }

}foreach;   // the name of the object of Print type

int main(){

    int array_of_int[] = { 1, 2, 3, 4, 5 };
    float array_of_float[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    for( decltype( array_of_float[ 0 ] ) element : array_of_float )
        foreach( element );

    puts( "" );

    for( decltype( array_of_int[ 0 ] ) element : array_of_int )
        foreach( element );


}

/* output for me:

1.1 2.2 3.3 4.4 5.5
1 2 3 4 5

*/
