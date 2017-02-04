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
/// expression

#include <iostream>
#include <string>


// #include <iomanip>





int main(){

    // array - assignment

    int array1[] = {1, 2, 3};
    int array2[3];  // empty

    // It is an error:
//    array1 = array2;

    // but with structure it is okay
    struct A { int array[3] = {1, 2, 3}; }; // here the size of the array is necessary!
    A one, two;
    std::cout << one.array[ 0 ] << ' '
              << one.array[ 1 ] << ' '
              << one.array[ 2 ] << '\n';    // 1 2 3

    two = one;  // okay
    // and print:
    std::cout << two.array[ 0 ] << ' '
              << two.array[ 1 ] << ' '
              << two.array[ 2 ] << '\n';    // 1 2 3








}



/* output:


*/
