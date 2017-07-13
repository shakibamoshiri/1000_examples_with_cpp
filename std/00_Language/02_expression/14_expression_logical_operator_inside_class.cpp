///
/// Expression
///
/// Logical Operator
///
///

/**
Return the result of a boolean operator

name            syntax      overload        inside class
negation        !a          yes         bool T::operator!()const
and             a && b      yes
inclusive       a || b      yes

NOTE:
*   The keyword-like forms ( and , or , not ) and the symbol-like forms
    ( &&, ||, ! ) can be used interchangeably.
*   All built-in operator returns bool, and must user-defined overload
    also return bool so that the user-defined operators can be used in
    the same manner as the built-ins. However,i a user-defined operator
    overload, any type can be used as return type ( including void ).
*   Built-in operators && and || perform short-circuit evaluation ( do
    not evaluate the second operand if the result is known after evaluating
    the frist ), but overloaded operator behave like regular function call
    and always evaluate both operand.
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
    bool operator!()const{
        return !this->data;
    }

    /// and
    bool operator&&(const Operand& obj)const{
        return this->data && obj.data;
    }

    /// inclusive or
    bool operator||(const Operand& obj)const{
        return this->data||obj.data;
    }


};

int main(){
    Operand one;
    std::cout<<"one             : "<<one<<std::endl; /// 0
    if (!one)
        std::cout<<"!one            : "<<!one<<std::endl; /// 1
    Operand two(1);
    if ( two && (!one) )
        std::cout<<"two && (!one)   : is true"<<std::endl;

    if ( two || one )
        std::cout<<"two || one      : is true"<<std::endl;
}



