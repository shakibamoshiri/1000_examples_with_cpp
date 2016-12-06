/**
std::basic_fstream
**/

/// 04_std::basic_fstream::is_open
/**

bool is_open();
bool is_open()const;

Checks if the file stream has an associated file.
Effectively calls rdbuf()->is_open().
**/
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        std::string filename("some_file");
        std::fstream fs(filename, std::ios_base::in);
        std::cout<<std::boolalpha;
        std::cout<<"fs.is_open(): "<<fs.is_open()<<std::endl;

        if(!fs.is_open()){
            fs.clear();
            fs.open(filename,std::ios_base::out);
            std::cout<<"fs.is_open(): "<<fs.is_open()<<std::endl;
        }
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

