/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <sstream>




int main(){
    std::string file = "c "                  // char
                       "120 "                // int
                       "3.14 "               // float
                       "false "              // boolean
                       "how are you today?";// string

    std::istringstream iss(file);
    char c;
    int i;
    float f;
    bool b;

    // char >> c
    // int >> i
    // float >> f
    // boolean >> b
    iss >> c >> i >> f >> std::boolalpha >> b;

    std::cout << c << ' ' << i << ' ' << f << ' ' << std::boolalpha << b << std::endl;

    // extract the rest of the file using the streambuf overload
    iss >> std::cout.rdbuf();
}
