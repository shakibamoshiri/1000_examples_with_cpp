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
/// std::regex_search
// Determines if there is a match between the regular expression 'e' and
// some subsequence in the target character sequence.
//
// regex_search will successfully match any subsequence of the given sequence
// whereas, std::regex_match will only return true of the regular expression
// matches the entire sequence.
//
// NOTE:
// It order to examine all matches within the target sequence, std::regex_search
// may be called in a loop, restarting each time from m[0].second of the previous
// call. std::regex_iterator offers an easy interface to this iterator.


#include <iostream>
#include <regex>

#include <string>


int main(){

    const char* line[]={"Roses are #ff0000","violets are #0000ff","all of my base are belong to you"};

    std::regex color("#([a-f0-9]{2})([a-f0-9]{2})([a-f0-9]{2})");

    for(const char* l:line)
        std::cout<<l<<" : "<<std::regex_search(l,color)<<'\n';

return 0;}
