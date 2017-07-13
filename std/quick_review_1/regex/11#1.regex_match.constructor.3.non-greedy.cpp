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

    // here the std::regex_match returns true because the entire of regex is matched
    // against "how are you today?"
    // first -> (how)
    // then  -> ( are you )
    // then  -> (today?)
    // here we did not store the match expression which for,
    // that we should use an object of std::match_results
    // the std::match_result has 4 case
    // one for const char*
    // one for const wchar*
    // one for string
    // one for wstring

    // for storing the result we simply can:
    std::match_results< const char* > m_result;
    std::regex_match( "how are you today?" ,    // a const char*
                       m_result,                // an object for storing the result of matching
                       std::basic_regex< char >( "(how)(.*?)(\\w+\\?)" ) );   // the regex( put the question mark after asterisk to make it non-greedy

    // and for printing:
    std::cout << '\n';
    std::cout << "the entire match    : " << m_result.str() << '\n'
              << "the first sub-match : " << m_result.str( 1 ) << '\n'
              << "the second sub-match: " << m_result.str( 2 ) << '\n'
              << "the third sub-match : " << m_result.str( 3 ) << std::endl;

}
// now by using non-greedy regex we have this output
/* output for me:

the entire match    : how are you today?
the first sub-match : how
the second sub-match:  are you
the third sub-match : today?

*/
