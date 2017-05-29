/*
            Regular Expression
            ******************
written and tested on code::block 16.01
                      Ubuntu      16.01
            ******************


std::regex_match:
    The entire target sequence must match the regular expression for
    this function to return true (i.e. without any additional characters
    before or after the match).

    For a function that return true when the  match is only part of the sequence,
    see "regex_search"

*/
/// std::regex_match constructor

#include <iostream>
#include <regex>
#include <string>
//#include <sstream>
//#include <vector>




int main(  ){

    std::string string =  "before subject after";
    std::basic_regex< char > regex( "(sub)(.+)" );  // sub plus anything ( greedy )
    std::match_results< std::string::const_iterator > m_result;


    // using sting.begin() is wrong syntax because the constructor needs const_iterator not iterator
    // okay with std::cbegin
    // or   with string.cbegin()
    if( std::regex_match( std::cbegin( string ) + 7, std::cbegin( string ) + 14 , m_result,  regex ) ){        // okay
        std::cout << m_result.str() << '\n'
                  << m_result.str( 1 ) << '\n'
                  << m_result.str( 2 ) << '\n'
                  << m_result.size() << std::endl;
    } else {
        std::cout << "no it was not match :(\n";    //
    }

    puts( "------------------" );
    for( std::size_t index = 0; index < m_result.size(); ++index ){
        std::cout << "m_result.str( " << index << " ) => "
                  << m_result.str( index ) << '\n';
    }
}

/* output for me:

subject
sub
ject
3
------------------
m_result.str( 0 ) => subject
m_result.str( 1 ) => sub
m_result.str( 2 ) => ject



*/
