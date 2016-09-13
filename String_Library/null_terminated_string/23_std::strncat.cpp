/// Null-terminate string

/// 23_std::strncat
/// definition in header < cstring >
/// string manipulation
/**
char* strcat( char* dest, const char* src, std::size_t count );

Appends a copy of the character string pointed to by src to
the end of the character string pointed to by dest. the char
arcter src[0] replaces the null terminator at the end of dest.
The resulting byte string is null-terminated.
The behavior is undefined if the destination array is not large
enough for the contains of both src and dest and the terminating
null character.
The behavior is undefined if the strings overlap.

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
        char str[50] = "hello";
        char str2[50] = "world";
        std::strcat(str,str2);
        std::strncat(str, "Goodbye World!", 3);
        std::puts(str);
    }
}
















