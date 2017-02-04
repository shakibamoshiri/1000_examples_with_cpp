/*
            Regular Expression
            ******************
written and tested on code::block 16.01
                      Ubuntu      16.01
            ******************


std::sub_match
    sub-expression match

    match_results object filled by one of the regex algorithm:
        regex_match
        regex_search
        regex_iterator
        regex_token_iterator

    These matches are sequence of characters. But objects of this class
    do not store the sequence of characters itself, but instead, the class
    derived from "pair" to hold pair of BidirectionalIterator to the
    initial and past-the-end character of a sequence, and provides
    reference semantics to this sequence.

    Objects of this class can be converted to string objects.

    sub_match< const char* >                equals to       csub_match
    sub_match< string::const_iterator >     equals to       ssub_match
    sub_match< const wchar_t* >             equals to       wcsub_match
    sub_match< string::const_iterator >     equals to       scsub_match

    Member Function:
        constructor
        length
        str
        operator string type
        compare


*/

/// std::sub_match operator string type
//  operator string_type const();

//  cast to string type
//  sub_match into a string object
//  it is an alias of member str

//  return value: a string with the content referred by the sub_match




#include <iostream>
#include <regex>
#include <string>




int main(  ){

    std::basic_regex< char > regex( "(sub)(ject)" );
    typedef std::match_results< const char* > mr_t;
    mr_t m_result;

    std::regex_match( "subject", m_result, regex );

    std::string output = "matches: \n";

    for( mr_t::iterator first = m_result.begin(); first != m_result.end(); ++first ){
//        output += *first + '\n';    // error: no match for operator +
        output += std::string( *first ) + '\n';    // okay
    }

    std::cout << output;
}
/* output for me:

matches:
subject
sub
ject

*/
