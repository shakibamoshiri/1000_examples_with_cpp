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

bool to_upper( const char& chr ){
    if( chr >= 'a' && chr <= 'd' )
        return true;
    else return false;
}

int main(){

    std::string string( "a b c d e f g h k" );
    std::replace_if( string.begin(), string.end(),  to_upper, '=' );
    std::cout << string << '\n';


}

/* output

= = = = e f g h k

Process returned 0 (0x0)   execution time : 0.013 s
Press ENTER to continue.


*/
