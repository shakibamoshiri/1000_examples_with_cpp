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

template< class T >
class MyHash;       // forward declaration

template<>
class MyHash< S > { // specialized template
public:
    std::size_t operator () ( S const& s ) const {  // S const& == const S&
        std::size_t hash_1 = std::hash< std::string >()( s.first_name );
        std::size_t hash_2 = std::hash< std::string >()( s.last_name );

        return hash_1 ^ ( hash_2 << 1 );
    }
};


// Demonstrates creation of a hash function for a user defined type.
// Using this as a template parameter for std::unsorted_map,
// std::unsorted_set, etc. Also requires specialization of std::equal_to
int main(){

    std::string sport_1( "boxing" );
    std::string sport_2( "swimming" );

    std::hash< std::string > hash;

    S obj1;

    obj1.first_name = sport_1;
    obj1.last_name  = sport_2;

    std::cout << "hash( sport_1 ) == " << hash( sport_1 ) << '\n'
              << "hash( sport_2 ) == " << hash( sport_2 ) << '\n'
              << "hash( sport_1 ) == " << std::hash< std::string >()( sport_1 ) << '\n'
              << "hash( sport_2 ) == " << std::hash< std::string >()( sport_2 ) << '\n'
              << "hash( obj1    ) == " << MyHash< S >()( obj1 ) << '\n';

              // error:
              // << "hash( obj1    ) == " << std::hash< S >( obj1 ) << '\n';

}

/* output for me
hash( sport_1 ) == 3781465875
hash( sport_2 ) == 4107428404
hash( sport_1 ) == 3781465875
hash( sport_2 ) == 4107428404
hash( obj1    ) == 146822011
*/
