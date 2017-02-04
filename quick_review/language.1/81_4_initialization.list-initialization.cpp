/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// initialization

#include <iostream>
#include <vector>


struct S {
    std::vector< int > vector = { 1, 2, 3 };        // list-initialization

    S(){}
    S( int a, int b, int c ) : vector{ a, b, c } {} // list-initialization of a member in constructor
};

int main(){

    S one;  // default constructor
    std::cout << one.vector[ 0 ] << ' '
              << one.vector[ 1 ] << ' '
              << one.vector[ 2 ] << std::endl;

    S two( -1, -2, -3 );
    std::cout << two.vector[ 0 ] << ' '
              << two.vector[ 1 ] << ' '
              << two.vector[ 2 ] << std::endl;

}
/* output:


*/
