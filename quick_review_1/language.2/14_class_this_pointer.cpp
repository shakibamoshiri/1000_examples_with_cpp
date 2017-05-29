/*
            language 2
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. Classes
2. Templates
3. Exceptions
4. Statements
5. Miscellaneous

*/
/// class
//  this pointer

/******************/
#include <iostream>

// by accessible inside member function
// also with sizeof operator
// for non-constant member function this is:    class* this;
// for constant member function this is:        const class* this;
class C {
private:
    int number;
    int grade = sizeof( *this );    // okay

public:

    C( int temp ){
        this->number = temp;        // okay
        std::cout << "constructor ... " << number << '\n';
    }

    void print(){
        number = 10;    // using implicit of this pointer, same as this->number
        std::cout << number << '\n';

        this->number = 11;
        std::cout << number << '\n';
    };

    void stuff(){
        int temp[ sizeof( *this )]; // okay, inside a member function, and wrong the outside of it
    }
};

int main(){

    C object( 9 );

    object.print();

}

/* output:

constructor ... 9
10
11

*/
