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
/// std::regex constructor


#include <iostream>
#include <regex>
#include <string>




int main(  ){

    // std::regex is a standard alias for std::basic_regex< char >

    std::string pattern = "^.+$";

    std::regex first;               // default constructor
    std::regex second = first;      // copy
    std::regex third( pattern );    // string object initializer
    std::regex fourth( "^.+$" );    // string literal initializer
    std::regex fifth( pattern.begin(), pattern.end() ); // range initializer
    std::regex sixth { '^','.','+','$' };               // initializer-list initializer

    using namespace std::regex_constants;
    std::regex seventh( pattern, ECMAScript );          // using flag
    std::regex eighth( pattern, ECMAScript | icase );   // multiple flags

}

/* output for me:



*/
