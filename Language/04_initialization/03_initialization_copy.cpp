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
Copy Initialization
Initializes an object form another object.

Syntax:
1   T object = object;
2   T object = { other };
3   f (other)
4   return other;
5   throw other;
6   catch ( T object )
7   T array[N] = { other };

Note:   Copy-initialization is less permissive than direct-initialization: explicit constructor
        are not converting constructors and are not considering for copy-initialization.
        The equal sign =, in copy-initialization of a named variable is not related to the assignment
        operator. Assignment operator overloads have no effect on copy-initialization.
*/

#include <iostream>
#include <string>
#include <memory>
#include <utility>

int main(){
    std::string s = "test";         // okay, constructor is non-explicit
    std::string n("test");          // okay, direct-initialization
    std::string s2 = std::move(s);  // okay, this copy-initialization performs a move

//    std::unique_ptr<int> p = new int(1);    // error, constructor is explicit
    std::unique_ptr<int> p (new int(1));    // okay, direct-initialization

    int n = 3.33;       // floating-integral conversion
    const int b = n;    // const does not matter

    const int c(b);     // okay

}









