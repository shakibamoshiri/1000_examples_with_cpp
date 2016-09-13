/// Null-terminate string

/// 16_std::strtol_strtoll
/// definition in header < cstdio >
/**
long strtol ( const char* str, char ** str_end , int base );
long long strtol ( const char* str, char ** str_end , int base );

Interprets an integer value in a byte string pointed to by str.
Discard is found, then takes as m any character as possible to form
a value base-n ( where n = base ) integer number representation and
converts them to an integer value. The valid integer value consist
of the following parts :
...
...
...


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
        const char* p  = "10 3000000000000000000000000000000 30 -34";
        char* end;
        std::cout<<"Parsing '"<<p<<"':\n";
        for (long i = std::strtol (p, &end, 10);
            p != end;
            i = std::strtol(p, &end , 10))
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
















