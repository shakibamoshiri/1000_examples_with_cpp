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

    std::string string( "subject" );
    std::basic_regex< char > regex( "(sub)(.+)" );  // sub plus anything ( greedy )

    if( std::regex_match( string, regex ) ){        // using 2 parameter, first is a string, second is a regular expression
        std::cout << "okay it was match :)\n";
    }


}

/* output for me:



*/
