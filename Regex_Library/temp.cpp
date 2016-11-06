/*
            The Regular Expression Library
            ******************************
Defined in header <regex>
// for more detail see: regex.h
                        regex_constants.h

--> Main class:
    These classes encapsulate a regular expression and the results of
    matching a regular expression within a target sequence of characters.

>   basic_regex:    regular expression library
>   sub_match:      identifies the sequence of characters matched by a sub-expression
>   match_results:  identifies one regular expression match, including all sub-expression

*/

#include <iostream>
#include <regex>



int main(){

    std::basic_regex<char>  txt("[a-z]");
    std::string context("how are you today? Do you have my phone number? okay, so write 09370947008");

    std::sub_match<char> one;

return 0;}
