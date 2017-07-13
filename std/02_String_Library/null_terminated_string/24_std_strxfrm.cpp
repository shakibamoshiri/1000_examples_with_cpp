/// Null-terminate string

/// 24_std::strxfrm
/// definition in header < cstring >
/// string manipulation
/**
std::size_t strxfrm (char* dest, const char* src, std::size_t count );

Transforms the null-terminated byte string pointed to by src into
the implementation-defined form such that comparing two transformed
string with std::strcmp gives the same result as comparing the
original strings with std::strcoll, in the current C locale.
The first count character of the transformed string are writing
to destination, including the terminating null character, and the
length of the null transformed string is returned, excluding the
terminating null character. If count is 0, then dest is allowed
to be a null pointer.

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
        std::setlocale(LC_COLLATE, "cs_CZ.iso88592");

        std::string in1("hrnec");
        std::string out1(1+std::strxfrm(nullptr,in1.c_str(), 0),' ');
        std::string in2("chrt");
        std::string out2(1+std::strxfrm(nullptr, in2.c_str(), 0), ' ');

        std::strxfrm(&out1[0],in1.c_str(), out1.size());
        std::strxfrm(&out2[0],in2.c_str(), out2.size());

        std::cout<<"In the Czech locale: ";
        if (out1 < out2)
            std::cout<<in1 <<" before " <<in2 <<std::endl;
        else
            std::cout<<in2<<" before "<<in1 <<std::endl;

        std::cout<<"In lexicographical comparison: ";
        if (in1 < in2 )
            std::cout<<in1 <<" before "<< in2 <<std::endl;
        else
            std::cout<<in2<<" before "<<in2<<std::endl;

    }
}
















