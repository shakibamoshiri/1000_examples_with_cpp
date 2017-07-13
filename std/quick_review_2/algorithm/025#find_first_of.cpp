/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>


/// find_first_of
//  Finds element from set in range( function template )


int main(){

    typedef std::char_traits< char > cht;

    const char* c_string = "abcdef abcde abcd abc xyz";
    const char* looking_for = "cde";

    const char* result_point = std::find_first_of( c_string, c_string + cht::length( c_string ),
                                              looking_for, looking_for + cht::length( looking_for ) );

    std::cout << "result point: " << result_point << '\n';
    std::cout << "looking for : " << looking_for << '\n';
    std::cout << "it was found at index: "
              << ( cht::length( c_string ) - cht::length( result_point ) )
              << '\n';

}

/* output

result point: cdef abcde abcd abc xyz
looking for : cde
it was found at index: 2

Process returned 0 (0x0)   execution time : 0.022 s
Press ENTER to continue.




*/
