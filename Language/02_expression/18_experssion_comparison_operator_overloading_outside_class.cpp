///
/// Expression
///
/// Comparison Operators
///
///

/**
Compare the argument.
name                        syntax              overload
equal to                    a == b              yes
not equal to                a != b              yes
less than                   a <  b              yes
greater than                a >  b              yes
less than or equal to       a <= b              yes
greater than or equal to    a >= b

Note:
All build-in operator return boolean, and most user-defined overload also
return boolean so that the the user-defined operators can be used in the_
same manner as the built-in. However, in a user-defined operator overload,
any type can be used as return type ( including void )
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
    /// equal to == | using direct accessing in the outside class
    /*
    template<typename L,typename R>
    friend bool operator==(const L& left,const R& right);
    */
    /// not equal to !=
    template<typename L,typename R>
    friend bool operator!=(const L& left,const R& right);

    /// less than
    template<typename L,typename R>
    friend bool operator<(const L& left,const R& right);

    ///  greater than
    template<typename L,typename R>
    friend bool operator>(const L& left,const R& right);

    /// less than or equal to <=
    template<typename L,typename R>
    friend bool operator<=(const L& left,const R& right);

    /// greater than or equal to >=
    template<typename L,typename R>
    friend bool operator>=(const L& left,const R& right);

};
/// equal to ==
template<typename L,typename R>
bool operator==(const L& left,const R& right){
    return *((int*)(&left)) == *((int*)(&right));
}

/// not equal to !=
template<typename L,typename R>
bool operator!=(const L& left,const R& right){
    return left.data != right.data;
}

/// less than <
template<typename L,typename R>
bool operator<(const L& left,const R& right){
    return left.data < right.data;
}

/// greater than >
template<typename L,typename R>
bool operator>(const L& left,const R& right){
    return left.data > right.data;
}

/// less than or equal to <=
template<typename L,typename R>
bool operator<=(const L& left,const R& right){
    return left.data <= right.data;
}

/// greater than or equal to >=
template<typename L,typename R>
bool operator>=(const L& left,const R& right){
    return left.data >= right.data;
}



int main(){
    Operand one(10),two(20),three(10);
    std::cout<<"one             : "<<one<<std::endl;
    std::cout<<"two             : "<<two<<std::endl;
    std::cout<<"three           : "<<three<<std::endl;

    std::cout<<(std::string(20,'.'))<<std::endl;

    /// testing if the two object of Operand are equal
    std::boolalpha(std::cout);

    std::cout<<"one == two      : "<<(one==two)<<std::endl;

    /// ... are not equal
    std::cout<<"one != two      : "<<(one!=two)<<std::endl;

    /// ... are less than
    std::cout<<"two <  one      : "<<(two<one)<<std::endl;

    /// ... are greater
    std::cout<<"three > two     : "<<(three>two)<<std::endl;

    /// ... are less than or equal to
    std::cout<<"one <= three    : "<<(one<=three)<<std::endl;

    /// ... are greater than or equal to
    std::cout<<"two >= one      : "<<(two>=one)<<std::endl;

}
