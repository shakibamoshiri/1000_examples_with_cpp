/**
/// Language Linkage
///
Provided for linkage between modules written in different programming languages.

extern string-literal { declaration-seq (optional ) }
extern string-literal declaration

1)  Applies the language specification string-literal to all function types, function
    names with external linkage and variables with external linkage declared in declaration-seq
2)  Applies the language specification string-literal to a single declaration of definition.

Only two language linkages are guaranteed to be supported:
1)  "C++", the default language linkage
2)  "C", which makes it possible to link with function written in the C programming
    language, and to define in a c++ program, functions that can be called from the
    modules written in c.

**/
#include <iostream>
#include <string>

extern "C" {
    int open (const char* pathName, int flags );    // C function declaration
}

int main(){
    int fd = open("text.txt", 0);   // calls a C function form a c++ language
}
// This C++ function can be called from C code
extern "C" void handler(int){
    std::cout<<"Callback invoked\n";    // It can use c++
}












