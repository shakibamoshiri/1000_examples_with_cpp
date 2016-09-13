/// Null-terminate string

/// 20_std::strcpy
/// definition in header < cstring >
/// string manipulation
/**
char* strcpy ( char* dest, cosnt char* stc );

Copies the character string pointed to by src, including the null
terminator, to the character array whose first element is pointed
to by dest. The behavior is undefined if the dest array is not large
enough. The behavior is undefined if the strings overlap.

Return Value:

**/

#include <iostream>
#include <memory>
#include <cstring>

int main(){
    { /// user sample:
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        const char* src = "Take the test.";
        /// src[0] = 'M'; cannot modify string literal
        auto dst = std::make_unique<char[]>(std::strlen(src)+1); /// +1 for the null
        std::strcpy(dst.get(), src);
        dst[0] = 'M';
        std::cout<<src <<"\n"<<dst.get()<<std::endl;
    }
}
















