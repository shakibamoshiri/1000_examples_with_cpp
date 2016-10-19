/// Null-terminate string

/// 25_std::strlen
/// definition in header < cstring >
/// string examination
/**
std::size_t strlen ( const char* str );

Returns the length of the given byte string, that is the number
of character in a character array whose first element is pointed
to by str up to end not including that first null character. The
behavior is undefined if there is not null character in the character
array pointed to by str.

Return Value:

**/

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

int main(){
    { /// user sample:
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        const char str[] = "How many character does this string contain ?";
        std::cout<<"without null character: "<<std::strlen(str)<<std::endl
                 <<"with null character   : "<<sizeof str<<std::endl;
    }
}
















