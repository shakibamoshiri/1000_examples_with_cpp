/*
        quick review containers library
        *******************************

*/

#include <iostream>
#include <set>

//
template<class CH, class TR, class CO>
std::basic_ostream<CH, TR>& operator << (std::basic_ostream<CH, TR>& out, CO& obj){
    for (auto tmp : obj) std::cout << tmp << ' ';
    return out;
}


int main(){

    std::set<int> one {3,1,5,2,6,7,1,1,2,3,6,5,4,3,2,1,2,3,4,5,6,7};

    std::cout << one << std::endl;

}




