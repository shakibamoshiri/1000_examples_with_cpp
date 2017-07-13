/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>


/// find_first_of
//  Finds element from set in range( function template )

char to_lowercase( const char chr ){
    if( chr >= 'A' && chr <= 'Z' )
        return chr + 32;
}

bool insentitive_case( const char c_1, const char c_2 ){
    return ( to_lowercase( c_1 ) == to_lowercase( c_2 ) );
}

int main(){

    typedef std::char_traits< char > cht;

    const char* c_string = "abcDef abcDE ABC ABC de DE";
    const char* looking_for = "DE";

    const int c_string_length    = cht::length( c_string );
    const int looking_for_length = cht::length( looking_for );

    const char* result_point = std::find_first_of( c_string, c_string + c_string_length,            // first range
                                                   looking_for, looking_for + looking_for_length,   // second range
                                                   insentitive_case );                              // binary predicate function
    std::cout << "result: " << result_point << '\n'
              << "index:  " << c_string_length - cht::length( result_point ) << '\n';




}

/* output


result: Def abcDE ABC ABC de DE
index:  3

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
