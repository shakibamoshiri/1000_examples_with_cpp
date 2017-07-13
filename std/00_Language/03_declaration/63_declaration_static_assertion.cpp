/**
static assertion

Performs compile-time assertion checking
Syntax:
static_assert (bool_constexpr, message )    since c++11
static_assert ( bool_constexpr  )       since c++17



**/

#include <iostream>
#include <string>
#include <type_traits>

template<class T>
void swap (T& a, T& b){
    static_assert(std::is_copy_constructible<T>::value,
                  "swap requires copying");
    static_assert(std::is_nothrow_move_constructible<T>::value
                  && std::is_nothrow_move_assignable<T>::value,
                  "swap may throw");

    auto c = b;
    b = a;
    a = c;
}

template<class T>
struct data_structure {
    static_assert(std::is_default_constructible<T>::value,
                  "Data Structure requires default-constructible elements");
};

struct no_copy {
    no_copy( const no_copy& ) = delete;
    no_copy() = default;
};

struct no_default {
    no_default () = delete;
};

int main(){

    int a,b;
    swap(a,b);
    /*
            static_assert(std::is_copy_constructible<T>::value,
                  "swap requires copying");
    */
    no_copy ncA, ncB;
    swap(ncA,ncB); // error: static assertion failed: swap requires copying

    /*
            static_assert(std::is_default_constructible<T>::value,
                  "Data Structure requires default-constructible elements");
    */
    data_structure<int> ds_ok;
    data_structure<no_default> ds_error; // error: static assertion failed: Data Structure requires default-constructible elements

}









