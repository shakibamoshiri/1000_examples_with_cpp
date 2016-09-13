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
// ( continuous the previous sample (61))
// or the function template has to be declared as a template before the class
// body, in which cast the friend declaration within F<T> can refer to the full
// specialization of operator << for this T

template<typename T>
class F;    // forward declaration to make function declaration possible

template<typename T>
std::ostream& operator<<(std::ostream& out, const F<T>&);

template<typename T>
class F {
private:
    T data;
public:
    F(const T& t): data(t) {}

    // refers to a full specialization for this particular T
    friend std::ostream& operator<< <> (std::ostream&, const F&);
    // note: this relies ( rely: to need or depend on something ) on template argument in declaration
    // can also specify the template argument with operator << <T>
};
// definition
template<typename T>
std::ostream& operator<<(std::ostream& out, const F<T>& obj){
    return out << obj.data;
}

int main(){
    F<int> i(1);
    std::cout<<i<<std::endl;

    F<float> f(1.22);
    std::cout<<f<<std::endl;

    F<char> c('c');
    std::cout<<c<<std::endl;

    F<const char*> she("how are you today?");
    std::cout<<she<<std::endl;
}







