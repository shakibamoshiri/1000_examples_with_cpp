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
Aggregate Initialization
( oxford, aggregate, adj means: made up several amounts that are added together to form a total number )

Initializes an aggregate from braced-initializer-list. {}

Syntax:
1   T object = {arg1, arg2, ... };
2   T object {arg1, arg2, ... }; since c++11

Explanation:
Aggregate initialization is a form of list-initialization, which initializes
aggregates an aggregate is an object of the type that is one of the following:
    - array type
    - class type ( typically, struct, union ),that has
        - no private or protected non-static data member
        - no user-provided constructor ( explicitly defaulted or deleted constructor are allowed ) since c++11
        - no base classes
        - no virtual member function
        - no default member initializers


*/

#include <iostream>
#include <string>
#include <memory>
#include <array>

struct S {
    int x;          // { one },
    struct F {
        int a;      // { two,
        int b;      //  three,
        int c[3];   // { four, five, six }
    }f; // if we do not write this object get error
        // because struct F hos no object for initialization by struct X
        // S s { 1, 2, 3, 4, 5, 6}
        // means s { 1 }
        // and   f { 2,3 , 4,5,6}
};                  // in total { one, { two, three { four, five, six } } };

union U {
    int a;
    const char* s;
};

int main(){
    int ar[] = {1,2,3};         // ar is int[3]
    char cr[3] = {'a'};         // means: {'a', '\0', '\0'}

    int ar2d1[2][2] = {{1,2}, {3,4}};   // fully braced 2D
    int ar2d2[2][2] = {1,2,3,4};      // brace elision
    int ar2d3[2][2] = {{1}, {3}};       // only first column {1,0} {3,0}

    std::array<int, 3> std_ar2{ {1,2,3} };  // std::array is an aggregate
    std::array<int, 3> std_ar1 = {1,2,3};   // brace-elision okay
    std::array<int, 3> std_ar3( {1,2,3} );  // okay, I do not name of it :)

    int ai[] = {1, 2.0};    // narrowing conversion form double to int.

    std::string str[]={std::string("one"),      // copy-initialization
                       "two",                   // conversion, then copy-initialization
                       {'t','h','r','e','e'}    // list-initialization
    };

    U u1 = {1};         // okay first member of the union
//    U u2 = { 0, "abc"}; // error, too many initializers for union
//    U u3 = { "abc"};    // error, invalid conversion to int;
    const char* Earth = "Hello World";
    U u4 = {'s'};       // okay
}









