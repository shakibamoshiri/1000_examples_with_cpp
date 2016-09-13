/// Null-terminate string

/// 39_std::memcpy
/// definition in header < cstring >
/// character array manipulation
/**
void* memcpy ( void* dest, const void* src, std::size_t count);

Copies count bytes from the object pointed to by src to the
object pointed to by dest. Both objects are reinterpreted as
arrays of unsigned char. If the objects overlap, the behavior
is undefined. If either dest or src is a null pointer, the
behavior is undefined, even if count is zero. If the object
are not TriviallyCopyable, the behavior of mmecpy is not
specified and may be undefined.


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
        /// simple usage
        char source[] = "once upon a midnight dreary...";
        char dest[4];
        std::memcpy(dest, source,sizeof dest);
        for ( char c : dest )
            std::cout<<c<<std::endl;

        /// reinterpreting
        double d = 1.0;
        /// std::int64_t n  = *reinterpret_cast<std::int64_t*>(&d); /// aliasing violation
        std::int64_t n;
        std::memcpy(&n, &d , sizeof d); /// okay
        std::cout<<std::hexfloat<<d<<" is "<<std::hex<<n
                 <<" as an std::int64_t\n";
    }

}
















