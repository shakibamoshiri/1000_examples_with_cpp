/*
        swap
        forward
        move
        type operation
        hash
        and so on.
        **********



*/
/// std::as_const

//  defined in header <utility>

//  Forms r-value reference to const type



#include <iostream>
#include <utility>
#include <cassert>
#include <type_traits>



int main(){

    std::string string = "how are you today?";
    const std::string& c_string = std::as_const( string );  // I think this function was deprecated because complier says not a member of std!

    assert( &string == &string );

    using what_type = std::remove_reference_t< decltype( std::as_const( string ) ) >;

    static_assert( std::is_same< std::remove_const_t< what_type >,
                   std::string::value>,
                   "" );

}
/* output for me:



*/
