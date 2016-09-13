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
    const char* name;
    int integer;

public:
    Base(const char* t): name(t),integer(0) {}
    Base(const int t): integer(t),name("empty") {}

    int& ref_integer(){return integer;}

    const char* &ref_name(){return name;}



    template<typename T>
    T& direct_set_anything(T& what){
        return what;
    }


    operator const char* &(){
        return this->name;
    }
    operator int&(){
        return integer;
    }


};
char* &print(char* &what){

    return what;
}

int main(){
    Base one("How are you today?");
    std::cout<<one.ref_integer()<<' '<<one.ref_name()<<std::endl;

    Base two(10);
    std::cout<<two.ref_integer()<<' '<<two.ref_name()<<std::endl;

    std::cout<<std::string(30,'.')<<std::endl;
    one.ref_integer() = 1000;
    two.ref_name() = "I am good, how about you?";

    std::cout<<one.ref_integer()<<' '<<one.ref_name()<<std::endl;
    std::cout<<two.ref_integer()<<' '<<two.ref_name()<<std::endl;

    std::cout<<std::string(30,'.')<<std::endl;

    /// by template member of class
    /// direct accessing to all
    one.direct_set_anything(one.ref_integer()) = 1;
    one.direct_set_anything(one.ref_name()) = "This is the one";

    two.direct_set_anything(two.ref_integer()) = 2;
    two.direct_set_anything(two.ref_name()) = "This is the two";

    std::cout<<one.ref_integer()<<' '<<one.ref_name()<<std::endl;
    std::cout<<two.ref_integer()<<' '<<two.ref_name()<<std::endl;

    std::cout<<std::string(30,'.')<<std::endl;

    /// by casing
    std::cout<<*(const char**)(&one)<<std::endl;
    std::cout<<*((int*) ( (const char**)(&one)+1 ))<<std::endl;

    std::cout<<std::string(30,'.')<<std::endl;

    std::cout<<*(const char**)(&two)<<std::endl;
    std::cout<<*((int*) ( (const char**)(&two)+1 ))<<std::endl;
    std::cout<<std::string(30,'.')<<std::endl;

    /// by void*
    void* all_field = &one;
    typedef const char** cc2;
    typedef int* i1;

    std::cout<<*(cc2)all_field<<std::endl;
    std::cout<<*(i1)((cc2)all_field+1)<<std::endl;
    std::cout<<std::string(30,'.')<<std::endl;

    /// by date type overloading
    const char* & temp_name = one;
    int& temp_integer = one;
    temp_name = "ha ha ha ha ha ...";
    temp_integer = 111111;
    std::cout<<one.ref_name()<<std::endl;
    std::cout<<one.ref_integer()<<std::endl;
    std::cout<<std::string(30,'.')<<std::endl;
}

