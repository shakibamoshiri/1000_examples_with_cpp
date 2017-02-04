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

struct Base {
    virtual ~Base (){} // must be polymorphic to use runtime-checked dynamic_cast
};

struct Derived : Base {
    virtual ~Derived (){}
};


int main(){

    Derived d_obj;          // okay it is a Derive object
    Base* b_ptr = &d_obj;   // also okay, we can use dynamic_cast but unnecessary

    Base& b_ref = d_obj;    // okay

    Base b_obj;
    // compiler says: error: invalid conversion from ‘Base*’ to ‘Derived*’
    // Derived* d_ptr = &b_obj;
    Derived* d_ptr = dynamic_cast<Derived*>(&b_obj);
    // compiler says: warning: dynamic_cast of ‘Base b_obj’ to ‘struct Derived*’ can never succeed

    // this calls std::bac_cast
    Derived& d_ref = dynamic_cast<Derived&>(b_obj);
//  terminate called after throwing an instance of 'std::bad_cast'
//  what():  std::bad_cast
//  Aborted (core dumped)

}
