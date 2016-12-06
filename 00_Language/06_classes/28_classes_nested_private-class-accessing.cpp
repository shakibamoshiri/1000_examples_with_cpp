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
    static nested f(){
        return nested{};
        // return object of nested class
    }
};
// although nested is a private member, but it
// possible to definition outside the class
void enclose::nested::g(int i){
    n = i;
}

int main(){

    // wrong way, because nested is a private member
    // enclose::nested n1;

    auto n2 = enclose::f();

    n2.g(22);
    std::cout<<n2.n<<std::endl;

    // what is the type of auto, with object of the private-nested class?
}
