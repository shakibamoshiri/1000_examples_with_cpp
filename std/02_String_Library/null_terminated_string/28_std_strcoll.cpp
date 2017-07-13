/// Null-terminate string

/// 28_std::strcoll
/// definition in header < cstring >
/// string examination
/**
int strcoll ( const char* lhs, const char* rhs );

Compares two null-terminated byte strings according to
the current locale as defined by the LC_COLLATE category.

Return Value:

**/

#include <iostream>
#include <cstring>
#include <clocale>


int main(){
    { /// user sample:
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        std::setlocale(LC_COLLATE, "cs_SZ.ios88592");

        const char* s1 = "hrnec";
        const char* s2 = "chrt";
        std::cout<<"In the Czech locale; ";
        if ( std::strcoll(s1,s2) < 0)
            std::cout<<s1<<" before "<<s2<<std::endl;
        else
            std::cout<<s2<<" before "<<s1<<std::endl;

        std::cout<<"In lexicographical comparison: ";
        if (std::strcmp(s1,s2) < 0)
            std::cout<<s1<<" before "<<s2<<std::endl;
        else
            std::cout<<s2<<" before "<<s1<<std::endl;
    }
}
















