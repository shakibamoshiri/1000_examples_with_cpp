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

template< class T > using size = typename std::tuple_size< T >;

int main(){

    std::cout << size< std::tuple< int > >::value;

}

/* output for me
1

*/


