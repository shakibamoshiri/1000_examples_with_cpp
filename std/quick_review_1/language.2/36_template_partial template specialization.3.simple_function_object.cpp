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
    R operator()( R obj )
    { return obj; }

};

template< typename R, typename A >
struct S< R( A ) > {
    R operator()( A obj )
    { return obj; }
};

template< typename R >
struct S< R( R, R ) > {
    R operator()( R one, R two )
    { return one + two; }
};



int main(){

    S< int, int > one;  // just print: primary template
    S< int( int ) > two;
    std::cout << two( 1 );      // gets int and returns int

    std::cout << '\n';
    S< char( int ) > three;
    std::cout << three( 65 );   // gets int and returns char

    std::cout << '\n';
    S< int( int, int ) > sum;
    std::cout << sum( 1, 4 );   // gets two int type and returns the sum of them

}

/* output:


*/
