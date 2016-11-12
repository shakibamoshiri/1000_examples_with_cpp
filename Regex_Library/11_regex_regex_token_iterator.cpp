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

    const std::string s("Quick Brown Fox");

    // tokenization  (non-matched fragment)
    // NOTE that regex is matched only  two times, when the third value is obtained
    // the iterator is a suffix iterator:
    std::regex ws("\\s+");  // \s means whitespace or tab, \S means not whitespace or tab
    std::copy(std::sregex_token_iterator(s.begin(),s.end(),ws,-1),
              std::sregex_token_iterator(),
              std::ostream_iterator<std::string>(std::cout<<"The output is:\n","\n"));



return 0;}













