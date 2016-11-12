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

    // Extraction of a sub-match
    std::regex regex("([a-z]+)\\.txt"); // () for group matching
    std::smatch base_match;

    for(const std::string& s:string){
        if(std::regex_match(s,base_match,regex)){
           // The first sub_match is whole string
           // The next sub_match is the first parentheses operation.
           if(base_match.size()==2){
            std::ssub_match base_sub_match=base_match[1];
            std::string base=base_sub_match.str();
            std::cout<<s<<" has a base of " <<base<<std::endl;
           }
        }
    }

    // doing this code with Perl
    // echo one.txt two.txt three.txt | perl -lne 'print $1.".$2 has a base of ".$1 while /([a-z]+)\.(txt)/g' (or /gs)
    // output:
    //
    // one.txt has a base of one
    // two.txt has a base of two
    // three.txt has a base of three

return 0;}
