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
//  static member function
//  static member function are not associated with any object.
//  NOTE:
//  When they are called, they have no *this pointer.

#include <iostream>

struct S {
    static void static_function();
};

void S::static_function(){ std::cout << __func__ << '\n'; }   // It looks like a regular function

int main(){

//    void ( S::* fp )() = &S::static_function;      // is wrong and compiler says: error: cannot convert ‘void (*)()’ to ‘void (S::*)()’ in initialization
    void ( *fp )() = &S::static_function;       // okay
    fp();
    // static_function

}

/* output:



*/
