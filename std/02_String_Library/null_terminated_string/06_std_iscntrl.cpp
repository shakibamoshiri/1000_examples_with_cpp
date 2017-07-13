/// Null-terminate string

/// 06_std::iscntrl
/// definition in header < cctype >
/**
int iscntrl ( int ch );
///
Checks if the given character is a control character as classified by
the currently installed C locale. In the default, C locale, the control
character are the character with the codes 0x00-0x1F and 0x7F

///
Return Value:
Non-zero value if the character is a control character, zero otherwise.
///
**/

#include <iostream>
#include <cctype>
#include <clocale>

int main(){
    { /// user sample:
        char c = '0x7F';
        char d = '0x1F';
        std::cout<<(int)c <<' '<<(int )d<<std::endl;
        std::cout<<c <<' '<<d<<std::endl;

    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
    }
}
















