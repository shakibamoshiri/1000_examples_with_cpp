/*
        swap
        forward
        move
        type operation
        hash
        and so on.
        **********



*/
/// std::forward
//
//  defined in header <utility>
//  When used according to the following recipe in a function
//  template, forwards  the argument to another function with
//  the value category it had when passed to the calling function.
//
//  For example, if used in wrapper such as the following, the
//  template behaves as describe below:
/**
template< class T>
void wrapper( T&& arg ){
    foo( std::forward< T >( arg ) );
}
**/

#include <iostream>
#include <utility>
#include <array>
#include <memory>

struct A {
    A( int&& temp ){ std::cout << "r-value overload temp == " << temp << '\n'; }
    A( int&  temp ){ std::cout << "l-value overload temp == " << temp << '\n'; }
};

class B {
public:

    template< class T_1, class T_2, class T_3 >
    B( T_1&& arg_1, T_2&& arg_2, T_3 arg_3 )
        :   // initializer
        first { std::forward< T_1 >( arg_1 ) }, // initializer for structure { }
        second{ std::forward< T_2 >( arg_2 ) },
        third { std::forward< T_3 >( arg_3 ) }
        {}  // end of constructor

private:
    A first, second, third; // struct A
};

template< class T, class U >
std::unique_ptr< T > make_unique_1( U&& u ){
    return std::unique_ptr< T >( new T(std::forward< U >( u ) ) );
}

template< class T, class... U >
std::unique_ptr< T > make_unique( U&&... u ){
    return std::unique_ptr< T >( new T( std::forward< U >( u )... ) );
}

int main(){

    auto p1 = make_unique_1< A >( 2 );  // r-value
    int i = 1;
    auto p2 = make_unique_1< A >( i );  // l-value

    std::cout << "B:\n";
    auto p3 = make_unique< B >( 2, i, 4 );  // recursively


}
/* output for me:

r-value overload temp == 2
l-value overload temp == 1
B:
r-value overload temp == 2
l-value overload temp == 1
r-value overload temp == 4


*/
