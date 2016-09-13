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

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& os, std::basic_ostringstream<char>&& iss){
    return os<<iss.str();
}

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& os, std::basic_ifstream<char>&& ifs){
    std::basic_streambuf<char>* buf(ifs.rdbuf());

}


int main()
{
    {
        /// owner
        std::cout<<std::ostringstream("Test ostringstream overloading")<<std::endl;
        std::ofstream("fstream.txt")<<"Test fstream overloading"<<std::endl;
        std::cout<<std::ifstream("fstream.txt");

        std::basic_istringstream<char> stream("basic_input_string_stream");
        stream >> std::cout.rdbuf();
        std::cout<<std::endl;
    }

    {
        /// en.reference.com
    }

    {
        /// msdn.microsoft.com
    }

}













