/**
///

**/

#include <iostream>
#include <string>
const char* f(){
    const char* t = "How are you today?";
    // temporary object
    return t;
}

std::string ss (){

    // local variable,
    // temporary object
    std::string s = "this is std::string";

    return s;
    // after return it would be destructed
}

int main(){

    // L-value is an alias
    // R-value is temporary-modifier

    // 'how' takes the address of t ( inside f function )
    const char* how = f();

    // also we can modify 'how'
    how = "I am good, how about you?";

    // and we can print
    std::cout<<how<<std::endl;

    // l-value binds to r-value
    std::string&& s = f();
    s = "you are insdie the main function";
    std::cout<<s<<std::endl;

}









