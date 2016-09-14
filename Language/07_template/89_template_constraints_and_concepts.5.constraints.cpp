/*
Template:
    01 template parameter and template argument
    02 class template
    03 function template
    04 variable template
    05 template argument deduction
    06 explicit (full) template specialization
    07 partial template specialization
    08 parameter pack
    09 sizeof ... operator
    10 fold expression
    11 dependent names
    12 SFINAE

    13 constraints and concepts
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <utility>


/// 13 constraints and concepts
//
//
//
/// Constraints
// A constraint is sequence of logical operators that specifies requirements
// on template arguments. They can appear within requires-expression and
// directly as bodies of concept
// There are 9 types of constraints:
/*
01  conjunction
02  disjunction
03  predicate constraints
04  expression constraints ( only in a requires-expression )
05  type constraints ( only in a requires-expression )
06  implicit conversion constraints ( only in a requires-expression )
07  argument deduction constraints ( only in a requires-expression )
08  exception constraints ( only in a requires-expression )
09  parameterized constraints ( only in a requires-expression )
*/
// the first three type of constraints may appear directly as the body
// of a concept or as an ad-hoc require clause:
template<typename T>
requires                        // requires-clause ( ad-hoc constraints )
sizeof(T) > 1 && get_value<T>() // conjunction of two predicate constraints
void f(T);

//
//
//
/// conjunction
// Conjunction of constraints P and Q is specified as P && Q
// A conjunction of two constraints is satisfied if both constraints are satisfied.
//
// template concept form the standard library ( Ranges TS )
template<class T> concept bool Integral = std::is_integral<T>::value;
template<class T> concept bool SignedIntegral = Integral<T> && std::is_signed<T>::value;
template<class T> concept bool UnsignedIntegral = Integral<T> && !SignedIntegral<T>;
//
//
//
/// disjunction
// Disjunction of constraints P and Q is specified as P || Q
// A disjunction of two constraints is satisfied if either constraints is satisfied.
//
// example constraint form the standard library ( Ranges TS )
template<class T = void> requires EqualityComparable<T>() || Same<T, void> struct equal_to;
//
//
//
/// predicate constraints
// A predicate constraint is a constant expression of type bool. it is
// satisfied if it equivalent to true
//
// predicate constraints must evaluate directly to bool, no conversion allowed:
//
template<typename T> struct S {
    constexpr explicit operator bool() const { return true; }
};
template<typename T>
requires S<T>       // bad predicate constraint: S<T> is not boolean
void f (T);
f(0);               // error, constraint never satisfied
//
//
//
/// requirement
// one: To introduce a requires-clause
template<typename T>
void f(T&&) requires Eq<T>;                 // can appear as the last element of a function declarator

template<typename T> requires Addable<T>    // or right after a template parameter list
T add (T a,T b) { return a + b; }


// two: To begin a requires-expression
template<typename T>
concept bool Addable = requires (T x) { x+x };  // requires-expression

template<typename T> requires Addable<T>        // requires-clause, not requires-expression
T add (T a,T b) { return a+b; }

template<typename T>
requires requires (T x) { x+x; }                // ad-hoc constraint, not keyword used twice
T add (T a,T b) { return a+b; }



/// simple requirement
// A simple requirement is an arbitrary expression
template<typename T>
concept bool = Addable = requires (T a, T b){
    a+b;    // the expression a+bis a valid expression that will compile
};

// example constraint from the standard library ( Ranges TS )
template<class T, class U = T>
concept bool Swapable = requires(T t, U u) {
    swap(std::forward<T>(t), std::forward<U>(u) );
    swap(std::forward<U>(u), std::forward<T>(t) );
};



/// type requirement
// A type requirement is the keyword typename followed by a type name, optionally qualified.
template<typename T> using Ref = T&;
template<typename T> concept bool C = requires () {
    typename T::inner;      // required nested member name
    typename S<T>;          // required class template specialization
    typename Ref<T>;        // required alias template sub-situation
};

// example concept from the standard library ( Ranges TS )
template<class T, class U> using CommanType = std::common_type_t<T, U>;
template<class T, class U> concept bool Common = requires (T t, U u) {
    typename CommonType<T, U>;      // commonType<T, U> is valid and name a type
    { CommonType<T, U> {std::forward<T>(t)} };
    { CommonType<T, U> {std::forward<U>(u)} };
};


/// compound requirement
// A compound requirement has the form
// { expression } noexcept (optional) trailing-return-type (optional)
// for more detail see: en.cppreference.com
template<typename T> concept bool C2 = requires (T x) {
    {*x} -> typename T::inner;
    // the expression *x must be valid
    // and the type T::inner must be valid
    // and type result of *x must be convertible to T::inner
};

// example concept from the standard library ( Ranges TS )
template<class T, class U> concept bool Same = std::is_same<T,U>::value;
template<class B> concept bool Boolean = requires(B b1, B b2) {
    { bool(b1) };                               // direct initialization constraint has to use expression
    { !b1 } -> bool;                            // compound constraint
    requires Same<decltype(b1 && b2), bool>;    // nested constraint,
    requires Same<decltype(b1 || b2), bool>;



/// nested requirement
// A nested requirement is another requires-clause, terminated with a semicolon.
//
// example constraint form ( Ranges TS )
template<class T> concept bool Samereqular = DefaultConstructible<T> &&
                                             CopyConstructible &&
                                             Destructible &&
                                             CopyAssignment &&
    requires (T a, size_t n) {
        requires Same<T*, decltype(&a)>;    // nested   "Same<...> evaluates is true"
        { a.~T() } noexcept;                // compound "a.~T() is a valid expression that does not throw
        requires Same<T*, decltype(new T>;      // nested   "Same<...> evaluates to true"
        requires Same<T*, decltype(new T[n])>;  // nested
        { delete new T };                   // compound
        { delete new T[n]};                 // compound
    };


/// concept resolution
// Like any other function template, a function concept ( but not variable concept )
// can be overloaded
template<typename T> concept bool C() { return true; }               // #1
template<typename T, typename U> concept bool C() { return true; }   // #2
void f(C);      // the set of concepts referred to by C includes
                // both #1 and #2 concept resolution
                // here select #1

//
//
templat<typename T> concept bool C() { return true; }           // #1
template<typename T, typename U> concept bool C() {return true;}// #2
void f(const C*);       // <wildcard> matches <T>, selects #1
                        // A wildcard can match template parameter of any kind (type, non-type, template)

template<typename T> concept bool C() { return true; }          // #1
template<typename T,typename U> concept bool c(){return true;}  // #2
void  f(C<char>);       // <wildcard, char> matched <T, U>, selected #2

// if a concept appears in a template introduction, the argument list is a
// sequence of placeholder as long as the list of parameter in the template introduction
template<typename ... Ts> concept bool B = true;
B{T}     void f();      // okay, <T> matches <...Ts>
B{...Ts} void g();      // okay, <...Ts> matches < ... Ts >

// if a concept appears as the name of a template-id, the concept argument
// list is exactly the sequence of arguments of that template-id
template<typename T> concept bool C() { return true; }          // #1
template<typename T,typename U>concept bool C() {return true;}  // #2

template<typename T>
void f(T> requires C<T>;    // matches #1

// if any argument does not match its corresponding parameter or if there are
// more argument than parameters and the last parameter is not a pack, the
// concept is not valid. If there is zero or more than one viable concept
// the program is ill-formed.
template<typename T> concept bool E() { return true; }  // #1
template<int T>      concept bool E() { return true; }  // #2

template<E<0> T> struct S1;     // error, <wildcard, 0> matches, neither <typename T> not <int T>
template<E T>    struct s2;     // both #1 and #2 match

