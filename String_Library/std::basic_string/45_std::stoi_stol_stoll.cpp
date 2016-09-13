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
std::stoi, std::stol, std::stoll

Defined in header <string>
int       stoi( const std::string& str, std::size_t* pos = 0, int base = 10 );
int       stoi( const std::wstring& str, std::size_t* pos = 0, int base = 10 ); (1)	(since C++11)

long      stol( const std::string& str, std::size_t* pos = 0, int base = 10 );
long      stol( const std::wstring& str, std::size_t* pos = 0, int base = 10 ); (2)	(since C++11)

long long stoll( const std::string& str, std::size_t* pos = 0, int base = 10 );
long long stoll( const std::wstring& str, std::size_t* pos = 0, int base = 10 ); (3)	(since C++11)


Parameters
str	-	the string to convert
pos	-	address of an integer to store the number of characters processed
base	-	the number base


Return value
The string converted to the specified signed integer type.
*/

int main() {
    {
        ///int stoi( const std::string& str, std::size_t* pos = 0, int base = 10 );
        std::string i = "123";
        int ifistring = std::stoi(i,0,0); /// equivalent to int ifistring = std::stoi(i);
        cout<<ifistring<<endl;

        ///int stol( const std::string& str, std::size_t* pos = 0, int base = 10 );
        i = "2.14748e+09";
        ifistring = std::stol(i);
        cout<<ifistring<<endl;

        ///long long stoll( const std::string& str, std::size_t* pos = 0, int base = 10 );
        cout<<pow(pow(2,8),4)/2-1;

    }
    {
    std::string str1 = "45";
    std::string str2 = "3.14159";
    std::string str3 = "31337 with words";
    std::string str4 = "words and 2";

    int myint1 = std::stoi(str1);
    int myint2 = std::stoi(str2);
    int myint3 = std::stoi(str3);
    // error: 'std::invalid_argument'
    // int myint4 = std::stoi(str4);

    std::cout << "std::stoi(\"" << str1 << "\") is " << myint1 << '\n';
    std::cout << "std::stoi(\"" << str2 << "\") is " << myint2 << '\n';
    std::cout << "std::stoi(\"" << str3 << "\") is " << myint3 << '\n';
    //std::cout << "std::stoi(\"" << str4 << "\") is " << myint4 << '\n';

}





















