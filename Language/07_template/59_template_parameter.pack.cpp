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
#include <typeinfo>
template<typename T> void print(const T value){std::cerr<<value<<std::endl;}

template<class T> struct make { typedef T type; };

/// 08 Parameter Pack
// A template parameter pack is a template parameter that accepts zero or more template
// arguments ( non-types or types ) A function parameter pack is a function template
// that accepts zero or more function arguments.
/** A template with at least one parameter pack is called a variadic template **/
// syntax:
// 1    type... Args (optional )
// 2    template | class ... Args (optional )
// 3    template <parameter-pack > typename ( c++17 ) class ... Args (optional )
// 4    Args... args (optional)
// 5    pattern...
// 1:   A non-type template parameter pack ( int ... I )
// 2:   A type template parameter pack
// 3:   A template template parameter pack
// 4:   A function template parameter pack
// 5:   parameter pack expansion: expands to comma-separated list of zero or more
//      patterns. Pattern must include at least one parameter pack.
//
// a variadic class template can be instantiated with any member of template arguments
template<class... Types> struct Tuple {};
Tuple <> t0;            // Types consists no argument
Tuple <int> t1;         // Types consists one argument: int
Tuple<int,float> t2;    // Types consists two argument: int and float
Tuple<0> error;         // 0 is not a type

// also with a template function:
template<class ... Args> void f(Args... args ){}
f();        // okay, args consists no argument
f(2);       // okay, args consists one argument: int
f(3,3.3);   // okay, args consists two argument, int and float


int main(){

}
