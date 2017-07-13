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
/// std::regex getloc


#include <iostream>
#include <regex>
#include <string>
#include <locale>



int main(  ){

    std::regex regex;
    std::locale locale( "" );

    regex.imbue( locale );
    regex.assign( "sub[a-z]+" );

    if( regex_match( "subject", regex ) ) puts( "string was matched" );
    else                                  puts( "string was not matched" );

    std::cout << "using locale: " << regex.getloc().name() << '\n';

}

/* output for me:

string was matched
using locale: LC_CTYPE=en_US.UTF-8;LC_NUMERIC=fa_IR;LC_TIME=fa_IR;LC_COLLATE=en_US.UTF-8;LC_MONETARY=fa_IR;LC_MESSAGES=en_US.UTF-8;LC_PAPER=fa_IR;LC_NAME=fa_IR;LC_ADDRESS=fa_IR;LC_TELEPHONE=fa_IR;LC_MEASUREMENT=fa_IR;LC_IDENTIFICATION=fa_IR

*/
