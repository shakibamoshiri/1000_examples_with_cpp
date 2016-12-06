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
#include <array>

/// 10 Depending Name
// Inside the definition of a template ( both class-template and function-template ),
// the meaning of some constructs may differ form one instantiation to another. In
// particular types and expression may depend on types of type template parameter and
// value of non-type template parameter.
template<typename T>
struct X : B<T> {           // B<T> is dependent on T
    typename T::A* pa;      // T::A* is dependent on T

    void f (B<T>* pb) {
        static int i = B<T>::i;     // B<T>::i is dependent on T
        pb->j++;                    // pd->j is dependent on T
    }
};
/// Note
// Name lookup and binding are different for dependent names and non-dependent names
