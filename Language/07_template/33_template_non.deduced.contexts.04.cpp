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
/// 05 template argument deduction
/**
**/
//  Non-deduced Contexts
//
//  04  a template parameter used in a template type of a function parameter
//      that has a default argument that is being used in the call for which
//      argument deduction is begin done.
template<typename T,typename F>
void f( const std::vector<T>& arr, const F& comp = std::less<T>() );
std::vector<std::string> arr(3);
f(arr);     // P1 = const std::vector<T>&       A1 = std::vector<std::string> l-value
            // P1 / A1 deduces T = std::string
            // P2 = non-deduced context for F ( template parameter ) used in the parameter
            //      type const F& of the function parameter comp.
            // that has a default argument that is being used in the call f(arr)

int main(){
return 0; }

