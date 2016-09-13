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

/// union like class
// if member of union are classes with user-defined constructor and destructor
// to switch the active member, explicit destructor and placement new are generally needed.

union S {
    std::string str;
    std::vector<int> vec;
    ~S() {}   // needs to know which member is active, only possible in union-like
            // class the whole union occupies max ( sizeof(string), sizeof(vector<int>))
};

int main(){
    S s = {"hello world"};
    // at this point, reading form s.vec is undefined-behavior

    std::cout<<"s.str = "<<s.str<<std::endl;

    s.str.~basic_string<char>();
    new (&s.vec) std::vector<int>;
    // new, s.vec is the active member of the union
    s.vec.push_back(10);
    std::cout<<s.vec.size()<<std::endl;
    s.vec.~vector<int>();
}
