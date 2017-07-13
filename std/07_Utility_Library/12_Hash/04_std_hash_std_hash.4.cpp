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


namespace k5 {

    template< class T >
    struct hash;        // here froward declaration is necessary

    struct S {
        std::string first_name;
        std::string last_name;
    };

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

int main(){

    k5::S obj = { "first", "last" };
    k5::hash< k5::S > hash_of_S;

    std::cout << k5::hash< k5::S >()( obj ) << '\n';
    std::cout << hash_of_S( obj ) << '\n';      // ADL(= argument depended name lookup)




}

/* output for me
1430405326
1430405326
*/
