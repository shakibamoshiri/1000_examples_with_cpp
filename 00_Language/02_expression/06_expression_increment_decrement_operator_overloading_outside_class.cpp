///
/// Expression
///
/// Increment and decrement operator ( outside class )
/**
Increment / decrement operator increments or decrements the value of the object.
        name:    syntax    overloadable
pre-increment       ++a             yes
pre-decrement       --a             yes
post-increment      a++             yes
post-decrement      a--             yes


**/
#include <iostream>
#include <string>

class Operand {
private:
    int date;
public:
   Operand(const int tempDate) : date ( tempDate ) {}
   Operand() : date (0) {}
   Operand(const double tempDou) : Operand(static_cast<int>(tempDou)){}
    /// << overload
    friend std::ostream& operator<<(std::ostream& out,const Operand& obj){
        out<<obj.date;
        return out;
    }
    /// pre-increment ++a
    template<typename T>
    friend T& operator++(T& object);

    /// pre-decrement --a
    template<typename T>
    friend T& operator--(T& object);

    /// post-increment a++
    template<typename T>
    friend T operator++(T& object,int);

    /// post-decrement a--
    template<typename T>
    friend T operator--(T& object,int);


};
/// pre-increment ++a
template<typename T>
T& operator++(T& object){
    ++object.date;
    return object;
}
/// pre-decrement --a
template<typename T>
T& operator--(T& object){
    --object.date;
    return object;
}
/// post-increment a++
/// NOTE
/// no need to return by &
/// using temp object to hold *this value
/// return temp and not *this
template<typename T>
T operator++(T& object,int){
    T temp = object;
    ++object.date;
    return temp;
}
/// post-decrement a--
/// NOTE
/// no need to return by &
/// using temp object to hold *this value
/// return temp and not *this
template<typename T>
T operator--(T& object,int){
    T temp = object;
    --object.date;
    return temp;
}


int main(){

        Operand one(10);
        std::cout<<"one  : "<<one<<std::endl;

        /// pre increment and decrement
        std::cout<<"++one: "<<++one<<std::endl;
        std::cout<<"--one: "<<--one<<std::endl;

        /// post increment and decrement
        std::cout<<"one++: "<<one++<<std::endl;
        std::cout<<"one  : "<<one<<std::endl;
        std::cout<<"one--: "<<one--<<std::endl;
        std::cout<<"one  : "<<one<<std::endl;

}

