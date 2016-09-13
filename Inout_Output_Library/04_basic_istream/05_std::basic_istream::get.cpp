/**
std::basic_istream
**/


/// 05_std::basic_istream::get
/**

1. int_type get() ;
2. basic_istream& get (char_type& ch );
3. basic_istream& get (char_type& s , std::streamsize count );
4. basic_istream& get (char_type& s , std::streamsize count , char_type delim );
5. basic_istream& get ( basic_streambuf& strbuf ) :
6. basic_istream& get ( basic_streambuf& strbuf , char_type delim ) :

Extracts character or characters from stream
All version behave as a UnformattedInputFunction. After constructing and checking the sentry object,
    these function perform the following :
    1) Read one character and return it if available. Otherwise, return Traits::eof() and set eofbit.
    2) Read one character and stores it to ch if available. Otherwise, leaves ch unmodified and sets
        failbit and eofbit.
    3) Same as get( s , count , widen('\n')), that is reads at most count-1 character and stores them
        into character siting pointed to by s until '\n' is found
    4) Reads character and stores them into the successive location of the character array whose first
        element is pointed to by s. Character are extracted and stored until any of the following occurs:
        -
        -
        -
            if no character were extracted , calls ...
    5) Same as get ( strbuf, widen('\n')), that is reads available character and inserts them to the
        given basic_streambuf object until '\n' is found.
    6) Read character and inserts them to the output sequence controlled by the given basic_streambuf object.

NOTE ; All versions set the value of gcount() to the number of characters extracted.

**/
#include <iostream>
#include <sstream>


int main() {
    {
        /// mine
        std::basic_istringstream<char> s("Shakiba");
        s.get();
        std::cout<<s.rdbuf()<<std::endl;
        std::cout<<std::endl;
    }
    {
        /// the site sample
        std::basic_istringstream<char> s1("Hello, World.");
        char c1 = s1.get(); /// Read 'H'

        std::cout<<"After reading : " << c1 <<" , gcount() == "<<s1.gcount() <<std::endl;

        char c2;
        s1.get(c2); /// Reads 'e'

        char str[5];
        s1.get(str, 5); /// read "llo,"

        std::cout<<"After reading " << str << " , gcount() == " << s1.gcount() << std::endl;
        std::cout<<c1 << c2 << str;

        s1.get(*std::cout.rdbuf()); /// Reads the rest , not including
        std::cout<<"\nAfter the last get(), gcount() == " << s1.gcount() << std::endl;
    }
    {
        /// msdn.microsoft.com
    }

}












