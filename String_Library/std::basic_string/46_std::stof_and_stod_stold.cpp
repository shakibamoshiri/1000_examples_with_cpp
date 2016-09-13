#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::stoi and stol and stoll
/*
std::stof, std::stod, std::stold
  C++  Strings library std::basic_string
Defined in header <string>
float       stof( const std::string& str, std::size_t* pos = 0 );
float       stof( const std::wstring& str, std::size_t* pos = 0 ); (1)	(since C++11)

double      stod( const std::string& str, std::size_t* pos = 0 );
double      stod( const std::wstring& str, std::size_t* pos = 0 ); (2)	(since C++11)

long double stold( const std::string& str, std::size_t* pos = 0 );
long double stold( const std::wstring& str, std::size_t* pos = 0 ); (3)	(since C++11)

Interprets a floating point value in a string str.
1) calls std::strtod(str.c_str(), &ptr) or std::wcstod(str.c_str(), &ptr) (until C++17)

1) calls std::strtof(str.c_str(), &ptr) or std::wcstof(str.c_str(), &ptr)(since C++17)

2) calls std::strtod(str.c_str(), &ptr) or std::wcstod(str.c_str(), &ptr)
3) calls std::strtold(str.c_str(), &ptr) or std::wcstold(str.c_str(), &ptr)

Parameters
str	-	the string to convert
pos	-	address of an integer to store the number of characters processed

Return value
The string converted to the specified floating point type.
*/

int main() {
    {
        ///float stof( const std::string& str, std::size_t* pos = 0 );
        std::string f = "3.14";
        float fffs = std::stof(f);
        cout<<fffs<<endl;

        ///double stod( const std::string& str, std::size_t* pos = 0 );
        f = "5.454545454545";
        double dffs = std::stod(f);
        cout<<dffs<<endl;
        ///long double stold( const std::string& str, std::size_t* pos = 0 );

    }
}





















