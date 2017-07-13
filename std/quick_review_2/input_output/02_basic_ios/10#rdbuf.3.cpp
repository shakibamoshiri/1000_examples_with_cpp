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

    std::ifstream input_file_stream( "file" );

    std::streambuf* cout_rdbuf = std::cout.rdbuf();
    std::streambuf* file_rdbuf = input_file_stream.rdbuf();

    std::cout << file_rdbuf;

    puts( "-------------" );
    input_file_stream.clear();
    input_file_stream.seekg( 0, std::ios_base::beg );

    input_file_stream >> cout_rdbuf;


}
/**
All stream objects keep information on the state of the object internally.
This information can be retrieved as an element of this type by calling
member function basic_ios::rdstate or set by calling basic_ios::setstate.
-------------
All stream objects keep information on the state of the object internally.
This information can be retrieved as an element of this type by calling
member function basic_ios::rdstate or set by calling basic_ios::setstate.

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.



**/
