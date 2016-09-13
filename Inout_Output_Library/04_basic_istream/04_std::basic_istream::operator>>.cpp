/**
std::basic_istream
**/

#include <iostream>
#include <sstream>
#include <locale>


/// 03_std::basic_istream::operator>>
/**

basic_istream& operator>>( short& value );
basic_istream& operator>>( unsigned short& value ); (1)
basic_istream& operator>>( int& value );
basic_istream& operator>>( unsigned int& value ); (2)
basic_istream& operator>>( long& value );
basic_istream& operator>>( unsigned long& value ); (3)
basic_istream& operator>>( long long& value );
basic_istream& operator>>( unsigned long long& value ); (4)	(since C++11)
basic_istream& operator>>( float& value );
basic_istream& operator>>( double& value );
basic_istream& operator>>( long double& value );(5)
basic_istream& operator>>( bool& value ); (6)
basic_istream& operator>>( void*& value ); 7)

basic_istream& operator>>( std::ios_base& (*func)(std::ios_base&) ); (8)
basic_istream& operator>>( std::basic_ios<CharT,Traits>& (*func)(std::basic_ios<CharT,Traits>&) ); (9)
basic_istream& operator>>( basic_istream& (*func)(basic_istream&) ); (10)
basic_istream& operator>>( std::basic_streambuf<CharT,Traits>* sb ); (11)

1,2,3,4 : behaves as a FormattedInputFunction. After constructing and checking the sentry object,
    which man skip leading whitespace, extracts an integer value by calling std::num_get::get()
5       : Behaves as a FormattedInputFunction. After constructing and checking the sentry object,
    which may skip leading whitespace, extracts a floating point value by calling std::num::get::get().
6       : Behaves as a FormattedInputFunction. After constructing and checking the sentry object,
    which may skip leading whitespace, extracts a bool value by calling std::num::get::get().
7       : Behaves as a FormattedInputFunction. After constructing and checking the sentry object,
    which may skip leading whitespace, extracts a bool value by calling std::num::get::get().
8,9,10  : Calls func (*this); , where func is an I/O manipulator.

11      : Behaves as a FormattedInputFunction. After construction and checking the sentry object,
    extracts all date form the input stream and stores it to 'sb'. The extraction stops if one
    of the following condition are met :
        end-of-file occurs on the input sequence
        inserting in the output sequence files ( in which case the character to be inserted is extracted )
        + An exception occurs ( in which case the exception is caught, and only rethrown if failbit
            enabled inexceptions()

Return value :
1,2,3,4,5,6,7,8,9+11 : *this
11                   : func(*this)
**/


int main() {
    {
        /// mine
    }
    {
        /// the site sample
        std::basic_string<char> input ("33 3.444 false Shakib MODHIR");
        std::basic_istringstream<char> stream (input); /// Initialize by input value

        int i;
        double d;
        bool b;

        stream >> i >> d >> std::boolalpha >> b;
        std::cout<<" i : " <<i<<'\n'
                 <<" d : " << d << '\n'
                 <<" b : " << std::boolalpha << b
                 <<std::endl;

        std::cout<<std::endl;



        /// extract the rest using the streambuf overload
        std::basic_istringstream<char> stream2 (input);
        stream2 >> std::cout.rdbuf();
        std::cout<<std::endl;
    }
    {
        /// msdn.microsoft.com
    }

}












