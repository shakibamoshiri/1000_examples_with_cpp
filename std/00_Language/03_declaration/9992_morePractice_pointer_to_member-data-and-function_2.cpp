/**
///

**/

#include <iostream>
#include <string>

struct D {
    const char* name;
    const char* getName(){
        return name;
    }

    const char* D::* pName;
    const char* (D::* pGetName)();
};

int main(){

    D one;
    one.name = "Shakib";
    one.pName = &D::name;
    one.pGetName = &D::getName;

    std::cout<<one.name<<' '<<one.getName()<<' '<<one.*(one.pName)<<' '<<(one.*(one.pGetName))()<<std::endl;

    D* two = &one;

    std::cout<<two->name<<' '<<two->getName()<<' '<<two->*(two->pName)<<' '<<(two->*(two->pGetName))()<<std::endl;

    const char* D::* D::* ppName = &D::pName;
    const char* (D::* D::* ppGetName)() = &D::pGetName;

    std::cout<<one.*(one.*ppName)<<' '
             <<(one.*(one.*ppGetName))()<<' '
             <<two->*(two->*ppName)<<' '
             <<(two->*(two->*ppGetName))()<<std::endl;





}









