/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <array>

/// all_of
//  template< class InputIterator, class UnaryPredicate >
//  bool all_of( InputIterator first, InputIterator last, UnaryPredicate function )
//
//  Test condition on all element in range


int main(){

    std::array< char, 4 > four_char = { 'a','a','a','a' };  // four letters of  a(s)
    std::array< char, 3 > three_char = { 'a','b','c' };     // three letters of a b c

    if( std::all_of( begin( four_char ), end( four_char ), []( char chr ){ return chr == 'a'; } ) ){
        puts( "all letters in the array are equal\n" );
    } else {
        puts ("four_char has some other letter except then 'a'" );
    }

    puts( "" );

    if( std::all_of( begin( three_char ), end( three_char ), []( char chr ){ return chr == 'a'; } ) ){
        puts( "all letters in the array are equal\n" );
    } else {
        puts ("three_char has some other letter except then 'a'" );
    }



}


/* output

all letters in the array are equal


three_char has some other letter except then 'a'

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.


*/
