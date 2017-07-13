/*

A review of abstraction section from cplusplus.com

*/

/// ios_base::iostate
//  Type for stream state flags
//
//  All stream objects keep information on the state of
//  the object internally. This information can be
//  retrieved as an element of this type by calling
//  member function basic_ios::rdstate or set by
//  calling basic_ios::setstate.

#include <iostream> // std::cout, std::ios
#include <fstream>

int main(){

    std::fstream input_stream;
    if( input_stream.rdstate() == std::ios_base::goodbit ){ // rdstate() return the current stream error state
        std::cout << "goodbit" << '\n';
    }

    input_stream.setstate( std::ios_base::eofbit ); // set the flag
    if( input_stream.rdstate() == std::ios_base::eofbit ){
        std::cout << "eofibt" << '\n';
    }

    input_stream.close();

}
/**

goodbit
eofibt

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.


**/
