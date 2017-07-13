/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>


/// transform
//  Transforms ranges.

char to_upper( const char& chr ){
    if( chr >= 'a' && chr <= 'z' )
        return chr - 32;
}

int main(){

    std::ifstream input_file_stream( "file" );

    std::istreambuf_iterator< char > begin ( input_file_stream ), end;
    std::ostreambuf_iterator< char > output( std::cout );

    std::transform( begin, end,     // range
                    begin,         // the output
                    to_upper );     // action

    input_file_stream.close();

}

/* output

IF THE GET POINTER (GPTR) HAS A VALUE AND THIS IS LESS THAN THE END POINTER (EGPTR): THE
FUNCTION RETURNS THE NUMBER OF CHARACTERS DIRECTLY AVAILABLE AT THE GET POINTER BEFORE THE END
POINTER (I.E., IT RETURNS (EGPTR()-GPTR()) WITHOUT CALLING ANY VIRTUAL MEMBER FUNCTION).
• IF THE GET POINTER (GPTR) IS EITHER NULL OR HAS REACHED THE END POINTER (EGPTR): THE FUNCTION
CALLS THE PROTECTED VIRTUAL MEMBER FUNCTION SHOWMANYC TO OBTAIN THE NUMBER OF CHARACTERS
EXPECTED TO BE AVAILABLE AFTER AN UNDERFLOW.
*/
