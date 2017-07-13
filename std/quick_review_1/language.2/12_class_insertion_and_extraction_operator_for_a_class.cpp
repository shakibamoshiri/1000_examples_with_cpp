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
//  insertion_and_extraction_operator_for_a_class
/******************/
#include <iostream>
#include <sstream>

class C {
private:
    int number;

public:
    C( int temp ) : number( temp ) {}

    friend std::ostream& operator <<( std::ostream& out, C& obj ){
        return out << obj.number;
    }
    friend std::istream& operator >>( std::istream& in,  C& obj ){
        return in >> obj.number;
    }

};


int main(){

    C object( 23 );
    std::cout << object << '\n';

    // std::cin overloading also works with istringstream >> operator
    std::istringstream( "32" ) >> object;
    std::cout << object << '\n';

}

/* output:

23
32

*/
