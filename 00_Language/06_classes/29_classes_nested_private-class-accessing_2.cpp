/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
    * nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    nested classes ( nest verb: 2 oxford: to put types of information together, or inside each other )
    A declaration of class / struct or union may appear in within another class.
    Such declaration declares nested class.
    Note:
    Declaration of a nested class can use only types of names, static member,
    and enumeration from the enclosing class.
    Note:
    Declaration in a nested class can use any member of the enclosing class.
*/

#include <iostream>
#include <string>
#include <utility>
#include <typeindex>
#include <exception>

/// nested class
// Nested class declaration obey member access specifier,
// so, a private member class can not be named outside the
// scope of the enclosing class, although object of the class
// may be manipulated ( oxford: to control or influence someone or something,
                    //          often in a dishonest way so that do not realize it )

class enclose {
private:
    struct nested {
        int n;
        void g(int);
    };
public:
    // first way to access nested class
    using nest = nested;

    // second way to access is tyepdef nested class
    typedef nested nest_2;

    // third way is
    static nested f(){
        // return constructor
        return nested();
        // or
        // return nested{};
    }

};
// although nested is a private member, but it
// possible to definition outside the class
void enclose::nested::g(int i){
    n = i;
}

struct ps{
    int* p;

};

int main(){
    // what is the type of auto, with object of the private-nested class?

    enclose::nest n1;
    n1.g(1);
    std::cout<<n1.n<<std::endl;

    enclose::nest_2 n2;
    n2.g(2);
    std::cout<<n2.n<<std::endl;

    auto n3 = enclose::f();
    n3.g(3);
    std::cout<<n3.n<<std::endl;

    decltype(enclose::f()) d;
    d.g(5);
    std::cout<<d.n<<std::endl;


    /// where does the 'auto' understand what type is of 'enclose::f()' from?
}

