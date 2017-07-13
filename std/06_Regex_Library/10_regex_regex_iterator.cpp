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
/// std::regex_iterator
// std::regex_iterator is a read-only ForwardIterator that accesses the
// individual matches of a regular expression within the underlying
// character sequence.
// On construction, and on every increment, it calls std::regex_search
// and remembers the result (that is,saves a copy of the value std::match_search<BiIter>)
// The first object may be used when the iterator is constructed or when the first dereferencing
// is done. Otherwise, dereferencing only returns a copy of the most recently obtained regex match.
//
// The default-constructed std::regex_iterator is the end-of-sequence iterator. When
// a valid std::regex_iterators incremented (? increased ? increment is a noun not verb)
// after reaching the last match (std::regex_search returns false), it becomes equal to the
// end-of-sequence iterator. Dereferencing or incrementing (?it is a noun?) it further invoke
// undefined behavior.
//
// A typical implementation of std::regex_iterator holds the begin (?not noun?) and the end iterators
// for the underlying sequence (two iterators of Bidirectional), a pointer to the regular expression
// (const regex_type*), the matches flags (std::regex_constant::match_flag_type), and the current match
// (std::match_results<BiIter>).
//
// NOTE:
// It is the programmer's responsibility to ensure that the std::basic_regex object
// passed to the iterator's constructor outlive the iterator. Because the iterator
// stores a pointer to the regex, incrementing (increasing) the iterator after
// the regex was destroyed accesses a dangling pointer.
//
// If the part of the regular expression that matched is just an assertion
// (^, $, \b, \B), the match stored in the iterator is a zero-length match,
// that is, match[0].first == match[0].second.
//
/// type
// cregex_iterator --> regex_iterator<const char*>
// wcregex_iterator --> regex_iterator<const wchar*>
// sregex_iterator  --> regex_iterator<std::string::const_iterator>
// wsregex_iterator  --> regex_iterator<std::wstring::const_iterator>

#include <iostream>
#include <regex>

#include <iterator>
#include <string>


int main(){

    const std::string s("Quick Brown Fox");

    std::regex wr("[^\\s]+");

    std::regex_iterator<std::string::const_iterator> begin_s = std::sregex_iterator(s.begin(),s.end(),wr);
    std::regex_iterator<std::string::const_iterator> end_s = std::sregex_iterator();
    // or:
    // auto begin_s = ...
    // auto end_s = ...
    // std::sregex_iterator begin_s = ...
    // std::sregex_iterator end_s = ...

    std::cout<<"Found "
             <<std::distance(begin_s,end_s)
             <<" words\n";

    for(std::sregex_iterator i=begin_s; i!=end_s; ++i){
        std::smatch match=*i;
        std::string m_s=match.str();
        std::cout<<m_s<<std::endl;
    }

return 0;}













