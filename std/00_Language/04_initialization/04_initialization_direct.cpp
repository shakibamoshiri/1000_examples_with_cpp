/*
Initialization:
    value       initialization
    copy        initialization
    direct      initialization
    aggregate   initialization
    list        initialization
    reference   initialization
    zero        initialization
    constant    initialization
********************************
Direct Initialization
Initializes an object form explicit set of constructor argument
Syntax:

1   T object ( arg );
1   T object ( arg1, arg2, ... );

2   T object { arg };
2   T object {arg1, arg2, ... }; since c++11

3   T ( other );
3   T ( arg1, arg2, ... );

4   static_cast<T>( other );
5   new T( args, ...);
6   class::class() : member ( args, ...) {...
7   [ arg ](){...

Note:   Direct-initialization is more permissive than copy-initialization: copy-initialization
        only considers non-explicit constructors and user-defined conversion function, while
        direct-initialization considered all constructors and implicit conversion sequences.
*/

#include <iostream>
#include <string>
#include <memory>
#include <utility>

struct F {
    int mem;
    explicit F(int n): mem(n) {}
};


int main(){
    std::string s1("test");         // direct-initialization, constructor form const char*
    std::string s2(10, 'A');        // okay, also

    std::unique_ptr<int> p(new int(1));     // okay, explicit constructor allowed
//    std::unique_ptr<int> m = new int(1);    // error, constructor is explicit

    F f(2);     // f is direct-initialization:
                // constructor parameter n is copy-initialization form the r-value 2
                // f.mem is direct-initialized form the parameter n
//    F f2=2;     // error, constructor is explicit

    std::cout<<s1<<' '<<s2<<' '<<*p<<' '<<f.mem<<std::endl;
}









