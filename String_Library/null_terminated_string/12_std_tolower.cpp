/// Null-terminate string

/// 12_std::tolower
/// definition in header < cctype >
/**
int tolower ( int ch );
Converts the given character to lowercase according to the character
conversion rules defined by the currently installed C locale.
In the default C locale, the following uppercase letters A-Z are
replaced with respective lowercase letters a-z.


Return Value:
Non-zero value if the character is a punctuation character, zero otherwise.
**/

#include <iostream>
#include <cctype>
#include <clocale>

int main(){
    { /// user sample:
        unsigned char c = 'D';
        std::cout<<"c before using std::tolower() : "<<c<<std::endl;
        char conc = std::tolower(c);
        std::cout<<"c after using std::tolower() : "<<conc<<std::endl;
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
    }
}
















