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
/// function

#include <iostream>



int main(){

    // generic lambda expression
    auto gle = []( auto one, auto two ){ return one > two; };

    std::cout << gle( 1, 3 ) << '\n';       // false
    std::cout << gle( 'b', 'a' ) << '\n';   // true
    std::cout << gle( 1.1 , 1 ) << '\n';    // true
}
/* output:


*/
