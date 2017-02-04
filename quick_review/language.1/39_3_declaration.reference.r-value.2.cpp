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


int main(){

    /// r-value
    // R-value reference can be used to extended lifetime of temporary object.
    // Note:
    // A l-value reference to const can extended the lifetime of temporary object, too
    // but they are not modifiable through them.

                                // r-value only binds to r-value
    std::string he("he");       // he is a l-value

//    std::string&& she = she;    // error, cannot bind to a l-value (to she)

//    std::string& he2 = he + he; // error the output of "he + he" is a r-value or a const l-value

    // binds he + he to a const l-value is okay
    const std::string& he2 =    // okay but not modifiable
        he + he;

//    he2 += " she";              // error, the location is read-only

    // but with a r-value we can bind and modify
    std::string&& he3 = he + he;
    he3 += " she";              // okay
    puts( he3.c_str() );        // 'hehe she' is the output

    std::string&& tmp("okay");  // direct initializer is also okay
}
