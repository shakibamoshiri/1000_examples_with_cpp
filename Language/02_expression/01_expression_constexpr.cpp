///
/// Expression
///
/// constant expression
/**
Defines an expression that can be evaluated a compile time.
Such expression can be used an non-type template argument, array
sizes, and other contexts that require constant expression.

int n = 1;
std::array<int, n> arr; // Error, because n is not a constant expression.
const int n2;
std::array<int ,n2> arr2; // okay, because n2 is a constant expression.

more information:
http://stackoverflow.com/questions/14116003/difference-between-constexpr-and-const
**/

#include <iostream>
#include <cassert>
int x=2;
struct A {
    int m;
    constexpr A(bool b) : m( b ? 10 : x ){}
};

int main(){
    { /// my sample
    }
    { /// en.reference.com
        /// Error
        constexpr int i = A(false).m;

        /// okay
        constexpr int i = A(true).m;
        std::cout<<i;
    }

}
