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

//function with r-value and l-value reference overload:
void over_load( int& l_v_ref ){ std::cout << "[l-value reference]\n"; }
void over_load( int&& r_v_ref ){ std::cout << "[r-value reference]\n"; }

template< typename T >
T&& user_forward( typename std::remove_reference< T >::type&& value ) noexcept {
    return static_cast< T&& >( value );
}
template< typename T >
T&& user_forward( typename std::remove_reference< T >::type& value ) noexcept {
    return static_cast< T&& >( value );
}

// function template taking r-value reference to deduce type:
template< typename T > void func( T&& r_v_ref ){
    std::cout << "not using forward: ";
    over_load( r_v_ref );   // always an l-value
    std::cout << "using forward: ";
    over_load( user_forward< T >( r_v_ref ) );  // r-value if argument is r-value
}

int main(){

    // l-value and r-value
    int value = 0;

    std::cout << "calling the func() with l-value:\n";
    func( value );
    puts( "" );
    std::cout << "calling the func() with r-value:\n";
    func( 0 );

}

/* output
calling the func() with l-value:
not using forward: [l-value reference]
using forward: [l-value reference]

calling the func() with r-value:
not using forward: [l-value reference]
using forward: [r-value reference]

*/
