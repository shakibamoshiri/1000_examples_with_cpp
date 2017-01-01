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

template<typename A, typename B, typename L = std::less<int> >
bool less_of (A first, B second, L compare = L() ){     // L() = std::less<int>()

    return compare( first, second ); // equivalent to std::less<int>()( first, second )
}

int main() {

    std::boolalpha( std::cout );
    std::cout << less_of( 3, 4 );   // true
    std::cout << less_of( 5, 4 );   // false

}


/* output for me:



*/


