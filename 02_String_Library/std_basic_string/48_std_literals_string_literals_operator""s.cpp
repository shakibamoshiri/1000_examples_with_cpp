#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::literals::string_literals::operator""s
/*
std::literals::string_literals::operator""s
C++  Strings library std::basic_string Defined in header <string>

string operator "" s(const char *str, std::size_t len);         (1)	(since C++14)
u16string operator "" s(const char16_t *str, std::size_t len);  (2)	(since C++14)
u32string operator "" s(const char32_t *str, std::size_t len);  (3)	(since C++14)
wstring operator "" s(const wchar_t *str, std::size_t len);     (4)	(since C++14)


*/

int main() {
    {
        /// string operator "" s(const char *str, std::size_t len);
        using namespace std::string_literals;
        std::string s1 = "abd\0ABC\0";
        std::string s2 = "abd\0ABC\0"s;
        std::string s3 = "abd\nABC\0";
        cout<<s1<<endl;
        cout<<s2<<endl;
        cout<<s3<<endl;

    }

}





















