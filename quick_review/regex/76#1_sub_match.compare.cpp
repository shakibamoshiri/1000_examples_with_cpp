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

/// std::sub_match operator compare




#include <iostream>
#include <regex>
#include <string>




int main(  ){

    std::basic_regex< char > regex( "\\d+" );
    typedef std::match_results< const char* > mr_t;
    mr_t m_result;

    std::regex_search( "Do you have 10 millions dollars?", m_result, regex );

    if( m_result.str().compare( "10" ) == 0 ) std::cout << "okay I found how much money do you have\n";

    if( m_result.str(0).compare( "10" ) == 0 ) std::cout << "okay I found how much money do you have\n";

    if( m_result[ 0 ].compare( "10" ) == 0 ) std::cout << "okay I found how much money do you have\n";




}
/* output for me:

okay I found how much money do you have
okay I found how much money do you have
okay I found how much money do you have

*/
