/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/




#include <iostream>
#include <functional>


struct F {
    unsigned operator()( const int value = 20 ){
        return value;
    }
} function;



int main(){

    std::cout << function() << '\n';
    std::cout << function(200) << '\n';

}
/* output

20
200

Process returned 0 (0x0)   execution time : 0.055 s
Press ENTER to continue.


*/
