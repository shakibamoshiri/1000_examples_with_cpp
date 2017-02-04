/*
        quick review containers library
        *******************************

*/

#include <iostream>
#include <vector>

// non-member function operator comparison == != < > <= >=

int main(){

    std::vector<int> one {1,2,2,2,3};
    std::vector<int> two {1,2,2,2,4};
    std::vector<int> three {2,2,2,2,3};

    std::cout << (one == two) << std::endl;     // false
    std::cout << (one < two) << std::endl;      // true
    std::cout << (one < three) << std::endl;      // true

}




