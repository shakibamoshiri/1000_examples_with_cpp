/*

A review of utility library

*/

/// Function:
//  swap:       Exchange value of two object
//  make_pair:  Construct pair object
//  forward:    Forward argument
//  move:       Move as r-value
//  move_if_noexcept:   Move if noexcept
//  declval:    Declaration value

#include <iostream>
#include <utility>

template< typename T >
void fn( T& lvr ){
    std::cout << "l-value reference\n";
}
template< typename T >
void fn( T&& rvr ){
    std::cout << "r-value reference\n";
}

struct A {  // copyable and movable and noexcept
    A() noexcept {}
    A( const A& ) noexcept {}
    A( A&& ) noexcept {}
};

struct B {  // copyable and movable and may throw exception
    B() {}
    B( const B& ) {}
    B( B&& ) {}
};

struct C {      // only movable
    C() {}
    C( C&& ) {}
};

int main(){

    std::cout << "A: ";
    A a;
    fn( std::move_if_noexcept( a ) );

    std::cout << "B: ";
    B b;
    fn( std::move_if_noexcept( b ) );

    std::cout << "C: ";
    C c;
    fn( std::move_if_noexcept( c ) );
}

/* output

A: r-value reference
B: l-value reference
C: r-value reference

Process returned 0 (0x0)   execution time : 0.016 s
Press ENTER to continue.


*/
