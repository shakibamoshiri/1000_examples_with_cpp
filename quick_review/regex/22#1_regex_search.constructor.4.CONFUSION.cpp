/*
            Regular Expression
            ******************
written and tested on code::block 16.01
                      Ubuntu      16.01
            ******************


std::regex_search:
    This function returns true if the expression is found anywhere in
    the target sequence, even if the sequence contains more characters
    that are not part of the match before or after the match.

    For a function that returns true only when the entire sequence matches
    see regex_match.

*/
/// std::regex_search constructor
//  It has 7 signatures
//
// 1) c-string
// 2) std::string
// 3) range
// 4) c-string with result_match
// 5) std::string with result_match
// 6) range with result_match
// 7) moving string is deleted( because of temporary object )

#include <iostream>
#include <regex>
#include <string>


int main(  ){

    const char* string = "this subject has a submarine as a subsequence. sub space sub space";
    std::match_results< const char* > m_result;
    std::basic_regex< char > regex ( "\\b(sub)([^ ]*)" );


    while( std::regex_search( string, m_result, regex ) ){
        std::cout << m_result.str() << " => ";

        for( std::__cxx11::sub_match<const char*>::string_type str : m_result ) std::cout << str << ' ';

        string = m_result.suffix().str().c_str();
        std::cout << '\n' << m_result.suffix().str().c_str() << '\n';
        // error: cannot convert ‘std::__cxx11::sub_match<const char*>::string_type {aka std::__cxx11::basic_string<char>}’ to ‘const char*’ in assignment|

        std::cout << std::endl;
    }


}

/* output for me:

subject => subject sub ject
submarine => submarine sub marine
subsequence. => subsequence. sub sequence.
sub => sub sub
sub => sub sub

*/
