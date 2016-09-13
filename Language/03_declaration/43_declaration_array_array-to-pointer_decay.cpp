/**
/// Array Declaration
///
Declares an object of array type.

Syntax:

noptr-declarator [ constant-expression ( optional ) ] attribute ( optional )
noptr-declarator    any valid declarator, but if it begins with *, &, &&, it
                    has to be surrounded by parentheses.
attribute           optional list of attributes
constant-expression an integral constant expression ( until c++14 ) a converted
                    constant expression of type std::size_t ( since c++14 ), which
                    evaluates to a value greater than zero.

**/
#include <iostream>
#include <string>
#include <numeric>
#include <iterator>

void g(int (&a)[3]){
    std::cout<<a[0]<<std::endl;
}
void f(int* p){
    std::cout<<*p<<' '<<*(p+1)<<' '<<*(p+2)<<std::endl;
}

int main(){
    /*
        Array-to-pointer decay
        There is an implicit conversion form l-value and r-value of array type
        to r-values of pointer type: it constructs a pointer to the first element
        of an array. This conversion is used whatever arrays appear in context where
        array are not expected, but pointer are
    */
    int a[3] = { 1,2,3};
    int* p = a; // *p points to a[0]
                // *(p+1) points to a[1]
                // *(p+2) points to a[2]
    std::cout<<sizeof(a)<<std::endl
             <<sizeof(p)<<std::endl;

    // where arrays are acceptable, but pointer are not, only array may be used
    g(a);   // okay, function takes an array by reference
//    g(p);   // error

    for ( int n : a )
        std::cout<<n<<' ';  // okay, array can be used in range-for loops

//    for ( int n : p )
//        std::cout<<n<<' ';  // error

    std::iota(std::begin(a), std::end(a),7);    // okay, begin and end take array
//    std::iota(std::begin(p), std::end(a),7);    // error

    // where pointer are acceptable, but arrays are not, both may be used.
    std::cout<<std::endl;
    f(a);   // okay
    f(p);   // okay

}












