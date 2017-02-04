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
//  name lookup for public and private class
/******************/
#include <iostream>

class A {};

class B : private A {};

class C : public B {
//    A* ptr;     // error, it finds A as private member;
    ::A* ptr;   // okay, it finds A as class
};

int main(){


}

/* output:



*/
