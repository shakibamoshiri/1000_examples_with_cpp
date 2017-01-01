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
/// std::uses_allocator< std::tuple >

//  This specialization of std::uses_allocator informs other library
//  components that tuple support uses-allocator construction, even though
//  they do not have a nested allocator_type.



#include <iostream>
#include <tuple>

int main(){

    // myalloc is a stateful Allocator with a single-argument constructor
    // that takes an int. It has no default constructor.
    typedef std::vector< int, myalloc< int > > innervector_t;
    typedef std::tuple< int, innervector_t > elem_t;
    typedef std::scoped_allocator_adaptor< myalloc< elem_t >, myalloc< int > > Alloc;

    Alloc a( 1, 2 );
    std::vector< elem_t, Alloc > v( a );

    vector.resize( 1 ); // uses allocator #1 for elements of vector
    std::get< 1 >( v [ 0 ] ).resize( 10 );  // uses allocator #2 for innervector_t

}

/* output for me


*/


