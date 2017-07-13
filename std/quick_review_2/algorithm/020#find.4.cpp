/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <string>

/// find
//  template< class InputIterator, class T>
//  InputIterator find( InputIterator first, InputIterator last, const T& value )
//
//  Finds a value in a range.



int main(){

    std::string string( "how are you today? I am fine, how about you!" );

    short number_of_space = std::count( string.begin(), string.end(), ' ' );    // find how many space the string has

    while( number_of_space-- ){
        std::string::const_iterator it_find_space = std::find( begin( string ), end( string ), ' ' ); // find the first space
        string.erase( it_find_space, it_find_space + 1 );                                             // remove that space + update the string for next find space
    }

    // prints the string with no space
    std::cout << string << '\n';

}

/* output


howareyoutoday?Iamfine,howaboutyou!

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.



*/
