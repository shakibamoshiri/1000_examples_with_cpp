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
/// std::regex_replace
// regex_replace uses a regular expression to perform substitution on a sequence of character.


#include <iostream>
#include <regex>

#include <iterator>
#include <string>


int main(){

    std::string text="Quick brown fox";
    std::regex vowel("a|e|i|o|u");

    // construct a string holding the result
    std::cout<<std::regex_replace(text,vowel,"[$&]");

    // in Perl the variable $& contains the string
    // by the last pattern match
    // perhaps in c++ as well

return 0;}













