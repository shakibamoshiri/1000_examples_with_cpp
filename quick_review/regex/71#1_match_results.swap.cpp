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

/// std::match_results swap




#include <iostream>
#include <regex>
#include <string>
#include <sstream>


int main(  ){


    typedef std::match_results< const char* > mr_t;
    mr_t first, second;
    const char* c_string = "Do you have 10 millions dollars?";

    std::regex_search( c_string, first, std::regex( "you" ) );
    std::regex_search( c_string, second, std::regex( "dollars?" ) );

    puts( "before swapping: " );
    std::cout << first.str() << '\n';
    std::cout << second.str() << '\n';

    puts( "after swapping: " );
    first.swap( second );

    std::cout << first.str() << '\n';
    std::cout << second.str() << '\n';



}

/* output for me:

before swapping:
you
dollars
after swapping:
dollars
you

*/
