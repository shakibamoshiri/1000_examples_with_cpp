/**
std::basic_istream
**/


/// 10_std::basic_istream::ignore
/**

basic_istram& ignore( std::streamsize count = 1, int_type delim = Traits::eof() );
Extracts and discards character from the stream until and including delim.

Return value : *this.


**/
#include <iostream>
#include <sstream>
#include <limits>


int main() {
    {
        /// mine
    }
    {
        /// the site sample
        std::istringstream input("1\nSome non-numeric input\n2\n");
        std::cout<<input.str()<<std::endl;

        for (;;){
                int n;
        input >> n;
        if (input.eof() or input.bad() )
            break;
        else if (input.fail()) {
            input.clear();
            input.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); /// skip bad input
        }else
            std::cerr.operator<<(n).operator<<(std::endl);
        }
    }
    {
        /// msdn.microsoft.com
    }

}













