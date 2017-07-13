/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

Type Traits (since C++11)
    Type traits defined a compile-time template-based interface to query or modify the
    properties of types. Any attempts to specialize any of the class template listed in
    This section results in undefined behavior, except that std::common_type may be
    specialized if the specialization depends on user-defined type

    (defined in header <type_traits>)

    Type Properties
    > is_const                       "                   const-qualified
    > is_volatile                    "                   volatile-qualified
    > is_trivial                     "                   trivial
    > is_trivially_copyable          "                   trivially copyable
    > is_standard_layout             "                   standard layout type
    > is_pod                         "                   plain-old date (POD) type
    > is_literal_type                "                   literal type
    > is_empty                       "                   class (not union) type and has no data
    > is_polymorphic                 "                   polymorphic class type
    > is_final                       "                   a final class type
    > is_abstract                    "                   abstract class type
    > is_singed                      "                   signed arithmetic type
    > is_unsigned                    "                   unsigned arithmetic type

*/
/// std::is_trivial_copyable
//    If T is a TriviallyCopyable type, provides the member constant value equal
//    true. For any other type, value is false. The only trivially copyable types
//    are scalar types, trivially copyable classes, and arrays of such types/classes
//    (possibly const-qualified, but not volatile-qualified).
//
//    A trivially copyable class is a class that
//
//        Has no non-trivial copy constructors (this also requires no virtual functions or virtual bases)
//        Has no non-trivial move constructors
//        Has no non-trivial copy assignment operators
//        Has no non-trivial move assignment operators
//        Has a trivial destructor
//
//    The behavior is undefined if std::remove_all_extents_t<T> is an incomplete type and not
//    (possibly cv-qualified) void.
//
/// NOTE:
//    Objects of trivially-copyable types are the only C++ objects that may be safely
//    copied with std::memcpy or serialized to/from binary files with std::ofstream::write()/std::ifstream::read().
//    In general, a trivially copyable type is any type for which the underlying bytes
//    can be copied to an array of char or unsigned char and into a new object of the
//    same type, and the resulting object would have the same value as the original.

#include <iostream>
#include <type_traits>
struct A {
    int m;
};

struct B {
    B(const B&) {}
};

struct C {
    virtual void foo();
};

int main(){

    std::cout << std::boolalpha;
    std::cout << std::is_trivially_copyable<A>::value << '\n';      // true
    std::cout << std::is_trivially_copyable<B>::value << '\n';      // false
    std::cout << std::is_trivially_copyable<C>::value << '\n';      // false
}
