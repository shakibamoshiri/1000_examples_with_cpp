/*
            Error Handling
            **************

4.  Assertion
        > static_assertion  : performs compile-time assertion checking
        > assert            : aborts the program if the user-specified condition is not true. May be disabled for release builds

*/
/// static_assert (bool_condition, message) since C++11
/// static_assert (bool_condition)          since C++17
// Massage can only be literal
//
// Performs compile-time assertion checking

#include <type_traits>

template<class T> void swap (T& left, T& right){
    static_assert( std::is_copy_constructible<T>::value, "Swap required coping");

    static_assert( std::is_nothrow_move_constructible<T>::value &&
                   std::is_nothrow_move_assignable<T>::value, "Swap may throw");

    auto tmp = right;
    right = left;
    left = tmp;
}

template<class T>
struct data_structure {
    static_assert( std::is_default_constructible<T>::value, "data_structure requires default-constructible elements" );
};

struct no_copy {
    no_copy (const no_copy&) = delete;
    no_copy () = default;
};

struct no_default {
    no_default () = delete;
};

int main(){

    int one, two;
    swap( one, two );

    data_structure<int> ds_ok;

    data_structure<no_default> ds_error; // runs static_assert

}
