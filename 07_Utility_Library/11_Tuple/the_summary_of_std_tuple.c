/*
        std::tuple
        **********

defined in header <tuple>

Class template std::tuple is a fixed-size collection of heterogeneous
values. It is a generalization on std::pair.

Template Parameter:
    Type...                     the type of elements that the tuple is stored. Empty list is supported.

Member Function:
    constructor                 constructs a new tuple
    operator =                  assigns the contents of one tuple to another
    swap                        swaps the contents of two tuples

Non-member Function:
    make_tuple                  creates a tuple object of the type defined by the argument types
    tie                         creates a tuple of l-value reference or unpacks a tuple
    forward_as_tuple            creates a tuple of r-value reference
    std::get( std::tuple )      tuple accesses specified element
    operator ==                 lexicographically compares the value of tuples
    operator !=                 "
    operator >                  "
    operator <                  "
    operator <=                 "
    operator >=                 "
    std::swap ( std::tuple )    specializes the std::swap algorithm

Helper Classes:
    tuple_size                  obtains the size of the tuple at the compile time
    tuple_element               obtains the type of the specified element
    std::uses_allocator< std::tuple >   specialized the std::uses_allocator type trait
    ignore                      placeholder to skip the elements when unpacking a tuple using tie


NOTE:
Until C++17, a function could not return a tuple using list-initialization:

std::tuple<int, int> f (){
    return {1, 3};                  // error until c++17
    return std::make_tuple( 1, 3 ); // always works
}

*/
