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
/// std::regex imbue
//  This function resets the basic_regex object, so it no longer
//  matched any character sequence( as if constructed with regex
//  default constructor ). You can use the regex::assign and
//  regex::operator= to assign a new regular expression to the
//  object once imbued.


#include <iostream>
#include <regex>
#include <string>
#include <locale>




int main(  ){

    std::regex regex( "anything" );
    regex.imbue( std::locale::classic() );
    regex.assign( "sub[a-z]*" );

    if( std::regex_match( "subject", regex ) ){
        puts( "the whole string is matched" );
    }

}

/* output for me:
the whole string is matched


*/
