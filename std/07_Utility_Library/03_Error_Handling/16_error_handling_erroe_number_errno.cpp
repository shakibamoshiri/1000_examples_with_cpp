/*
            Error Handling
            **************

3.  Error Number (defined in header <cerrno>)

        > errno                     : macro which expends to POSIX-compatible thread-local error number variable
        > E2BIG, EACCES, ..., EXDEV : macros for standard POSIX-compatible error conditions

*/
/// errno


#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <clocale>


int main(){

    double not_a_number = std::log( -1.0 );

    if (errno == EDOM){

        std::cout << "log( -1.0 ) failed. " << std::strerror( errno ) << '\n';
        std::setlocale( LC_MESSAGES, "de_DE.utf8" );
        std::cout << "Or / in German, " << std::strerror( errno ) << '\n';

    }

}
