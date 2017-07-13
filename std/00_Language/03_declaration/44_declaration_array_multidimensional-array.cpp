/**
/// Array Declaration
///
Declares an object of array type.

Syntax:

noptr-declarator [ constant-expression ( optional ) ] attribute ( optional )
noptr-declarator    any valid declarator, but if it begins with *, &, &&, it
                    has to be surrounded by parentheses.
attribute           optional list of attributes
constant-expression an integral constant expression ( until c++14 ) a converted
                    constant expression of type std::size_t ( since c++14 ), which
                    evaluates to a value greater than zero.

**/
#include <iostream>
#include <string>
#include <numeric>
#include <iterator>
int main(){

    // when the element type of an array is another array,
    // it is said that the array is multidimensional

    // array of 2 arrays or 3 ints each
    int arr[2][3] = {
        {10,20,30},
        {40,50,60}
    };
    std::cout<<arr[0][0]<<' '<<arr[2][3]<<std::endl;

    /*
        Note that when array-to-pointer implicit conversion is applied, a
        multidimensional array is converted tot a pointer to its first
        elements ( e.g. a pointer to the first row or th its first plane )
        array-to-pointer conversion is applied only once.
    */
    int arr2[2];        // array of 2 ints
    int* ptr1 = arr2;      // pointer to the first element of arr2

    int arr3[2][3];     // 2 x 3 matrix
//    int** ptr2 = arr3;     // error: ptr2 does not decay to int**
    // error: cannot convert ‘int (*)[3]’ to ‘int**’ in initialization|
    int (*ptr3)[3] = arr3;  // okay, pointer to the first 3-element row of arr3

    int* t2 = arr[0];
    std::cout<<*t2<<' '<<*(t2+1)<<' '<<*(t2+2)<<' '
             <<*(t2+3)<<' '<<*(t2+4)<<' '<<*(t2+5)<<std::endl;

    int arr4[2][3][4];          // 2 x 3 x 4 three-dimensional array
    int (*ptr4)[3][4] = arr4;   // pointer to the first 3 x 4-element plane of arr4

}












