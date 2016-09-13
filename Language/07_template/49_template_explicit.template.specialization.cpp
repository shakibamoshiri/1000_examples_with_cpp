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

template<typename T>
struct is_void: std::false_type {};

template<>  // explicit specialization for T = void
struct is_void<void>: std::true_type {};


int main(){

    // for any type T other than void, the class is derived form 'false_type'
    std::cout<<is_void<char>::value<<std::endl;

    // but when T is void, the class is derived form true_type
    std::cout<<is_void<void>::value<<std::endl;

return 0; }

