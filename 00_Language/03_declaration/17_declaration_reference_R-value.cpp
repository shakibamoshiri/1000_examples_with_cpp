/**
/// Reference Declaration
///
///
Declares a named variable as a reference, that is, an alias to an already-existing object or function.

Syntax:
A reference variable declaration is only simple declaration whose declarator has the form.
&   attr ( optional ) declarator
&&  attr ( optional ) declarator since c++11

1   L-value reference declaration: the declaration S& D; declares D as an l-value reference
    to the type determined by decl-specifier-seq S
2   R-value reference declarator: the declaration S&& D; declares D as an r-value reference
    to the type determined by decl-specifier-seq S.

NOTE: There is no reference to void and no reference to reference

NOTE: Reference type cannot by cv-qualified at the top level; there is no syntax
      for that in declaration, and if a qualification is introduced through a typedef,
      decltype, or template type argument, it is ignored.
      Because reference art not objects, there are no array of reference, no pointer
      to reference, and no reference to reference

      int& a[2]; Error
      int& *p;   Error
      int& &r;   Error

      Also:

      typedef int& lref;
      typedef int&& rref;

      int n;
      lref&     r1 = n;     type of r1 is int&
      lref&&    r2 = n;     type of r2 is int&
      rref&     r3 = n;     type of r3 is int&
      rref&&    r4 = n;     type of r4 is int&&

**/
#include <iostream>
#include <string>


int main(){
    // R-value references can be user to extend the lifetime of temporary object
    // note, l-value references to const can extend the lifetimes of temporary object, too,
    // but they are not modifiable through them.

    std::string s1 = "Test";
//    std::string&& r1 = s1;              // Error: cannot bind to l-value

    const std::string& r2 = s1 + s1;    // Okay, l-value reference to const extends lifetime
//    r2 += " TEST";                       // Error: cannot modify through reference to constant

    std::string&& r3 = s1 + s1;         // Okay r-value reference extends lifetime
    r3 += " TEST";                      // Okay can modify through reference non-constant
    std::cout<<r3<<std::endl;
}












