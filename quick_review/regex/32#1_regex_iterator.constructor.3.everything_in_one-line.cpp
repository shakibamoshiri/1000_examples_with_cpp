/*
            Regular Expression
            ******************
written and tested on code::block 16.01
                      Ubuntu      16.01
            ******************


std::regex_iterator
    When it constructed, and every time the operator++ is applied to it,
    the iterator performs a regex_search to find successive matches on a
    sequence. Dereferencing a valid regex_iterator yields a match_result ( yield means to produce or provide something )
    object.

    A special value of regex_iterator is used to indicate an end-of-sequence.
    This iterator should not be dereferenced. Its value is the same for all
    end-of-sequence regex_iterator object of the same type, no matter the
    sequence being iterated by each.

    Internally, the object (of iterator) keeps a match_result object with the
    information about the most recent match (if any), which is updated every
    time the iterator is incremented with operator++. A reference to this object
    is returned when the iterator is dereferenced using operator*.

    Member function:
        constructor

    Operator:
        operator ++
        operator ==
        operator !=
        operator *
        operator ->

*/
/// std::regex_iterator ( constructor )
//
//  1)  default
//  2)  copy
//  3)  initialization
//  4)  moving = delete


#include <iostream>
#include <regex>
#include <string>


int main(  ){

    std::string string( "one two three four five" );
    std::basic_regex< char > regex( "[a-z]+" ); // matches a word

    std::regex_iterator< std::string::iterator > first( string.begin(), string.end(), regex );
    std::regex_iterator< std::string::iterator > last;

    // instead of using regex_search and a while loop and update the string
    // each time, we can use just a while loop and this's it.

     // note that this operator ( != ) is overloaded
     // everything in one line
    while( first != last ) std::cout << (first++)->str() << '\n';

    // update the string for research by regex_search
    // by operator ++ which is overloaded
    // ++first;




}

/* output for me:

one
two
three
four
five
*/
