///
/// Expression
///


/**
Built-in member access operator

**/
#include <iostream>
#include <string>
#include <cassert>
/// user defined
//#include "temp.h"

class Base {
private:
    int iBase;
public:

    Base(int t): iBase(t) {}
    int fBase() { return iBase;};

};


int main(){

    /// creates an object
    Base one(20);

    /// accessing through filed of member impossible because of field is private
    /// std::cout<<one.iBase<<std::endl;

    /// accessing through function of member
    std::cout<<one.fBase()<<std::endl;

    /// creating a pointer to filed of member | it impossible, because the field is private
    /// int Base::* piBase = &Base::iBase;

    /// creating a pointer to function of member is possible | by default all function is public
    int (Base::* pfBase)()  = &Base::fBase;

    /// accessing through pointer to function of member. By: object.*function
    /// (object.*pointer-function)()
    /// the parentheses is necessary ()()
    std::cout<<(one.*pfBase)()<<std::endl;

    /// creates a pointer to object
    /// pointer = & object
    Base* p = &one;

    /// accessing to field of member through pointer impossible | filed is private


    /// accessing to function of member through pointer to object
    /// pointer->function
    std::cout<<p->fBase()<<std::endl;

    /// accessing to pointer-function of member through pointer to object
    /// (pointer->*pointer-function)()
    /// the parentheses is necessary ()()
    std::cout<<(p->*pfBase)()<<std::endl;






}

