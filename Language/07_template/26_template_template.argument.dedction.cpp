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
In order to instantiate a function template, every template argument must be known,
but not every template argument has to be specified, like before: see file 15

template<typename To, typename From> To convert(From f){}
void f(float argc){
    convert<int>(argc);             // calls convert<int,float>(float)
    convert<float>(argc);           // calls convert<float,float>(float)
    int (*ptr)(float)=convert;      // instantiation convert<int,float>(float)
    /// one type sticks on To       : convert<int> sticks to To
    /// another sticks on From      : convert<???>(float) sticks to From
}

**/

template<class T> void f(std::initializer_list<T> t){}




int main(){
    /// P gives std::initializer_list<P> and A is a braced-init-list

    f({1,2,3});     // p=std::initializer_list<T>, A={1,2,3}
                    // P'1=T, A'1=1 deduces T=int
                    // P'2=T, A'2=2 deduces T=int
                    // P'3=T, A'3=3 deduces T=int
                    // deduction succeed, T=int

    f({1,"asdf"});  // P=std::initializer_list<T>, A={1,"asdf"}
                    // P'1=T, A'1=1: deduces T=int
                    // P'2=T, A'2="asdf", deduces T=const char*
                    // deduction fails, T ambiguous



return 0; }

