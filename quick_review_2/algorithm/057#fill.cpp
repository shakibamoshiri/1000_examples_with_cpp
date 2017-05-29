/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>


/// fill
//  Fill range with value.



int main(){

    std::string string( 10, ' ' );
    std::fill( string.begin(), string.end(), '=' );
    std::cout << string << '\n';


}

/* output

==========

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.

*/
