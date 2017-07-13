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

    std::cout << 20 << '\n';

    std::cout.width( 10 );
    std::cout << 20 << '\n';

    std::cout.fill( '*' );  // set the asterisk as filled character
    std::cout.width( 15 );
    std::cout << std::left << 20 << '\n';

}
/**

20
        20
20*************

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.


**/
