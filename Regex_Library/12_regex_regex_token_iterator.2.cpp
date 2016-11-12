/*
            The Regular Expression Library
            ******************************
Defined in header <regex>
// for more detail see: regex.h
                        regex_constants.h

--> Iterators:
    The regex iterator are used to traverse the entire set of regular expression matches found
    within a sequence.

>   regex_iterator:         iterators through all regex matches within a character sequence
>   regex_token_iterator:   iterators through the specific sub-expression within all regex
                            matches in a given string or through unmatch substring

*/
/// std::regex_token_iterator
// std::regex::token_iterator is a read-only ForwardIterator that accesses the individual
// sub-matches of every match of a regular expression within the underlying character
// sequence. It can also be used to access the part of the sequence that were not matched
// by the given regular expression (e.g. as a tokenizer)
//
/// type
// cregex_token_iterator    regex_token_iterator<const char*>
// wcregex_token_iterator   regex_token_iterator<const wchar*>
// sregex_token_iterator    regex_token_iterator<std::string::const_iterator>
// wsregex_token_iterator   regex_token_iterator<std::wstring::const_iterator>

#include <iostream>
#include <regex>

#include <iterator>
#include <algorithm>
#include <string>


int main(){

    // iterating the first sub-matches
    std::string html="<p><a href=\"http://google.com\">google</a> "
                     "< a HREF =\"http://cppreference.com\">cppreference</a>\n</p>";

    std::cout<<html<<std::endl;

    // std::regex url=" ... " is a wrong syntax
    // It has no = member operator
    //             "<\\s*A\\s+[^>]*href\\s*=\\s*\"([^\"]*)\""
    std::regex url("<\\s*A\\s+[^>]*href\\s*=\\s*\"([^\"]*)\"", std::regex::icase);
    std::copy(std::sregex_token_iterator(html.begin(),html.end(),url,1),
              std::sregex_token_iterator(),
              std::ostream_iterator<std::string>(std::cout<<"\n\nThe output:\n","\n"));



return 0;}













