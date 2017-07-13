/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <iomanip>



/// is_permutation
//  Tests whether a range is permutation of another range.


int main(){
    typedef std::char_traits< char > cht;

    const char* one( "a b c d e" );
    const char* two( "e a b c d" );
    const char* three( "e a b c e" );

    bool one_and_two = std::is_permutation( one, one + cht::length( one ), two );
    bool one_and_three = std::is_permutation( one, one + cht::length( one ), three );

    std::cout << ( one_and_two ? "permutation" : "non-permutation" ) << '\n';
    std::cout << ( one_and_three ? "permutation" : "non-permutation" ) << '\n';

}

/* output

permutation
non-permutation

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.




*/
