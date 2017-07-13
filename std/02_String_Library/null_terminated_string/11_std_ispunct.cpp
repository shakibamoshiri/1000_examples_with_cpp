/// Null-terminate string

/// 10_std::ispunct
/// definition in header < cctype >
/**
int ispucnt ( int ch );
///
Checks if the given character is a punctuation character as classified
by the current C locale. The default C locale classifies the character
!@#$%^&*()_+,./\:;'"[]{}\`| as punctuation.
///
Return Value:
Non-zero value if the character is a punctuation character, zero otherwise.
///
**/

#include <iostream>
#include <cctype>
#include <clocale>

int main(){
    { /// user sample:
        unsigned char c = 'd';
        bool tc = std::ispunct(c);
        std::cout<<"Does '\\t' is punctuation : "<<std::boolalpha<<tc<<std::endl;
        c = '!';
        tc = std::ispunct(c);
        std::cout<<"Does ' ' is punctuation : "<<std::boolalpha<<tc<<std::endl;
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
    }
}
















