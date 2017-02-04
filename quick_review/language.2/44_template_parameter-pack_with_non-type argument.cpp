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
//  function argument lists


/******************/
#include <iostream>

/******************/

/*
    // error: call of overloaded ‘print()’ is ambiguous|
    template< int N >
    void
    print(){ std::cout << N << '\n'; }

    template< int N, int... Rest >
    void
    print(){
        std::cout << N << '\n';
        print<Rest...>();
    }

*/

// avoiding of ambiguous by compiler
template< int N >
void
print(){ std::cout << N << '\n'; }

template< int N, int M, int... Rest >
void
print(){
    std::cout << N << '\n';
    std::cout << M << '\n';
    print<Rest...>();
}





int main(){

    print< 1, 3, 4 >();

}

/* output:


*/
