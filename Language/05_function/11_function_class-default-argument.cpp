/*
Function:
    declaring function
*   default argument
    variadic argument
    lambda function
    operator overloading
    address of overloading function
***************************************
     default argument
**********************
Allowed a function to be called without providing one or more trailing argument.

void print ( int a = 3 , int b = 5 );

print (1,1);    calls print (1,1)
print (1);      calls print (1,5)
print ();       calls print (3,5)

Default arguments are only allowed in the parameter lists of function declaration
and Lambda-expressions. ( since c++14 ) and are not allowed in the declaration of
pointer to function, reference to function, or in typedef declaration. Template
parameter lists are similar syntax for their default template argument.

*/

#include <iostream>
#include <string>
#include <array>

/* in a class */
class C {
    void f(int i = 3);
    void g(int i, int j = 99);
    C(int arg);         // non-default constructor
};
void C::f(int i = 3);   // error, default argument already specified in class scope
void C::g(int i = 4, int j);    // okay, in this translation unit, C::g can be called with no argument
                                // since int i inside class before has not got default value
C::C ( int arg = 1 );           // error, turns this into a default constructor


/* virtual funciton */
struct Base {
    virtual void f(int n=4);
};
struct Derived : Base {
    void f(int n) override;
};

Derived d;
Base& b = d;
b.f();  // okay, since has a default argument
d.f();  // error, since hos no default argument


/* Local variable are not allowed in default argument */
void f(){
    int n =1;
    extern void g(int x = n );  // error, local variable cannot be defaulted
}

/* The this pointer is not allowed in default argument */
class A {
    void f( A* p = this){}  // error, this is not allowed
};

/* Non-static class member are not allowed in default argument ( even if are not evaluated ),
except when used to form a pointer-to-member or in a member access expression */
int b;
class X {
    int a;
    static int b;
    int mem1 ( int t = a);   // error, non-static cannot be used
    int mem2 ( int t = b);  // okay, lookup finds X::b, the static member-data
};


/* parameter place, Note, must be parameters that appear earlier in the parameter list in scope */
int a;
int f(int a, int b=a);          // error, the parameter a used in a default argument
int g(int a, int b=sizeof(a));  // error, parameter a is used in a default argument


/* the default argument are not part of the function type */
int f(int = 1);
void h(){
    int j = f(1);   // run f(1)
    int k = f();    // calls f(0);
}
int (*p1)(int) = &f;
int (*p2)()    = &f;    // error, the type of f is int(int)

/* if a lambda-expression appears in a default argument, it
   cannot explicitly or implicitly capture anything. */
void f(){
    int i =1;
    void g1(int = [i] {return i;} () );     // error, captures something
    void g2(int = [i] {return 0;} () );     // error, captures something
    void g3(int = [=] {return i;} () );     // error, captures something
    void g4(int = [=] {return 0;} () );     // okay, capture-less
    void g5(int = []  {return sizeof i;} () );  // okay, capture-less

int main(){


}

