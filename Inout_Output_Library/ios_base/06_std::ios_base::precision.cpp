/// ios_base

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::ios_base::imbue
/*
std::locale imbue ( const std::locale& loc);


*/

int main() {
    {
        /// mine

    }
    {
        /// the site no sample
        const double d(3.343445567645);
        cout<<cout.precision()<<endl;
        cout<<d<<endl;
        cout.precision(10);
        cout<<d<<endl;
    }
}





















