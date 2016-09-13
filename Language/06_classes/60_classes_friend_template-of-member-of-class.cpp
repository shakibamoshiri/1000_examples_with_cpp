/*
Classes
    - class declaration
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
    * friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    Fried Declaration
    The friend declaration appears in a class body and grants a function
    or another class access to private and protected members of the class
    where the friend declaration appears.
    (grant means: to agree to give someone what they ask for,
     especially formal or legal permission to do something )

     Syntax:
     friend function-declaration
     friend function-definition
     friend elaborated-class-name ; ( elaborated means: very complicated and detailed; carefully prepared and organized)
     friend simple-type-specifier ;
     friend typename-specifier ; since c++11
*/

#include <iostream>
#include <string>
// #include <cstdlib>


/// template friend
// when friend declaration refers to a full specialization of a function
// template, the keyword 'inline' and 'default' argument can not be used.
template<class T> void f(int);  // primary
template <> void f<int> (int);  // full
class A {
//    friend void f<int>(int x=1);    // error, default argument not allowed
};

// if a member of a class template A is declared to be friend of a non-template class B,
// the corresponding member of every specialization of A becomes a friend of B. If A is
// explicitly specialized, as long as there is a member of the same name, same kind
// ( type, function, class template, function template ), same parameter / signature,
// it will be a friend of B

template<typename T>    // primary template
struct C {
    struct D {};
    void f(){};
    struct E {
        void g(){}
    };
};
template <>             // full specialization
struct C<int> {
    struct D {};
    int f(){}           // not void f()
    struct E {
        void g(){}
    };
};
class B {
    template<class T>
    friend struct C<T>::D;      // C<int>::E is friend, as well as all C<T>::E

    template<class T>
    friend void C<T>::f();      // C<int>::f() is not a friend, because the signatures do not match, but A<char>::f() is

    template<class T>
    friend void C<T>::E::g();   // C<int>::E::g() is not a friend it is not a member of A, and C<int>::D is not a specialization of C<int>::D
};


int main(){

}







