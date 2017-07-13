/*

A review of abstraction section from cplusplus.com

*/

/// basic_streambuf::in_avail
//  streamsize in_avail();
//
//  Gets number of available to read

//  Note that streamsize is a singed integral type

#include <iostream> // std::cout, std::ios
#include <fstream>



int main(){

    // get file size using pubseekoff

    std::ifstream input_file_stream( "file" );
    if( input_file_stream.good() ){
        std::streambuf* sb = input_file_stream.rdbuf();
        char chr;
        input_file_stream >> chr;

        std::streamsize size = sb->in_avail();

        std::cout << "first character in file: " << chr << '\n';
        std::cout << size << " characters in buffer after it\n";
    }
    input_file_stream.close();

}
/**

first character in file: I
504 characters in buffer after it

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.


-------------------
the content of the file:
If the get pointer (gptr) has a value and this is less than the end pointer (egptr): The
function returns the number of characters directly available at the get pointer before the end
pointer (i.e., it returns (egptr()-gptr()) without calling any virtual member function).
• If the get pointer (gptr) is either null or has reached the end pointer (egptr): The function
calls the protected virtual member function showmanyc to obtain the number of characters
expected to be available after an underflow.
**/
