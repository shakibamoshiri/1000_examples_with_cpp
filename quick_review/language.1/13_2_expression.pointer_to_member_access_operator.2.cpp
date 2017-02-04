/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// expression

#include <iostream>

struct Bird {
    int value;

    Bird (int t): value(t) {}

    int function (int t){ return value * t; }
};

int main(){

    int Bird::* p2value = &Bird::value;                 // pointer to member -> value
    int (Bird::* p2function)(int) = &Bird::function;    // pointer to member -> function

    Bird* chick = new Bird(10);

    std::cout << chick->*p2value << std::endl;          // 10
    std::cout << (chick->*p2function)(2) << std::endl;  // 10 * 2 = 20

    // or
    std::cout << ((*chick).*p2value) << std::endl;          // 10
    std::cout << ((*chick).*p2function)(3) << std::endl;    // 10 * 3 = 30

    delete chick;


}
