/*
Classes
    * class declaration
    - union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
    - nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    class declaration
    Classes and stucts are user-defined types,defined by class-specifier,,
    which appears in declaration-specifier-sequence of the declaration syntax.
    class-key attribute class-head-name base-class { member-specification };

*/

#include <iostream>
#include <string>

/// Forward declaration
// declaration a class type, which will be defined later in the scope
class Vector;   // forward declaration
class Matrix {
    // do something
    friend Vector operator*(const Matrix&, const Vector&);
};
class Vector {
    // do something
    friend Vector operator*(const Matrix&, const Vector&);
};

// contain forward declaration of std::ostream
#include <iosfwd>
struct MyStruct {
    int value;
    friend std::ostream& operator<<(std::ostrea& out,const OtherStruct& t);
    // definition provided in MyStruct.cpp file which uses #include <ostream>
};

// if forward declaration appears in local scope, it hide previously declared
// class, variable, function, and all other declaration of the some name that
// may appear in enclosing scopes
struct S { int a;};
struct S;           // does nothing ( S, already defined in this scope )
void g(){
    struct S;       // forward declaration of a new, local struct "S"
                    // this hides global strcut S until the end of this scope
    S* p;           // pointer to local struct S
    struct S {      // definition of the local struct S
        char* p;
    };
}

// note that a new class name may also be introduced by an elaborated type specifier
// which appears as part of another declaration, but only if name lookup cannot find
// a previously declared class with the same name.
class U;
namespace ns {
    class Y f(class T p);   // declares function ns::f and declares ns::f and ns::Y
    class U f():            // U refers to ::U
    Y* p; T* q;             // can use pointers and reference to T and Y
}



int main(){

}

