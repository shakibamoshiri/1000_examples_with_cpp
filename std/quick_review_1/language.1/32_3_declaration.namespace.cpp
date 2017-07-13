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

namespace A {
    int a1;
    void f (char){ }
}

namespace B {
    int b;
    void f (char){ }
}

namespace C {
    int c1;
    void f (int) {}
}

int main(){
    A::a1++;    // okay
    using namespace A;
    ++a1;       // okay

    using namespace B;
    // error: call of overloaded ‘f(char)’ is ambiguous
//    f('a');
    // f does not know which one is correct
    // f(char) of A
    // f(char) of B;
    A::f('A');  // okay
    B::f('B');  // okay

    using C::f;
    f('C');     // okay, it knows that it should call f in namespace C
}
