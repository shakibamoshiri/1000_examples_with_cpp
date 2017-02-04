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


template< typename... PPE > struct S {  // it expands to template parameter such as: int and any others type

    template< PPE... value > struct SS {    // it expands to non-template parameter such as 1, 'c',
        void operator()(  ){
            std::cout << "struct SS was called\n";
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



*/
