/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>


/// find_end
//  Find the last sup-sequent in a range
//
// Note that this function returns the last sub-sequence of a range,
// for the first one, you can you std::search.



int main(){

    typedef std::char_traits< char > cht;

    const char* c_string = "abcdef abcde abcd abc xyz";
    const char* looking_for = "abc";

    const char* result_point = std::find_end( c_string, c_string + cht::length( c_string ),
                                              looking_for, looking_for + cht::length( looking_for ) );

    std::cout << "result point: " << result_point << '\n';
    std::cout << "looking for : " << looking_for << '\n';
}

/* output

result point: abc xyz
looking for : abc



*/
