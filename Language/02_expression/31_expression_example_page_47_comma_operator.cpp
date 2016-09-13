///
/// Expression
///

/**

**/
#include <iostream>
#include <string>
#include <cstdio>
/// user defined
//#include "temp.h"

int main(){
    int n =1;
    int m = (++n, std::cout<<"n = "<<n<<std::endl, ++n, 2*n);
    /// first:      ++n
    /// second:     std::cout
    /// third       ++n
    /// fourth      2*n
    /// now n = 6
    /// therefore m = 6

    std::cout<<"m = "<<(++m, m)<<std::endl;
    /// first       std::cout
    /// second      ++m
    /// third       std::cout<<m
    /// now m = 7
    /// therefore std:;cout<<m = 7
}

