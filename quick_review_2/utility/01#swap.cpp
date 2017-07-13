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



int main(){

    std::pair< std::string, unsigned > pair_1, pair_2;
    pair_1 = std::make_pair( "first", 1 );

    std::swap( pair_1, pair_2 );

    std::cout << pair_2.first << ' ' << pair_2.second << '\n';

}

/* output
first 1

Process returned 0 (0x0)   execution time : 0.028 s
Press ENTER to continue.

*/
