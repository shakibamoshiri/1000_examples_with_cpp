/**

/// Expression
/// string literal
/// user-defined literals ( since c++11 )

Only the following parameter lists are allowed on literal operators :
( const char * ) 	(1)
( unsigned long long int ) 	(2)
( long double ) 	(3)
( char ) 	(4)
( wchar_t ) 	(5)
( char16_t ) 	(6)
( char32_t ) 	(7)
( const char * , std::size_t ) 	(8)
( const wchar_t * , std::size_t ) 	(9)
( const char16_t * , std::size_t ) 	(10)
( const char32_t * , std::size_t ) 	(11)


**/
#include <iostream>

/// user defined
//#include "temp.h"

// used as conversion
constexpr long double operator"" _deg(long double deg){
    return deg*3.141592/100;
}
// used with custom type
struct mytype {
    unsigned long long m;
    mytype ( unsigned long long m ) : m ( m ){}

};
mytype operator "" _mytype ( unsigned long long m ){
    return mytype(m);
}

// used for side-effects
void operator"" _print(const char* str){
    std::cout<<str;
}
int main(){
    double x = 90.0_deg;
    std::cout<<std::fixed<<x<<std::endl;

    mytype y = 123_mytype;
    std::cout<<y.m<<std::endl;

    0x123ABC_print;
}













