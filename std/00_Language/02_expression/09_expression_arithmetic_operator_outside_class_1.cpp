///
/// Expression
///
/// Arithmetic Operator
///
/// 09_expression_arithmetic_operator_outside_class_1
/**
Return the result of specific arithmetic operator;

Note:
All built-in operator returns values, and most user-defined overload
also return value so that the user-defined can be used in the same _
manner as the built-ins. However, in a user-defined operator overload,
any type can be used as return type ( including void ). In particular,
stream insertion and stream extraction overloads of operator<< and __
operator>> return &

name:                  syntax       overload
unary plus              +a              yes
unary minus             -a              yes
addition                a + b           yes
subtraction             a - b           yes
multiplication          a * b           yes
division                a / b           yes
module                  a % b           yes

bitwise NOT             ~a              yes
bitwise AND             a & b           yes
bitwise OR              a | b           yes
bitwise XOR             a ^ b           yes
bitwise list shift      a << b          yes
bitwise right shift     a >> b          yes

**/
#include <iostream>

class Operand {
private:
    int data;
public:
   Operand(const int tempDate) : data ( tempDate ) {}
   Operand() : data (0) {}
   Operand(const double tempDou) : Operand(static_cast<int>(tempDou)){}
    /// << overload
    friend std::ostream& operator<<(std::ostream& out,const Operand& obj){
        out<<obj.data;
        return out;
    }

    /// Unary plus +a
    template<typename T>
    friend T operator+(const T&);

    /// Unary minus -a
    template<typename T>
    friend T operator-(const T&);

    /// Addition a + b
    template<typename L,typename R>
    friend L operator+(const L&, const R&);

    /// Subtraction a - b
    template<typename L,typename R>
    friend L operator-(const L&,const R&);

    /// Multiplication a * b
    template<typename L,typename R>
    friend L operator*(const L&,const R&);

    /// Division a / b
    template<typename L,typename R>
    friend L operator/(const L&,const R&);

    /// Module a % b
    template<typename L,typename R>
    friend L operator%(const L&,const R&);



};
/// unary plus   +a
template<typename T>
T operator+(const T& what) {
    return +what.data;
}
/// unary minus -a
template<typename T>
T operator-(const T& what) {
    return -what.data;
}
/// addition
template<typename L,typename R>
L operator+(const L& left,const R& right){
    return left.data + right.data;
}
/// subtraction
template<typename L,typename R>
L operator-(const L& left,const R& right){
    return left.data - right.data;
}
/// multiplication
template<typename L,typename R>
L operator*(const L& left,const R& right){
    return left.data * right.data;
}
/// division
template<typename L,typename R>
L operator/(const L& left,const R& right){
    return left.data / right.data;
}
/// module
template<typename L,typename R>
L operator%(const L& left,const R& right){
    return left.data % right.data;
}

int main(){
    Operand one(10);
        Operand two(50);

    std::cout<<"one         : "<<one<<std::endl;
    std::cout<<"two         : "<<two<<std::endl;
    std::cout<<std::string(19,'.')<<std::endl;
    std::cout<<"+one        : "<<+one<<std::endl;
    std::cout<<"-one        : "<<-one<<std::endl;


    /// Addition
    std::cout<<"one + two   : "<<one+two<<std::endl;

    /// Subtraction
    std::cout<<"one - two   : "<<one-two<<std::endl;

    /// Multiplication
    std::cout<<"one * one   : "<<one*one<<std::endl;

    /// Division
    std::cout<<"two / one   : "<<two/one<<std::endl;

    /// Module
    std::cout<<"two % one   : "<<two%one<<std::endl;
}
/**
**It has no explanation and only has a sample**
for getting more information, you can read others documentation.

**NOTE**
There is `friend` definition because of `private date`
If we use `public data` no need to use `friend`
---
**/
