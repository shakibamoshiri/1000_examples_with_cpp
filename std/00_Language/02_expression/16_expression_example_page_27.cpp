///
/// Expression
///
/// Logical Operator
///
///

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
    /// negative !

};

int main(){
    int n = 2;
    int* p = &n;
    /// pointers are convertible to boolean
    if ( p && *p == 2
        || !p && n != 2) /// || has lower precedence then &&
            std::cout<<"true\n";

    /// stream are also convertible to boolean.
    std::cout<<"Enter 'quit' to quit.\n";
    for ( std::string line; std::cout<<"> "&& std::getline(std::cin, line) && line != "quit"; );
}
