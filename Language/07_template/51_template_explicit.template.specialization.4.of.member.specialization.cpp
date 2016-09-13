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


/// 06 Explicit (full) Template Specialization
// Allows customizing the template code for a given set of template argument
// syntax:
// template<> declaration
/**
Any of the following can be fully specialized
01  function template
02  class template
03  ( since c++14 ) variable template
04  member function of a class template
05  static data member of a class template
06  member class of a class template
07  member enumeration of a class template
08  member class template of a class or class template
09  member function template of a class or class template

**/
// Member of specialization
// When defining a member of an explicitly specialized class template
// outside the body of the class, the syntax template <> is not used,
// expect it it is a member of an explicitly specialized member class
// template, which is specialized as a class template, because otherwise,
// the syntax would require such definition to begin with template<parameter>
// required by the nested template
template<typename T> struct A {
    struct B {};                    // member class
    template<class U> struct C {    // member class template
        void f();
        void g();
        void j();
    };
};
template<>              // specialization of struct A
struct A<int> {
    void f(int);        // member function of a specialization
                        // forward declaration
};
// no need template<>
// template<> not used for a member of a specialization
void A<int>::f(int){};  // definition

template<>              // specialization of a nested-member class
struct A<char>::B {
    void f();           // forward declaration
};
// no need template<>
// template<> not used for a nested-member of a specialization member class either
void A<char>::B::f(){}  // declaration of A::B{ void f(): };

// template<> is used when defined a member of an explicitly
// specialization member class template specialized as a class template
template<>              // belongs to A<char>
template<>              // belongs to C<char>
void A<char>::C<char>::f(){};

template<class T>       // belongs to A<T>
template<class U>       // belongs to C<U>
void A<T>::C<U>::j(){}

template<>              // belongs to A<char> and U is for C<U>
template<class U>
void A<char>::C<U>::g(){}



int main(){


return 0; }


