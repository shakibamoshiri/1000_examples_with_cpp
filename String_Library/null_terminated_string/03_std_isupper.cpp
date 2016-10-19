/// Null-terminate string

/// 03_std::isupper
/// definition in header < cctype >
/**
int isupper ( int ch );
/**

Checks if the given character is an uppercase character as classified
by the currently installed C locale. In the default "C" locale, isupper
returns true only for the uppercase letters: ABCDEFGHJIOMNKLPQRSTXYZ.
If isupper returns true, it is guaranteed that incntrl, isdigit, isputct,
and isspace return false for the same character in the smae C locale.
The behavior is undefined if the value of ch is not representable as
unsigned char and is not equal to EOF.

**/

#include <iostream>
#include <cctype>
#include <clocale>

int main(){
    { /// user sample:
        char c = 'C';
        std::cout<<"char c: "<<c<<std::endl;
        bool testc = isupper(c);
        std::cout<<"char c, does is lowercase ? "<<std::boolalpha<<testc<<std::endl;
        c = 'c';
        testc = isupper(c);
        std::cout<<"char c, does is lowercase ? "<<std::boolalpha<<testc<<std::endl;
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
    }
}
















