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
/// 01 template parameter and template argument

/// example, non-type template parameter

// simple non-type template parameter
template<int N> struct S {
    int a[N];
};
template<const char*> struct S2{};

// complicated non-type
template<
    char c,
    int (&ra)[5],
    int (*pf)(int),
    int (S<10>::*a)[10]>
    struct Complicated {
        // calls the function selected at the compile time
        // and stores the result in the array selected at compile time
        void f(char base){
        ra[4] = pf(c-base);
        }
    };
//S2<"test"> s2;      // error, string literal can not be used
char okay[]="okay"; // static object with linkage
//S2<&okay[0]> s3;    // error, array element has no linkage
S2<okay> s4;        // okay, works

int a[5];
int f(int t){return t;}


int main(){
    S<10> s;    // s.a is an array of 10 int
    s.a[9]=9;

    Complicated< '2',a,f,&S<10>::a > c;
    c.f('0');

    std::cout<<s.a[9]<<' '<<a[4]<<std::endl;
}

