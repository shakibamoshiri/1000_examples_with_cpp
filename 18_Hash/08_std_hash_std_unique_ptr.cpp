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
/// std::hash for std::unique_ptr

//  The template specialization of std::unique_ptr< T, deleter > allows
//  users to obtain hashes of objects of type std::unique_ptr< T, deleter >


#include <iostream>
#include <functional>
#include <memory>

struct S {
    S(){ std::cout << "S constructor...\n"; }
    ~S(){ std::cout << "S constructor...\n"; }
};

int main(){

    S* obj = new S();
    std::unique_ptr< S > uptr( obj );

    std::cout << "hash( uptr ) == " << std::hash< std::unique_ptr< S > >()( uptr ) << '\n';
    std::cout << "hash( obj  ) == " << std::hash< S* >()( obj ) << '\n';

}

/* output for me

S constructor...
hash( uptr ) == 147687952
hash( obj  ) == 147687952
S constructor...



*/
