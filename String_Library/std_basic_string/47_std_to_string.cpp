#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::to_string
/*
std::to_string

std::string to_string( int value );                 (1)	(since C++11)
std::string to_string( long value );                (2)	(since C++11)
std::string to_string( long long value );           (3)	(since C++11)
std::string to_string( unsigned value );            (4)	(since C++11)
std::string to_string( unsigned long value );       (5)	(since C++11)
std::string to_string( unsigned long long value );  (6)	(since C++11)
std::string to_string( float value );               (7)	(since C++11)
std::string to_string( double value );              (8)	(since C++11)
std::string to_string( long double value );         (9)	(since C++11)

Parameters
value	-	a numeric value to convert
Return value
a string holding the converted value
Notes
std::to_string may yield unexpected results when used with floating point types and
the return values may be substantially different from what std::cout would print, see the example.

*/

int main() {
    {
        int i = 154;
        std::string is = std::to_string (i);
        cout<<is<<endl;
    }
    {
    double f = 23.43;
    double f2 = 1e-9;
    double f3 = 1e40;
    double f4 = 1e-40;
    std::string f_str = std::to_string(f);
    std::string f_str2 = std::to_string(f2); // Note: returns "0.000000"
    std::string f_str3 = std::to_string(f3); // Note: Does not return "1e+40".
    std::string f_str4 = std::to_string(f4); // Note: returns "0.000000"
    std::cout << "std::cout: " << f << '\n'
              << "to_string: " << f_str  << '\n' << '\n'
              << "std::cout: " << f2 << '\n'
              << "to_string: " << f_str2 << '\n' << '\n'
              << "std::cout: " << f3 << '\n'
              << "to_string: " << f_str3 << '\n' << '\n'
              << "std::cout: " << f4 << '\n'
              << "to_string: " << f_str4 << '\n';
    }
}





















