/*
        swap
        forward
        move
        type operation
        hash
        and so on.
        **********



*/
/// std::rel_ops::operator !=, >, <=, >=

//  defined in header <utility>

//  Given a user-defined operator == and operator < for object of
//  type T, implements the usual semantics of other comparison operators.



#include <iostream>
#include <utility>

struct S {
    int integer;
};

bool operator == ( const S& lhs, const S& rhs )
{ return lhs.integer == rhs.integer; }

bool operator < ( const S& lhs, const S& rhs )
{ return lhs.integer < rhs.integer; }



int main(){

    S s1 = { 1 };
    S s2 = { 2 };

    using namespace std::rel_ops;

    std::boolalpha( std::cout );
    std::cout << "not equal?\t" << ( s1 != s2 ) << '\n';
    std::cout << "greater?\t" << ( s1 > s2 ) << '\n';
    std::cout << "less equal?\t" << ( s1 <= s2 ) << '\n';
    std::cout << "greater equal?\t" << ( s1 >= s2 ) << '\n';

}
/* output for me:

not equal?      true
greater?        false
less equal?     true
greater equal?  false

*/
