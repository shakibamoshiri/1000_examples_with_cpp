/**
std::basic_istream
**/


/// 07_std::basic_istream::unget
/**

basic_istream& unget();

makes the most recently extracted character available again.

Then the function behaves as UnformattedInputFunction. After construction and checking the sentry
object, if any ios_base::iostate flags are set, the function sets [ failbit ]  and returns.
Otherwise, calls rdbuf()->sungetc().

if rdbuf()->sungetc() returns Traits::eof(), calls setstate ( badbit );
In any case, sets the gcount() counter to zero.

**/
#include <iostream>
#include <sstream>


int main() {
    {
        /// mine

    }
    {
        /// the site sample
        std::basic_istringstream<char> s1("hello world.");
        char c1 = s1.get();
        if(s1.unget()){
            char c2 = s1.get();
            std::cout<<"Got : " << c1 << " got again : " << c2 << std::endl;
        }
    }
    {
        /// msdn.microsoft.com
    }

}












