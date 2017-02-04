/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// expression

#include <iostream>
#include <string>

struct S {
    int number;

    void print () const { std::cout << this->number << std::endl;}

    void print_and_modify () const {
        // here the number is const number, because the function is const
        const_cast<int&>(number) = 3;
        std::cout << this->number << std::endl;
    }

    void print_and_modify_2 () const {
        // S* <==> this
        // <S*>   (this)
        const_cast<S*>(this)->number = 4;
        std::cout << this->number << std::endl;
    }


};  // end of structure S


int main(){
    S one = {2};
    one.print();                // the output is 2
    one.print_and_modify();     // the output is 3
    one.print_and_modify_2();   // the output is 4
}
