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



int main(){

    std::ofstream ofs;  // output-file-stream
    ofs.open( "file_5" );

    std::cout << "tie example:\n";
    *std::cin.tie() << "This is inserted into std::cout\n";

    std::cin.tie( &ofs );   // tie to the output-file_stream
    *std::cin.tie() << "This is inserted into the file by *std::cin.tie()\n";

    ofs.close();


}
/**

tie example:
This is inserted into std::cout

Process returned 0 (0x0)   execution time : 0.021 s
Press ENTER to continue.



**/
