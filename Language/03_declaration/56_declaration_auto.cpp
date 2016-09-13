/**
/// auto specifier
///
Specifies that the type of the variable that is being declared will be automatically deduced
form its initializer. For functions, specifies that the return type is a trailing return type
or will be deduced from its return statement since c++14

Syntax:
auto variable initializer
auto function -> return type
auto function
decltype(auto) variable initializer
decltype(auto) function
auto ::
cv (optional) auto ref(optional) parameter

Note:
Until c++11, auto had the semantic of storage duration specifier
Mixing auto variable and function in on declaration, as in auto f()->int, i=0 is not allowed.

**/
#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>

template<class T, class U>
auto add(T t, U u) -> decltype(t+u) {return t+u;}

auto get_fun (int arg) -> double (*)(double) {
    switch(arg){
        case 1: return std::fabs;
        case 2: return std::sin;
        default: return std::cos;
    }
}
int main (){
    auto a = 1+2;
    std::cout<<"type of a "<<typeid(a).name()<<std::endl;
    auto b = add(1,1.2);
    std::cout<<"type of b "<<typeid(b).name()<<std::endl;

    // compile time error
//    auto int c;

    auto d = {1,3};
    std::cout<<"type of d "<<typeid(d).name()<<std::endl;

    auto myLambda = [](int x){return x+3;};
    std::cout<<"myLambda "<<myLambda(5)<<std::endl;
    int (*myL)(int) = [](int x){return x+3;};
    std::cout<<"myLambda "<<myL(5)<<std::endl;

    auto my_fun = get_fun(2);
    std::cout<<"type of my_fun "<<typeid(my_fun).name()<<std::endl;
    std::cout<<"my_fun "<<my_fun(3)<<std::endl;
}










