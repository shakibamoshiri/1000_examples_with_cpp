/// Null-terminate string

/// 32_std::strcspn
/// definition in header < cstring >
/// string examination
/**
size_t strcspn ( const char* dest, const char* src );

Returns the length of the maximum initial segment of the byte
string pointed to by dest, that consist of only the character
not found in byte string pointed to by src.
The function name stands for "complementary span"

Return Value:

**/

#include <iostream>
#include <cstring>
#include <clocale>

const char* invalid = "*$#";
int main(){
    { /// user sample:

    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        std::string s = "abcde321@#";
        std::size_t sp = std::strcspn ( s.c_str(), invalid );
        if (sp != s.size() )
            std::cout<<"'"<<s<<"' contains invalid chars starting a position "
                    <<sp<<std::endl;
    }
}
















