/*

A review of abstraction section from cplusplus.com

*/

/// basic_streambuf::pubseekoff
//  pos_type pubseekoff( off_type, ios_base::seekdir way, ios_base::openmode which = ios_base::in | ios_base::out )
//
//  Set internal position pointer to relative position

// note:
// Member seekoff does nothing in basic_streambuf, but derived classes shall override this
// behavior to alter the internal pointers appropriately: both basic_filebuf and
// basic_stringbuf override this virtual member function to set the internal pointer specified by
// which to a position offset off relative to the direction specified by way.

#include <iostream> // std::cout, std::ios
#include <fstream>



int main(){

    // get file size using pubseekoff

    std::ifstream input_file_stream( "file" );

//    std::streambuf* sb = input_file_stream.rdbuf();
    long size = input_file_stream.rdbuf()->pubseekoff( 0, input_file_stream.end );

    std::cout << size << '\n';
    input_file_stream.close();

}
/**

505

Process returned 0 (0x0)   execution time : 0.005 s
Press ENTER to continue.


**/
