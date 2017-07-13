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
/// Example
void tprintf(const char* format){   // base function
    std::cout<<format;
}
template<typename T, typename... Targs>
void tprintf(const char* format,T value, Targs... Frags){   //recursive variadic function
    for ( ; *format != '\0'; format++ ) {
            if ( *format == '%' ) {
                    std::cout<<value;
                    tprintf( ++format++,Frags...);        // recursive call
                    // both okay, format+1
                    // or        ++format
                    // but format++ is not correct
                    // because it calculate ++ later, but here format needs increase instantly
                    // tprintf( format+1,Frags...);        // recursive call
                    return;
            }
            std::cout<<*format;
    }
}


int main(){
    tprintf("% world% %\n","Hello","!",1234);
}


