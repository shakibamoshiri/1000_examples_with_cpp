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

struct P {
    template<typename T>
    static T* ptr() noexcept { return new T;}
};
template<typename T>
struct A {
    int n;
    static int sn;

    A(int t): n(t){}
    int f(){return 10+n;}
    static int sf(){return 4;}
    class B{};
    enum E {RED=1, BLUE=2};
    void g(){
        typedef int U;
        /// keyword template needed for a dependent template member
        int* p = T().template ptr<U>();
        p->~U();     /// U is int, calls int's pseudo destructor
        delete p;
    }
};
template<>int A<P>::sn = 2;
/**
const char* print(){
    return __func__;
}
struct One {
    const char* name = "struct one";
    struct Two{
        const char* name = "struct two";
    };
};
**/
int main(){

    A<P> a(1);
    std::cout<<a.n<<' '         ///
             <<a.sn<<' '        /// A::an also works
             <<a.f()<<' '       ///
             <<a.sf()<<' '      /// A::sf() also works
             //<<a.B<< ' '        /// error: nested type not allowed.
             <<a.RED<<' '<<std::endl; /// enumerator
    std::cout<<(std::string(20,'.'))<<std::endl;
    /**
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
    **/
}

