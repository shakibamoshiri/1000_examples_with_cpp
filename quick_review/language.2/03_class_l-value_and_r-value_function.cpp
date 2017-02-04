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
#include <iostream>

struct S {
    void f() &  { std::cout << "l-value" << '\n'; }
    void f() && { std::cout << "r-value" << '\n'; }
};

int main(){

    S obj;

    obj.f();
    S().f();

    std::move( obj ).f();

}

/* output:

l-value
r-value
r-value

*/
