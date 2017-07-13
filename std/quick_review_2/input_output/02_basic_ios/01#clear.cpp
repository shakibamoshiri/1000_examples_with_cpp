/*

A review of abstraction section from cplusplus.com

*/

/// basic_ios::clear
//  void clear( iostate state = goodbit )
//  Sets error state flags







#include <iostream> // std::cout, std::ios
#include <fstream>

int main(){

    std::basic_fstream< char > f_stream;
    f_stream.open( "file", std::ios_base::in ); // for reading a file not writing
    std::cout << ( f_stream.rdstate() == std::ios_base::goodbit ? "good-bit" : "fail-bit" ) << '\n';

    f_stream << "going to be sent to the file"; // set the error
    std::cout << ( f_stream.rdstate() == std::ios_base::goodbit ? "good-bit" : "fail-bit" ) << '\n';

    // the error, should be clear
    f_stream.clear();
    // or
    // f_stream.clear( std::ios_base::goodbit );
    char buffer[ 120 ]{};
    std::cout << ( f_stream.rdstate() == std::ios_base::goodbit ? "good-bit" : "fail-bit" ) << '\n';
    f_stream.getline( buffer, 120 );
    std::cout << buffer << '\n';

    f_stream.close();

}
/**

good-bit
fail-bit
good-bit
All stream objects keep information on the state of the object internally.

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.


**/
