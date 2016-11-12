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

    // write the results to an output iterator
    std::regex_replace(std::ostreambuf_iterator<char>(std::cout),   // output
                       text.begin(),                                // beginning of the string
                       text.end(),                                  // end of the string
                       vowel,                                       // searching for
                       "*");                                        // replace with "*"

return 0;}













