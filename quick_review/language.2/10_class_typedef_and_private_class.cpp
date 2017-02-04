/*
            language 2
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. Classes
2. Templates
3. Exceptions
4. Statements
5. Miscellaneous

*/
/// class
//  private member class and typedef

/******************/
#include <iostream>

class A {
    class B {};
public:
    typedef B B_t;  // okay B_t is public
};


int main(){

    //A::B object;        // error, cannot access to B, it is private

    A::B_t object;      // okay

}

/* output:



*/
