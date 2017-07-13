/*
            Regular Expression
            ******************
written and tested on code::block 16.01
                      Ubuntu      16.01
            ******************


std::basic_regex< char >
    basic_regex object do not conduct the matches directly through any
    of its matches. Instead they are used as argument for regex algorithm
    ( regex_match, regex_search, regex_replace, regex_iterator ) and
    regex iterator adaptors ( regex_iterator, and regex_token_iterator )
    that perform these matches using the rules specified with constructing
    the basic_regex object.

    Member Function:
        constructor
        destructor
        operator =

    Assignment:
        assign

    Const Operation:
        mark_count
        flags:
            icase
            nosubs
            optimize
            collate
            ECMAScript
            basic
            extended
            awk
            grep
            egrep

    Locale:
        imbue
        getloc

    Swap:
        swap

    Non-member function:
        std::swap( basic_regex )


*/
/// std::regex mark_count()


#include <iostream>
#include <regex>
#include <string>




int main(  ){

    // std::regex is a standard alias for std::basic_regex< char >

    std::regex regex( "(sub)([a-z]*).*" );

    std::cout << "how many mark_count(): " << regex.mark_count() << '\n';

    std::match_results< const char* > m_result;
    regex_match( "subject", m_result, regex );  // finds the function via ADL

    // now regex.mark_count() == 2
    // and m_result.size() became 3, so:
    if( m_result.size() == regex.mark_count() + 1 ){
        puts( "okay, all sub-expression was captured" );
        std::cout << "match-expression itself: " << m_result.str() << '\n'; // or m_result[ 0 ]
        for( std::size_t index = 1; index < m_result.size(); ++index ){
            std::cout << "sub-expression: " << index << " : " << m_result[ index ] << '\n';
        }
    }

}

/* output for me:

how many mark_count(): 2
okay, all sub-expression was captured
match-expression itself: subject
sub-expression: 1 : sub
sub-expression: 2 : ject

*/
