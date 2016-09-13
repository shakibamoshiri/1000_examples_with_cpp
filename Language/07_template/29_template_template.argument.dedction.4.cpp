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
// If the usual deduction from P and A fails, the following alternative are additionally considered:
// 1. if the original P is a reference type, the deduced A (i.e the type referred to by the reference )
//     can be more cv-qualified then the transformed A
template<typename T> void f1(const T& t){}
bool a = false;
f1(a);      // P = const T&, adjusted to const T, A = bool
            // deduced T = bool, deduced A = const bool
            // deduced A is more cv-qualified than A

// 2. the transformed A can be another pointer or pointer to member type
//    that can be converted to the deduced A via a qualification-conversion
//    or a function pointer conversion ( since c++17 )
template<typename T> void f(const T*){}
int* p;
f(p);       // P = T, A = int*
            // deduces T = int, deduced A = const int*
            // qualification-conversion applies ( form int* to const int*)

// 3. if P is a class and P has the form simple-template-id, then the transformed A
//    can be a derived class of the deduced A. likewise (means: formal:1. the same, 2. also)
//    , if P is a pointer to a class of the form simple-template-id, the transformed A can
//    a pointer to a derived class pointed to by the deduced A.
template<class T> struct B {};
template<class T> struct D : public B<T> {};
template<class T> void f(B<T>&) {}
void f(){
    D<int> d;
    f(d);   // P = D<T>& , adjusted P = B<T> ( a simple-template-id)
            // A = D<int>
            // deduced T = int, deduced A = B<int>
            // A is derived form deduced A


int main(){
return 0; }

