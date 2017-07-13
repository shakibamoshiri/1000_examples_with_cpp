/*

A review of abstraction section from cplusplus.com

*/
/// ios

#include <iostream>
#include <locale>

int main(){
    // imbue example
    std::locale here( "" );
    std::cout.imbue( here );
    std::cout << 3.3232 << '\n';

}
/**
3.3232

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.
-----------------------------------------------------------------------------------------------
This code writes a floating point number using the global locale given by the environment. For
example, in a system configured with a Spanish locale as default, this could write the number using
a comma decimal separator:
3,14159

**/
