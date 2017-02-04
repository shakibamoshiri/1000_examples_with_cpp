/*
            language 2
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********

            Algorithm
*/
///

#include <iostream>>
#include <vector>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;


int main(){

    std::string str1("./program --one 1 1 1 --two 2 2 2 --three 3 3 3");
    typedef std::vector< std::string > vector_of_string;

    vector_of_string all_command;
    split( all_command, str1, is_any_of("--"), token_compress_on );

    std::cout << all_command[ 0 ] << '\n';
    std::cout << all_command[ 1 ] << '\n';
    std::cout << all_command[ 2 ] << '\n';
    std::cout << all_command[ 3 ] << '\n';

}
