/*

A review of abstraction section from cplusplus.com

*/

/// ios_base::width
//
//  streamsize width() const;               // getter
//  streamsize width( streamsize wide );    // setter


#include <iostream> // std::cout, std::ios

int main(){
    // field width

    std::cout.fill( '*' );  // set the asterisk as filled character
    for( int index = 0; index < 15; ++index ){
        std::cout.width( index );
        std::cout << "Test " << std::left << '\n';
    }

}
/**

Test
Test
Test
Test
Test
Test
Test *
Test **
Test ***
Test ****
Test *****
Test ******
Test *******
Test ********
Test *********

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.



**/
