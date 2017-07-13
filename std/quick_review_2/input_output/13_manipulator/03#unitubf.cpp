/*

A review of abstraction section from cplusplus.com

*/

/// manipulator :: unitbuf
//  ios_base unitbuf( ios_base& str )
//
//  Flushes buffer after insertions.

#include <iostream>
#include <fstream>

int main(){

    std::ofstream output_file( "file_1" );

    output_file << "go" << " to" << " the file_1" << '\n';  // flushes 4 times

    output_file.close();

}
/**



**/
