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

char& lvalue_function_ref(std::string& s, std::size_t n){
    return s.at(n);
    // string::at() returns a reference to a char
}
int main(){
    // When a function's return type is l-value reference,
    // the function call expression ( above lvalue_function_ref)
    // becomes an l-value expression
    std::string str = "Test";
    lvalue_function_ref(str,2) = 'S';   // the function call is l-value, can be assigned to

    std::cout<<str<<std::endl; // output: TeSt;
}












