/**
std::basic_ofstream
**/

/// 04_std::basic_ofstream::is_oepn
/**
bool is_open(): since c++11
bool is_open() const; since c++11

Checks if the file stream has an associated file.
Effectively calls rdbuf()->is_open();


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
        std::string filename ( "some_file");
        std::fstream fs(filename, std::ios_base::in); /// only create and is not open
        std::cout<<std::boolalpha;
        std::cout<<"fs.is_open() : "<<fs.is_open()<<std::endl; /// false
        if(!fs.is_open()){
            fs.clear(); /// clear failbit
            fs.open(filename, std::ios_base::out); /// already created and new is open
            std::cout<<"fs.is_open() :" <<fs.is_open()<<std::endl; /// true
        }
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

