#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::operator_stream
/*
stream >> input
stream << output

*/



int main() {
    std::basic_string<char> s("hello, world");
    std::basic_istringstream<char> is(s); /// input string stream => istringstream
    std::string temp;
    is >> temp;
    cout<<temp<<endl;

    typedef std::basic_istringstream<char> iss;
    iss is2(s);
    is2 >> temp;
    cout<<temp<<endl;

    typedef std::basic_ostringstream<char> oss;
    oss os;
    os << s;
    cout<<os.str()<<endl;


}





















