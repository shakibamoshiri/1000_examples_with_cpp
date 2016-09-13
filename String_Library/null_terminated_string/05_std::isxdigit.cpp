/// Null-terminate string

/// 05_std::isxdigit
/// definition in header < cctype >
/**
int isxdigit ( int ch );
///
Checks if the given wide character is a hexadecimal numeric character:
012345689abcdefABCDEF.

Note : isdigit and isxdigit are the only standard narrow character
classification function that are not affected by the currently C
locale. Although some implementations ( e.g Microsoft in 1252 codepage )
may classify additional single-byte character as digit.
///
**/

#include <iostream>
#include <cctype>
#include <clocale>

int main(){
    { /// user sample:
        char c = 'g';
        bool tc = std::isxdigit(c);
        std::cout<<"does 'g' is hex digit ? "<<std::boolalpha << tc <<std::endl;
        c = '5'; /// character of digit
        tc = std::isxdigit(c);
        std::cout<<"does '5' is hex digit ? "<<std::boolalpha << tc <<std::endl;
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
    }
}
















