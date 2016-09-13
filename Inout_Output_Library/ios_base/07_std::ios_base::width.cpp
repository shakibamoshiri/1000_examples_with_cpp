/// ios_base

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::ios_base::width
/*

1. streamsize width () const;
2. steamsize width ( streamseize new_width );

manage the minimum number of character to generate on certain output operation and
the maximum number of characters to generate on certain output operations.

1. Return the current field width.
2. Return the field width to the given one.

*/

int main() {
    {
        /// mine
        cout.widen(3);
        cout<<"hello"<<endl;
        /// cout.setf( std::ios_base::width(10)); Error
        cout.widen(100);
        cout<<"helloooooooooooooo"<<endl;
    }
    {
        /// the site no sample
    }
}





















