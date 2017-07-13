/*
        quick review string library
        ***************************

*/

#include <iostream>
#include <string>

// constructor

int main(){
    typedef std::basic_string<char> string;

    string str1 = "constructor one";
    string str2 ("constructor two");
    string str3 ("constructor three", 10);
    string str4 = string("constructor four");
    string str5 = str4;
    string str6 (str5);
    string str7 (10,'*');
    string str8 ({'s','t','r','8'});

    std::cout << str1 << str2 << str3
              << str4 << str5 << str6
              << str7 << str8 << std::endl;
}




