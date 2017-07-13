/*

A review of abstraction section from cplusplus.com

*/

/// iomanip
//  template< class moneyT >
//  /* unspecified */ get_money( moneyT& mon, bool intl = false );
//
//  Gets monetary value

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <iomanip>  // input/output manipulators
#include <string>


int main(){

    long double price;
    std::cout << "Please enter the price: ";
    std::cin >> std::get_money( price );

    if( std::cin.fail() ) std::cout << "error: when reading price\n";
    else                  std::cout << "the entered price is: " << price << '\n';

}
/**
Please enter the price: 44
the entered price is: 44

Process returned 0 (0x0)   execution time : 1.335 s
Press ENTER to continue.


Please enter the price: 33 one two three
the entered price is: 33

Process returned 0 (0x0)   execution time : 7.177 s
Press ENTER to continue.

Please enter the price: one 22
error: when reading price

Process returned 0 (0x0)   execution time : 5.181 s
Press ENTER to continue.


**/
