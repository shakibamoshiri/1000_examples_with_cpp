/*

A review of abstraction section from cplusplus.com

*/

/// basic_ios::tie
//  basic_ostream< char_type, traits_type >* tie() const;                                       // getter
//  basic_ostream< char_type, traits_type >* tie( basic_ostream<char_type, traits_type>* sb );  // setter
//
// Gets/Sets tied stream

#include <iostream> // std::cout, std::ios
#include <fstream>
#include <unistd.h>


int main(){

    std::ofstream output_stream( "file_4" );
    std::ifstream input_stream( "file_4" );
    input_stream.tie( &output_stream );

    std::string line;
    for( int count = 0; count < 20; ++count ){
        output_stream << "line: " << count << '\n';
        std::getline( input_stream, line );
        std::cout << line << '\n';
        sleep( 1 );
    }

    input_stream.close();
    output_stream.close();

}
/**

line: 0
line: 1
line: 2
line: 3
line: 4
line: 5
line: 6
line: 7
line: 8
line: 9
line: 10
line: 11
line: 12
line: 13
line: 14
line: 15
line: 16
line: 17
line: 18
line: 19

Process returned 0 (0x0)   execution time : 20.014 s
Press ENTER to continue.


**/
