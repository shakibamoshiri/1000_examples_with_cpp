/// Null-terminate string

/// 13_std::atof
/// definition in header < cctype >
/**
int atof ( const char* str );

Interprets an floating point value in a byte string pointed to by str.
Function discard any whitespace character ( as determined by std::isspace() )
until first non-whitespace character is found. Then it takes as many character
as possible to form a value floating point representation and converts them
to floating point value. The valid floating point value can be one of the
following :
...
,..
...


Return Value:
Non-zero value if the character is a punctuation character, zero otherwise.
**/

#include <iostream>
#include <cctype>
#include <clocale>

int main(){
    { /// user sample:
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        std::cout<<std::atof("0.0000000123") << std::endl
                 <<std::atof("0.023") <<std::endl
                 <<std::atof("15e13")<<std::endl
                 <<std::atof("-0x1fab-2") <<std::endl
                 <<std::atof("inF")<<std::endl
                 <<std::atof("Nam")<<std::endl;
    }
}
















