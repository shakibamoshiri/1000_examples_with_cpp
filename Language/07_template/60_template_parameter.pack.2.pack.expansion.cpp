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
// Pack Expansion
// A pattern followed by an ellipsis in which the name of at least one parameter
// pack appears at least once, is expanded into zero or more comma-separated
// instantiations of the pattern, where the name of the parameter pack is replaced
// by each of the type form the pack, in order.
template<class... Us> void f(Us... paras) {}
template<class... Ts> void g(Ts... args ) {
    f(&args...);        // "&args..." is a pack expansion
                        // "&args" is its pattern
}
g(1, 0.2, "a");         // Ts... args expand to int E1, double E2, const char* E3
                        // &args... expand to &E1, &E2, &E3
                        // Us.. paras expand to int* E1, double* E2, const char** E3
//
// if the names of two  parameter pack appears in the same pattern, they are
//; expanded simultaneously, and they must have the same length:
template<typename...> struct Tuple {};
template<typename T1, typename T2> struct Pair {};
template<class... Args1> struct zip {
    template<class... Args2> struct with  {
        typedef Tuple<Pair<Args1, Args2> ... > type;
        // Pair<Args1, Args2> ... is the pack expansion
        // Pair<Args1, Args2> is the pattern
    };
};
typedef zip<short, int>::with<unsigned short, unsigned::type T1;
// Piar<Args1, Args2>... expands to
// Pair<short, unsigned short>, Pair<int, unsigned int>
// T1 is Tuple< Pair< short, unsigned short>, Pair<int, unsigned> >
//
typedef zip<short>::with<unsigned short, unsigned>::type T2;
// error, pack expansion contains parameter packs or different length
//
// if a pack expansion is nested within another pack expansion, the parameter
// packs that appear inside the innermost pack expansion are expanded by it,
// and there must be another pack mentioned in the enclosing pack expansion,
// but not in the innermost one:
template<class... Args>
void g(Args... args) {
    f(const_cast<const Args*>(&args)...);
    // const_cast<const Args*>(&args)   is the patten, it expands two packs
    // Args and args simultaneously
    f(h(args...) + args... );   // Nested pack expansion:
    // inner pack expansion it "args...", it it expanded first
    // outer pack expansion it h(E1, E2, E3) + args..., it is expanded
    // second ( as h(E1, E2, E3 ) + E1, h(E1, E2, E3) + E2, h(E1, E2, E3 ) + E3
}




int main(){

}
