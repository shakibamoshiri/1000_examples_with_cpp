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
// Both function template and class template declaration may appear with 'friend'
// specifier in any non-local class or class template ( although only function
// template may be defined within the class or class template that is granting friendship ).
// In this case every specialization af the template becomes a friend, whether it is
// implicitly instantiated, partially specialized, or explicitly specialized.
class A {
    template<typename T>
    friend class B;     // every B<T> is a friend of A

    template<typename T>
    friend void f(T) {} // every f(T) is friend of A
};

// Friend declaration can not refer to partial ( means: no complete or whole. => The partial eclipse of the sun )
// specialization, but can refer to full specialization

template<typename T> class C {};        // primary
template<typename T> class C<T*> {};    // partial
template<> class C<int>{};    // full
class D {
//    template<class T> friend class C<T*>;   // error!

    friend class C<int>;                    // okay
};

int main(){

}







