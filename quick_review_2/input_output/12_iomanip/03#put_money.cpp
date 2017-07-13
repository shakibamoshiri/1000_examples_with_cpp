/*

A review of abstraction section from cplusplus.com

*/

/// iomanip
//  template< class moneyT >
//  /* unspecified */ put_money( const moneyT& mon, bool intl = false );
//
//  Puts monetary value.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <iomanip>  // input/output manipulators


int main(){

    std::cout << "price: " << std::put_money( 21.33 );

}
/**



**/
