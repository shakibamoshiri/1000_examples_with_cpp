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


/// 1 Designates a function or several function as friends of this class
struct X {
    char* foo(int){};
    X(char){}
    ~X(){}
};
class Y {
    int data;   // private data
    // the non-member function operator<< will have access to Y's private member
    friend std::ostream& operator<<(std::ostream& out, const Y& obj);
    friend char* X::foo(int);   // member of other classes can be friend too
    friend X::X(char), X::~X(); // constructor and destructor can be friend to
};
// Note: friend declaration does not declare a member function
// this operator<< still needs to be defined, as a non-member function
std::ostream& operator<<(std::ostream& out, const Y& obj){
    return out << obj.data;    // can access private data member
}

/// 2 only allowed in non-local class definition
// Defines a non-member function, and makes it a friend of
// this class at the same time. such non-member function is always in-line
class Q {
    int a;
    friend void friend_set(Q& t, int i){
        t.a = i;    // this is a non-member function
    };
public:
    void mmeber_set(int i){ // this is a member function and no need to create an object like W& t in the friend_set()
        // this->a = i;
        // or
        a = i;
    }
};

/// 3 ...
/// 4 ...

class A {}; // declared and defined
// class A; is correct, only declaration not definition
class B {
    int data;
    class C {};         // private nested type
    enum { a = 100 };   // private enumeration
    friend class D;     // friend class forward declaration
    friend A;           // friend class declaration ( new syntax since c++11 );
};
class D : B::C {        // error until c++11, the base clause is not part of member declarations. Allowed in c++11
    B::C ab;            // okay B::C accessible to member of friend
    class A: B::C {};   // okay ,B::C accessible to base-clause of nested member of friend
    int v[B::a];
};

/// note 1,2,3
// Friendship is not transitive ( a friend of your friend is not your friend )
// Friendship is not inherited ( your friend's children are not your friend )
// Access specifier have no effect on the meaning of friend declaration
// A friend class declaration can not define a new class ( friend class A {}; error )
int main(){

}







