/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>


/// replace
//  Replace value in range.

char to_upper( const char& chr ){
    if( chr >= 'a' && chr <= 'z' )
        return chr - 32;
}

int main(){

    std::string string( "a B c D e F g H" );
    std::replace( string.begin(), string.end(), ' ', '+' );
    const char* ptr = &*string.begin();

    std::cout << ptr << '\n';

}

/* output
a+B+c+D+e+F+g+H

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
