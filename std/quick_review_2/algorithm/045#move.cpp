/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <iterator>

/// move
//  Move range of element

int main(){

    typedef std::char_traits< char > cht;

    const char* hear_me( "Can you hear me well? I am find how about you?" );
    const int hear_me_length = cht::length( hear_me );

    std::string result( hear_me_length, ' ' );

    std::move( hear_me, hear_me + hear_me_length,  // range of elements
                        result.begin() );

    std::cout << result << '\n';
    std::cout << hear_me << '\n';
}

/* output
Can you hear me well? I am find how about you?
Can you hear me well? I am find how about you?

Process returned 0 (0x0)   execution time : 0.013 s
Press ENTER to continue.


*/
