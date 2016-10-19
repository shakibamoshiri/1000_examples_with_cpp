/**
std::basic_ios
**/

#include <iostream>
#include <sstream>
#include <locale>


/// std::basic_ios::imbue
/**

std::locale imbue ( const std::locale& loc );

Replace the current locate. Effectively calls ios_base::imbue(loc) and if there is
    an associated stream buffer ( rdbuf () != 0 ), then calls rdbuf()->pubimbue(loc).
    an associated stream buffer ( rdbuf () != 0 ), then calls rdbuf()->pubimbue(loc).

**/

int main() {
    {
        /// mine : did not know

    }
    {
        /// the site sample
        std::basic_istringstream<char> iss;
        iss.imbue ( std::locale ("en_US.UTF8"));

        std::cout << "Current locale : " << iss.getloc().name() <<std::endl;

        iss.imbue(std::locale());
        std::cout<<"Global locale : "<<iss.getloc().name()<<std::endl;
    }

}












