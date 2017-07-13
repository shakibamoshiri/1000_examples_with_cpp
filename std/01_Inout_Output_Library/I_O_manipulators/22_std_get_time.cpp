/**
std::manipulators
c**/

/// 21_std::get_time
/**
Defined in header <iomanip>
template <class CharT>
|* unspecified *| get_time ( std::tm* tmb, const CharT* fmt);

When used in an expression in >> get_time( tmb, fmt ). parses the
character input as a date / time value according to format string
fmt according to the std::time_get facet of the locale currently
imbued in output stream out. The resultant value is stored in a
std::tm object pointed to by tmb.

NOTE
    As specified in std::time_get::do_get which this function
    calls, it's unspecified if this function zero out the flied
    in *tmb that are not set directly be the conversion specifiers
    that appear in fmt: portable programs should initialize every
    filed of *tmb to zero before calling std::get_time.

**/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <locale>

int main()
{
    {
        /// owner

    }
    {
        /// en.reference.com
        std::tm t = {};
        std::istringstream ss("2011-Februar-18 23:12:34");
        ss.imbue(std::locale("de_DE.utf-8"));
        ss >> std::get_time(&t, "%Y-%b-%d %H:%M:%S");
        if(ss.fail()){
            std::cout<<"Parse failed\n";
        }else{
            std::cout<<std::put_time(&t, "%c") <<std::endl;
        }
    }

    {
        /// cplusplus.com

    }

    {
        /// msdn.microsoft.com
    }

}
