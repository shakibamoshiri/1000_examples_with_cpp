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
//  static data member
//  Like static member function, they are not associated with any object.
//  They exists even though no objects of the class have been defined.
#include <iostream>

struct S {
    static int si;  // declaration and incomplete
};
int S::si = 10;     // definition, complete


int main(){

    // They are not associated with any object
    int* si_ptr = &S::si;   // okay
    std::cout << *si_ptr << '\n';       // 10

    // They exists without any existence objects
    std::cout << S::si << '\n';

}

/* output:

10
10

*/
