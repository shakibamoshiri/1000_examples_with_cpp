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


    const char* line="Roses are #ff0000 violets are #0000ff all of my base are belong to you";

    std::regex_search(line,std::regex("#([a-f0-9]{2})"))?
        std::cout<<"okay":
        std::cout<<"not found";


/**
   * @brief Indicates if there is a match between the regular expression @p e
   * and a C-style null-terminated string.
   *
   * @param __s  The C-style null-terminated string to match.
   * @param __re The regular expression.
   * @param __f  Controls how the regular expression is matched.
   *
   * @retval true  A match exists.
   * @retval false Otherwise.
   *
   * @throws an exception of type regex_error.

  template<typename _Ch_type, class _Rx_traits>
    inline bool
    regex_match(const _Ch_type* __s,
		const basic_regex<_Ch_type, _Rx_traits>& __re,
		regex_constants::match_flag_type __f
		= regex_constants::match_default)
    { return regex_match(__s, __s + _Rx_traits::length(__s), __re, __f); }
**/

return 0;}
