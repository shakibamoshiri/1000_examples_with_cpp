/**
std::basic_ios
**/

#include <iostream>
#include <sstream>
#include <locale>


/// std::basic_ios::narrow
/**

char narrow (char_type c, char default ) const ;

Converts a current locate-specific character to its standard equivalent.
    The result is converted from char_type to char if needed. If no ===
    conversion can be  performed. the function returned dfault.
Effectively calls std::use_facet < std::ctype < char_type > (getloc().narrow (c, dfault )

Parameter :
    c = character to convert
    dfault character to return id the conversion was unsuccessful

**/

int main() {
    {
        /// mine : did not know

    }
    {
        /// the site sample
        /// NO sample in either site
    }

}












