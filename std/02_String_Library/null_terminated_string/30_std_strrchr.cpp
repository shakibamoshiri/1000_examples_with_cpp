/// Null-terminate string

/// 30_std::strrchr
/// definition in header < cstring >
/// string examination
/**

cosnt char* strrchr ( const char* str, int ch);
      char* strrchr ( char*, int ch);

Finds the last occurrence of ch ( after conversion to char ) in the
byte string  pointed to by str. The terminating null character is
considered to be a part of the string and can be found if searching
for '\0'

Return Value:
Pointer to the found character in str, or null pointer if no such character if found.
**/

#include <iostream>
#include <cstring>
#include <clocale>


int main(){
    { /// user sample:
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        char input[] = "/home/user/hello.c";
        char* output = std::strrchr(input, '/');
        if (output)
            std::cout<<output+1<<std::endl;
    }
}
















