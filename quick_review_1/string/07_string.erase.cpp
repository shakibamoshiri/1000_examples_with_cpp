/*
        quick review string library
        ***************************

*/

#include <iostream>
#include <string>


// erase

int main(){
    typedef std::basic_string<char> string;

    string str = "hard work pays off";

    std::cout << str << std::endl; // hard work pays off

    str.erase(0,5);

    std::cout << str << std::endl; // work pays off ( and remove 'hard' )

    str.erase( std::begin(str), std::begin(str)+5);

    std::cout << str << std::endl; // pays off // remove work
}




