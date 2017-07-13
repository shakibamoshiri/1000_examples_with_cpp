/*
    quick review:
    General-Purpose Utility

    01. program utility
    02. date and time
    03. function object
    04. bitset
    05. pair
    06. tuple
    07. swap, forward, move
    08. type operations
    09. hash support

*/
/// 03. function object in header <functional>

//  may you would like to define a function object to yourself

#include <iostream>
#include <functional>

struct S {
    typedef int Integer;
    Integer i;
    S( Integer t ) : i( t ) {}; // with using this constructor call, we get an error, so it should be declare
};


int main(){

    // remember this syntax, because for function object we use exactly this style:

    S one = 10;     // conversion constructor call
    std::cout << one.i << '\n'; // 10

}


/* output:



*/
