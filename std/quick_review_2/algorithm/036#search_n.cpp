/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <iomanip>



/// search_n
//  Searches range for sub-sequence.


int main(){
    typedef std::char_traits< char > cht;

    const char* one( "yellow ball" );

    // looking for two 'l' in the range
    const char* result = std::search_n( one, one + cht::length( one ), 2, 'l' );

    std::cout << one << '\n';
    std::cout << result << '\n';

}

/* output

yellow ball
llow ball

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.




*/
