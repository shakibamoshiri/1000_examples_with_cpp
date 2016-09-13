/**
std::manipulators
c**/

/// 22_std::put_time
/**
Defined in header <iomanip>
template <class CharT>
|* unspecified *| get_time ( std::tm* tmb, const CharT* fmt);

When used in an expression out << put_time(tmb, fmt),converts the
date and time information from a given character time tmb to a
character string according to format string fmt, as if by calling
std::strftime, std::wcsftime, or analog( depending or CharT),according
to the std::time_put facet of the locale currently imbued in the output
stream out.
**/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <locale>
#include <ctime>

int main()
{
    {
        /// owner

    }
    {
        /// en.reference.com
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);
        std::cout.imbue(std::locale("ru_RU.utf8"));
        std::cout<<"ru_RU: "<<std::put_time(&tm, "%c %Z")<<std::endl;
        std::cout.imbue(std::locale("ja_JP.utf8"));
        std::cout<<"ja_JP: "<<std::put_time(&tm, "%c %Z")<<std::endl;
    }

    {
        /// cplusplus.com

    }

    {
        /// msdn.microsoft.com
    }

}
