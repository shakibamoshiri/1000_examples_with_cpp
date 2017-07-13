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

/// std::match_results begin, end, cbegin, cend
//  the match_results has inner iterator for iteration
//  through all matches
//
//  const_iterator begin()  const;
//  const_iterator end()    const;
//  const_iterator cbegin() const;
//  const_iterator cend()   const;



#include <iostream>
#include <regex>
#include <string>


int main(  ){

    std::basic_regex< char > regex( "(sub)(.+)" );
    typedef std::match_results< const char* > mr_t;
    mr_t m_result;

    std::regex_match( "subject", m_result, regex );

    for( mr_t::iterator first = m_result.begin();
         first != m_result.end();
         ++first ){
            std::cout << *first << '\n';
         }

    puts( "----------" );

    for( mr_t::iterator first = m_result.cbegin();
         first != m_result.cend();
         ++first ){
            std::cout << *first << '\n';
         }



}

/* output for me:

subject
sub
ject
----------
subject
sub
ject

*/
