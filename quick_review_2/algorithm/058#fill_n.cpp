/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>


/// fill_n
//  Fill range with value.



int main(){

    std::string string( 10, '+' );
    std::fill_n( string.begin(), 5, '-' );
    std::cout << string << '\n';


}

/* output
-----+++++

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
