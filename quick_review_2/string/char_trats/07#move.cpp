/*

A review of string library( char_treats )

*/

/// char_traits::move
//  static char_type* move( char_type* destination, const char_type* source, size_t n );
//
//  Moves character sequence.

#include <iostream>
#include <string>



int main(){
    char bar[] = "----|++++++++++++";
    std::cout << bar << '\n';

    std::char_traits< char >::move( bar + 4, bar, 11 );
    std::cout << bar << '\n';

    std::char_traits< char >::move( bar + 8, bar, 9 );
    std::cout << bar << '\n';
}

/**

----|++++++++++++
--------|++++++++
----------------|

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.


**/
