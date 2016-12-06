/// Null-terminate string

/// 06_std::iscntrl
/// definition in header < cctype >
/**
int isgraph ( int ch );
///
Checks if the given character is graphic ( has a graphical representation )
as classified by the currently installed C locale. In the default C locale,
the following characters are graphic:
digit, 0-9
uppercase, A-Z
lowercase, a-z
punctuation, !@#$%^&*()./:;=+`[]{}|~?,<>

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
        unsigned char c = '?';
        bool tc = std::isgraph(c);
        std::cout<<"Does '?' is graphical : "<<std::boolalpha<<tc<<std::endl;
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
    }
}
















