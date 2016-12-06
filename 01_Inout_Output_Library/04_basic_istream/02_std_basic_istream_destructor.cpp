/**
std::basic_istream
**/

#include <iostream>
#include <sstream>
#include <locale>


/// 02_std::std::basic_istream::destructor
/**
virtual ~basic_istream() ;

Destruct the input stream.

    Note : This destructor does not preform any operation on the underlying streambuffer ( rdbuf() );
The destructors of the derived input streams such as std::basic_ifstream ans std::basic_istringstream
are responsible for calling the destructor of the streambuffer.

**/

void print_string_buffer(std::basic_streambuf<char>* p){ /// equivalent to std::streambuf * p;
    std::basic_istream<char> buf (p);                    /// equivalent to std::istream buf;
    int i;
    buf >> i;
    std::cout << i;
} /// calls the destructor of buf, 'p' remains unaffected

int main() {
    {

    }
    {
        /// the site sample
        std::basic_istringstream<char> s1("1 2 3");
        print_string_buffer(s1.rdbuf());

        int i;
        s1 >> i;
        std::cout<<' '<<i<<std::endl;
        s1 >> i;
        std::cout<<' '<<i<<std::endl;

    }
    { /// msdn.microsoft.com
    }

}












