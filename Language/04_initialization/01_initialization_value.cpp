/*
Initialization:
    value       initialization
    copy        initialization
    direct      initialization
    aggregate   initialization
    list        initialization
    reference   initialization
    zero        initialization
    constant    initialization
********************************
Value Initialization
This is the initialization performed when a variable is constructed with an empty initializer:
Syntax:
1   T();
2   new T();
3   class::class(...) : member () {...
4   T object {};
5   T{};
6   new T{}
7   class::class : member{} {...

Note: A constructor is user-provided if ti is user-provided and not explicitly
      defaulted on its first declaration. The syntax T object(); does not initialize
      an object; it declares a function that take no argument and return T. The way
      to value-initialize a named variable before c++11 was T object = T();, which
      value-initializes a temporary and then copy-initializes the object: most compiler
      optimize out the copy in this case.


*/

#include <iostream>
#include <string>

struct A {
    int i;
    A() {} // user-provided default constructor, does not initialize i
};

struct B {A a;};



int main(){
    /*
      Since c++11, value-initializing a class without a user-provided constructor,
      which has a member of class type with a user-provided constructor zeroes out
      the member before calling its constructor
    */
    std::cout<<B().a.i<<std::endl; // value-initializes a B temporary
    // leaves b.a.i uninitialized in c++03
    // sets b.a.i to zero in c++11
    // (note that B{}.a.i leaves b.a.i uninitialized in c++11, but for
    // a different reason: in post-DR1301 c++11 B{} is aggregate-initialization,
    // which then value-initializes A, which has user-provided constructor



}









