/*

A review of abstraction section from cplusplus.com

*/

/// basic_streambuf::pubsync
//  int pubsync();
//
//  Synchronize stream buffer

// Return Value
// The default definition of sync in streambuf always returns zero, indicating success.
// Derived classes can override this default behavior, and eventually return -1 to indicate failure.

#include <iostream> // std::cout, std::ios
#include <fstream>
#include <unistd.h>



int main(){

    //

    std::ofstream output_file_stream( "file_2" );
    std::streambuf* sb_ptr = output_file_stream.rdbuf();

    sb_ptr->sputn( "how are you today?\n", 19 );
    sb_ptr->pubsync();                          // immediately flash to the file
    sleep( 5 );
    sb_ptr->sputn( "I an fine.\n", 11 );

    output_file_stream.close();

}
/**



**/
