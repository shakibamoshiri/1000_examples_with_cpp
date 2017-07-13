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
//
// An explicit specialization of a static data member of a template is a definition
// if the declaration includes an initializer; otherwise, it is a declaration. These
// definition must use braces for default initialization:
template<class T>
struct B {
    static int x;
};

template<> int B<int>::x = 0;   // declaration of a static data member
template<> int B<int>::x ();    // error, function declaration
template<> int B<int>x {};      // definition of a default-initialized static member





int main(){


return 0; }


