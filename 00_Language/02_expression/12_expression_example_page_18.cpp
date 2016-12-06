///
/// Expression
///
/// Arithmetic Operator
///
/// Example_page_18

/**
**/


#include <iostream>
#include <string>
class Operand {
private:
    int data;
public:
    Operand(const int tempData) : data (tempData) {}
    Operand() : Operand(0) {}
    Operand(const double tempData) : Operand(static_cast<int>(tempData)) {}
    friend std::ostream& operator<<(std::ostream& out, const Operand& object){
        out << object.data;
        return out;
    }
    /************************************************/


};

int main(){
    char c = 0x6a;
    int n1  = 1;
    unsigned char n2 = 1;
    unsigned int n3 = 1;
    std::cout<<"char: "<<c<<" int: "<<+c<<std::endl
             <<"-1, where 1 is signed: "<<-n1<<std::endl
             <<"-1, where 1 is unsigned char: "<<-n2<<std::endl
             <<"-1, where 1 is unsigned int: "<<-n3<<std::endl;
    char a[3];
    std::cout<<"size of array: "<<sizeof a<<std::endl
             <<"size of pointer: "<<sizeof +a<<std::endl;
}



/**
**It has no explanation and only has a sample**
for getting more information, you can read others documentation.

**NOTE**
There is `friend` definition because of `private date`
If we use `public data` no need to use `friend`
---
**/
