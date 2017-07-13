/// Null-terminate string

/// 18_std::strtof_strtod_strtold
/// definition in header < cstdio >
/**
float       strtof ( const char* str, char** str_end );
double      strtod ( const char* str, char** str_end );
long double strtold( const char* str, char** str_end );

Interprets a floating point value in a byte string pointed to by str.
Function discard any whitespace character ( as determined by std::
isspace()) until first non-whitespace character is found. Then it
takes as many character as possible to form a valid floating point
representation and converts them to floating point value. The floating
point value can be one of the following:
>>>
>>>
>>>

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
        const char* p = "111.22 -3.33 0X1.BC7A2D60A2D7P+6 1.234e2344zzzz";
        char* end;
        std::cout<<"Parsing \\"<<p<<"\"\n";
        for ( double f = std::strtod(p, &end); p!=end; f = std::strtod(p, &end)){
            std::cout<<"'"<<std::string (p, end-p)<<"'->";
            p = end;
            if ( errno == ERANGE ){
                std::cout<<"range error, got";
                errno = 0;
            }
            std::cout<<f<<std::endl;
        }
    }
}
















