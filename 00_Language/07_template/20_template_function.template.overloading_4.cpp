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
/// 03 Function Template
/**
Function template overloading
function template and non-template function may be overloaded.

**/
// more specialization
template<class T> void f(T);            // #1
template<class T> void f(T*);           // #2
template<class T> void f(const T*);     // #3
void d(){
    const int* p;
    f(p);       // overload resolution picks:   #1  void f(T)   [T= const int*]
                //                              #2  void f(T*)  [T= const int]
                //                              #3  void f(const T*)    [T= int]
    // #3 is more specialized
    // in other word, f(const T*) is more specialized than f(T) and F(T*)
}


template<class T> void f(T, T*);        // #1
template<class T> void f(T, int*);      // #2
void d(int* p){
    f(0, p);    // deduction for #1:    void f(T, T*)   [T = int]
                // deduction for #2:    void f(T, int*) [T = int]
    // Neither is more specialized w.r.t. T the call is ambiguous
}



int main(){ return 0; }

