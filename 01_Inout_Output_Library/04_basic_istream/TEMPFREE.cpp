/**
std::basic_ostrream
**/


/// 00_std::basic_ostream
/**


**/
#include <ctime>
#include <unistd.h>
#include <iostream>

int main() {
    {/// mine
    }

    {
        /// the site sample
        while(true){
            std::time_t result = std::time(NULL);
            std::cout <<std::unitbuf<< std::ctime(&result)<< " K-FIVE" <<std::unitbuf;
            sleep(1);

        }
    }

    {/// msdn.microsoft.com
    }

}













