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

/// 11 SFINAE ( Subsituation Failure Is Not An Error )
// This rule applies during overload resolution of function template:
// When sub-situating the deduced type for the template parameter fails,
// the specialization is discarded form the overload set instead of causing
// a compile error.
// This feature is used in template meta-programming. for more detail read main site: en.cppreference.com
//
//
/// Type SFINAE
// the following type errors are SFINAE errors:
// >    attempting to instantiate a pack expansion containing multiple packs of different
// >    attempting to create an array of void, array of reference, array of function, array of
//      abstract class type, array of negative size, or array of size zero
template<int I> void div (char (*) [I%2==0]=0){
    //  this overload is selected when I is even
    std::cout<<"this overload is selected when I is even"<<std::endl;
}
template<int I> void div ( char (*) [I%2==1]=0){
    // this overload is selected when I is odd
    std::cout<<"this overload is selected when I is odd"<<std::endl;
}

// >    attempting to use a type that is not a class or enumeration on the
//      left of a scope resolution operator ::
template<class T> int f(typename T::B* );
template<class T> int f(T);
int i = f<int>(0);  // it uses: int f(T);

int main(){

    div<3>();
    div<4>();

}
// error: no matching function for call to ‘div(char (*)[4])’|
