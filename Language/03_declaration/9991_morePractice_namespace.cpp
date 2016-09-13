/**
///

**/

#include <iostream>
#include <string>

// creating a namespace
namespace shakib {
        const char* print(const char* t){
            return t;
        }
}
// alias namespace
namespace k5 = shakib;

// extending namespace
namespace shakib {
    const int length (const char* t){
        int count=0;
        while(*t){
            count++;
            t++;
        }
        return count;
    }
}
// extending namespace std
namespace std {
    const int length(const char* t){
        int count=0;
        while(*t){
            count++;
            t++;
        }
        return count;
    }
}
int main(){
    std::cout<<shakib::print("how are you today?")<<std::endl;
    std::cout<<k5::print("using k5 = shakib")<<std::endl;

    // extending k5 namespace
    std::cout<<k5::length("How are you today?")<<std::endl;

    // extending std namespace
    std::cout<<std::length("How are you today?")<<std::endl;
}









