/*
        swap
        forward
        move
        type operation
        hash
        and so on.
        **********



*/
/// std::declval

//  defined in header <utility>
//  typename std::add_rvalue_reference< T >::type declval()

//  Converts any type T to a reference type, making it possible
//  to use member functions in decltype expressions without
//  the need to go through constructors.



#include <iostream>
#include <utility>

struct Default {
    int f() const { return 1; }
};

struct NonDefaut {
    NonDefaut( const NonDefaut& ){}
    int f() const { return 1; }
};

int main(){

    decltype( Default().f() ) n1 = 1;   // int n1

    // decltype( DonDefault().f() ) n2 = n1;    // error, not default constructor
    decltype( (typename std::add_rvalue_reference< NonDefaut >::type).f() ) n2 = n1; // int n2;

    std::cout << n2;

}
/* output for me:



*/
