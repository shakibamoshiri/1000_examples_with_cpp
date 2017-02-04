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

    std::string string =  "before subject after";
    std::basic_regex< char > regex( "(sub)(.+)" );  // sub plus anything ( greedy )
    std::match_results< std::string::const_iterator > m_result;

    if( std::regex_match( string, m_result, regex ) ){      // three parameter
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
    // using sting.begin() is wrong syntax because the constructor needs const_iterator not iterator
    // if( std::regex_match( std::begin( string ) + 7, std::begin( string ) + 14 , m_result,  regex ) ){        // okay
    if( std::regex_match( string.cbegin() + 7, string.cbegin() + 14 , m_result,  regex ) ){        // okay
        std::cout << m_result.str() << '\n'
                  << m_result.str( 1 ) << '\n'
                  << m_result.str( 2 ) << std::endl;
    } else {
        std::cout << "no it was not match :(\n";    //
    }
}

/* output for me:

no it was not match :(

subject
sub
ject

*/
