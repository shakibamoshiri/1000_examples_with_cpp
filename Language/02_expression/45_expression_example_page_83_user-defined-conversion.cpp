/**

/// Expression
/// user-defined conversion.
/// in general

operator conversion-type is
explicit operator conversion-type-id

Enable implicit conversion or explicit conversion from a class type to another type.
first: Declares a user-defined conversion function that participate in all implicit
       and explicit conversion.
second Declares a user-defined conversion function that participates in direct-initialization
       and explicit conversion only.

**/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
/// user defined
//#include "temp.h"
struct X {
    // implicit conversion.
    operator int() const {return 7;}

    // explicit conversion.
    //
    // it works with static_cast<int*>(variable)
    explicit operator int*() const {return nullptr;}
    // for implicit conversion user can uses it:
    //
    // In order to declares:  int* q = x;
    // operator int*() {return nullptr;}
    //

    // Error: array operator not allowed in conversion-type-id
    //
    // operator int(*)[3]() const {return nullptr;}

    using arr_t = int[3];
    operator arr_t*() const {return nullptr;}
    // Error: conversion to array no allowed in any case
    //
    //operator arr_t () const;
};
int main(){
    X x;

    int n = static_cast<int>(x); // okay, sets n to 7
    int m = x;                  // okay, sets m to 8

    int* p = static_cast<int*>(x);  //okay, sets p to null
    // Error: no implicit conversion.
    //
    // int* q = x;

    int (*pa)[3] = x; // okay.
}













