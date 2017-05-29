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
/// 2. template
//  different between function template and class template


/******************/
#include <iostream>

/******************/


template< typename T > struct S { typedef typename T::i type; };    // accepts class, struct, and union ( class/struct/union::type )

struct A { typedef int i; };

int main(){



    S< A >::type i;
    i = 10;
    std::cout << i << '\n'; // 10

    // typedef typename T::i type;
    // what is looks like
    A::i i2 = 11;
    std::cout << i2;        // 11

}

/* output:


*/
