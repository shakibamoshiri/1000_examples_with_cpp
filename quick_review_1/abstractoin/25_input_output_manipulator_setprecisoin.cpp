/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <iomanip>
#include <sstream>



int main(){
    double d1, d2, d3;
    std::istringstream ("2.2323343455 3.333333333333 4.44444444444444") >> d1 >> d2 >> d3;

    std::cout << d1 << ' ' << d2 << ' ' << d3 << std::endl;

    std::cout << std::setprecision(10) << d1 << ' ' << d2 << ' ' << d3 << std::endl;

    std::cout << std::setprecision(15) << d1 << ' ' << d2 << ' ' << d3 << std::endl;

}
