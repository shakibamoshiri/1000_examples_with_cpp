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
/// std::less
//

#include <iostream>
#include <functional>



int main() {

    // std::less reruns bool
     bool result = std::less<int>()( 3, 4);  // if 3 is less then 4
     std::cout << result;   // true (1)

     result = std::greater<int>()( 3, 4 );  // if 3 is grater then 4
     std::cout << result;   // false (0)

}


/* output for me:



*/


