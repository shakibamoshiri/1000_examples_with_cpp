/// Null-terminate string

/// 36_std::memchr
/// definition in header < cstring >
/// character array manipulation
/**

const void* memchar ( const void* prt, in ch, std::size_t count)
      void* memchar ( const void* prt, in ch, std::size_t count)

convert ch to unsigned char and locates the first occurrence of
that value in the initial count character ( each interpret as
unsigned char ) or the object pointed to by str.


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
        char arr[] = {'a','\0','a','A','a','a','A','a'};
        std::cout<<arr<<std::endl;
        char* pc = (char*) std::memchr(arr,'A',sizeof arr);

        if (pc != NULL )
            std::cout<<"search character found\n";
        else
            std::cout<<"search character not found'\n";
    }
}
















