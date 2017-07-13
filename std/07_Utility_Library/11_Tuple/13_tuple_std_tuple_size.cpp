/*
        std::tuple
        **********

defined in header <tuple>

Class template std::tuple is a fixed-size collection of heterogeneous
values. It is a generalization on std::pair.

Helper Classes:
    tuple_size                  obtains the size of the tuple at the compile time
    tuple_element               obtains the type of the specified element
    std::uses_allocator< std::tuple >   specialized the std::uses_allocator type trait
    ignore                      placeholder to skip the elements when unpacking a tuple using tie

*/
/// std::tuple_size( std::tuple )

//  Provides access to the number of elements in a tuple
//  as a compile-time constant expression.




#include <iostream>
#include <tuple>
#include <algorithm>

template< typename T >
void size_of_tuple (T){

    std::cout << std::tuple_size< T >::value;
}

int main(){
    std::tuple< int > one( 1 );

    size_of_tuple( one );   // 1


    size_of_tuple( std::make_tuple(1, "one", 1.1) );    // 3


    // error: type mismatching
//    size_of_tuple( std::tuple<1, "one", 1.1> );

    // or directly
    std::cout << std::tuple_size< std::tuple< int, float > >::value;     // 2

}

/* output for me

132

*/


