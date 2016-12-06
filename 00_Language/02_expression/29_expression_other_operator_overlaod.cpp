///
/// Expression
///

/// Other operator () and , and ?:
/**
name                    syntax              overload        inside          outside
function call           a (a1,a2)           yes             yes             -
comma                   a, b                yes             yes             yes
ternary condition       a?b:c               no              -               -

The function call operator provides function semantics for any object.

The ternary condition operator checks the boolean value of the first _
expression and, depending on the resulting value, evaluates and return
either the second or the third expression.

**/
#include <iostream>
#include <string>
#include <cassert>
/// user defined
//#include "temp.h"

class Operand {
private:
    int data;
public:

    Operand (const int tempData): data(tempData) {}
    Operand () : data(0) {}

    friend std::ostream& operator<<(std::ostream& out,const Operand& obj){
        out<<obj.data;
        return out;
    }
    /// function call
    void operator()(){
        std::cout<<this->data;
    }
    const int operator,(const Operand& obj){
        return this->data+obj.data;
    }
};
int main(){

    Operand one(30);
    one();

    Operand two(20);
    two();

    Operand three;
    three = (one,two);
    three();

}

