/*

A review of iterator library


*/

/// istreambuf_iterator
//  input stream buffer iterator

#include <iostream>
#include <iterator>



int main(){

    std::istreambuf_iterator< char > input_buffer_stream_iterator( std::cin.rdbuf() ), end_of_stream_buffer;

    std::string string;
    while( input_buffer_stream_iterator != end_of_stream_buffer && *input_buffer_stream_iterator != '\n' )
        string += *input_buffer_stream_iterator++;

    std::cout << "you entered: " << string << '\n';

}
/* output

how are you today?
you entered: how are you today?

Process returned 0 (0x0)   execution time : 7.020 s
Press ENTER to continue.


*/
