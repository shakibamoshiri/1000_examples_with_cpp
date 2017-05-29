/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>


/// replace_copy and replace_copy_if as the same
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


*/
