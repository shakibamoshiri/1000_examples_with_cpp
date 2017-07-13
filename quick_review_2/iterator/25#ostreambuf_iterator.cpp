/*

A review of iterator library


*/

/// ostreambuf_iterator
//  output stream buffer iterator

#include <iostream>
#include <iterator>
#include <algorithm>



int main(){

    std::istreambuf_iterator< char > input_buffer_stream_iterator( std::cin.rdbuf() ), end_of_stream_buffer;

    std::string string;
    while( input_buffer_stream_iterator != end_of_stream_buffer && *input_buffer_stream_iterator != '\n' )
        string += *input_buffer_stream_iterator++;

    std::ostreambuf_iterator< char > output_stream( std::cout.rdbuf() );
    std::copy( string.begin(), string.end(), output_stream );

}
/* output

how are you today?
how are you today?
Process returned 0 (0x0)   execution time : 4.705 s
Press ENTER to continue.


*/
