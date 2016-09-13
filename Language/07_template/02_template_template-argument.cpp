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
/// 01 template parameter and template argument

// template argument
// if an argument can be interpreted as a both a type-id and an expression
// it is always interpreted as a type-id, even if the corresponding template
// parameter is non-type
template<typename T> void f(){}  // #1
template<int      I> void f(){}  // #2

void g(){
    f<int()>(); // "int()" is both a type and an expression
}               // calls #1 it is interpreted as a type

// The template argument that can be used with a non-type template parameter
// can be any converted constant expression of the type of the template parameter
template<const int* PCI> struct X {};
int ai[10];
X<ai> xi;   // okay, array to pointer conversion and cv-qualification conversion

struct Y{};
template<const Y& YY> struct Z {};
Y y;
Z<y> z;     // okay, no conversion and cv-qualification conversion

template<int (&pa)[5]> struct W {};
int b[5];
W<b> w;

void s(char){}
void s(int) {}
template<void (*pf)(int)> struct P {};
P<s> p;     // okay, overload resolution selects void s(int)


int main(){}
