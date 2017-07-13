/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <iomanip>


/// count
//  Count appearance of a value in a range( function template )


int main(){
    typedef std::char_traits< char > cht;

    const char* today( "How are you today? I am fine how about you?" );
    const int number_of_spaces = std::count( today, today + cht::length( today ), ' ' );

    std::cout << "the string has "
              << number_of_spaces
              << " spaces in itself\n";

}

/* output
the string has 9 spaces in itself




*/
