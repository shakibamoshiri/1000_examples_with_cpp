/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// expression

#include <iostream>
#include <string>

std::string stuff (){ return "a return a temporary string"; }

std::string& stuff (int){   // here the int type is just to remove the error the of the ambiguous compiler
    std::string str = "a return of a temporary string";
    return str;
}

int main(){
    /// r-value
    // R-value reference can be used to extended lifetime of temporary object.
    // Note:
    // A l-value reference to const can extended the lifetime of temporary object, too
    // but they are not modifiable through them.

    std::string one = stuff();
    std::cout<< one << std::endl;       // okay

//    std::string two = stuff(0);         // dangling reference
    // because str in the stuff(int) is a temporary object
    // and after the end of the block it was destroyed
    // so here, the program compiles well, but at runtime
    // it happily says (segmentation fault)
    //
    // Also if you turn "all compiler warning" on, it says:
    // warning: reference to local variable ‘str’ returned

    // here is one solution:
    // first with a reference to const like this:
    const std::string& three(stuff(0));    // okay but not modifiable and not printable

    // also error and (segmentation fault)
    // std::cout << three << std::endl;     // undefined behavior: reads from a dangling reference
    //std::cout << three << std::endl;


    // note that a r-value reference does not work.
//    std::string&& four = stuff(0);          // it does not work.



}
