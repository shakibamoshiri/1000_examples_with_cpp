/// ios_base

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::ios_base::setf
/*

The formating flags before the call to the function

*/

int main() {
    {
        /// c plus plus reference sample
        const double PI = 3.1415196535;
        const int WIDTH = 15;
        cout.setf(std::ios_base::right);
        cout<<std::setw(WIDTH/2)<<"radius"
            << std::setw(WIDTH) << "circumference"
            << endl;

        cout.setf(std::ios_base::fixed);
        for( double redius = 1; redius <= 6; redius+=0.5){
            cout<<std::setprecision(1) << std::setw(WIDTH/2)
                <<redius << std::setprecision(2) << std::setw(WIDTH)
                << (2 * PI * redius) <<endl;
        }
    }
    {
        /// mine

    }
}





















