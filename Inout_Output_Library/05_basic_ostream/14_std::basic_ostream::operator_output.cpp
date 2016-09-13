/**
std::basic_ostrream
**/


/// 13_std::basic_ostream::op
/**
basic_ostream& operator<<( short value );
basic_ostream& operator<<( unsigned short value );	 (1)
basic_ostream& operator<<( int value );
basic_ostream& operator<<( unsigned int value );	 (2)
basic_ostream& operator<<( long value );
basic_ostream& operator<<( unsigned long value ); 	 (3)
basic_ostream& operator<<( long long value );
basic_ostream& operator<<( unsigned long long value );	(4) 	(since C++11)
basic_ostream& operator<<( float value );
basic_ostream& operator<<( double value );
basic_ostream& operator<<( long double value );	        (5)
basic_ostream& operator<<( bool value );	            (6)
basic_ostream& operator<<( const void* value );         (7)
basic_ostream& operator<<( std::basic_streambuf<CharT, Traits>* sb);	(8)
basic_ostream& operator<<(
    std::ios_base& (*func)(std::ios_base&) );	                        (9)
basic_ostream& operator<<(
    std::basic_ios<CharT,Traits>& (*func)(std::basic_ios<CharT,Traits>&) );         (10)
basic_ostream& operator<<(
    std::basic_ostream<CharT,Traits>& (*func)(std::basic_ostream<CharT,Traits>&) ); (11)

Insert a character or a character string.
**/


#include <iostream>
#include <sstream>
#include <fstream>


int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        std::cout<<"hello, world" /// the const char* overloaded
                 <<"\n";
        int c = 0;
        std::ofstream("test_operator_stdout.txt",std::ios_base::app) << c++ << "\ttest_operator_stdout in the basic_ostream\n";

    }

    {
        /// msdn.microsoft.com
    }

}













