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

/// Member Specification
// The member specification, or the body of a class definition
// is a brace-enclosed sequence of any number of are following:

// 1.   member declaration, which are declaration of static and non
// static data member and function, typedef declaration, scoped and
// unscoped enumeration, and other nested, class declaration
class S {
    int d1;             // non-static data member
    int a[10]={1,2};    // non-static data member with initializer (c++11)
    static const int d2=2;  // static data member with initializer
    virtual void f1(int)=0; // pure virtual member function
    std::string d3,*d4, f2(int);    // two data members and a member function
    enum {NORTH, SOUTH, EAST, WEST};
    struct nestedS {
        std::string s;
    }d5, *d6;
    typedef nestedS value_type, *pointer_type;
};

// 2.   function definitions, which both declare and define member function
// . A semicolon after a member function definition as optional. All member
// function that are defined inside a class body are automatically in-line
class M {
    std::size_t C;
    std::vector<int> data;
public:
    M ( std::size_t R, std::size_t C) : C(C), data(R*C) {}  // constructor definition
    int operator()(std::size_t r, std::size_t c) const {    // member function definition
        return data[r*C+c];
    }
    int& operator()(std::size_t r, std::;size_t c){         // another member function definition
        return data[r*C+c];
    }
};

// 3.   Access specifier: public, protected, private
class S {
public:
    S();            // public constructor
    S(const S&);    // public copy constructor
    virtual ~S();   // public virtual destructor
private:
    int* ptr;       // private data member
};

// 4.   using declaration
class Base {
protected:
    int b;
};
class Derived : public Base {
    using Base::b;      // make Base's protected member b, to a public member of derived
    using Base::Base:   // inherit all parent's constructor (c++11)
}

// 5.   static_assert declaration
template<typename T>
struct Foo {
    static_assert(std::is_floating_point<T>::value, "Foo<T> T must be floating point");
};

// 6.   member template declaration
struct S {
    template<typename T>
    void f(T&& n);

    template<class CharT>
    struct nestedS {
        std::basic_string<CharT> s;
    };
};

// 7.   alias declaration
template<typename T>
struct identify {
    using type = T;
};


int main(){

}

