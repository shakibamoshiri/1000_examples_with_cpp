/**
/// typedef specifier
The typedef declaration provided a way to create an alias that can be
used anywhere in place of a ( possibly complex ) type name.

syntax
typedef type_declaration
**/
#include <iostream>
#include <string>

// simple typedef
typedef unsigned long long llong;
// the following two objects have the same type
unsigned long long L1;
llong              L2;

// more complicated typedef
typedef int int_t, *intp_t, (&fp)(int, llong), arr_t[10];
// two objects have the same type
int a[10];
arr_t a2;

// common C idiom to avoid having to write "struct S"
typedef struct {int a;int b;}S, *pS;
pS ps1;
S* ps2;

// error: conflicting specifiers in declaration of ‘suint’
// typedef static unsigned int suint;

// std::add_const, like many other metafunctions, use member typedefs
template<class T>
struct add_const {
    typedef const T type;
};

int main(){
    add_const<int>::type i = 3;
    std::cout<<i<<std::endl;

    add_const<char*>::type s = "How are you today?";
    std::cout<<s<<std::endl;



}









