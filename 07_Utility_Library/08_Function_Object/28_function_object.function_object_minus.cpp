/*
            Function Object
            ***************

4. Function objects (build-in)
    4.1 arithmetic  operations

    --------------------------------------------
    4.2 comparison  operations

    --------------------------------------------
    4.3 logical     operations

    --------------------------------------------
    4.4 bitwise     operations

    --------------------------------------------
    4.5 negators    operations
*/
/// std::minus
//  Function object for performing subtraction.
//  Effectively call operator - on two instance of type T

#include <iostream>
#include <functional>
#include <algorithm>


int main() {

    int n1 = 2, n2 = 4;

    typedef std::minus<int> minus;

    int number = minus()(n1, n2);

    std::cout << number;        // -2

}


/* output for me:



*/


