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
Reference Initialization
Binds a reference to an object.
Syntax:
1   T& reference = object;
2   T& reference = {arg1, arg2, ... };
3   T& reference (object)
4   T& reference {arg1, arg2, ...};

2   T&& reference = object;
2   T&& reference = {arg1, arg2, ...};
2   T&& reference (object);
2   T&& reference {arg1, arg2, ...};

given R fn (T& arg);
given R fn (T&& arg);
fn (object);
fn ({arg1, arg2});

given T& fn(){ or T&& fun() {

return object;

class::class(...) : reference(expr){...};

Note: Once initialized, a reference cannot be changed to refer to another object.

*/

#include <iostream>
#include <string>
#include <utility>
#include <sstream>

struct S {
    int mi;
    const std::pair<int,int>& mp;   // reference member
};

void f(int){}

struct A{};
struct B : A {
    int n;
    operator int&(){return n;};
};

B bar(){return B();}

//int& bad_ref;   // error, no initializer
extern int& good_ref;   // okay

int main(){
    // L-value
    int n = 1;
    int& r1 = n;            // l-value reference to object n
    const int& cr(n);       // reference can be more cv-qualified
    volatile int& cv{n};    // any initializer syntax can be used
    int& r2 = r1;           // another l-value reference to the object n
//    int& bad = cr;          // error, less, cv-qualified
    int& r3 = const_cast<int&>(cr); // const_cast is needed

    void (&rf)(int) = f;    // l-value reference to function
    int ar[4];
    int (&aref)[4] = ar;      // l-value reference to array

    B b;
    A& base_ref = b;        // reference to base sub-object
    int& converted_ref=b;   // reference to the result of a conversion
}










