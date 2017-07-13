/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::reference_wrapper::operator =
//  copy assignment

#include <iostream>
#include <functional>   // reference_wrapper


int main(){

    int a{ 3 };
    int b{ 5 };
    int c{ 7 };

    std::reference_wrapper< int > first = a;
    std::reference_wrapper< int > second = b;
    second = first = c;

    std::cout << first << ' ' << second << '\n';


}

/* output

7 7

Process returned 0 (0x0)   execution time : 0.016 s
Press ENTER to continue.



*/
