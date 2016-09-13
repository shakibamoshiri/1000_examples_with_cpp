/// Null-terminate string

/// 31_std::strspn
/// definition in header < cstring >
/// string examination
/**
size_t strspn ( const char* dest, const char* src );

Returns the length of the maximum initial segment ( span ) of the
byte string pointed to by dest. That consist of only the character
found in byte string pointed to by src.

Return Value:

**/

#include <iostream>
#include <cstring>
#include <clocale>

const char* low_alpha = "abcdefkjgklopqurstyxzw";
int main(){
    { /// user sample:

    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        std::string s = "abcde321@#";
        std::size_t sp = std::strspn ( s.c_str(), low_alpha );
        std::cout<<"After skipping initial lowercase letter from '"<<s
                 <<"'\nThe remainder is '"<<s.substr(sp) <<"'\n";
    }
}
















