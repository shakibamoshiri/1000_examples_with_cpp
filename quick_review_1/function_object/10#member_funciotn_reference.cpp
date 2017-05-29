/*
    quick review:
    General-Purpose Utility

    01. program utility
    02. date and time
    03. function object
    04. bitset
    05. pair
    06. tuple
    07. swap, forward, move
    08. type operations
    09. hash support

*/
/// 03. function object in header <functional>



#include <iostream>
#include <functional>


int main(){

    std::string string = "how are you today?";

    std::size_t ( std::string::* sz )() const noexcept = &std::string::size;

    std::cout << (string.*sz)();    // 18


}


/* output:



*/
