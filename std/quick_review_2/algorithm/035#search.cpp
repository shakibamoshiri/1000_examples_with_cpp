/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <iomanip>



/// search
//  Searches range for sub-sequence.


int main(){
    typedef std::char_traits< char > cht;

    const char* one( "Can you hear me?" );
    const char* two( "Do not shout! I can hear you" );
    const char* word( "hear" );

    const int one_length  = cht::length( one );
    const int two_length  = cht::length( two );
    const int word_length = cht::length( word );

    const char* result_1 = std::search( one, one + one_length,
                                        word, word + word_length );

    if( result_1 < one + one_length )
        std::cout << result_1 << '\n';

    const char* result_2 = std::search( two, two + two_length,
                                        word, word + word_length );

    if( result_2 < two + two_length )
        std::cout << result_2 << '\n';


}

/* output

hear me?
hear you

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
