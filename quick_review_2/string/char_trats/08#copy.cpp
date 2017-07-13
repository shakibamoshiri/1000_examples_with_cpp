/*

A review of string library( char_treats )

*/

/// char_traits::copy
//  static char_type* copy( char_type* destination, const char_type* source, size_t n );
//
//  Copies characters sequence.

#include <iostream>
#include <string>



int main(){
    const char today[] = "how are you today?";

    const unsigned size_index = std::char_traits< char >::length( today );
    char now[ size_index ];

    std::char_traits< char >::copy( now, today, size_index );
    now[ size_index ] = '\0';

    std::cout << now << '\n';


}

/**

how are you today?

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.



**/
