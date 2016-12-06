/**
std::basic_ios
**/

#include <iostream>
#include <fstream>


/// std::basic_ios::tie
/**

std::basic_ostream<charT , Traits>* tie () const;
std::basic_ostream<charT , Traits>* tie ( std::basic_ostream <CharT , Traits>* str )

Manages the tied stream. A tied stream is an output which is synchronized with the sequence controlled by
    the stream buffer ( rdbuf() ), that is, flush() is called on the tied stream before any input / output
    operation on *this.
    1. Return the current tie stream. If there is no bad stream, NULL is returned.
    2. Sets the current tied stream to str (parameter). Returns the tied stream before the operation,
        If there is no tied stream, NULL is returned.

**/

int main() {
    {
        /// mine : did not know

    }
    {
        /// the site sample
        std::string s;
        std::ofstream os("test_tie.txt");
        std::ifstream is("test_tie.txt");

        os << "Hello";

        is >> s;

        std::cout<<"Result before tie() :  \"" << s << "\"\n";
        std::cout<<is.bad()<<' '<<is.good()<<' '<<is.fail()<<' '<< is.eof();
        is.clear();
        is.tie(&os);

        is >> s;

        std::cout<<"Result after tie() :  \"" << s << "\"\n";

    }

}












