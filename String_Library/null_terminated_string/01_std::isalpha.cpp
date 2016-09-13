/// Null-terminate string

/// 01_std::isalpha
/// definition in header < cctype >
/**
int isalpha( int ch);
/**
Checks if the given character is an alphabetic character as classified
by the currently installed C locate. In the default locate, the following
character are alphabetic:

Uppercase letters:  ABCDEFGHJIOLKMNPQRSTXYZ
Lowercase letters:  abcdefghjiolkmnpqrstxzy

In locales other than "C", an alphabetic character is a character for
which std::isupper() or std::islower() returns non-zero or any other
character considered alphabetic by the locate. In any case, std::iscutrl(),
std::isdigit() and std::issapce() will returns zero for this character.
The behavior is undefined if the value of ch is not representable as
unsigned char and is not equal to EOF.
**/

#include <iostream>
#include <cctype>
#include <clocale>

int main(){
    { /// user sample:
        unsigned int c = 34;
        std::cout<<c<<std::endl;
        std::cout<<"char c is an alphanumeric: "<<std::isalpha(c)<<std::endl;
    }
    { /// sample of en.reference.com
        unsigned char c = '\xdf'; /// German letter ''' in ISO-8859-1
        std::cout<<"isalnum (\'\\xdf\', default C locale) returned: "
                 <<std::boolalpha << (bool) std::isalpha(c) << '\n';
        std::setlocale(LC_ALL, "de_DE.iso88591");
        std::cout<<"isalnum (\'\\xdf\', default C locale) returned: "
                 <<std::boolalpha << (bool) std::isalpha(c) << '\n';
    }
}
















