/*
            Regular Expression
            ******************
written and tested on code::block 16.01
                      Ubuntu      16.01
            ******************


std::regex_token_iterator
    A regex_iterator with a token

    Member function:
        constructor

    Operator:
        operator =
        operator ==
        operator !=
        operator *
        operator ->
        operator ++


std::regex_token_iterator is a read-only ForwardIterator that accesses the
individual sub-matches of every match of a regular expression within the--
underlying character sequence. It can be also be use to access the part of
the sequence that were not matched by the given regular expression.

On construction, it constructs an "std::regex_iterator" and on every increment
it steps through the requested sub-matches from the current "match_results",
incrementing the underlying "regex_iterator" when incrementing away form the
last sub-match.

Just before becoming the end-of-sequence iterator, a "std::regex_token_iterator"
may become a suffix iterator, if the index -1( non-matched flagment ) appears in
the last requested sub-match index. Such iterator, if dereferenced, returns a
"match_results" corresponding to the sequence of character between the last
match and the end of sequence.

NOTE: for basic_regex< char > in the function signature:
the iterator does not keep a copy of the object( only a reference ), therefore
this should not be a temporary parameter.
Actually:
std::regex_token_iterator any( type.begin(), type.end(), "some regex", flag ); (= delete )
"some regex" is a temporary regex object

*/
/// std::regex_token_iterator operator = (assignment)


#include <iostream>
#include <regex>
#include <string>




int main(  ){

    std::string string( "--one 1 1 1 --two 2 2 2 --three 3 3 3 --" );
    std::basic_regex< char > regex( "\\s+.+?(?=-)" );
    typedef std::regex_token_iterator< std::string::const_iterator > regex_iterator;

    regex_iterator last, first( string.begin(), string.end(), regex, -1 );

    for( ; first != last; ++first ){
        std::cout << *first << ' ';
    }



}

/* output for me:

--one --two --three --

*/
