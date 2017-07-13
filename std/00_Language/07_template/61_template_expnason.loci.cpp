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
/// function argument lists:
// A pack expansion maybe appear inside the parentheses ( parenthesis () )
// of a function call operator, in which cast the largest expansion to the
// left of the ellipsis it the pattern that is expanded:
f(&args...);                // expands to f(&E1, &E2, &E3)
f(n, ++args...);            // expands to f(n, ++E1, ++E2, ++E3);
f(const_cast<const Args*>(&args)...);   // f(cosnt_cast<const E1*>(&x1), const_cast<const E2*>(&x2), const_cast<const E3*>(&x3))
f(h(args...) + args...);    // expand to f(h(E1, E2, E3) + E1, h(E1, E2, E3) + E2, h(E1, E2, E3) + E3 )
//
//
/// Template argument lists
// pack expansion can be used anywhere in a template in a argument list,
// provided the template has the parameters to match the expansion.
template<class A, class B, class... C> void func ( A arg1, B arg2, C... arg3){
    container<A,B,C...> t1;     // expands to:  container<A,B,E1,E2,E3>
    container<C...,A,B> t2;     // expands to:  container<E1,E2,E3,A,B>
    container<A,C...,B> t3;     // expands to:  container<A,E1,E2,E3,B>
}
//
//
/// Function parameter list
// In a function parameter list, if an ellipsis appears in a parameter declaration
// ( whether it names a function parameter pack (as in, Args... args) or not ) the
// parameter declaration is the pattern
template<typename... Ts> void f(Ts...){}
f('a',1);       // Ts... expands to void f(char,int)
f(0.1);         // Ts... expands to void f(double)
template<typename... Ts, int... N> void g(Ts (&... arr)[N]) {}
int n[1];
g<cons char, int>("a",n);       // Ts (&...arr)[N] expands to const char (&)[2], int (&)[1]

// Note: in the pattern Ts (&... arr)[N], ellipsis is the innermost, not the lest element
// as is all other pack expansions.
// Note: Ts (&...)[N] is not allowed because the c++11 grammar required the parenthesized
// ellipsis to have a name: CWG #1488
//
//
/// Template parameter lists
// pack expansion may appear in a template parameter list:
template<typename... T> struct value_holder {
    template<T... Values>   // expands to a non-type template parameter
    struct apply {};        // list, such as <int, char, int(&)[5]>
};
//
//
/// Base specifier and member initializer list
// A pack expansion may designate the list of base classes in a class declaration.
// Typically, this also means that the constructor needs to use a pack expansion
// in the member initializer list to call the constructors of these bases:
template<class... Mixins>
class X : public Mixins... {
public:
    X ( const Mixins&... mixins) : Mixins(mixins)... {}
};
//
//
/// Braced initializer list
// in a braced-init-list ( brace-enclosed list of initializers and other braced-init-list,
// used in list-initialization and some other contexts), a pack expansion may appear as well:
template<typename... Ts> void func (Ts... args){
    const int size = sizeof...(args)+2;
    int res[size] = {1,args...,2};
    // since initializer lists guarantee sequencing, this can be used to
    // call a function on each element of a pack, in order:
    int dummy[sizeof...(Ts)] = { (std::cout<<args, 0) ... };
}


int main(){}


