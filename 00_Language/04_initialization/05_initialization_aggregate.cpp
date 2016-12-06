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
    char arr[] = "abc";             // equivalent to arr[4] = {'a','b','c','\0'};
//    unsigned char arr2[3] = "abc";  // error, initializer string too long
    unsigned char arr3[4] = "abc";  // okay

    S s1={1, {2,3, {4,5,6} } };
    S s2 = { 1, 2, 3, 4, 5, 6};     // the same as above; but with brace elision

    S s3{1, {2,3, {4,5,6} } };      // okay in c++11, direct-list-initialization
    S s4{1,2,3,4,5,6};              // error in c++11 but okay in c++14;


}









