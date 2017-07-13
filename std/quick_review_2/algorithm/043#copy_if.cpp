/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <iterator>

/// copy_if
//  Copies certain element of range


int main(){

    typedef std::char_traits< char > cht;

    const char* hear_me( "Can you hear me well? I am find how about you?" );
    const int hear_me_length = cht::length( hear_me );

    std::ostreambuf_iterator< char > output ( std::cout );

    std::copy_if( hear_me, hear_me + hear_me_length,        // range of elements
                  output,                                   // the output
                  []( const char chr ){                     // UnaryPredicate function
                    return chr != ' ';                      // copying everything except ' '
                  } );

}

/* output

Canyouhearmewell?Iamfindhowaboutyou?
Process returned 0 (0x0)   execution time : 0.015 s
Press ENTER to continue.



*/
