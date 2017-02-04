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


int main(){
    // reference declaration

    typedef int&    lref;
    typedef int&&   rref;

    int n;

    lref&   r1 = n;     // type of r1 is int&
    lref&&  r2 = n;     // type of r2 is int&, too
    rref&   r3 = n;     // type of r3 is int&, too
    rref&&  r4 = 1;     // type if r4 is int&&

    /**   it means (but I am not sure)
    *
    *   &     with &  become &
    *   &&    with &  become &
    *   &     with && become &
    *   &&    with && become &&
    **/


}
