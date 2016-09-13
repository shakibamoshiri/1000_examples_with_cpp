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
/// 01 template parameter and template argument

// default template argument

// Default template argument are specified in the parameter lists after = sing.
// Defaults can be specified for any kind of template parameter like,
// type, non-type or typename, but not to parameter pack.
//
// Note: defaults in primary template, is need to all subsequent template
// Default parameter are not allowed
// # in the out-of-class definition of a member template
// # in friend class template declaration
// # in any function template declaration or definition

class C {
private:
    int i;
public:
    C(int t): i(t) {}
    void p () { std::cout<<i<<std::endl; }
};


int main(){
    C c = 1;    // conversion constructor, both copy-initializer and direct-initializer are allowed
    c.p();

    C c2(2);    // default constructor, only direct-initializer is allowed
    c2.p();
}
