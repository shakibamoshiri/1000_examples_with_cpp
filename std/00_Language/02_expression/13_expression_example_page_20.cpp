///
/// Expression
///
/// Arithmetic Operator
///
/// Example_page_20

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
    char c =  2;
    unsigned int un = 2;
    int n = -10;
    std::cout<<"2 + (-10), where 2 is a char        = "<<c+n<<'\n'
             <<"2 + (-10), where 2 is a unsigned    = "<<un+n<<'\n'
             <<"-10 - 2.12                          = "<<n-2.12<<std::endl;

    char a[4] = {'a', 'b', 'c', 'd'};
    char* p = &a[1];
    std::cout<<"Pointer addition examples: "<<*p<<*(p+2)
             <<*(2 + p )<<* (p - 1 )<<std::endl;

    char* p2 = &a[4];
    /// distance between p and p2
    std::cout<<"pointer different: "<<p2 - p <<std::endl;
}



/**
**It has no explanation and only has a sample**
for getting more information, you can read others documentation.

**NOTE**
There is `friend` definition because of `private date`
If we use `public data` no need to use `friend`
---
**/
