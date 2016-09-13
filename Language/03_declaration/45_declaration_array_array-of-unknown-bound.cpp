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
#include <numeric>
#include <iterator>

int main(){
    /*
        Array of unknown bound
        If constexpr is omitted in the declaration of an array, the type
        declared is "array of unknown bound of T", which is a kind of
        incomplete type, expect when used in a declaration with an aggregate
        initializer:
    */

    // unknown variable x
    extern int x[];         // the type of x is "array of unknown array of 2 int"
    int a[] = {11,22,33};   // the type of a in "array of 3 int"

    // because array element cannot have incomplete type,
    // multidimensional array cannot have unknown bound
    // in a dimension other than the first:
    extern int b[][2];      // okay array of unknown bound of array of 2 int
//    extern int c[2][];      // error, array has incomplete element type
    extern int d[][3][3];   // okay

    /*
        Reference and pointers to array of unknown bound can be formed,
        but cannot be initialized or assigned from arrays and pointers
        to arrays of known bound. Note that in the C programming language
        pointer to array of unknown bound are compatible with pointer to
        array of known bound and are thus convertible and assignable in
        both direction.
    */
    extern int e[];         // unknown bound
    int (&r1)[] = e;            // okay, reference to unknown bound
    int (*p1)[] = &e ;            // okay, pointer to unknown bound
//    int (*pc)[2] = e;           // error in c++ ( but okay in c)

    int f[] = {2,3,4};
//    int (&r2)[] = f;    // error
//    int (*p2)[] = &f;   // error in c++ ( but okay in C )
    int (&r3)[(sizeof(f)/sizeof(int))] = f;   // okay
    int (*p3)[3] = &f;  // okay

}












