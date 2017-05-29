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
#include <cstdlib>

struct Base {};
struct Derived : Base {};
int main(){
    // static_cast< new_type >( input )
    // get input and return as a new_type
    // Converts between types using a combination of implicit and user-defined conversions.

    Derived d;
    Base& b_ref = d; // up-cast via implicit conversion

    Derived& d_ref = static_cast<Derived&>(b_ref);  // down-cast


    Derived d_arr[10];
    Base* b_ptr = static_cast<Base*>(d_arr);    // up-cast
}
