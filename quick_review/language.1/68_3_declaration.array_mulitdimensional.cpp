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

    // array - multidimensional

    int array1[] = {1, 2, 3};

    int array2[2][3] = {
        {1, 3, 5},      // first row
        {2, 4, 6}       // second row
    };

    int* ptr1 = array1; // pointer to first element

    int (*array_ptr)[3] = array2;   // pointer to the first 3-element

    // print the first 3-element of array2
    std::cout << array2[ 0 ][ 0 ] << ' '
              << array2[ 0 ][ 1 ] << ' '
              << array2[ 0 ][ 2 ] << '\n';      // 1 3 5

    // and print the array_ptr
    std::cout << array_ptr[ 0 ][ 0 ] << ' '
              << array_ptr[ 0 ][ 1 ] << ' '
              << array_ptr[ 0 ][ 2 ] << '\n';   // 1 3 5


    std::cout << *( array_ptr[ 0 ] ) << ' '     // okay the first row
              << *( array_ptr[ 1 ] ) << ' '     // okay the second row

              // okay with compiler but undefined behavior
              << *( array_ptr[ 2 ] ) << '\n';   // illegal

    std::cout << **( array_ptr ) << ' '     // first element of the first row
              << **( array_ptr + 1 ) << ' ' // first element of the second row
              << '\n'; // 1 2



}



/* output:


*/
