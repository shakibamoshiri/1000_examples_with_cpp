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


template<typename R>
R& change (R& value){ return value; }

int main(){

    // l-value template function

    int number(20);             // it is a new initializer after C++11
    change( number ) = 2;
    std::cout << number
              << '\n';          // 2

    char vawol('O');
    change( vawol ) = 'O';
//    change( vawol ) = {'O'};    // also okay
    std::cout << vawol
              << '\n';          // O

    const char* me("Are you"
                   " kidding"
                   " me?");     // l-value variable

    change( me ) = "No!";       // l-value function works!
    std::cout << me << '\n';    // No!

    const char* you =
        ( change (me) =
            "I love you" );     // okay. "you" is a l-value and change function is also l-value and both accept a r-value "I love you"
                                // and both are changed

    std::cout << you            // I love you
              << '\n'
              << me             // I love you
              << '\n';
}
