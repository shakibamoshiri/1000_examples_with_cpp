/**
/// Pointer Declaration
///
///
Declares a variable of a pointer or pointer-to-member type

Syntax:

A pointer declaration is any simple declaration whose declarator has the form:

* attribute ( optional ) const/volatile ( optional ) declarator
nested-name-specifier * attribute ( optional ) const/volatile ( optional ) declarator
1   Pointer Declarator: The declaration s* d; declares d as a pointer to the type
    determined by decl-specifier-seq s;
2   Pointer to Member Declarator: The declaration s c::* d; declares d as a pointer
    to member of c of type determined by decl-specifier-seq s.

**/
#include <iostream>
#include <string>


void* fi(const int i){return (void*)i;}         // okay with int
//void* ff(const float f){return (void*)f;}     // may be wrong with float
// void* fc(const char c){return (void*)c;}     // may be wrong with char

void* print (void * what){
    return what;
}

int main(){
    int n = 10;
    float f = 2.33;
    char c = 'c';

    std::cout<<(int)fi(10)<<std::endl;

    std::cout<<*((int*)print(&n))<<std::endl;
    std::cout<<*((float*)print(&f))<<std::endl;
    std::cout<<*((char*)print(&c))<<std::endl;



}












