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
//
// Member or a member template may be nested within many enclosing class
// template. In an explicit specialization for such a member, there is a
// template <> for every enclosing class template that is explicitly specialized:
template<class T1> class A {
    template<class T2> class B {
        void nested ();
    };
};
template<> template<> class A<int>::B<double>;
template<> template<> void  A<int>::B<char>::nested(){}

////////////////////////////////////////////////////////////

template<class T1> class C {
    template<class T2> class D {
        template<class T3> void mft(T3);    // member template
        void mf();
    };
};

// specialization
template<>              // class C. specialized
template<class T2>      // class D, unspecialized
class C<int>::D {       // needs to write 'class' because it is member of the class
    template<class T3> void mft(T3);
};

// specialization
template<>              // specialized C
template<>              // specialized D
template<class T> void C<int>::D<char>::mft(T t){}

// specialization
template<>
template<>
template<>
void C<int>::D<int>::mft(int i){}

// Error, B<double> is specialization and is a member template
// so its enclosing C must be specified also
template<class T>
template<> void C<T>::D<double>mf(){}
// complier says:
// error: invalid explicit specialization before ‘>’ token
// error: enclosing class templates are not explicitly specialized
// error: invalid declarator before ‘mf’




int main(){


return 0; }


