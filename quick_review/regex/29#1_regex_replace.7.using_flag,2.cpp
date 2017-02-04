/*
            Regular Expression
            ******************
written and tested on code::block 16.01
                      Ubuntu      16.01
            ******************


std::regex_replace
    Replaces matched sequence

*/
/// std::regex_replace
//  It has 6 signatures

//  C-string / C-string
//  C-string /   string
//    string / C-string
//    string /   string
//  range    / C-string
//  range    /   string
//
//  version 1,2,3,4 return a string
//  and 5,6 return an iterator that point to the element past the last
//  character written to the sequence pointed by out( first parameter )

#include <iostream>
#include <regex>
#include <string>


int main(  ){

    std::string string( "1 2 3 4 5" );
    std::basic_regex< char > regex( "\\d" );

    std::cout << std::regex_replace( string, regex, "number" );  // all digits are replaced
    // output is:
    // number number number number number

    puts ( "" );

    // but if we want just one occurrence to replace, then we can use flag
    std::cout << std::regex_replace( string, regex, "number", std::regex_constants::format_no_copy );  // does not copy extra character from std::string string
    // output is:
    // numbernumbernumbernumbernumber

    // the space was not copied

}

/* output for me:

const char c_string[] = "I have only 1 dollar!";

*/
