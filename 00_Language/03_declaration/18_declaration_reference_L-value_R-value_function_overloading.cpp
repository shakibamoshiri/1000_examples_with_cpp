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

void f(int& c){
    std::cout<<"L-value reference overload f("<<c<<")\n";
}

void f(const int& c){
    std::cout<<"L-value reference to const overload f("<<c<<")\n";
}

void f(int&& c){
    std::cout<<"R-value reference overload f("<<c<<")\n";
}

int main(){
    // More importantly, when a function has both r-value reference and l-value
    // reference overloads. The r-value reference overload binds to r-value,
    // while the l-value reference overload binds to l-value.

    int i = 1;
    const int ci = 2;
    f(i);       // calls f(int&)
    f(ci);      // calls f(const int&)
    f(3);       // calls f(int&&);
                // would call f(const int&) if f(int&&) overload was not provided.

    /*

    L-value referencĵe overload f(1)
    L-value reference to const overload f(2)
    R-value reference overload f(3)


    */
}












