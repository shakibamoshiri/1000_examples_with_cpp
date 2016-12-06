/**
std::basic_istream
**/


/// 08_std::basic_istream::putpack
/**

basic_istream& putback( char_type ch );

    Puts the character 'ch' back to the input stream so the next character will 'ch'
First the character eofbit, then behave as UnformattedInputFunction, After construction
and checking the sentry object if rdbuf() is not null, calls rdbuf()->sputbacks(ch),
which calls rdbuf()->pbackfail(ch) if 'ch' does not equal the most recently extracted
character. If rdbuf() is null or if rdbuf()->sputbackc(ch), returns Traits::eof(),
calls setstate(badbit). In any case, sets the gcount() counter to zero.

Return value : *this

**/
#include <iostream>
#include <sstream>


int main() {
    {
        /// mine

    }
    {
        /// the site sample
        std::basic_stringstream<char> s1("Hello World");
        s1.get();
        if(s1.putback('Y')) /// Modifies the buffer
            std::cout<<s1.rdbuf()<<'\n';
        else
            std::cout<<"Putback failed\n";

        std::istringstream s2("hello world"); /// Input-only stream
        s2.get();
        if(s2.putback('Y'))
            std::cout<<s2.rdbuf()<<'\n';
        else
            std::cout<<"Putback failed\n";
        s2.rdbuf()->sputbackc('H');
        s2.clear();
        if(s2.putback('h'))
            std::cout<<s2.rdbuf()<<std::endl;
        else
            std::cout<<"Putback failed\n";

    }
    {
        /// msdn.microsoft.com
    }

}












