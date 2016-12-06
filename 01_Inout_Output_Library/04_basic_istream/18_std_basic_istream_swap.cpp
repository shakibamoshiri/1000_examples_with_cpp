/**
std::basic_istream
**/


/// 18_std::basic_istream::swap
/**

protected member :
    void swap  ( basic_istream& rhs);

    Calls basic_ios::swap( rhs ), to swap all date members of the base class except for rdbuf(),
and swaps the values of the gcount() counters between *this and "rhs". This swap function is
protected; it called by the swap function of the swappable input stream classes :
    std::basic_istringstream
    std::basic_ifstream,
which know how to correctly swap the associated sterambuffers.

**/
#include <iostream>
#include <sstream>
#include <fstream>


int main() {
    {
        /// mine
    }
    {
        /// the site sample
        std::basic_istringstream<char> s1("hello");
        std::basic_istringstream<char> s2("bye");
        std::cout<<"s1 : "<<s1.str()<<std::endl;
        std::cout<<"s2 : "<<s2.str()<<std::endl;
        s1.swap(s2);
        std::cout<<"s1 : "<<s1.str()<<std::endl;
        std::cout<<"s2 : "<<s2.str()<<std::endl;

        std::swap(s2,s1);
//        std::ios_base::swap(s1,s2);
//        std::basic_istream::swap(s1,s2);


        std::cout<<"s1 : "<<s1.str()<<std::endl;
        std::cout<<"s2 : "<<s2.str()<<std::endl;

    }

    {
        /// msdn.microsoft.com
    }

}













