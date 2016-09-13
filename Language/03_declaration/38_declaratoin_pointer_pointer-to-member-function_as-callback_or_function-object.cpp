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
#include <vector>
#include <algorithm>
#include <functional>

int main(){
    /*  Pointer to member function
        Pointer to member function may be used as callbacks or as function
        object, often after applying std::mem_fn or std::bind
    */

    std::vector<std::string> v = {"one", "two", "three"};
    std::vector<std::size_t> l;

    transform(v.begin(), v.end(), std::back_inserter(l),
              std::mem_fn(&std::string::size));

    for ( const std::size_t n : l )
        std::cout<<n<<' ';

}












