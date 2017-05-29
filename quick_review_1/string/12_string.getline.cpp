/*
        quick review string library
        ***************************

*/

#include <iostream>
#include <string>
#include <sstream>

// getline

int main(){
    typedef std::basic_string<char> string;

    typedef std::basic_ostringstream<char> oss;
    typedef std::basic_istringstream<char> iss;

    oss ostring;
    iss istring;

    ostring << "2" << std::endl << 4 << '\n' << " 6 " << "\n" << 8 << std::endl;

    istring.str( ostring.str() );

    int sum = 0;
    string line = "";
    while( getline( istring, line) ) sum += std::stoi(line);

    std::cout << sum << std::endl; // 20 == ( 2 + 4 + 6 + 8 )
}




