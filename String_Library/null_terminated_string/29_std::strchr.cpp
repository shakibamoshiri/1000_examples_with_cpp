/// Null-terminate string

/// 29_std::strchr
/// definition in header < cstring >
/// string examination
/**

cosnt char* strchr ( const char* str, int ch);
      char* strchr ( char*, int ch);

Finds the first occurrence of the character static_cast<char>(ch)
in the byte string pointed to by str.
The terminating null character is considered to be a part of the string .

Return Value:
Pointer to the found character of in str, or a null pointer if no
such character is found.
**/

#include <iostream>
#include <cstring>
#include <clocale>


int main(){
    { /// user sample:
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        const char* str = "Try not. Do , or do not. There is no try.";
        char target = 'T';
        const char* result = str;
        while ((result  = std::strchr(result, target))!= NULL ){
            std::cout<<"Found '"<<target<<"' starting at '"<<result<<std::endl;
            ++result;
        }
    }
}
















