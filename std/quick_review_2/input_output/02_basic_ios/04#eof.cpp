/*

A review of abstraction section from cplusplus.com

*/

/// basic_ios::eof
//  bool eof() const
//  Check weather end-of-bit is set







#include <iostream> // std::cout, std::ios
#include <fstream>

int main(){

    std::basic_ifstream< char > input_stream( "file" );
    char c = '\0';
    if( input_stream ){
        while( input_stream.get( c ) ){
            putchar( c );
        }
    }

    if( input_stream.eof() ){
        puts( "end-of-file was reached" );
    } else {
        puts( "error reading" );
    }

    input_stream.close();

}
/**
All stream objects keep information on the state of the object internally.
This information can be retrieved as an element of this type by calling
member function basic_ios::rdstate or set by calling basic_ios::setstate.
end-of-file was reached

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.



**/
