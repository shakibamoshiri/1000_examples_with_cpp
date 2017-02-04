/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <sstream>




int main(){

    std::istringstream input("one|two|three|four|five");


    char store[6]{};    // assuming for the buffer
    input.seekg(0,input.end);           // goes to end
    std::size_t size = input.tellg();   // get the length of input
    input.seekg(0,input.beg);           // goes back to beginning


    for( ;input.getline(&store[0], size ,'|'); ) std::cout << store << std::endl;

}
