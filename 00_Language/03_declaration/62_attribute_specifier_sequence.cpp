/**
Attribute specifier sequence ( since c++ 11)

Introduced implementation-defined attributes for types, objects, code, etc.
[[ attribute ]] [[ attr 1, attr 2, attr 3 ( args ) ]] [[ namespace::attr(args)]] alignas_specifier

Standard attribute

[[ noreturn ]]
[[ carries_dependency ]]
[[ deprecated ]]
[[ deprecated ("reason") ]]

**/

#include <iostream>
#include <string>

[[ noreturn ]] void f() {
    throw "error"; // okay
}

[[ noreturn ]] void q(int i){
    // behavior is undefined if called with an argument <= 0
    if (i > 0 )
        throw "positive";
}

int main(){
}









