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

    const char c_string[] = "I have only 1 dollar!";
    std::basic_regex< char > regex( "(\\d) ([a-z]+)" ); // matches 1 => $1 and dollar => $2

// error
// no match function: const char c_string* = "I have only 1 dollar!";
//    std::regex_replace( std::back_inserter( result ), c_string, regex, "$1,000,000 $2s" );

// still error
// not match function: const char* c_string = "I have only 1 dollar!";
//    std::regex_replace( std::back_inserter( result ), std::begin( c_string ), std::begin( c_string ) + 22 , regex, "$1,000,000 $2s" );

    // okay works with: const char c_string[] = "I have only 1 dollar!";
    std::string result;
    std::regex_replace( std::back_inserter( result ), std::begin( c_string ), std::begin( c_string ) + 22 , regex, "$1,000,000 $2s" );
    std::cout << result;

}

/* output for me:

I have only 1,000,000 dollars!


*/
