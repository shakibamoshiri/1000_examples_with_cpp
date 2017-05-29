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
/// std::regex_match constructor

#include <iostream>
#include <regex>
#include <string>
//#include <sstream>
//#include <vector>




int main(  ){

    const char c_string[] =  "before subject after";
    std::basic_regex< char > regex( "(sub)(.+)" );  // sub plus anything ( greedy )
    std::match_results< const char* > m_result;

    if( std::regex_match( c_string, m_result, regex ) ){      // three parameter
        std::cout << m_result.str() << '\n'
                  << m_result.str( 1 ) << '\n'
                  << m_result.str( 2 ) << std::endl;
    } else {
        std::cout << "no it was not match :(\n";    // because there are other things that does not match against regular expression (sub)(.+)
    }

    // so we can use range constructor
    // string.begin() + 7
    // string.begin() + 14

    puts( "" );
    if( std::regex_match( std::begin( c_string ) + 7, std::begin( c_string ) + 14 , m_result,  regex ) ){        // okay
        std::cout << m_result.str() << '\n'
                  << m_result.str( 1 ) << '\n'
                  << m_result.str( 2 ) << std::endl;
    } else {
        std::cout << "no it was not match :(\n";    //
    }

    // first if does not match
    // but second if matches
}

/* output for me:

no it was not match :(

subject
sub
ject

*/
