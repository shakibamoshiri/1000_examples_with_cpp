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

/// std::match_results position



#include <iostream>
#include <regex>
#include <string>


int main(  ){

    std::basic_regex< char > regex( "\\w+" );   // only word
    typedef std::match_results< const char* > mr_t;
    mr_t m_result;
    const char* c_string = "Do you have 10 millions dollars?";

    std::string temp;
    while( std::regex_search( c_string, m_result, regex ) ){

        for( std::size_t index = 0; index < m_result.size(); ++index ){
            std::cout << "at position: " << m_result.position( index )
                      << " we have a match: " << m_result.str( index ) << '\n';
        }

        temp = m_result.suffix();
        c_string = temp.c_str();

        // also we can use this syntax:
        // c_string = c_string + m_result.length();


    }
//error: ‘c_str’ in ‘std::__cxx11::string {aka class std::__cxx11::basic_string<char>}’ does not name a type|
//error: invalid static_cast from type ‘const value_type {aka const std::__cxx11::sub_match<const char*>}’ to type ‘const char*’|
//error: cannot convert ‘const value_type {aka const std::__cxx11::sub_match<const char*>}’ to ‘const char*’ in assignment|

}
// why the all position is 1? because it goes ahead each time just before the word
// first is 0 because it matches Do
// then it passes from Do and stuck at ' you'
// then the same things for            ' have'
//                                      ' 10'
// and so on.

/* output for me:

at position: 0 we have a match: Do
at position: 1 we have a match: you
at position: 1 we have a match: have
at position: 1 we have a match: 10
at position: 1 we have a match: millions
at position: 1 we have a match: dollars

*/

/* output for the syntax: c_string = c_string + m_result.length(); with a little change in regex( "\\w+ ?" )

at position: 0 we have a match: Do
at position: 0 we have a match: you
at position: 0 we have a match: have
at position: 0 we have a match: 10
at position: 0 we have a match: millions
at position: 0 we have a match: dollars

*/
