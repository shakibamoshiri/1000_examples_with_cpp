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

/// std::match_results constructor
//  it has default, copy and move constructor


#include <iostream>
#include <regex>
#include <string>


int main(  ){

    typedef std::match_results< std::string::const_iterator > mr_t;
    mr_t first;     // default constructor

    std::string string = "subject";

    std::regex_match( string, first, std::basic_regex< char > ( "sub(.+)" ) );

    mr_t second( first );       // copy constructor

    for( std::size_t index = 0; index < second.size(); ++index ) std::cout << "match " << index << " : " << second[ index ] << '\n';

}

/* output for me:

match 0 : subject
match 1 : ject

*/
