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

struct S {
    mutable int mi;
    S (int n): mi(n){}
    int f (int n) {return mi + n;}
};
struct D: public S {
    D (int n): S(n) {}
};

/***************************/
const char* print(){
    return __func__;
}
struct One {
    const char* name = "struct one";
    struct Two{
        const char* name = "struct two";
    };
};

int main(){

    int S::* pmi = &S::mi;
    int (S::* pf)(int) = &S::f;

    const S s(7);
    /// can not modify
    /// s.*pmi = 10;
    std::cout<<s.*pmi<<std::endl;

    D d(7);     /// base pointers works with derived object.
    D* pd = &d;
    std::cout<<(d.*pf)(7)<<' '<<(pd->*pf)(8)<<std::endl;

    std::cout<<(std::string(20,'.'))<<std::endl;

    One one;
    One::Two two;
    std::cout<<one.name<<std::endl;
    std::cout<<two.name<<std::endl;

    const char* One::* s_one = &One::name;
    One* pone = &one;
    std::cout<<pone->*s_one<<std::endl;
    std::cout<<one.*s_one<<std::endl;

    const char* One::Two::* s_two = &One::Two::name;
    One::Two* ptwo = &two;
    std::cout<<two.*s_two<<std::endl;
    std::cout<<ptwo->*s_two<<std::endl;

}

