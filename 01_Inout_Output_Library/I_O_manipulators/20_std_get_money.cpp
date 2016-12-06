/**
std::manipulators
c**/

/// 20_std::get_money
/**
Defined in header <iomanip>
template <class MoneyT>
|* unspecified *| get_money ( MoneyT& mon, bool inil = false );

When used in an expression in >> get_money (mon, intl ), parses the
character input as a monetary value, as specified by the std::money_get
faced of the locate currently imbued in in, and stores the value in mon.
This function behaves as a FormattedInputFunction.
**/
#include <iostream>
#include <iomanip>
#include <sstream>

int main()
{
    {
        /// owner

    }
    {
        /// en.reference.com
        std::basic_istringstream<char> in("$1,234.56 2.22 USD  3.33");
        long double v1,v2;
        std::string v3;
        in.imbue(std::locale("en_US.UTF-8"));
        in >> std::get_money(v1) >> std::get_money(v2) >> std::get_money(v3,true);

        if (in){
            std::cout<<std::quoted(in.str()) << " Parsed as: "
                     <<v1<<", "<<v2<<", "<<v3<<std::endl;
        }
        else{
            std::cout<<"Parse failed";
        }
    }

    {
        /// cplusplus.com

    }

    {
        /// msdn.microsoft.com
    }

}
