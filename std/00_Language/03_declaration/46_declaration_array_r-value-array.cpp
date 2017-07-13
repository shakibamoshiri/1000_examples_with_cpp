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

void f (int (&&x)[2][3] ){
    std::cout<<sizeof(x)<<std::endl;
}
struct X {
    int i[2][3];
}x;
template<typename T> using identity = T;

int main(){
    /*
        Array r-value
        Although arrays cannot be returned from functions by value and cannot
        be targets of most cast expression, array pr-value may be formed by using
        a type alias to construct an array temporary using brace-initialized
        function cast. Array x-value may be formed by accessing an array member
        of a class r-value or by using std::move or another cast or function
        call that returns an r-value reference.
    */
    std::cout<<sizeof(X().i)<<std::endl;    // size of the array
    f(X().i);                               // okay: binds to x-value
    //f(x.i);                                 // error: cannot binds to l-value
    int a[2][3];
    f(std::move(a));                        // okay, binds to x-value

    using arr_t = int[2][3];
    f(arr_t{});                             // okay: binds to pr-value
    f(identity<int[][3]>{{1,1,1},{2,2,2}}); // okay: binds to pr-value

}












