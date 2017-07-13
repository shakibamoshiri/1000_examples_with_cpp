/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
//#include <array>



/// generate
//  Generate values for range with function


int main(){

    std::string string{ "                          " };
    char chr = 'a';
    std::generate( string.begin(), string.end(),        // range of elements
                   [ &chr ]{ return chr++; } );
    std::cout << string << '\n';

}

/* output

abcdefghijklmnopqrstuvwxyz

Process returned 0 (0x0)   execution time : 0.016 s
Press ENTER to continue.
*/
