/// Null-terminate string

/// 17_std::strtoul_strtoull
/// definition in header < cstdio >
/**
unsigned long strtoul ( const char* str, char ** str_end , int base );
unsigned long long strtoull ( const char* str, char ** str_end , int base );

Interprets  an unsigned integer value in a byte string pointed to by str.
Discard any whitespace character ( as identified by calling isspace())
until the first non-whitespace character is found, then takes as many
character as possible to form a valid base-n ( where n = base ) unsigned
integer number representation and converts them to an integer value. The
valid unsigned integer value consist of the following parts:
>>>
>>>
>>>
Parameter:
str     pointer to the null-terminated byte string to be interpreted
str_end pointer to a pointer to character
base    base of interpreted integer value.

Return Value:

**/

#include <iostream>
#include <cstdio>
#include <string>

int main(){
    { /// user sample:
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        const char* p  = "10 3000000000000000000000000000000 30 34";
        char* end;
        std::cout<<"Parsing '"<<p<<"':\n";
        for (unsigned long i = std::strtoul (p, &end, 10);
            p != end;
            i = std::strtoul(p, &end , 10))
            {
                std::cout<<"'"<<std::string(p,end-p) <<"'-> ";
                p = end;
                if ( errno == ERANGE ) {
                    std::cout<<"range error, get ";
                    errno = 0;

                }
                std::cout<<i<<std::endl;
            }
    }
}
















