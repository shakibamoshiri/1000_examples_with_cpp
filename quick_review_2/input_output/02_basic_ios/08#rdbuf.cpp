/*

A review of abstraction section from cplusplus.com

*/

/// basic_ios::rdbuf
//  basic_streambuf< char_type, traits_type >* rdbuf() const;                                           // getter
//  basic_streambuf< char_type, traits_type >* rdbuf( basic_streambuf< char_type, traits_type >* sb );  // setter
//  Gets/Sets stream buffer
//
//  setter: returns a pointer to the stream buffer object currently associated with the stream
//  getter: sets the object pointed by 'sb' as the stream buffer associated with the stream and clear the error-state-flags


#include <iostream> // std::cout, std::ios
#include <fstream>


int main(){

    std::streambuf *bs_buffer, *bs_backup;
    std::ofstream output_stream( "file_3" );

    bs_backup = std::cout.rdbuf();          // back up cout's stream-buffer
    bs_buffer = output_stream.rdbuf();      // get file stream-buffer

    std::cout.rdbuf( bs_buffer );           // assigns the stream-file-buffer to cout

    std::cout << "this text is written to the file_3\n";

    std::cout.rdbuf( bs_backup );           // restore cout's to original buffer
    std::cout << "to the screen\n";
    output_stream.close();

}
/**

to the screen

Process returned 0 (0x0)   execution time : 0.019 s
Press ENTER to continue.



**/
