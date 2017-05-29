/*
        quick review containers library
        *******************************

*/

#include <iostream>
#include <deque>

// constructor

std::ostream& operator << (std::ostream& out, std::deque<std::string>&& dstr){
    for (std::string s : dstr) out << s << ' ';
    return out;
}

std::deque<std::string>&& func (){
    return {"one","two","three"};
}

int main(){

    std::cout << (std::deque<std::string>{"how","are","you","today?"}) << std::endl;



    //std::cout << (func()) << std::endl;


}




