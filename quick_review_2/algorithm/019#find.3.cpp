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

    // find a '?' end erase from there up to the end
    string.erase( std::find( string.begin(), string.end(), '?' ), string.end() );

    std::cout << string << '\n';

}

/* output

how are you today

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.





*/
