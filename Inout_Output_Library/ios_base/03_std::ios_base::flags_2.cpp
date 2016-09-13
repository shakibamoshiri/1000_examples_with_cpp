/// ios_base

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::
/*

*/

int main() {
    int i = 123;
    char c = 'f';
    cout<<i<<endl;
    cout.flags(std::ios_base::hex);
    cout<<i<<endl;

    cout.flags(std::ios_base::oct);
    cout<<i<<endl;

    cout.flags(std::ios_base::uppercase);
    cout<<c<<endl;

    bool b = false;
    cout.flags(std::ios_base::boolalpha);
    cout<<b<<endl;

    cout.flags(std::ios_base::showbase);
    cout<<i<<endl;

    double d = 1.23344565345;
    cout<<d<<endl;

    cout.flags(std::ios_base::showpoint  );
    cout<<d<<endl;

}





















