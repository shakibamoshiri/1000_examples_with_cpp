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
#include <string>

struct Base {};
struct Derived : Base {};
int main(){
    // static_cast< new_type >( input )
    // get input and return as a new_type
    // Converts between types using a combination of implicit and user-defined conversions.


    void* f = new float(33.23);
    float* i = static_cast<float*>(f);
    std::cout << *i << std::endl;       // 33.23

    delete f;

}
