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
    int a, b, c;
public:
    C(int t1, int t2, int t3): a(t1), b(t2), c(t3) {}
    void p () { std::cout<<a<<' '<<b<<' '<<c<<std::endl; }
};

class D {
private:
    int a, b, c;
public:
    D(int t1=0, int t2=0, int t3=0): a(t1), b(t2), c(t3) {}
    void p () { std::cout<<a<<' '<<b<<' '<<c<<std::endl; }
};


int main(){
    C c = {1,2,3};    // conversion constructor
    c.p();

    C c2(10,20,30);      // default constructor
    c2.p();

    D d=100;
    d.p();

    D d2 = {100,200};
    d2.p();

    D d3 = {100,200,300};
    d3.p();
}
