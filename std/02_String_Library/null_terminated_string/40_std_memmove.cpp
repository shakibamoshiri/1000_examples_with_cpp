/// Null-terminate string

/// 40_std::memmove
/// definition in header < cstring >
/// character array manipulation
/**

void* mmemove ( void* dest, const void* src, std::size_t count);

Copies count character form the object pointed to by src to the
object pointed to by dest. Both objects are reinterpreted as _
arrays of unsigned char. The object may overlap: copying takes
place as if the character were copied to a  temporary character
array and then the characters were copies form the array to dest.
If the object are not TriviallyCopyable, the behavior or memmove
is not specified and may be undefined.

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
        char str[] = "12345667890";
        std::cout<<str<<std::endl;
        std::memmove(str+4, str+3, 3); /// copy form [4,5,6] to [ 5,6,7]
        std::cout<<str<<std::endl;
        std::memmove(str, str+8, 9); /// copy form [4,5,6] to [ 5,6,7]
        std::cout<<str<<std::endl;
    }

}
















