/// Null-terminate string

/// 27_std::strncom
/// definition in header < cstring >
/// string examination
/**
int strncmp ( const char* lhs, const char* rhs, size_t count );

Compares at most count character of two null-terminated byte string.
The comparison is done lexicographically. The sign of the result is
the sing of the first pair of character ( both interpret as unsigned
char ) that differ in the string being compared.
The behavior is undefined if lhs or rhs are not pointers to null-
terminated strings.

Return Value:
Negative value if lhs appears before rhs in lexicographical order.
Zero if lhs and rhs compares equal.
Positive value if lhs appears after rhs in lexicographical order.s
**/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

void demo(const char* lhs, const char* rhs, int sz)
{
    int rc = std::strncmp(lhs, rhs, sz);
    if(rc == 0)
        std::cout << "First " << sz << " chars of ["
                  << lhs << "] equal [" << rhs << "]\n";
    else if(rc < 0)
        std::cout << "First " << sz << " chars of ["
                  << lhs << "] precede [" << rhs << "]\n";
    else if(rc > 0)
        std::cout << "First " << sz << " chars of ["
                  << lhs << "] follow [" << rhs << "]\n";
}
int main(){
    { /// user sample:
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        demo("Hello, world!", "Hello, everybody!",13);
        demo("Hello, everybody!", "Hello, world!",13);
        demo("Hello, everybody!", "Hello, world!",7);
        demo("Hello, everybody!"+12,"Hello, somebody!"+11, 5);

    }
}
















