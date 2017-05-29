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
//  virtual function

/******************/
#include <iostream>


struct Base {
    virtual void func(){ std::cout << "base class\n"; }
};

struct Derived : Base {
    virtual void func(){ std::cout << "derived class\n"; }
};



int main(){

    Base base;
    Derived derived;

    base.func();        // base class
    derived.func();     // derived class

    // non-virtual function call
    base.Base::func();      // base class
    derived.Base::func();   // base class

    // virtual function through pointer
    Base* base_ptr = &base;
    Base* derived_ptr = &derived;
    base_ptr->func();
    derived_ptr->func();

    // virtual function through reference
    Base& base_ref = base;
    Base& derived_ref = derived;
    base_ref.func();
    derived_ref.func();
}

/* output

base class
derived class
base class
base class
base class
derived class
base class
derived class



*/
