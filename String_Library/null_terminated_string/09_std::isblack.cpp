/// Null-terminate string

/// 09_std::isblack
/// definition in header < cctype >
/**
int issapce ( int ch );
///
Checks if the given character is a black character as classified
by the currently installed C locale. Black character are whitespace
character used to separate words within a sentence, In the default
C locale, only space ( 0x20 ) and horizontal tab ( 0x09 ) are
classified as black character

///
Return Value:

///
**/

#include <iostream>
#include <cctype>
#include <clocale>

int main(){
    { /// user sample:
        unsigned char c = '_';
        bool tc = std::isblank(c);
        std::cout<<"Does '?' is graphical : "<<std::boolalpha<<tc<<std::endl;
        c = ' ';
        tc = std::isblank(c);
        std::cout<<"Does '?' is graphical : "<<std::boolalpha<<tc<<std::endl;
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
    }
}
















