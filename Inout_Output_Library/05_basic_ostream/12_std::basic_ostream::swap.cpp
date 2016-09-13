/**
std::basic_ostrream
**/


/// 12_std::basic_ostream::swap
/**

protected :
    void swap(basic_ostream& rhs);

Calls basic_ios::swap(rhs) to swap all date members of the class, except for rdbuf(),
between *this and rhs. This swap function is protected : it is called by the swap
function of the swappable output stream classes std::basic_ofstream and std::ostringstream,
which know how to correctly swap the associated streambuffers.

**/


#include <iostream>
#include <sstream>
#include <chrono>

int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        std::ostringstream s1("Hello");
        std::ostringstream s2("bye");

        s2.swap(s1);       /// okay, ostringstream has a public member that the name is swap()
        std::swap(s1, s2); /// okay, calls the s1.swap(s2) like above

        /* ERROR : std::cout.swap(s2) or std::cout.swap(s1)
           swap is a protected member is the basic_ostream */
        std::cout<< s1.str() << std::endl;
    }

    {
        /// msdn.microsoft.com
    }

}













