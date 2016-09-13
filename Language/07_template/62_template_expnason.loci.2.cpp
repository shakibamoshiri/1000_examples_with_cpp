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
#include <typeinfo>
template<typename T> void print(const T value){std::cerr<<value<<std::endl;}

template<class T> struct make { typedef T type; };

/// 08 Parameter Pack
// A template parameter pack is a template parameter that accepts zero or more template
// arguments ( non-types or types ) A function parameter pack is a function template
// that accepts zero or more function arguments.
/** A template with at least one parameter pack is called a variadic template **/
// syntax:
// 1    type... Args (optional )
// 2    template | class ... Args (optional )
// 3    template <parameter-pack > typename ( c++17 ) class ... Args (optional )
// 4    Args... args (optional)
// 5    pattern...
// 1:   A non-type template parameter pack ( int ... I )
// 2:   A type template parameter pack
// 3:   A template template parameter pack
// 4:   A function template parameter pack
// 5:   parameter pack expansion: expands to comma-separated list of zero or more
//      patterns. Pattern must include at least one parameter pack.
//
// Expansion loci ( loci is plural of locus. It means: The exact place where something happens or which is that is thought to be the center of something )
// Depending on where the expansion takes place, the resulting comma-separated
// list is a different kind of list:
// function parameter list
// member initializer list
// attribute list ,etc the following is the list of allowed:
//
//
//
//
/// Lambda captures
// A parameter pack may appear in the capture classes of a lambda expression
template<class... Args> void f (Args... args) {
    auto lm = [&, args...] { return g(args...); };
    lm();
}
//
//
/// The sizeof... operator
// The sizeof... operator is classified as a pack expression as well:
template<class ...Types> struct count {
    static const std::size_t value = sizeof...(Types);
};
//
//
/// Dynamic exception specialization
// The list of exceptions is dynamic exception specialization may also be a pack expansion
template<class.... X> void func (int arg ) throw(X...) {
    // ... throw different Xs in different situations
}
//
//
/// Alignment specifier
// Pack expression are allowed in the lists of expression used by the keyword align
//
//
/// Attribute list
// Pack expansion are allowed in the lists of attribute, as in [[ attribute ]], For
// example: void [[ attribute... ]] function ()
//
//
/// Fold-expressions
// In fold-expression, the pattern is the entire subexpression that does not contain
// an unexpanded parameter pack.


int main(){

}


