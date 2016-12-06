/**

/// Expression
/// Implicit Conversions
///

**/
#include <iostream>
#include <string>
#include <cassert>
/// user defined
//#include "temp.h"
template<typename T>
class zero_inti{
private:
    T val;
public:
    zero_inti() : val (static_cast<T>(0)) {}
    zero_inti(T val) : val(val) {}
    operator T&() { return val;}
    operator T() const { return val;}
};
int main(){
    zero_inti<int> i; assert(i==0);
    i = 7;            assert(i==7);

    /// error in c++98 and c++11 ( more than one conversion function)
    /// OK in c++14 ( both functions convert to the same type int )
    switch(i){}

    /// always okay, implicit conversion.
    switch(i+0){}

}













