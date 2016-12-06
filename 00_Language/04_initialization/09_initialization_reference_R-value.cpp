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

    int n=1;
    // R-value
//    int& bad2 = 1;          // error, cannot bind l-value reference to r-value

    const int& cref = 1;    // bound to r-value
    int&& rref = 1;         // bound to r-value

    const A& cref2 = bar(); // reference to A sub-object of B temporary
    A&& rref2 = bar();        // same

    int&& xref = static_cast<int&&>(n); // bind directly to n
//    int&& copy_ref = n;                 // error, cannot bind to an l-value
    double&& copy_refd = n;             // bind to an r-value temporary with value 1.0

    // restrictions on temporary lifetime
    std::ostream& but_ref = std::ostringstream() << 'a';
    // the ostringstream temporary was bound to the left operand of operator <<,
    // but its lifetime ended at the semicolon: but_ref is now a dangling reference.

    S a{1, {2,3}};          // temporary pair {2,3} bound to the reference member
                            // a.mp and its lifetime is extended to match a
                            // (note:does not compile in c++17)
    S* p = new S{1,{2,3}};  // temporary pair {2,3} bound to the reference
                            // member a.mp, but its lifetime ended at the semicolon
                            // p-> mp is a dangling reference
}










