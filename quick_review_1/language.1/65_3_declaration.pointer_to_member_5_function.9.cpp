/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// expression

#include <iostream>
#include <string>
#include <functional>

// #include <iomanip>





int main(){

    char& ( std::string::* fptr )( std::size_t ) = &std::string::at;

    std::string she( "how are you today." );

    // modifies the first letter
    ( she.*fptr )( 0 ) = 'H';

    // modifies the last letter
    ( she.*fptr )( she.size() - 1 ) = '?';

    std::cout << she;

}



/* output:


*/
