/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::reference_wrapper::operator &
//  cast to reference
//
// operator type&() const noexcept{}

#include <iostream>
#include <functional>   // reference_wrapper


int main(){

    int a{ 3 };

    std::reference_wrapper< int > first = a;

    static_cast< int& >( first ) = 30;
    int& second = first;
    ++second;

    std::cout << a << '\n';
    std::cout << first << '\n';


}

/* output

31
31

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
