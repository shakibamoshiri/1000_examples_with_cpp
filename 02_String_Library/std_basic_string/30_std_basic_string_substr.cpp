#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::substr
/*

basic_string substr( size_type pos = 0, size_type count = npos ) const;

Returns a substring [pos, pos+count). If the requested substring extends past the end of the string, or if count == npos, the returned substring is [pos, size()).

Parameters
pos	-	position of the first character to include
count	-	length of the substring


Return value
An empty string if pos == size().
String containing the substring [pos, pos+count).


Exceptions
std::out_of_range if pos > size()
*/


int main() {
    std::basic_string<char> t = "abcefghmn1234567890";
    cout<<t<<endl;
    std::basic_string<char> s = t.substr(9);
    cout<<s<<endl;

    cout<<endl;
    cout<<t<<endl;
    s = t.substr(0,9);
    cout<<s<<endl;

    cout<<endl;
    cout<<t<<endl;
    s = t.substr(t.size()-3,100);
    cout<<s<<endl;
    {
        /// c plus plus reference

    std::string a = "0123456789abcdefghij";

    std::string sub1 = a.substr(10);
    std::cout << sub1 << '\n';

    std::string sub2 = a.substr(5, 3);
    std::cout << sub2 << '\n';

    std::string sub3 = a.substr(12, 100);
    std::cout << sub3 << '\n';

    std::string sub4 = a.substr(a.size()-3, 50);
    std::cout << sub4 << '\n';
}
}




















