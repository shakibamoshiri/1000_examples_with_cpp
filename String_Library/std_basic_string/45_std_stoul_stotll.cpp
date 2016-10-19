#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::stoul, std::stoull
/*

Defined in header <string>
unsigned long      stoul( const std::string& str, std::size_t* pos = 0, int base = 10 );
unsigned long      stoul( const std::wstring& str, std::size_t* pos = 0, int base = 10 );(1)	(since C++11)

unsigned long long stoull( const std::string& str, std::size_t* pos = 0, int base = 10 );
unsigned long long stoull( const std::wstring& str, std::size_t* pos = 0, int base = 10 );(2)	(since C++11)

Parameters
str	-	the string to convert
pos	-	address of an integer to store the number of characters processed
base	-	the number base

Return value
The string converted to the specified unsigned integer type.

Exceptions
std::invalid_argument if no conversion could be performed
std::out_of_range if the converted value would fall out of the range of the result type or if the underlying function
(std::strtoul or std::strtoull) sets errno to ERANGE.
*/

int main() {
    {
        /// unsigned long      stoul( const std::string& str, std::size_t* pos = 0, int base = 10 );

        /// unsigned long long stoull( const std::string& str, std::size_t* pos = 0, int base = 10 );
    }

}





















