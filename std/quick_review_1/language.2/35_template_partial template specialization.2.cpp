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
//  partial template specialization


/******************/
#include <iostream>
/******************/

template< typename R, typename A = R >
struct S {
    S(){ std::cout << "primary template\n"; }
};

template< typename R >
struct S< R( R ) > {
    S(){ std::cout << "partial specialization of R( R )\n"; }
};

template< typename R, typename A >
struct S< R( A ) > {
    S(){ std::cout << "partial specialization of R( A )\n"; }
};





int main(){

    S< int, int > one;  // it needs two type
    S< int( int ) > two;    // it needs 1 type, and another type became default -> typename A = R
    S< int( char ) > three; // it needs 1 type, and another type became default -> typename A = R

}

/* output:


*/
