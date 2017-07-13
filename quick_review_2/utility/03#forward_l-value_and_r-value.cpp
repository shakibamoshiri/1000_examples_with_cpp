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


int main(){

    // l-value and r-value
    int value = 0;

    std::cout << "calling the over_load() with l-value: ";
    over_load( value );

    std::cout << "calling the over_load() with r-value: ";
    over_load( 0 );

}

/* output
calling the over_load() with l-value: [l-value reference]
calling the over_load() with r-value: [r-value reference]


*/
