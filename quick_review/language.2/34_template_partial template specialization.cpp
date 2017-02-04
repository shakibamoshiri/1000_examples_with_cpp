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

template< typename T >
struct S {
    S(){ std::cout << "primary template\n"; }
};

template< typename T >
struct S< T* > {
    S(){ std::cout << "partial specialization of T*\n"; }
};

template< typename T >
struct S< T& > {
    S(){ std::cout << "partial specialization of T&\n"; }
};

template< typename T >
struct S< T() > {
    S(){ std::cout << "partial specialization of T()\n"; }
};

template< typename T >
struct S< T(int) > {
    S(){ std::cout << "partial specialization of T( int )\n"; }
};



int main(){

    S< int > i;         // simple integer
    S< int* > iptr;     // integer pointer
    S< int& > iref;     // integer reference
    S< int() > ipf;     // integer pointer function
    S< char( int ) > chpf;  // char with integer argument

}

/* output:


*/
