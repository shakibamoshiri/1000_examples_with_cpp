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

/// std::declval
//  r-value reference to type T without referring to any object
//  This function shall only be used in unevaluated operands (such as the operands of sizeof and decltype).

//  The return type uses add_rvalue_reference to return T&& when T is an object type.

struct A {
    virtual int value() = 0;
};

class B : public A {
private:
    int value__;

public:
    B( int lv1, int lv2 ): value__( lv1 * lv2 ) {}
    int value(){ return value__; }
};

int main(){

    decltype( std::declval< A >().value() ) integer_1;  // int type
    decltype( std::declval< B >().value() ) integer_2;  // int type

    decltype( B( 0, 0 ).value() ) integer_3;            // int type and knows the constructor

    integer_1 = integer_2 = B( 20, 2 ).value();

    std::cout << integer_1 << '\n';

}

/* output

40

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
