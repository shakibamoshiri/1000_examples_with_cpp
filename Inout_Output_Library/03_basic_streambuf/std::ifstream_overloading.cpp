/**
std::basic_streambuf
**/


/// 00_std::basic_straembuf::
/**

**/


#include <iostream>
#include <sstream>
#include <fstream>

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& os, std::basic_ostringstream<char>&& iss){
    return os<<iss.str();
}

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& os, std::basic_ifstream<char>&& ifs){
    return std::cout<<ifs.rdbuf();
}


int main()
{
    {
        /// owner
        std::cout<<std::ostringstream("Test ostringstream overloading")<<std::endl;
        std::ofstream("fstream.txt")<<"Test fstream overloading"<<std::endl;
        std::cout<<std::ifstream("fstream.txt")<<std::endl;


    }

    {
        /// en.reference.com
    }

    {
        /// msdn.microsoft.com
    }

}













