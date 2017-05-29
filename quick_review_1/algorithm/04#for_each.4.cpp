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
    void operator()( int element ){
        std::cout << element << ' ';
    }
};

int main(){

    int array[] = { 1, 2, 3, 4, 5 };

    Print obj;      // an instance of Print type

    // mini-foreach
    for( int element : array )
        obj( element );     // it runs with operator( int element )
}

/* output for me:


*/
