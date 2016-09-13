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
Conversion Function Template
Template argument deduction is used when selecting user-defined conversion function
template argument

A is the type that is required as the result of the conversion.
P is the return type of the conversion function template, except that

a) If the return type is a reference type then P is the referred type
b) If the return type is an array type and A is not a reference type,
   then P is the pointer type obtained by array-to-pointer conversion
c) If the return type is a function type and A is not a reference type,
   then P is the function pointer type obtained by function-to-pointer conversion
d) If P is cv-qualified, the top-level cv qualifiers are ignored.

If A is cv-qualified, the top-level cv qualifiers are ignored.
If A is a reference type, the referred type is used by deduction.
If, the usual deduction from P and A (as described above) fails,

the following alternatives are additionally considered:


a) If the original A is a reference type, A can be more cv-qualified
   than the deduced A
b) If A is a pointer or pointer to member type, the deduced A is allowed
   to be any pointer that can be converted to A by qualification conversion.
c) If the original A is a function pointer type, the deduced A is allowed
    to be pointer to noexcept function, convertible to the original A by
    function pointer conversion.
d) If the original A is a pointer to member function, the deduced A is allowed
   to be a pointer to noexcept member function, convertible to the original A
   by function pointer conversion.
**/
struct A {
    template<class T> operator T***(){}
};
A a;
const int* const* const* p = a;     // A = const int* const* const* and P = T***

// regular function call deduction for it is:
/** template<class T> void f(T*** p){} **/// as if called with the argument
// of type const int* const* const* fails
// additional deduction for conversion function determines T = int
// deduced A is int***, convertible to const int* const* const*


int main(){

return 0; }

