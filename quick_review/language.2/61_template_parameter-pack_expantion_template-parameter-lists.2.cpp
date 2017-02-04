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
//  template argument lists


/******************/
#include <iostream>
#include <utility>  // std::pair
#include <functional>
/******************/


template< typename... PPE > struct S {

    template< PPE... value > struct SS {
        void operator()(  ){
            std::cout << "struct SS was called\n";
            const int size = sizeof...( value );
            int array[ size ] = { value... };

            std::cout << size << '\n';
            std::cout << sizeof( array ) << '\n';
        }
    };

};

int main(){
    S< int >::SS< 3 > one;
    one();

    S< int, char >::SS< 3, 'c' > two;
    two();
}

/* output:
struct SS was called
1
4
struct SS was called
2
8




*/
