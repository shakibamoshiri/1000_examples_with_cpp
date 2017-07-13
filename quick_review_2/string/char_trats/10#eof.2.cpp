/*

A review of string library( char_treats )

*/

/// char_traits::eof
//  static constexpr int_type eof() noexcept;
//
//  end-of-file character
//  end-of-file value

#include <iostream>
#include <string>
#include <fstream>



int main(){

    std::ifstream input_file_stream( "file" );
    while( input_file_stream.peek() != std::char_traits< char >::eof() )
        std::cout << char( input_file_stream.get() );       // c++ cast
}

/**
If the get pointer (gptr) has a value and this is less than the end pointer (egptr): The
function returns the number of characters directly available at the get pointer before the end
pointer (i.e., it returns (egptr()-gptr()) without calling any virtual member function).
• If the get pointer (gptr) is either null or has reached the end pointer (egptr): The function
calls the protected virtual member function showmanyc to obtain the number of characters
expected to be available after an underflow.


**/
