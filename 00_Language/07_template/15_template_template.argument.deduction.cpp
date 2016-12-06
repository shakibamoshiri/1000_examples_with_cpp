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
/// 03 Function Template
/**
Template argument deduction ( important )
In order to instantiate a "function template", every template argument must be known,
but not every template argument has to be specified. When possible the compiler will
deduce the missing template argument from the function argument. This occurs when a
function-call is attempted and when an address of a function template is taken:
**/
template<typename To, typename From> To convert(From f){}
void f(float argc){
    convert<int>(argc);         // calls convert<int,float>(float)
    convert<float>(argc);        // calls convert<float,float>(float)
    int (*ptr)(float)=convert;  // instantiation convert<int,float>(float)
    /// one type sticks on To       : convert<int> sticks to To
    /// another sticks on From      : convert<???>(float) sticks to From
}

template<typename A, typename B> void AB (A a,B b){}
void f2 (){
    AB(1,1);        // AB<>(int, int)
    AB('a','a');    // AB<>(char, char)
}


template<typename C, typename D> void CD(){}    // no argument
void f3(){
//    CD(1,1);          // error, no match for call the function CD
//    CD();             // error same as above
    CD<int,int>();      // okay, instantiates CD<int,int>()
    int (*pf)();
    CD<int(),int()>();          // type
    CD<int(*)(),int(*)()>();    // type, same as above
}



int main(){
    std::cout<<"Hello, World"<<std::endl;
    // operator<< "Hello, World"<<std::endl;
    // then deduced to operator<< <char, std::char_traits<char>> both time
    // std::endl is deduced to &std::endl<char, std::char_trains<char>>
return 0;}

