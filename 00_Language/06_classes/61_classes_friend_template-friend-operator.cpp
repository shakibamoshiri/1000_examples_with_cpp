/*
Classes
    - class declaration
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
    * friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    Fried Declaration
    The friend declaration appears in a class body and grants a function
    or another class access to private and protected members of the class
    where the friend declaration appears.
    (grant means: to agree to give someone what they ask for,
     especially formal or legal permission to do something )

     Syntax:
     friend function-declaration
     friend function-definition
     friend elaborated-class-name ; ( elaborated means: very complicated and detailed; carefully prepared and organized)
     friend simple-type-specifier ;
     friend typename-specifier ; since c++11
*/

#include <iostream>
#include <string>
// #include <cstdlib>


/// template friend, operators
// A common use case for template friends is declaration of a non-member operator
// overload that acts on a class template, e.g. operator<<(std::ostream& ,const X<T>&)
// for some user-defined X<T>

template<typename T>
class F {
private:
    T data;
public:
    F(const T& t): data(t) {}

    // generates a non-template operator << for this T
    friend std::ostream& operator<<(std::ostream& out, const F& obj){
        return out << obj.data;
    }
};

int main(){
    F<int> i(1);
    std::cout<<i<<std::endl;

    F<float> f(1.235);
    std::cout<<f<<std::endl;

    F<const char*> she("how are you today?");
    std::cout<<she<<std::endl;
}







