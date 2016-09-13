/**
std::basic_ofstream
**/

/// 05_std::basic_ofstream::open
/**
void open( const char* filename, std::ios_base::openmode mode = std::ios_base::out);
void open( const std::string& filename, std::ios_base::openmode mode = std::ios_base::out);

Opens and associated the file with name "filename" with the file stream.
Calls setstate(failbit) on failure.
Calls clear() on success. since c++11
1)  Effectively calls rdbuf()->open(filename, mode). (see std::basic_filebuf::open)
    for the details on the effects of the call).
2)  Effectively calls (1) as if by open(filename.c_str(), mode);


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
            fs.open(filename, std::ios_base::out); /// create file.
            fs.close();
            fs.open(filename);
        }
        /// bad using
        /// std::cout(std::boolalpha);
        /// goog using
        std::boolalpha(std::cout);
        std::cout<<"fs.open(): " <<fs.is_open()<<std::endl;
        std::cout<<"fs.good(): "<<fs.good()<<std::endl;
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

