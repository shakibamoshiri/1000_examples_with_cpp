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
#include <vector>
#include <iterator>
#include <utility>

/// 10 Depending Name
// Inside the definition of a template ( both class-template and function-template ),
// the meaning of some constructs may differ form one instantiation to another. In
// particular types and expression may depend on types of type template parameter and
// value of non-type template parameter.
//
//
//
//
/// The template disambiguator for dependent names
// In the declaration of a definition of a template, including alias template,
// a name that is not a member of the current instantiation and is dependent on
// a template parameter is not considered to be a type unless the keyword 'typename'
// is used or unless it was already established as a type name, e.g. with a typedef
// declaration or by being used to name a base class.
int p = 1;
template<typename T> void foo ( const std::vector<T>& v) {
    // std::vector<T>const_iterator is a dependent name
    typename std::vector<T>::const_iterator it = v.begin();
    //
    // without 'typename' compiler says:
    // need ‘typename’ before ‘std::vector<T>::const_iterator’ because ‘std::vector<T>’ is a dependent scope


    // without 'typename' the following is parsed as multiplication
    // of the type-dependent member variable 'const_iterator'
    // and some variable 'p'. Since there is a global 'p' visible
    // at this point, this template definition compiles.
    std::vector<T>::const_iterator* p;

    typedef typename std::vector<T>::const_iterator iter_t;
    // iter_t is a dependent name, but it is known to be a type name
    iter_t* p2;
};

template<typename T> struct S {
    typedef int value_t;        // member of current instantiation
    void f(){
        S<T>::value_t n{};      // S<T> is dependent, but 'typename' not needed
        std::cout<<n<<'\n';
    }
};

int main(){
    std::vector<int> v;
    foo(v);             // error
                        // template instantiation fails: there is no member variable
                        // called 'const_iterator' in the type std::vector<int>

    S<int>().f();       // okay, output 0
}
