/*
        swap
        forward
        move
        type operation
        hash
        and so on.
        **********



*/
/// std::move_is_noexcept

//  move_if_noexcept obtains in r-value reference to its argument if
//  its move constructor does not throw exception, otherwise obtains
//  an l-value reference to its argument, It is typically used to
//  combine move semantic with strong exception guarantee.



#include <iostream>
#include <utility>

struct Bad {
    Bad(){}

    Bad( Bad&& )    // may throw
    { std::cout << "throwing move constructor called\n"; }

    Bad( const Bad& )   // may throw as well
    { std::cout << "throwing copy constructor called\n"; }

};

struct Good {
    Good(){}

    Good( Good&& ) noexcept     // will not throw
    { std::cout << "non-throwing move constructor called\n"; }

    Good( const Good& ) noexcept    // will not throw
    { std::cout << "non-throwing copy constructor called\n"; }

};


int main(){

    Good g;
    Bad  b;

    Good g2 = std::move_if_noexcept( g );
    Bad  b2 = std::move_if_noexcept( b );

}
/* output for me:

non-throwing move constructor called
throwing copy constructor called

*/
