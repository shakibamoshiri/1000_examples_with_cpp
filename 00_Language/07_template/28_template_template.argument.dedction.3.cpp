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
// set of overloaded function
template<class T> int f( T (*p)(T) ){}
int g(int);
int g(char);
f(g);   // P=T(*)(T), A+overload set
        // P=T(*)(T), A1=int(int):  deduces T=int
        // P=T(*)(T), A2=int(char): fails to deduces
        // only one overload work, deduction succeeds

template<class T> void f(T){}
int a[3];
f(a);           // P = T, A = int[3], adjusted to int*. Deduces T = int

const int b=11;
f(b);           // P = T, A = const int, adjusted to int. Deduces T = int

void g(int){}
f(g);           // P = T, A = void(int), adjusted to void(*)(int). Deduces T = void (*)(int)


template<class T>
int f(T&&);         // P is a r-value reference to cv-unqualified T ("forwarding reference")
template<class T>
int g(const T&&);   // P is a r-value reference to cv-qualified T ( not special )

int main(){

    int i;
    int n1 = f(i);  // argument is l-value:     calls f<int&>(int&) ( special case )
    int n1 = f(0);  // argument is not l-value: calls f<int>(int&&)

    int n3 = g(i);  // error, deduces to g<int>(const int&&), which cannot bind to r-value reference to an l-value

return 0; }

