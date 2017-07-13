/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <cctype>   // tolower() and toupper()

/// transform
//  Transforms ranges.

char to_upper( const char& chr ){
    if( chr >= 'a' && chr <= 'z' )
        return chr - 32;
}

int main(){

    const char* today{ "how are you today?" };
    const int today_size = std::char_traits< char >::length( today );
    std::ostreambuf_iterator< char > output( std::cout );

    std::transform( today, today + today_size,
                    output,
                    to_upper );


}

/* output
HOW ARE YOU TODAY?
Process returned 0 (0x0)   execution time : 0.020 s
Press ENTER to continue.


*/
