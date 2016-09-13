//#include <unistd.h>
#include <iostream>
#include <map>
namespace k5 {
    const char* shakib(const char* what) {
        return what;
    }
}
int main(){
    std::cout<<k5::shakib("hello");
}
