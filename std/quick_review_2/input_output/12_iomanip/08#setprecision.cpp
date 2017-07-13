/*

A review of abstraction section from cplusplus.com

*/

/// iomanip
// setprecision
// /*unspecified*/ setprecision (int n);
// Set decimal precision

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <iomanip>  // input/output manipulators



int main(){

    double f = 1.234567;

    std::cout << std::setprecision( 5 ) << f << '\n';
    std::cout << std::setprecision( 8 ) << f << '\n';

    std::cout << std::fixed;

    std::cout << std::setprecision( 5 ) << f << '\n';
    std::cout << std::setprecision( 15 ) << f << '\n';

}
/**

1.2346
1.234567
1.23457
1.234567000000000

Process returned 0 (0x0)   execution time : 0.009 s
Press ENTER to continue.

**/
