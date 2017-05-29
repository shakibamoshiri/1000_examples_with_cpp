/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
//#include <array>



/// generate_n
//  Generate values for range with function


int main(){

    std::string string{ "                          " };
    char chr = 'a';
    std::generate_n( string.begin(), 10,        // range of elements and size
                   [ &chr ]{ return chr++; } );
    std::cout << string << '\n';

}

/* output

abcdefghij

Process returned 0 (0x0)   execution time : 0.010 s
Press ENTER to continue.


*/
