/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>

/// copy
//  Copies range of element.


int main(){

    typedef std::char_traits< char > cht;

    const char* hear_me( "Can you hear me well?" );
    const int hear_me_length = cht::length( hear_me );

    std::string copy_of_hera_me( hear_me_length, ' ' );

    std::copy( hear_me, hear_me + cht::length( hear_me ), &( *copy_of_hera_me.begin() ) );


    std::cout << copy_of_hera_me << '\n';

}

/* output

Can you hear me well?

Process returned 0 (0x0)   execution time : 0.030 s
Press ENTER to continue.




*/
