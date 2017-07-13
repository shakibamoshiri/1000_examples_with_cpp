/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <sstream>
#include <climits>



int main(){

    std::istringstream input("120 240\nhow are you today\n360 c \n3.14 \n480\n");

    std::size_t integer=0;

    while(true){
        input >> integer;

        if( input.eof() || input.bad() ) {
            break;

        } else if (input.fail()){
            input.clear();
            input.ignore(INT_MAX,'\n'); // skip bad input
            //input.ignore('c'); // skip bad input

        } else {
            std::cout << integer << std::endl;
        }
    }

}
