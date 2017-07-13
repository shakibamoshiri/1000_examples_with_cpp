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
#include <sstream>
// #include <cstdlib>


/// Example
// stream insertion and extraction operators are often declared as non-member function

class IE {
private:
    int i;
public:
    IE(int t=0): i(t) {}

    friend std::ostream& operator<<(std::ostream&, const IE&);
    friend std::istream& operator>>(std::istream&, IE&);
};
std::ostream& operator<<(std::ostream& out, const IE& obj){
    return out << obj.i;
}
std::istream& operator>>(std::istream& in, IE& obj){
    return in >> obj.i;
}


int main(){
    IE one(1);
    std::cout<<one<<std::endl;

    std::istringstream("100") >> one;
    std::cout<<one<<std::endl;

    std::cout<<"Please enter an integer: ";
    std::cin>>one;
    std::cout<<one<<std::endl;
}







