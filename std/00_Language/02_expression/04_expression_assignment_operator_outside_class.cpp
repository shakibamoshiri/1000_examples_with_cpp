///
/// Expression
///
/// operator
/**


**/

#include <iostream>
#include <string>

class Operand {
private:
    int data;
public:
   Operand(const int tempData) : data ( tempData ) {}
   Operand() : data (0) {}
   Operand(const double tempDou) : Operand(static_cast<int>(tempDou)){}
    /// << overload
    friend std::ostream& operator<<(std::ostream& out,const Operand& obj){
        out<<obj.data;
        return out;
    }
    template<typename L, typename R>
    friend L& operator+=(L& left,const R& right);

    template<typename L, typename R>
    friend L& operator-=(L& left,const R& right);

    template<typename L, typename R>
    friend L& operator*=(L& left,const R& right);

    template<typename L, typename R>
    friend L& operator/=(L& left,const R& right);

};
template<typename L, typename R>
L& operator+=(L& left,const R& right){
    left.data+=right.data;
    return left;
}
template<typename L, typename R>
L& operator-=(L& left,const R& right){
    left.data-=right.data;
    return left;
}
template<typename L, typename R>
L& operator*=(L& left,const R& right){
    left.data*=right.data;
    return left;
}
template<typename L, typename R>
L& operator/=(L& left,const R& right){
    left.data/=right.data;
    return left;
}

int main(){
    { /// my sample
    }
    { /// en.reference.com
        Operand one(100);
        Operand two(50);
        Operand three(10);

        std::cout<<"one is:     "<<one<<std::endl;
        std::cout<<"two is:     "<<two<<std::endl;
        std::cout<<"three is:   "<<three<<std::endl;

        std::cout<<std::string(30,'.')<<std::endl;

        one+=two;
        std::cout<<"one+=two:   "<<one<<std::endl;

        one-=three;
        std::cout<<"one-=three: "<<one<<std::endl;

        one*=one;
        std::cout<<"one*=one:   "<<one<<std::endl;

        one/=two;
        std::cout<<"one/=two    "<<one<<std::endl;

    }

}

