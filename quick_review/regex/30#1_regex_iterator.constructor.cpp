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
    std::match_results< std::string::const_iterator > m_result;

    // find all match without using regex_iterator ( by regex_search )
    while( std::regex_search( string, m_result, regex ) ){
        std::cout << m_result.str() << '\n';

        // updating the string
        string = m_result.suffix().str();
    }
    // the output is:
    // one
    // two
    // three
    // four
    // five

    // the std::regex_iterator does this algorithm internally we us
    // this is an object of regex_iterator the holds a std::match_result for us
    // also does std::regex_search for us

    // because of the using regex_search above, not std::string string
    // is empty, so:
    string = "one two three four five";

    std::regex_iterator< std::string::iterator > first( string.begin(), string.end(), regex );

    // this end of iteration is fixed, and common for all iterations that we do
    std::regex_iterator< std::string::iterator > last;

    // now because the regex_iterator holds an object of std::match_result
    // this object (= first) works same as an object of std::match_results
    // and it has str(), suffix(), or so on member function



    puts( "------------------" );
    std::cout << first->str() << '\n';
    puts( "------------------" );
    std::cout << first->suffix().str() << '\n';
    puts( "------------------" );

    // the output is:
    // ------------------
    // one
    // ------------------
    //  two three four five
    // ------------------

}

/* output for me:

one
two
three
four
five
------------------
one
------------------
 two three four five
------------------

*/
