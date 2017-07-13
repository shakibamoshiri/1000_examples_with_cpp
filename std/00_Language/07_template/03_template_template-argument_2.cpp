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
/// 01 template parameter and template argument

// template argument 2

// The only expressions are that non-type template parameter of reference
// and pointer type cannot refer to / be the address of:
// # a sub-object ( include non-static class member, base sub-object, or array element )
// # a temporary object
// # a string literal
// # the result of type-id
// # or the predefined variable __func__

template<class T, const char* CCH> class X{};
//X<int, "class X"> x1;       // error, used form string literal

template<int* p> class Z {};
int a[10];

struct A {
    int a;
    static int z;
}aa;
//Z<&a[0]> z1;        // error, address of array element
//Z<&aa.a> z2;        // error, address of non-static member
Z<&aa.z> z3;        // okay
Z<&A::z> z4;        // okay

template<const int& ci> struct M {};
M<1> m1;        // error, temporary object
int c = 1;
M<c> m2;        // okay













int main(){}
