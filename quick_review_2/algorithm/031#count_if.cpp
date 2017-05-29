/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <iomanip>


/// count_if
//  Returns the number of element in a range that satisfies a condition


int main(){
    typedef std::char_traits< char > cht;

    const char* today( "How are you today? I am fine how about you?" );
    const int number_of_non_spaces = std::count_if( today, today + cht::length( today ),
                                                    []( const char chr ) { return chr != ' '; } );

    std::cout << "the string has "
              << number_of_non_spaces
              << " non-spaces in itself\n";

}

/* output


the string has 34 non-spaces in itself


*/
