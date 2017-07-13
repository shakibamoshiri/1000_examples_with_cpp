/*

A review of abstraction section from cplusplus.com

*/

/// basic_ios::operator !
//  explicit operator !() const
//  Evaluate stream ( not )







#include <iostream> // std::cout, std::ios
#include <fstream>

std::ostream& operator << ( std::ostream& output, const std::ifstream& input_stream ){
    if( !input_stream ) {
        std::cout << "ERROR while reading the file\n";
    }
    return output;
}
// error: could not convert ‘input_stream’ from ‘const ifstream {aka const std::basic_ifstream<char>}’ to ‘bool’
int main(){

    std::basic_ifstream< char > input_file_stream( "nofile" );
    std::cout << input_file_stream;


}
/**

ERROR while reading the file

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.



**/
