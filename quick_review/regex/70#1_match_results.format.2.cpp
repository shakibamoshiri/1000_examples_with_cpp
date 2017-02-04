/*
            Regular Expression
            ******************
written and tested on code::block 16.01
                      Ubuntu      16.01
            ******************


std::match_results

regex matching operation, each match being of the corresponding "sub_match" type.

It is filled by regex_match, regex_search, or regex_iterator with the results of
the matching operation. The elements in "match_results" object are const-qualified,
and thus are not meant to be modified outside of these function.


some typedef for match_results:

cmatch      equals to typedef match_results< const char*>
smatch      equals to typedef match_results< string::const_iterator >

wcmatch      equals to typedef match_results< const wchar_t* >
wsmatch      equals to typedef match_results< wstring::const_iterator >


    Member function:
        constructor
        destructor
        operator =

    Capacity:
        empty
        size
        max_size

    Iterator:
        begin
        end
        cbegin
        cend

    Element access:
        operator []
        prefix
        suffix
        length
        position
        str

    Formating:
        format

    Swap:
        swap

    Observers:
        ready
        get_allocator

    Non-member function:
        operators( match_result )
        std::swap( match_result )
*/

/// std::match_results format
//  Format replacement string



#include <iostream>
#include <regex>
#include <string>
#include <sstream>


int main(  ){

    std::basic_regex< char > regex( "\\d+ (\\w+)" );
    typedef std::match_results< const char* > mr_t;
    mr_t m_result;
    const char* c_string = "Do you have 10 millions dollars?";

//    // it has not output
//    std::regex_match( c_string, m_result, regex );
//    std::cout << m_result.format( "prefix is [$`]\n" );
//    std::cout << m_result.format( "match  is [$&]\n" );
//    std::cout << m_result.format( "suffix is [$']\n" );
//
//    puts( "-------------------" );

    // okay
    std::regex_search( c_string, m_result, regex );
    std::cout << m_result.format( "match  is [$&]\n" ); // the entire of match
    std::cout << m_result.format( "sub    is [$1]\n" ); // only sub 1
    std::cout << m_result.format( "match  is [$0]\n" ); // all match


}

/* output for me:

match  is [10 millions]
sub    is [millions]
match  is [10 millions]

*/
