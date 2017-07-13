/// Null-terminate string

/// 08_std::issapce
/// definition in header < cctype >
/**
int issapce ( int ch );
///
Checks if the given character is a whitespace character as classified
by the currently installed C locale. In the default locale, the whitespace
character are the following:
-   space (0x20, ' ')
-   form feed (0x0c, '\f')
-   line feed (0x0a, '\n')
-   carriage return (0x0d, '\r')
-   horizontal tab (0x09, '\t')
-   vertical tab (0x0b, '\v')

///
Return Value:

///
**/

#include <iostream>
#include <cctype>
#include <clocale>

int main(){
    { /// user sample:
        unsigned char c = '?';
        bool tc = std::isspace(c);
        std::cout<<"Does '?' is graphical : "<<std::boolalpha<<tc<<std::endl;
        c = ' ';
        tc = std::isspace(c);
        std::cout<<"Does '?' is graphical : "<<std::boolalpha<<tc<<std::endl;
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
    }
}
















