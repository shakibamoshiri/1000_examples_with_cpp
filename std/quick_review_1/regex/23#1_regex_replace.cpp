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
    std::string string( "how are you today?" );
    std::basic_regex< char > regex( " (are) (you) " );  // $1 == are, $2 == you, also ' are you ' == $&

    std::string result = std::regex_replace( string, regex, " is he " );     // this syntax, returns a string itself
    std::cout << result;    // how is he today?

    // also
    // std::cout << std::regex_replace( string, regex, " is he " );    // is okay

}

/* output for me:



*/
