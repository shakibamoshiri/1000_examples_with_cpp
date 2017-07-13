///
/// Expression
///
/// operator
/**
    operator:                     syntax                 overload
    simple assignment                   a = b                 yes
    addition assignment                 a += b                yes
    subtraction assignment              a -= b                yes
    multiplication assignment           a *= b                yes
    division assignment                 a /= b                yes
    module assignment                   a %= b                yes

    bitwise AND assignment              a &= b                yes
    bitwise OR assignment               a |= b                yes
    bitwise XOR assignment              a ^| b                yes
    bitwise left shift assignment       a <<= b               yes
    bitwise right shift assignment      a >>= b               yes

what is the copy assignment ?
Copy assignment operator replaces the contents of the object 'a' with a copy
of the contents of 'b' ( 'b' is not modified ). For example types, this is a
special member function, described in "copy assignment operator"

What is the move assignment ?
Move assignment operator replaces the contents of the object 'a' with the __
contents of 'b', avoiding copying if possible ( 'b' may by modified ). For _
class types, this is a special member function, described in move assignment
operator ( since c++11 ).

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
    /// = for class and overload with int
    Operand& operator = (const Operand& obj){
        this->data = obj.data;
        return *this;
    }
    Operand& operator = (const int tempInt){
        this->data = tempInt;
        return *this;
    }

    /// += for class and overload with int
    Operand& operator += (const Operand& obj){
        this->data += obj.data;
        return *this;
    }
    Operand& operator += (const int tempInt){
        this->data += tempInt;
        return *this;
    }

    /// -= for class and overload with int
    Operand& operator -= (const Operand& obj){
        this->data -= obj.data;
        return *this;
    }
    Operand& operator -= (const int tempInt){
        this->data -= tempInt;
        return *this;
    }

    /// *= for class and overload with int
    Operand& operator *= (const Operand& obj){
        this->data *= obj.data;
        return *this;
    }
    Operand& operator *= (const int tempInt){
        this->data *= tempInt;
        return *this;
    }

    /// /= for class and overload with int
    Operand& operator /= (const Operand& obj){
        this->data /= obj.data;
        return *this;
    }
    Operand& operator /= (const int tempInt){
        this->data /= tempInt;
        return *this;
    }

    /// %= for class and overload with int
    Operand& operator %= (const Operand& obj){
        this->data %= obj.data;
        return *this;
    }
    Operand& operator %= (const int tempInt){
        this->data %= tempInt;
        return *this;
    }
    Operand& operator %= (const double tempDou){
        this->data %= static_cast<int>(tempDou);
        return *this;
    }


};

int main(){
    { /// my sample
    }
    { /// en.reference.com
        int n = 0; /// not an assignment

        n = 1;      /// direct assignment

        n = {};     /// zero-initialization, then assignment

        n = 'n';    /// integral promotion, then assignment

        n = 1.0;    /// floating-point conversion, then assignment

        /// Error
        // n = {1.0};
        /// compile error ( narrowing conversation )

        int& r = n; /// not an assignment
        int* p;

        r = 4;      /// assignment through reference
        Operand one(20);
        one=30;
        std::cout<<"one         : "<<one<<std::endl;
        one+=30;
        std::cout<<"one+=30     : "<<one<<std::endl;
        one-=20;
        std::cout<<"one-=20     : "<<one<<std::endl;
        one*=2;
        std::cout<<"one*=2      : "<<one<<std::endl;
        one/=4;
        std::cout<<"one/=4      : "<<one<<std::endl;
        one%=3.33333;
        std::cout<<"one%=3.3    : "<<one<<std::endl;
    }

}

