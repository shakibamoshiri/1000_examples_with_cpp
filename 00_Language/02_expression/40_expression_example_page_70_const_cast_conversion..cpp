/**

/// Expression
/// Implicit Conversions
/// const_cast< new_type >

Convert between type with different cv-qualification.

Returns a value of type new_type

**/
#include <iostream>
#include <string>
#include <cassert>
/// user defined
//#include "temp.h"
struct type {
    int i;
    type() :i(3) {}
    void f(int t) const {
        /// this->i = t                     compile error: this is a pointer to const
        const_cast<type*>(this)->i = t; /// OK as long as the type object in not const.
     }
};
int main(){

    /// note: Pointer to function and pointers to member function are not subject to const_cast

    int i = 3;
    const int& cerf_i = i;
    const_cast<int&>(cerf_i) = 5;   /// okay: modifies i
    std::cout<<"i = "<<i<<std::endl;

    type t; /// note if this would be const type t; then t.f(4) is UB
    t.f(4);
    std::cout<<"type::i = "<<t.i<<std::endl;

    const int j = 3;

    int* pj = const_cast<int*>(&j);
    /// undefined behavior
    *pj = 5;
    std::cout<<j<<std::endl;

    /// pointer to member function const, okay
    void (type::*mfp)(int) const = &type::f;

    /// compile error: const_cast does not work on function pointers
    const_cast<void(type::*)(int)>(mfp);
}













