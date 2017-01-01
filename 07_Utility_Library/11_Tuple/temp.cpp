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
/// std::ignore

//  An object of unspecified type such that any value can be assigned
//  to it with no effect. Intended for use with std::tie when unpacking
//  a std::tuple as a placeholder for the argument that are not used.


#include <iostream>
#include <tuple>
#include <string>
#include <set>

int main(){

    std::set< std::string > set_of_string;

    bool inserted;

    std::tie( std::ignore, inserted ) = set_of_string.insert( "string" );

    if( inserted ) std::cout << "value was inserted successfully\n";


}

/* output for me


*/


