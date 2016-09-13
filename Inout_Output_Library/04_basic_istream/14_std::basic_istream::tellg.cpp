/**
std::basic_istream
**/


/// 14_std::basic_istream::tellg
/**

pos_type tellg();

    Returns input position indicator of the current associated streambuf object.
Behaves as UnformattedInputFunction, except that gcount() is not affected.
After constructing and checking the sentry object, if fail() == true, returns
pos_type(-1). Otherwise, returns rdbuf()->pubseekoff(0, std::ios_base::cur, std::ios_base::in);

Return value : The current position of the  get pointer on success, pos_type (-1) on failure.

**/
#include <iostream>
#include <sstream>


int main() {
    {
        /// mine
    }
    {
        /// the site sample
        std::basic_string<char> string("hello, world");
        std::basic_istringstream<char> input(string);

        std::basic_string<char> word;
        input >> word;
        std::cout<<"after reading the word \"" <<word
                 <<"\" tellg() returns " <<input.tellg() <<std::endl;
    }

    {
        /// msdn.microsoft.com
    }

}













