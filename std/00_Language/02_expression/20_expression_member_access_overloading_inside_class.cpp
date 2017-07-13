///
/// Expression
///
/// Member access operator
///
///

/**
Accesses a member of its operand

name                            syntax          overload        inside_class        outside_class
subscript                       a[b             yes             okay                not
indirection                     *a              yes             okay                okay
address-of                      &a              yes             okay                okay
member of object                a.b             no              not                 not
member of pointer               a->             yes             okay                not
pointer to member object        a.*b            no              not                 not
pointer of member of pointer    a->*b           yes             okay                okay

Note:
    As with most user-defined overload, return types should match return
    types provided by the built-in operators so that the user-defined __
    operators can be used in the same manner as the built-is. However, in
    a user-defined operator overload, any type can be used as return type
    ( including void ). One exception is 'operator ->', which must return
    a pointer to another class with overloaded operator ->
**/


#include <iostream>
#include <string>
#include <cassert>

class Operand {
private:
    int data[3];
public:

    Operand (std::initializer_list<int> init ) {
        std::copy(init.begin(),init.end(),data);
    }
    Operand () : data{0,0,0} {}

    friend std::ostream& operator<<(std::ostream& out,const Operand& obj){
        for ( const int t : obj.data){
            out<<t<<' ';
        }
        return out;
    }
    void print(){
        for ( const int t : data )
            std::cout<<t<<' ';
    }
void (Operand::* p2p)() = &Operand::print;
    /************************************************/
    /// subscript []
    int& operator[](const int tempInt){
        assert(tempInt<3);
        return this->data[tempInt];
    }
    /// indirection *
    int* operator*(){
           return this->data;
    }
    /// address-of &
    /// by default it exist for any class
    /// but we can it to use easier by overloading it.
    int* operator&(){
        return this->data;
    }

    /// member of object a.b | can not be overload

    /// member of pointer a->b
    Operand* operator->(){
        return this;
    }

    /// pointer to member of object a.*b | can not be overload

    /// pointer to member of pointer a->*b
    /// it is not perfect yes.
        Operand* operator->*(void (Operand::* p2p)()){
            return 0;
    }
};

int main(){
    Operand one;
    std::cout<<one<<std::endl;
    one[0] = 11;
    one[1] = 22;
    one[2] = 33;
    std::cout<<one<<std::endl;
    **one = 1; /// equivalent to * ( *one + 0 ) = 1;
    *(*one+1) = 2;
    *(*one+2) = 3;
    std::cout<<one<<std::endl;
    *(&one) = 10;
    *(&one+1) = 20;
    *(&one+2) = 30;
    std::cout<<one<<std::endl;
    /// access by member of object
    one.print();
    /// access by member of pointer;
    one->print();

    void (Operand::* p2p)() = &Operand::print;
    Operand* two;
    std::cout<<(two->*p2p)();




}

