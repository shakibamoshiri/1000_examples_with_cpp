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

struct Base {
    int iBase;
    Base(int t): iBase(t) {}
    int fBase() { return iBase;};
};


int main(){

    /// creates an object.
    Base one(20);

    /// accessing through filed of object |                    one.field
    std::cout<<one.iBase<<std::endl;

    /// accessing through member of object |                   one.function
    std::cout<<one.fBase()<<std::endl;


    /// creates a pointer to filed of member |              Base::*         pinter to field of member
    int Base::* piBase = &Base::iBase;

    /// creates a pointer to function of member |           ( Base::* )     pointer-function to function of member
    /// the parentheses is necessary ()()
    int (Base::* pfBase)() = &Base::fBase;

    /// accessing through pointer to field of member |         one.*filed
    std::cout<<one.*piBase<<std::endl;

    /// accessing through pointer to function of member |      (one.*function)()
    /// the parentheses is necessary ()()
    std::cout<<(one.*pfBase)()<<std::endl;

    /// creates pointer to object |                             Base*
    Base* two = &one;

    /// accessing through pointer to member filed |            two->filed
    std::cout<<two->iBase<<std::endl;

    /// accessing through pointer to member function |         two->function
    std::cout<<two->fBase()<<std::endl;

    /// accessing through pointer to pointer member filed |    (two->*pointer_to_filed)
    /// the parentheses is necessary ()()
    std::cout<<(two->*piBase)<<std::endl;

    /// accessing through pinter to pointer member function |  (two->*pointer_to_function)
    /// the parentheses is necessary ()()
    std::cout<<(two->*pfBase)()<<std::endl;


}

