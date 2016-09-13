/// Null-terminate string

/// 26_std::strcmp
/// definition in header < cstring >
/// string examination
/**
int strcmp ( const char* lhs, const char* rhs);

Compares two null-terminated byte strings lexicographically.
The sign of the result is the sign of the different between
the values of the first pair of character ( both interpreted
as unsigned char ) that differ in the strings being compared.
The behavior is undefined is lhs or rhs are not pointers to
null-terminated strings.

Return Value:
Negative value if lhs appears before rhs in lexicographical order.
Zero if lhs and rsh compare equal
Positive value if lhs appears after rhs in lexicographical order.
**/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

int main(){
    { /// user sample:
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        std::vector<const char*> cats {"Healthciff", "Snagglepuss","Hobbes","Garfield"};
        std::sort(cats.begin(), cats.end(),
                  [] (const char* strA, const char* strB )
                  {return std::strcmp(strA,strB) < 0;});
        for (const char* cat : cats ){
            std::cout<<cat<<std::endl;
        }
    }
}
















