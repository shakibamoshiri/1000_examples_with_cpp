/// Null-terminate string

/// 10_std::isprint
/// definition in header < cctype >
/**
int isprint ( int ch );
///
Checks if is a printable character as classified by the currently
installed C locale. In the default, "C" locale. The following character
are printable:
digit 0-9
uppercase A-Z
lowercase a-z
punctuation ( !@# .. )
space ' '

///
Return Value:

///
**/

#include <iostream>
#include <cctype>
#include <clocale>

int main(){
    { /// user sample:
        unsigned char c = '\t';
        bool tc = std::isprint(c);
        std::cout<<"Does '\\t' is printable : "<<std::boolalpha<<tc<<std::endl;
        c = 's';
        tc = std::isprint(c);
        std::cout<<"Does ' ' is printable : "<<std::boolalpha<<tc<<std::endl;
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
    }
}
















