#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::operator+
/*


*/



int main() {
    std::string s1("one");
    std::string s2(" two");
    cout<<s1 + s2<<endl;
    cout<<s1 + " + two [char*]"<<endl;
    cout<<"one [char*] + " + s2<<endl;
    cout<<std::string("string without object1") + std::string(" + string without object2")<<endl;
    cout<<s1.at(2) + s2.at(2)<<endl;
    std::string s3 = s1.substr(2) + s2.substr(3);
    cout<<s3<<endl;
}





















