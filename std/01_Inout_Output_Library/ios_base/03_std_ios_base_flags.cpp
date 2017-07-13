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

    /// Using fmtflag as class member constants:
    int number = 150;
    cout.setf(std::ios_base::hex, std::ios_base::basefield);
    cout.setf(std::ios_base::showbase);
    cout<<number<<endl;

    /// Using fmtflag as inherited class member constants:
    cout.setf(std::ios::hex, std::ios::basefield);
    cout.setf(std::cout.showbase);
    cout<<number<<endl;

    /// Using fmtflag as object member constants:
    cout.setf(cout.hex, cout.basefield);
    cout.setf(cout.showbase);
    cout<<number<<endl;

    /// Using fmtflags as a type:
    std::ios::fmtflags ff;
    ff = cout.flags();
    ff &= ~cout.basefield;
    ff |= cout.hex;
    ff |= cout.showbase;
    cout.flags(ff);
    cout<<number<<endl;


}





















