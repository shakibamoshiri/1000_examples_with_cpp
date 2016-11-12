/*
            The Regular Expression Library
            ******************************
Defined in header <regex>
// for more detail see: regex.h
                        regex_constants.h

--> Algorithms:
    These functions are used to apply the regular expression encapsulated in a regex
    to a  target sequence of character.

>   regex_match:    attempts to match a regular expression to an entire character sequence
>   regex_search:   attempts to match a regular expression to any part of a character sequence
>   regex_replace:  replace occurrences of a regular expression with formatted replacement text

*/
/// std::regex_match
// Determines if the regular expression 'value' matches the given target.
// There is 7 implementation of it. For more detail see them main site
//
// NOTE:
// The regex_match only will successfully match a regular expression on an entire
// character sequence, whereas std::ragex_search will successfully match subsequence


#include <iostream>
#include <regex>

#include <string>


int main(){

    std::string string[]={"one.txt","two.txt","three.txt","one.dat","two.dat","three.dat"};

    // Extraction of several sub-match
    std::basic_regex<char> regex("([a-z]+)\\.([a-z]+)"); // ([a-z]+).([a-z]+) or (\w+).(\w+)
    std::smatch pieces_match;

    for(const std::string& str: string){
        if(std::regex_match(str,pieces_match,regex)){
            std::cout<<str<<'\n';
            for(std::size_t i=0;            // i
                i < pieces_match.size();    // when i < size
                ++i){                       // ++i
                std::ssub_match sub_match=pieces_match[i]; // for each match
                std::string piece=sub_match.str();         // get pieces
                std::cout<<" submatch " <<i<<" : "<<piece<<'\n';
            }
        }
    }

return 0;}
