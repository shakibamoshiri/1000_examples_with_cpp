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


// #include <iomanip>




int main(){

    // enumeration

    enum struct Color { RED, GREEN, BLUE };

    Color window = Color::RED;

    switch( window ){
        case Color::RED     : std::cout << "red";   break;
        case Color::GREEN   : std::cout << "green"; break;
        case Color::BLUE    : std::cout << "blue";  break;
    }   // print red

}



/* output:


*/
