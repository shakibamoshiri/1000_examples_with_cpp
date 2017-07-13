/// Null-terminate string

/// 33_std::strpbrk
/// definition in header < cstring >
/// string examination
/**

const char* strpbrk ( const char* dest, const char* breakset );
char* strpbrk ( char* dest, const char* breakset );

Scans the null-terminated byte string pointed to by dest for
any character form the null-terminated byte string pointed to
by breakset, and returns a pointer to that character.

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
        const char* str = "hello world, friend of mine!";
        const char* sep = " ,!";

        unsigned int cnt = 0;
        do{
            str = std::strpbrk ( str, sep); /// find separator
            if ( str )
                str = str += std::strspn ( str, sep); /// skip separator
            ++cnt; /// increment word count
        }while ( str && *str );

        std::cout<<"There are " <<cnt<<"words\n";
    }
}
















