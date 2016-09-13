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



/// 07 partial template specialization
// Allows customizing class template for a given category of template argument
//
// The template parameter list and the template argument list of a member of a
// partial specialization must match the parameter list and the argument list of
// the partial specialization.
// Just like with members of primary template, they only need to be defined if need in the program.
// NOTE:
// Member of partial specialization are not related to the members of the primary template
// Explicit (full) specialization of a member of a partial specialization is declared the
// same way as an explicit specialization of the primary template.
//
// If a class template is a member of another class template, and it has partial specialization,
// these specialization are members of the enclosing class template.

struct B {
    int n;
};
struct C {
    struct D {
        float f;
    };
};

class E {
    class N {
    public:
        int i;
    };
};



int main(){

    // okay, but B() is wrong syntax
    make<B>::type one;
    one.n = 3;
    print(one.n);

    // okay, same as above
    make<C::D>::type two;
    two.f = 2.3;
    print(two.f);

}
