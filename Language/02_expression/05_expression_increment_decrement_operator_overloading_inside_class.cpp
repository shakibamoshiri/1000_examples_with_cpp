///
/// Expression
///
/// Increment and decrement operator ( inside class )
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
    Operand& operator++(){
        ++this->date;
        return *this;
    }
    /// pre-decrement --a
    Operand& operator--(){
        --this->date;
        return *this;
    }
    /// post-increment a++
    /// NOTE
    /// no need to return by &
    /// using temp object to hold *this value
    /// return temp and not *this
    Operand operator++(int){
        Operand temp = *this;
        ++this->date;
        return temp;
    }
    /// post-decrement a--
    /// NOTE
    /// no need to return by &
    /// using temp object to hold *this value
    /// return temp and not *this
    Operand operator--(int){
        Operand temp = *this;
        --this->date;
        return temp;
    }

};

int main(){
    { /// my sample
    }
    { /// en.reference.com
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

}

