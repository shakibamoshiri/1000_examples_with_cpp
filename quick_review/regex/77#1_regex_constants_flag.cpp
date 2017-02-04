/*
            Regular Expression
            ******************
written and tested on code::block 16.01
                      Ubuntu      16.01
            ******************


std::regex_constants

*/

/// std::sub_match operator compare




#include <iostream>
#include <regex>
#include <string>




int main(  ){

    std::basic_regex< char >::flag_type flags = std::regex_constants::icase | std::regex_constants::ECMAScript;
    std::basic_regex< char > regex( "(Sub)(jecT)", flags );

    typedef std::match_results< const char* > mr_t;
    mr_t m_result;

    std::regex_match( "subject", m_result, regex );

    if( m_result.ready() ) std::cout << m_result.str();







}
/* output for me:

subject

*/
