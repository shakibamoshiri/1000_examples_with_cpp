/// Null-terminate string

/// 15_std::atoi_atol_atoll
/// definition in header < cstdio >
/**
int atoi ( const char* str );
long atol ( const char* str );
long long atoll ( const char* str );

Interprets an integer value in a byte string pointed to by str.
Discard any whitespace character until the first non-whitespace
character is found, then takes as many character as possible to
form a value integer number representation and converts them to
integer value. The valid integer value consist of the following
parts:
    -(optional) plus or minus sign
    - numeric digit


Return Value:

**/

#include <iostream>
#include <cstdio>

int main(){
    { /// user sample:
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        const char* s1 = "34";
        const char* s2  = "2.346656";
        const char* s3 = " 34334 with words";
        const char* s4 = " word and 4";

        int i1 = std::stoi(s1);
        int i2 = std::stoi(s2);
        int i3 = std::atoi(s3);
        int i4 = std::atoi(s4);

        std::cout<<"the result of std::atoi() s1,s2,s3,s4 :"
                 <<i1<<' '<<i2<<' '<<i3<<' '<<i4<<std::endl;
    }
}
















