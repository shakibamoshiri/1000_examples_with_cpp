/*
Classes
    - class declaration
    * union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
    - nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    union declaration
    A union is a special class type that can hold only one of its
    non-static data member at a time. The class specifier for a union
    declaration is similar to class or struct declaration
    union attribute class-head-name { member-specification};
    The union is only as big as necessary to hold it largest data member.
    The other data member are allocated in the same bytes as part of largest
    member.


*/

#include <iostream>
#include <string>
#include <vector>


/// union-like class | anonymous menas: with a name that is not known
// A union-like class is any class with at least one anonymous union as a
// member. The members of all member anonymous unions of a class are called
// its variant member.

struct S {
    enum { CHAR, INT, DOUBLE} tag;
    union {
        char c;
        int n;
        double d;
    };
};
void print_s(const S& s){
    switch(s.tag){
        case S::CHAR:   std::cout<<s.c<<std::endl;  break;
        case S::INT:    std::cout<<s.n<<std::endl;  break;
        case S::DOUBLE: std::cout<<s.d<<std::endl;  break;
    }
}

int main(){
    // need to assign s.tag, before assigns s.d or s.c or s.n
    S s = {S::CHAR, 'a'};
    print_s(s);

    // need to assign s.tag, before assigns s.d or s.c or s.n
    s.tag = S::INT; s.n = 123;
    print_s(s);

    // need to assign s.tag, before assigns s.d or s.c or s.n
    s.tag = s.DOUBLE;
    s.d = 1.22;
    print_s(s);
}
