/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <iterator>

/// copy_n
//  Copies range of element based on number


int main(){

    typedef std::char_traits< char > cht;

    const char* hear_me( "Can you hear me well?" );
    const int hear_me_length = cht::length( hear_me );

    // std::string copy_of_hera_me;
    std::ostreambuf_iterator< char > output ( std::cout );

    std::copy_n( hear_me,3 , output ); // the output is directly sent to the screen


    // std::cout << copy_of_hera_me  << '\n';

}

/* output

Can
Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
