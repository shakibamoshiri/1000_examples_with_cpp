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
/// std::tuple_element< std::tuple >

//  Provides compile-time indexed access to the types of the elements of the tuple.



#include <iostream>
#include <tuple>

template< class... ARGS >
struct type_list {

    template< std::size_t N >
    using type = typename std::tuple_element< N, std::tuple< ARGS... > >::type;

};

int main(){

    std::cout << std::boolalpha;
    type_list< int, char, bool >::type< 2 > boolean = true;
    std::cout << boolean;

}

/* output for me


*/


