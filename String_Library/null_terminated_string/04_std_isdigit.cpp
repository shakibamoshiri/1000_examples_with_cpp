/// Null-terminate string

/// 04_std::idigit
/// definition in header < cctype >
/**
int isdigit ( int ch );
/**

 Checks if the given character is one of the 10 digit: 0123456789.
 The behavior is undefined if the value of ch is not representable
 as unsigned char and is not equal to EOF.

**/

#include <iostream>
#include <cctype>
#include <clocale>

int main(){
    { /// user sample:
        char c = 'c';
        bool tc = std::isdigit(c);
        std::cout<<"does 'c' is digit ? "<<std::boolalpha << tc <<std::endl;
        c = '5'; /// character of digit
        tc = std::isdigit(c);
        std::cout<<"does 'i' is digit ? "<<std::boolalpha << tc <<std::endl;
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
    }
}
















