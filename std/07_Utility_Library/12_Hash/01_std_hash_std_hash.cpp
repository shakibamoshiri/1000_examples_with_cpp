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

// demonstrates the computation of a hash for std::string,
// a type that already has a hash specialization.
int main(){
    std::string string( "how are you today?" );

    std::hash< std::string > hash_function;

    std::cout << ( hash_function( string ) ) << '\n';

    std::size_t result_of_hash = hash_function( string );
    std::cout << result_of_hash << '\n';
}

/* output for me

2102615042
2102615042

*/
