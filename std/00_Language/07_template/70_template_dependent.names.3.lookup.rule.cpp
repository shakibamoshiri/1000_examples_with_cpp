/*
Template:
    01 template parameter and template argument
    02 class template
    03 function template
    04 variable template
    05 template argument deduction
    06 explicit (full) template specialization
    07 partial template specialization
    08 parameter pack
    09 sizeof ... operator
    10 fold expression

    11 dependent names

    12 SFINAE
    13 constraints and concepts
*/
#include <iostream>
#include <array>

/// 10 Depending Name
// Inside the definition of a template ( both class-template and function-template ),
// the meaning of some constructs may differ form one instantiation to another. In
// particular types and expression may depend on types of type template parameter and
// value of non-type template parameter.
//
//
//
//
/// lookup rules
// As discussed in lookup, the lookup of a dependent name used in a template
// is postponed ( put off ) until the template arguments are known, at which time
// * ... read main site
// * ... read main site
// The purpose of this is rule, is to help guard against violation or the ODR for template
// instantiation

// an external library
namespace E {
    template<typename T> void writeObject ( const T& t ) {
        std::cout<< "Value = "<<t<<std::endl;
    }
}

// translation unit 1:
// Programmer one wants to allow E::writeObject to work with vector<int>
namespace P1 {
    std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
        for ( int n : v )
            out << n <<' ';

        return os;
    }
    void doSomething() {
        std::vector<int> v;
        E::writeObject(v);  // error, will not find P1::operator<<
        // std::cout<< "Value = "<<t<<std::endl;
        // namesapce E cannot find P1::operator<<
    }
}

// translation unit 2
// programmer two want to allow E::writeObject to work with vector<int>
namespace P2 {
    std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
        for ( int n : v )
            out << n <<' ';

    return os;
    }
    void doSomethingElse(){
        std::vector<int> v;
        E::writeObject(v);  // error, will not find P2::operator<<
        // what catnot find P2::operator<<?
        // well std::cout inside E::writeObject() in the namesapce E
    }
}
//
// for more detail, please read the main site: en.cppreference.com
//
/// solution
//
namespace P1 {
    // if C is a class definition in the P1 namespace
    std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
        for ( int n : v )
            out << n <<' ';

        return os;
    }
    void doSomething() {
        std::vector<int> v;
        E::writeObject(v);  // okay, instantiates writeObject(std::vector<P1::C>)
                            // which finds P1::operator<< via ADL
    }
}
/// Note:
// This rule makes it impractical to overload operators for standard library types

int main() {
}
