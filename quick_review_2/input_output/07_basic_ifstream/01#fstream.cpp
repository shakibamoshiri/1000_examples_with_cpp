/*

A review of abstraction section from cplusplus.com

*/

/// basic_ifstream

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>



int main(){

    std::ifstream input_file_stream( "file" );

    char chr;
    while( input_file_stream.good() ){

        std::cout << (char)input_file_stream.get();
    }

    input_file_stream.close();

}
/**



**/
