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
/// std::plus
//  Function object for performing addition.
//  Effectively call operator + on two instance of type T

#include <iostream>
#include <functional>
#include <algorithm>


int main() {

    int n1 = 2, n2 = 4;

    typedef std::plus<int> plus;

    int number = plus()(n1, n2);

    std::cout << number;        // 6

}


/* output for me:



*/


