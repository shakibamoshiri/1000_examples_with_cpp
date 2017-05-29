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


int& change (int& value){ return value; }

int* change_2 (int* value){ return value; }

const char* &change_3 (const char* &value){ return value; }

const char** change_4 (const char** value) {return value; }

int main(){

    // l-value reference

    int number = 20;            // number is a r-value
    std::cout << number
              << std::endl;     // 20

    change(number) = 2;         // change function here is a l-value ( through reference )
    std::cout << number
              << std::endl;     // 2

    *change_2( &number ) = 22;  // change_2 function here is a l-value( through pointer )
    std::cout << number
              << std::endl;     // 22

    const char* he("how are"
                   " you"
                   " today?");  // he variable is a r-value

    // okay but undefined behavior
//    const char& rhe = reinterpret_cast<const char&>(he);
//    std::cout << rhe << std::endl;

    change_3( he ) = "I am fine"
        " how about your";      // and here change_3 is also a r-value function
    std::cout << he << std::endl;// I am fine how about you


    const char* she("what is"
                    " your"
                    " name?");  // she is a r-value

    *change_4( &she ) = "Linda";// *change_4 is a r-value function
    std::cout << she;
}
