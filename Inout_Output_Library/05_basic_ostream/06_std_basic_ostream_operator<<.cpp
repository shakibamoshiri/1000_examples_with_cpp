/**
std::basic_ostrream
**/


/// 06_std::basic_ostream::operator<<
/**

Insert a characters or a character string.
    1) constant char overloaded
    2) char overloaded
    3) Rvalue overloaded | only in LLVM libc++ not in g++

**/


#include <iostream>
#include <sstream>
#include <fstream>

int main()
{
    {
        /// owner
        std::basic_ostringstream<char> d;
        d.operator=(std::ostringstream("").str()); /// ERRoR in g++ but correct in clang c++11
    }

    {
        /// en.reference.com
        std::cout<<"Hello World"
                 <<"\n";
        std::basic_ofstream<char>("test_operator_equal.txt", std::ios_base::app) << "\ttest_operator_equal.txt\n";
        std::basic_ofstream<char>("test_operator_equal.txt", std::ios_base::app) << "\ttest_operator_equal.txt\n";
        std::basic_ofstream<char>("test_operator_equal.txt", std::ios_base::app) << "\ttest_operator_equal.txt\n";
        std::basic_ofstream<char>("test_operator_equal.txt", std::ios_base::app) << "\ttest_operator_equal.txt\n";

    }

    {
        /// msdn.microsoft.com
    }

}













