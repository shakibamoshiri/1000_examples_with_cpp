/// Null-terminate string

/// 12_std::toupper
/// definition in header < cctype >
/**
int toupper ( int ch );

Converts the given character to uppercase according to the character
conversation rules defined by the currently installed C locale. In the
C locale, the following lowercase letters a to z are replaced with
respective uppercase letters A to B.

Return Value:
Non-zero value if the character is a punctuation character, zero otherwise.
**/

#include <iostream>
#include <cctype>
#include <clocale>

int main(){
    { /// user sample:
        unsigned char c = 'd';
        std::cout<<"c before using std::tolower() : "<<c<<std::endl;
        char conc = std::toupper(c);
        std::cout<<"c after using std::tolower() : "<<conc<<std::endl;
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
    }
}
















