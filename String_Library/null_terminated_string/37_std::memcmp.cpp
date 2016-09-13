/// Null-terminate string

/// 36_std::memcmp
/// definition in header < cstring >
/// character array manipulation
/**

int memcmp ( const void* lhs, const void* rsh, std::size_t count);

Reinterpret the objects pointed to by lhs and rhs as arrays of
unsigned char and compares the first count character of those
arrays. The comparison is done lexicographically. The sign of
the result is the sign of the difference between the value of
the first pair of bytess ( both interpreted as unsigned char)
that buffer in the objects being compared.


Return Value:

**/

#include <iostream>
#include <cstring>
#include <clocale>

#include <unistd.h>

void demo ( const char* lhs, const char* rhs, size_t sz){
    std::cout<<std::string(lhs,sz);
    int rc = std::memcmp(lhs,rhs,sz);
    if ( rc == 0 )
        std::cout<<"compare equal to ";
    else if (rc < 0 )
        std::cout<<" precedes ";
    else if ( rc > 0)
        std::cout<<" follows ";
    std::cout<<std::string(rhs, sz)<<" in lexicographical order\n";
}

int main(){
    { /// user sample:

    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        char a1[] = {'a','b','c'};
        char a2[sizeof a1] = {'a','b','d'};

        demo(a1,a2,sizeof a1);
        demo(a2,a1,sizeof a1);
        demo(a1,a1,sizeof a1);
    }
}
















