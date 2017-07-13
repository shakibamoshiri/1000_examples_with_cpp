/**

/// Expression
/// user-defined conversion.
/// in general

operator conversion-type is
explicit operator conversion-type-id

Enable implicit conversion or explicit conversion from a class type to another type.
first: Declares a user-defined conversion function that participate in all implicit
       and explicit conversion.
second Declares a user-defined conversion function that participates in direct-initialization
       and explicit conversion only.

**/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
/// user defined
//#include "temp.h"
struct To {
    To() = default;
    To(const struct Form&){} // converting constructor
};
struct Form {
    operator To() const {return To();} // converting function.
};
int main(){
    Form f;
    To t1(f); // direct-initialization: calls the constructor
    // ( note, if converting constructor is not available, implicit copy constructor
    // will be selected, and conversion function will be called to prepare its argument )

//    To t2 = f; // copy-initialization: ambiguous
    // ( note, if conversion function is from a  non-const type, e.g.
    // From::operator To();, it will be selected instead of the ctor in this case )

    To t3 = static_cast<To>(f); // direct-initialization: called the constructor

//    const To& r = f; // reference-initialization: ambiguous
}













