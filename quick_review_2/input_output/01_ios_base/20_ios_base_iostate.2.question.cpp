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

    std::fstream input_stream( "file" );
    std::cout << input_stream.rdstate() << '\n';        // 4 == that means failbit
    // why at he beginning of an input stream the io-flags of the stream sets to failbit?

}
/**




**/
