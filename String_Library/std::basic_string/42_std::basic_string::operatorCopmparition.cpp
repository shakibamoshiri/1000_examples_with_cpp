#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::compare_operator
/*
==
!=
<
>
<=
>=

*/



int main() {
    std::string s1 ("hello");
    std::string s2 ("hello");
    std::string d1 ("world");
    std::string d2 ("world!");

    if(s1 == s2) cout<<"s1 == s2"<<endl;
    if(s1 != d1) cout<<"s1 != d1"<<endl;
    if(s1 < d1) cout<<"s1 < s2"<<endl;
    if(d1 > s1) cout<<"d1 > s1"<<endl;
    if(d2 >= d1) cout<<"d2 >= d1"<<endl;
    if(d1 <= d2) cout<<"d1 <= d2"<<endl;
}





















