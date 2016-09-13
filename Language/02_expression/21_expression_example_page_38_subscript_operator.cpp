///
/// Expression
///
///
///
///

/**
**/
#include <iostream>
#include <string>
#include <cassert>
/// user defined
//#include "temp.h"


int main(){
    int arr[4] {1, 2, 3, 4};
    int* p = &arr[2];
    std::cout<<p[1]<<'\n'
            <<p[-1]<<'\n'
            <<1[p]<<'\n'
            <<-1[p]<<'\n'
            <<(-1)[p]<<'\n';
}

