/**
std::basic_fstream
**/

/// 05_std::basic_fstream::open
/**

void open(const char* filename, ios_base::openmode mode = ios_base::in | ios_base::out );
void open(const std::string filename, ios_base::openmode mode = ios_base::in | ios_base::out );

Opens and associates the file with name filename with the file stream.
Calls setstate(failbif) on failure.
Calls clear() on success. since c++11
1)  Effectively calls rdbuf()->open(filename, mode).
2)  Effectively calls (1) as if by open(filename.c_str(), mode).

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
        std::string filename("example.123");
        std::fstream fs;
        fs.open(filename);
        if(!fs.is_open()){
            fs.clear();
            fs.open(filename, std::ios_base::out); /// Create file.
            fs.close();
            fs.open(filename);
        }
        std::boolalpha(std::cout);
        std::cout<<"fs.is_open(): "<<fs.is_open()<<std::endl;
        std::cout<<"fs.good()   : "<<fs.good()<<std::endl;
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

