/// ios_base

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::ios_base::unsetf
/*

Such as std::ios_base::setf but unlike

UNsets the formation flags indentified by flags.

*/

int main() {
    {
        /// mine
        int i = 20;
        cout<<i<<endl;

        cout.setf(std::ios_base::hex);
        cout<<i<<endl;

    }
    {
        /// c plus plus reference had not got a sample.

    }
}





















