/*
Classes
    * class declaration
    - union declaration
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
    class declaration
    Classes and stucts are user-defined types,defined by class-specifier,,
    which appears in declaration-specifier-sequence of the declaration syntax.
    class-key attribute class-head-name base-class { member-specification };

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/// Local classes
// A class declaration can appear in namespace scope ( in which case it
// defines an ordinary class ), inside another class definition ( in which
// case it defines class ) and inside the body of a function, in which case
// it defines a local class. This class only exist within the function scope
// and is not accessible outside.
//  - local class can not have static member
//  - member function of a local class have no linkage
//  - member function of a local class have to be defined entirely inside the class body
//  - local class can not have member template or friend templates
//  - a local class inside a function ( including member function ) can access the same
//    that the enclosing function can access
// - local classes could not be used as template argument ( until c++11)


int main(){
    std::vector<int> v{1,2,3};
    struct Local {
        bool operator()(int a,int b){
            return a < b; // 1 2 3
            // return a > b;    // 3 2 1
        }
    };

    std::sort(v.begin(), v.end(), Local());
    for ( int n : v )
        std::cout<<n<<' ';
}

