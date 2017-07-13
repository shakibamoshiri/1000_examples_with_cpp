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

    if( std::regex_match( "how are you today?" , std::basic_regex< char >( "(how)(.*)(\\w+\\?)" ) ) ){
       std::cout << "okay it was match\n";
    } else {
        std::cout << "no sorry it was not match\n";
    }

    // the output is:
    // okay it was match

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
}

/* output for me:


*/
