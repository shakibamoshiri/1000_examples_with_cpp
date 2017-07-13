/*

A review of abstraction section from cplusplus.com

*/

/// ios_base::precision
//  streamsize precision() count;               // getter
//  streamsize precision( streamsize pre );     // setter
//
//  Gets/Sets floating-point decimal precision
#include <iostream>


int main(){
    // modify precision

    double f = 1.234567;
    std::cout.unsetf( std::ios::floatfield );        // float filed not set
    std::cout.precision( 4 );                       // set the precision
    std::cout << f << '\n';

    std::cout.precision( 10 );
    std::cout << f << '\n';

    std::cout.setf( std::ios::fixed , std::ios::floatfield );   // float filed sets to fix
    std::cout << f << '\n';

}
/**

1.235
1.234567
1.2345670000

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.




**/
