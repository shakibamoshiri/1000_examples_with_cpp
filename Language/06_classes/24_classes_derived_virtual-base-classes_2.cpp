/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
    - nested class                  - constructor
    * derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    derived classes
    Any type class may be declared as derived form one or or more
    base classes which, in turn, may be derived from their own base
    classes, formating an inheritance hierarchy.

    Syntax:
    attribute (optional) : access-specifier(optional) virtual-specifier(optional) class-or-decltype

    Note:
    If access-specifier is omitted ( leave out ), it defaults to 'public' for classes
    declared with class-key 'struct' and to 'private' for classes declared class-key 'class'

*/

#include <iostream>
#include <string>
#include <utility>
#include <exception>

/// virtual base classes
// Similar to protected inheritance, private inheritance may also used
// for controled polymorphism:
// within the members of the derived ( but not within further-derived classes )
// derived IS-A base

template<typename Transprot>
class servic : Transprot {  // private inheritance form the Transport policy
public:
    void transmit(){
        this->sane(...);    // send using whatever transport was supplied
    }
};

// TCP transport policy
class tcp {
public:
    void send(...);
};

// UDP transport policy
class udp {
public:
    void send(...);
};

servic<tcp> servic(host, port);
servic.send(...);   // send over TCP

int main(){
}
