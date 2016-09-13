/// Null-terminate string

/// 36_std::memcmp
/// definition in header < cstring >
/// character array manipulation
/**

void* memset ( void* dest, int ch, std::size_t count);

Converts the value ch to unsigned char and copies it into
each of the first count character of the object pointed to
by dest. If the object is not trivially-copyable(e.g. scalar
array, or C-compatible struct), the behavior is undefined. If
count is greater than the size of the object pointed to by
dest. the behavior is undefined.


Return Value:

**/

#include <iostream>
#include <cstring>
#include <clocale>

#include <unistd.h>

int main(){
    { /// user sample:

    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        int a[20];
        std::memset(a,0,sizeof a);
        for (int ai : a )
            std::cout<<ai;

        std::cout<<a<<std::endl;
    }

}
















