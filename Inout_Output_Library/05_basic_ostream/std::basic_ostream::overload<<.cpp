/**
std::basic_ostrream
**/


/// std::basic_ostream::
/**

**/


#include <iostream>
#include <sstream>
#include <chrono>


std::basic_ostream<char>& operator<<(std::basic_ostream<char>& os ,std::ostringstream& ss){
        return os<<ss.str();
}
std::basic_ostream<char>& operator<<(std::basic_ostream<char>& os,std::ostringstream&& ss){
        return <<ss.str();
}

int main()
{
    {
        /// owner
        std::ostringstream s("hello shakib");
        std::cout<<s<<std::endl;
        std::cout<<(std::ostringstream("test 2"))<<std::endl;
    }

    {
        /// en.reference.com
    }

    {
        /// msdn.microsoft.com
    }

}













