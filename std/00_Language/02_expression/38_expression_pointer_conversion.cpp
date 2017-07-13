/**

/// Expression
/// Implicit Conversions
///

**/
#include <iostream>
#include <string>
#include <cassert>
/// user defined
//#include "temp.h"

int main(){
    char** p = 0;

    /// Error: level 2 is more cv-qualified, but level 1 is not const
    /// const char** p1 = p;

    /// okay: level 2 is more cv-qualified and const added at level 1
    const char* const* p2 = p;

    /// okay: level 2 is more cv-qualified, and const added to level 1
    volatile char* const* p3 = p;

    /// okay: 2 is more cv=qualified and const was already at 1
    volatile const char* const* p4 = p;

    double *arr[2][2];

    /// okay: since c++17
    /// double const* const(*parr)[2] = arr;

    /// Note that in the C programming language, const / volatile ( = syn : unstable )can be added to the first level only.

    char** pp = 0;

    /// okay in c and c++
    char* const* pp1 = p;

    /// Error in C but okay in c++
    const char* const* pp2 = p;
}













