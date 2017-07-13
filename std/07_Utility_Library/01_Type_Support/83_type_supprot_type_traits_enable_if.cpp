
/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

Miscellaneous Transformations (in header <type_traits>
    > aligned_storage           defines the type suitable for use as uninitialized storage for type of given size
    > aligned_union             defines the type suitable for use as uninitialized storage for all given types
    > decay                     applies type transformations as when passing a function argument by value
    > enable_if                 hides a function overload or template specialization based on compile-time boolean
    > conditional               chooses one type of another based on compile-type boolean
    > common_type               deduces the result type of mixed-mode arithmetic expression
    > underlying_type           obtains the underlying integer type for a given enumeration type
    > result_of                 deduces the return type of a function call expression
    > void_t                    void variadic alias template

*/
/// std::enable_if
// template<bool B, class T = void> struct enable_if
//
// If B is true, std::enable_if has a public member typedef type, equal to T;
// otherwise, there is no member type.
//
// This metafunction is a convenient way to leverage SFINAE to conditionally
// remove function from overload resolution based on  type traits and to provide
// separate function overloads and specifications for different type traits.
// std::enable_if can be used as an additional function argument (not applicate to operator overload)
// as a return type (not applicate to constructors and destructors ), or as a
// class template of function template parameter.


#include <iostream>
#include <type_traits>
#include <string>

namespace detail { struct inplace_t {}; }
void* operator new(std::size_t, void* ptr, detail::inplace_t){ return ptr; }

// #1   enabled via the return type
template<class T, class... ARGS>
typename std::enable_if< std::is_trivially_constructible<T, ARGS&&...>::value >::type
construct(T* t,ARGS&&... args) { std::cout << "constructing trivially constructible T\n"; }

// #2
template<class T, class... ARGS>
typename std::enable_if< ! std::is_trivially_constructible<T, ARGS&&...>::value >::type
construct(T* t,ARGS&&... args) {
    std::cout << "constructing non-trivially constructible T\n";
    new(t, detail::inplace_t{}) T(args...);
}

// #3   enabled via a parameter
template<class T>
void destroy(T* t, typename std::enable_if< std::is_trivially_destructible<T>::value >::type* = 0){
    std::cout << "destroying trivially destructible T\n";
}

// #4   enabled via a template parameter
template<class T, typename std::enable_if<
! std::is_trivially_destructible<T>{} &&
( std::is_class<T>{} || std::is_union<T>{} )>::type* = nullptr>
void destroy(T* t){
    std::cout << "destroying non-trivially destructible T\n";
    t -> ~T();
}

// #5 enabled via template parameter
template<class T, typename = std::enable_if_t< std::is_array<T>::value > >
void destroy(T* t){ // note: function signature is unmodified
    for( std::size_t i = 0; i < std::extent<T>::value; ++i ) destroy( (*t)[i] );
}

/*
template<class T, typename = std::enable_if_t< std::is_void<T>::value > >
void destroy(T* t){ } //   ERROR    has the same signature with #5
*/

// the partial specialization of A is enable via a template parameter
template<class T, class Enable = void> class A {};  // primary template

template<class T> class A <
    T,
    typename std::enable_if< std::is_floating_point<T>::value >::type
    > {};   // specialization for floating points type



int main(){
    std::aligned_union_t< 0, int, std::string > u;

    construct(reinterpret_cast<int*>(&u));
    destroy(reinterpret_cast<int*>(&u));

    construct(reinterpret_cast<std::string*>(&u),"hello");
    destroy(reinterpret_cast<std::string*>(&u));

    A<int> a1;      // okay, matches the primary template
    A<double> a2;   // okay, matches the partial specialization
}
