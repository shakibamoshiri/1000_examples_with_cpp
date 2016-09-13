/// Null-terminate string

/// 19_std::strtoimax_strtoumax
/// definition in header < cinttypes >
/**
std::intmax_t strtoimax ( const char* nptr, char** endptr, int base );
std::uintmax_t strtoimax ( const char* nptr, char** endptr, int base ); c++11

Interprets an integer value in a byte string pointed to by nptr.
Discards any whitespace character ( as identified by calling isspace ())
until the first non-whitespace character is found. Then takes as many
character them to an integer value. The valid integer value consist
of the following parts:
>>>
>>>
>>>

Return Value:

**/

#include <iostream>
#include <cinttypes>
#include <string>

int main(){
    { /// user sample:
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        std::basic_string<char> str("hellowrold");
        std::intmax_t val = std::strtoimax(str.c_str(), nullptr, 36);
        std::cout<<str<<" In base 36 is "<<val <<" In base 10\n";

        char* nptr;
        val = std::strtoimax(str.c_str(), &nptr, 30);
        if (nptr != &str[0] + str.size())
            std::cout<<str<<" in base 30 is invalid."
                     <<" The first invalid digit is: "<<*nptr<<std::endl;
    }
}
















