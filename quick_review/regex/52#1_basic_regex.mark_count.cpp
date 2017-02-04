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

    std::regex first;
    first = "^(.+)$";
    std::regex second;
    second.assign( "([0-9])([A-F])" );

    std::cout << first.mark_count() << '\n';    // 1 => that means it has one sub-match
    std::cout << second.mark_count() << '\n';   // 2 => that means it has two sub-match

}

/* output for me:



*/
