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
/// Placeholder
// The unconstrained placeholder 'auto' and constrained 'placeholders' which
// have the form
// concept-name < template-argument-list ( optional )> ,
// are placeholders for the type that is to be deduced.
// Placeholders may appear in variable declaration ( in which cast they are deduced
// form the initializer ) or in function return types ( in which case they are
// deduced form return statement )
std::pair<auto, auto> p2 = std::make_pair(0, 's');  // first auto is int, second is char

Sortable x = f(y);              // The type of x is deduced from the return type of f,
                                // only compiles if the type satisfies the constraint Sortable

auto f(Container) -> Sortable;  // return type is deduced formthe return statement
                                // only compiles if the  type satisfies Sortable

// Placeholder may also appear in parameters, in which case they turn function
// declarations into template declaration ( constrained if the placeholder is constrained )
void f ( std::pair<auto, EqualityComparable> );     // this is a template whit two parameter:
                                                    // unconstrained type parameter         ( auto )
                                                    // and a constrained non-type parameter ( EqualityComparable )

// Constrained placeholder may be used anywhere auto may be used,
// for example, in generic lambda declarations:
auto g1  = [](Assignable& a, auto* b) { a =* b; };

// if constrained type specifier designate a non-type or a template, but
// it used as a constrained placeholder, the program is ill-formated
template<std::size_t N> concept bool Even = (N%2 == 0 );
struct S1 { int n; };
int Even::* p2 = &S1::n;            // error, invalid use of a non-type concept

void f ( std::array<auto, Even> );  // error, invalid use of a non-type concept

template<Even N> void f(std::array<auto, N> );  // okay
