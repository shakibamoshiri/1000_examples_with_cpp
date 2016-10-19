/**
std::basic_ios
**/

#include <iostream>
#include <sstream>
#include <locale>


/// std::basic_ios::widen
/**

char_type widen (char c ) const;

    Converts a character c to its equivalent in the current locale..
The result is converted from char to character type used within the
stream if needed.
    Effectively calls std::use_faces < std::ctype < char_type > (getloc()).widen(c);

**/

int main() {
    {
        /// mine : did not know


    }
    {
        /// the site sample
        /// NO sample in either site

    }
    { /// msdn.microsoft.com
        const char* s ("hello");
        std::cout<<s[0]<<std::endl;

        char w;
        w = std::cout.widen(s[0]);
        std::cout<<w<<std::endl;
    }

}












