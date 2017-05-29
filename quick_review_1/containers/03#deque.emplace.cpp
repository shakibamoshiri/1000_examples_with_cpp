/*
        quick review containers library
        *******************************

*/

#include <iostream>
#include <deque>

// constructor

int main(){

    std::deque<std::string> one;

    one.emplace(one.begin(),"how");     // constructs a new string an puts in the position one.begin();
    one.emplace(one.begin()+1,"are");   // constructs a new string an puts in the position one.begin();

    one.pop_front(); // remove one first element

    std::cout << one.size() << std::endl; // 1


}




