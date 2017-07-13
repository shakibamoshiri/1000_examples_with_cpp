/**
/// Array Declaration
///
Declares an object of array type.

Syntax:

noptr-declarator [ constant-expression ( optional ) ] attribute ( optional )
noptr-declarator    any valid declarator, but if it begins with *, &, &&, it
                    has to be surrounded by parentheses.
attribute           optional list of attributes
constant-expression an integral constant expression ( until c++14 ) a converted
                    constant expression of type std::size_t ( since c++14 ), which
                    evaluates to a value greater than zero.

**/
#include <iostream>
#include <string>

int main(){
    // arr1 and arr2 have the same const-qualified type "array of 5 const char"
    typedef const char cc;
    cc arr1[5] = {};

    typedef char c5[5];
    const c5 arr2 = {};

    // when used with new[] -expression, the size of an array may be
    // zero; such an array has no elements
    int* p = new int[0];    // accessing p[0] or *p is undefined
    delete[] p;

    // Assignment
    // Object of array type cannot be modified as a whole:
    // even though they are l-value ( e.g. an address of
    // array can be taken ), they cannot appear on the left
    // hand side of assignment operator
    int a[3] = {1, 2, 3}, b[3]={4,5,6};
    int (*p2)[3] = &a;
    std::cout<<*(*p2+0)<<' '<<*(*p2+1)<<' '<<*(*p2+2)<<std::endl;

//    a = b;  // error: address of a can be taken.
    struct {int c[3];} s1, s2={11,22,33};
    s1 = s2;
    std::cout<<s1.c[0]<<' '<<s1.c[1]<<' '<<s1.c[2]<<std::endl;
}












