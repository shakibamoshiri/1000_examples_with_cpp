/*
        std::hash
        *********

defined in header <functional>

The hash template defines a function object that implements a hash
function, Instances of this function object satisfy Hash.
(for more detail see the main website)

    Member Type:
        argument_type       key
        result_type         std::size_t

    Member Function:
        constructor
        operator

*/
/// std::hash

#include <iostream>
#include <functional>
#include <string>

struct S {
    std::string first_name;
    std::string last_name;
};

namespace std {
    // template< class T >
    // struct hash;        // forward declaration in necessary the out of std ( but not required here )
    //
    // why?
    // because already struct hash is declared here, and hash< S > is a specialized template for strcut S

    template<>
    struct hash< S > {
        typedef S           argument_type;
        typedef std::size_t result_type;

        result_type operator()( argument_type const& s ){
            result_type const h1( std::hash< std::string>()( s.first_name ) );  // equivalent to std::size_t( /**/ )
            result_type const h2( std::hash< std::string>()( s.last_name ) );   // equivalent to std::size_t( /**/ )

            return h1 ^ ( h2 << 1 );
        }
    };
}
// demonstrates how to specialize std::hash for user-defined type
int main(){

    S obj = { "first_name" , "last_name" };


    std::hash< S > hf;

    std::cout << "hash( obj ) == " << hf( obj ) << '\n';

}

/* output for me

*/
