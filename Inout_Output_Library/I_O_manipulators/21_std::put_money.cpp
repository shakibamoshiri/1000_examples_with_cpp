/**
std::manipulators
c**/

/// 20_std::get_money
/**
Defined in header <iomanip>
template <class MoneyT>
|* unspecified *| put_money ( MoneyT& mon, bool inil = false );

When used in an expression out << put_money(mon, intl ), converts
the monetary value mon to tis character representation as specified
by the std::money_put facet of the locale currently imbued in out.
This function behaves as a FormattedOutputFunction.

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
    long double mon = 123.45; // or std::string mon = "123.45";
    std::cout.imbue(std::locale("en_US.utf8"));
    std::cout << std::showbase
              << "en_US: " << std::put_money(mon) << " or " << std::put_money(mon, true) << '\n';
    std::cout.imbue(std::locale("ru_RU.utf8"));
    std::cout << "ru_RU: " << std::put_money(mon) << " or " << std::put_money(mon, true) << '\n';
    std::cout.imbue(std::locale("ja_JP.utf8"));
    std::cout << "ja_JP: " << std::put_money(mon) << " or " << std::put_money(mon, true) << '\n';
    }

    {
        /// cplusplus.com

    }

    {
        /// msdn.microsoft.com
    }

}
