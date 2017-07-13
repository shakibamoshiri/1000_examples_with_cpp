/*

A review of abstraction section from cplusplus.com

*/

/// basic_ios::good
//  bool good() const
//  Checks weather state or stream is good







#include <iostream> // std::cout, std::ios
#include <sstream>

void print_state( const std::ios& stream ){
    std::cout << "good-bit == " << stream.good() << '\n';
    std::cout << "eof      == " << stream.eof() << '\n';
    std::cout << "fail-bit == " << stream.fail() << '\n';
    std::cout << "bad-bit  == " << stream.bad() << '\n';
}

int main(){

    std::basic_ostringstream< char > oss;
    print_state( oss );
    puts ( "" );

    oss.clear( std::ios_base::goodbit );
    print_state( oss );
    puts( "" );

    oss.clear( std::ios_base::eofbit );
    print_state( oss );
    puts( "" );

    oss.clear( std::ios_base::failbit );
    print_state( oss );
    puts( "" );

    oss.clear( std::ios_base::badbit );
    print_state( oss );

}
/**

good-bit == 1
eof      == 0
fail-bit == 0
bad-bit  == 0

good-bit == 1
eof      == 0
fail-bit == 0
bad-bit  == 0

good-bit == 0
eof      == 1
fail-bit == 0
bad-bit  == 0

good-bit == 0
eof      == 0
fail-bit == 1
bad-bit  == 0

good-bit == 0
eof      == 0
fail-bit == 1
bad-bit  == 1

Process returned 0 (0x0)   execution time : 0.003 s
Press ENTER to continue.


**/
