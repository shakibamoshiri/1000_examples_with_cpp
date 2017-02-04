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
/// std::regex operator = (assignment)


#include <iostream>
#include <regex>
#include <string>




int main(  ){

    // std::regex is a standard alias for std::basic_regex< char >

    std::string pattern = "^.+$";

    std::regex first;               // default constructor
    std::regex second = first;      // copy
    std::regex third;
    third = second;
    first = { '^','.','+','$' };
    second = pattern;

    std::regex fourth;
    fourth = "^.+$";

}

/* output for me:



*/
