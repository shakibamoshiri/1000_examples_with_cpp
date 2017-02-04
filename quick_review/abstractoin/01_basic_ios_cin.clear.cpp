/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <string>

int main(){

    double d = 0.0;

    while( std::cout << "Please enter a number\n" && !(std::cin >> d) ){
        std::cin.clear();
        std::string line;
        std::getline(std::cin, line);
        std::cout << "I am sorry, but '" << line << "' is is number\n";
    }

    std::cout << "Thank you for entering the number " << d << std::endl;

}
