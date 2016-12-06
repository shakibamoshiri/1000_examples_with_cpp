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
// Explicit specialization can only appear in the same namespace as the primary
// template, and has no appear after the non-specialized template declaration. It
// always in the scope of that namespce:
namespace N {
    template<class T> class X {};   // primary template
    template<> class X<int>   {};   // specialization in same namespce

    template<class T> class Y {};   // primary template
    template<> class Y<char>;       // forward declare specialization for char
}
class N::Y<char> {};                // okay, specialization in same namespace

// Note:
// Specialization must be declare before the first use that would
// cause implicit instantiation, in every translation unit where such use occurs:
class String {};
template<classs T> class Array {};
template<class T> void sort ( Array<T>& v ) {}      // primary template

void f ( Array<String>& v ) {
    sort(v);        // implicitly instantiation sort ( Array<String>& )
                    // using the primary template for sort()
}
template<>          // Error, explicit specialization of sort ( Array<String>& )
void sort<String>( Array<String>& v ){}             // after implicit instantiation

// At template specialization that was declare but not defined can be
// used just like any other incomplete type ( e.g. pointers and reference to it may be used )
template<class T> class X;      // primary template
template<> class X<int>;        // ( primary ) specialization ( declared, but not defined )
X<int>* p;                      // okay, pointer to incomplete type
X<int> x;                       // error, object of incomplete type

int main(){


return 0; }

