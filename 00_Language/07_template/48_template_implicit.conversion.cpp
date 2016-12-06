/*
Template:
    01 template parameter and template argument
    02 class template
    03 function template
    04 variable template
    05 template argument deduction
    06 explicit (full) template specialization
    07 partial template specialization
    08 parameter pack
    09 sizeof ... operator
    10 fold expression
    11 dependent names
    12 SFINAE
    13 constraints and concepts
*/
#include <iostream>

template<typename T> void print(const T value){std::cerr<<value<<std::endl;}

template<class T> struct make { typedef T type; };


/// 05 template argument deduction
/**
Implicit Conversion

Type deduction does not consider implicit conversion
(other than type adjustments listed above ): that is the
job for overload resolution, which happens later.

**/

template<class T> struct Z {
    typedef typename T::x xx;
};
template<class T> typename Z<T>::xx f ( void*, T ){}    // #1
template<class T>              void f ( int, T ) {}     // #2

struct A {} a;

int main(){
  f(1, a);  // for #1, deduction determines T = struct A, but the remaining argument 1
            // cannot be implicitly converted to its parameter void*, so deduction fails
            // Instantiation of the return type is not requested.
            // for #2, deduction determines T = struct A, and the remaining argument 1
            // can be implicitly converted to its parameter int, deduction succeeds for #2
            // The function call compiles as a call to #2 (deduction failure is SFINAE)

return 0; }

