/*
            Regular Expression
            ******************
written and tested on code::block 16.01
                      Ubuntu      16.01
            ******************


std::regex_match:
    The entire target sequence must match the regular expression for
    this function to return true (i.e. without any additional characters
    before or after the match).

    For a function that return true when the  match is only part of the sequence,
    see "regex_search"

*/

#include <iostream>
#include <regex>
#include <string>
//#include <sstream>
//#include <vector>




int main(  ){

    std::string string( "how are you today?" );

    std::basic_regex< char > regex( "\\w+ \\w+ \\w+ (\\w+\\?)" );    // match 4 words
    // std::basic_regex< char > regex( "\\w+ \\w+ \\w+ (\\w+\\)" );    // match 4 words it does not work for std::regex_match because does not completely match
    std::match_results< std::string::const_iterator > m_result;

    std::regex_match( string, m_result, regex );    // it return boolean and also store the result in the m_result

    std::cout << m_result.str() << '\n';
    std::cout << m_result.str( 1 ) << '\n'; // first sub-match ( capture from first () )


}

/* output for me:


*/
