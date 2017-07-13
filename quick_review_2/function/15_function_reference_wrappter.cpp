/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::reference_wrapper
//  Reference wrapper

#include <iostream>
#include <functional>   // reference_wrapper


int main(){

    int a{ 3 };
    int b{ 5 };
    int c{ 7 };

    // an array of reference
    std::reference_wrapper< int > ref_array[] = { a, b, c };

    for( int& x : ref_array ){
        std::cout << ++x << '\n';
    }

    std::cout << '\n' << a
              << '\n' << b
              << '\n' << c;

}

/* output


4
6
8

4
6
8
Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.


*/
