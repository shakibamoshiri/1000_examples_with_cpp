/// Null-terminate string

/// 21_std::strncpy
/// definition in header < cstring >
/// string manipulation
/**
char* strncpy ( char* dest, cosnt char* stc, std::size_t count );

Copies at most count character of the byte string pointed to by src
( including the terminating null character ) to character array pointed
to be dest. If count is reached before the entire string src was copied,
the resulting character array is not null. If after copying the terminating
null character from src, count is not reached, additional null character
are written to dest null the total of count character have been written.
If the strings overlap, the behavior is undefined.

Return Value:

**/

#include <iostream>
#include <memory>
#include <cstring>

int main(){
    { /// user sample:
    }
    std::cout<<std::endl;
    { /// sample of en.reference.com
        const char* src = "hi";
        char dest[6] = {'a','b','c','d','e','f'};
        std::strncpy(dest, src, 5);

        std::cout<<"The contests of dest are: ";
        for (char c : dest ){
            if (c){
                std::cout<<c<<' ';
            }else{
                std::cout<<"\\0"<<' ';
            }
            std::cout<<'\n';
        }
    }
}
















