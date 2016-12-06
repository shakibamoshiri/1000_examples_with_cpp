/// Null-terminate string

/// 35_std::strtok
/// definition in header < cstring >
/// string examination
/**

char* strtok (char* str, const char* delim );

Finds the next token in a null-terminated byte string pointed
to by str. The separator characters are identified by null-
terminated byte string pointed to by delim.
This function is designed to be called multiples times to obtain
successive tokens form the same string.
>>>
>>>
>>>

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
        char input[40] = "A bird came down the walk";
        char* token = std::strtok(input," ");

        while ( token != NULL ){
            std::cout<<token<<std::endl;
            sleep(1);
            token = std::strtok("walk"," ");
        }
    }
}
















