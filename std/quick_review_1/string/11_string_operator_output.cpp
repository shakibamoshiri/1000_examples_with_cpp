/*
        quick review string library
        ***************************

*/

#include <iostream>
#include <string>
#include <sstream>

// operator >> and <<

int main(){
    typedef std::basic_string<char> string;

    typedef std::basic_ostringstream<char> oss;
    typedef std::basic_istringstream<char> iss;

    oss ostr;
    iss istr;

    ostr << "hard";
    ostr << " work";
    ostr << " pays";
    ostr << " off";

    string str;

    istr.str( ostr.str() );

    getline( istr, str);
    std::cout << str;   // hard work pays off

}




