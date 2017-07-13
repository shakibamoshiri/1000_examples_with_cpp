/*
        quick review containers library
        *******************************

*/

#include <iostream>
#include <deque>

// constructor

int main(){

    std::deque<std::string> one { "how", "are", "you", "today" };   // okay

    std::deque<std::string> two (one.begin(), one.end());           // okay

    std::deque<std::string> three (two);                            // okay

    std::deque<std::string> four (4,*one.begin());                  // okay

    for (std::string s : four) std::cout << s << ' ';   // how how how how
}




