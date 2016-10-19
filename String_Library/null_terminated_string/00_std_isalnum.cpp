/// Null-terminate string

/// 00_std::isalnum
/// definition in header < cctype >
/**

Checks if the given character is an alphanumeric character as classified
by the current C locate. In the default locate, the following character
are alphanumeric :
digit           : 0123456789
upper letters:  : ABCDEFGHIJKLMNOPQRSTXWZ
lower letters:  : abcdefghjiklmnopqrstxyz

The behavior is undefined if the value of ch is not representable as
unsigned char and is not equal to EOF.

**/

#include <iostream>
#include <cctype>
#include <clocale>

int main(){
    { /// user sample:
        unsigned char c = '';
        std::cout<<c<<std::endl;
        std::cout<<"char c is an alphanumeric: "<<std::isalnum(c)<<std::endl;
    }
    { /// sample of en.reference.com
        unsigned char c = '\xdf'; /// German letter ''' in ISO-8859-1
        std::cout<<"isalnum (\'\\xdf\', default C locale) returned: "
                 <<std::boolalpha << (bool) std::isalnum(c) << '\n';
        std::setlocale(LC_ALL, "de_DE.iso88591");
        std::cout<<"isalnum (\'\\xdf\', default C locale) returned: "
                 <<std::boolalpha << (bool) std::isalnum(c) << '\n';
    }
}
















