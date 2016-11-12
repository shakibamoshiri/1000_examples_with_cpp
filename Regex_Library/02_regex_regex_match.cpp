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
    std::regex regex("[a-z]+\\.txt"); // matches all letters that followed by .txt

    for (const std::string& str:string)
        std::cout<<str<<" : "<<std::regex_match(str,regex)<<'\n';
    // true for matching
    // false for unmatch

return 0;}
