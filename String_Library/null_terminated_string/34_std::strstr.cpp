/// Null-terminate string

/// 34_std::strstr
/// definition in header < cstring >
/// string examination
/**
const char* strstr ( const char* str, const char* target);
char* strstr ( char* str, const char* target );


Finds the first occurrence of the byte string target in the byte
string pointed to by str. The terminating null character are not
compared.

Return Value:

**/

#include <iostream>
#include <cstring>
#include <clocale>


int main(){
    { /// user sample:

    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        const char* str = "Try not. Do, or do not. There is no try.";
        const char* target = "not";
        const char* result = str;

        while ( (result = std::strstr(result, target) ) != NULL ){
            std::cout<<"Found '"<<target<<"' string st '"
                     <<result<<"' \n";
            ++result;
        }
    }
}
















