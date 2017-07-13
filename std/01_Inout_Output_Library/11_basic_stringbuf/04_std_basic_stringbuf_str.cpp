/**
std::basic_stringbuf
**/

/// 04_std::basic_stringbuf::str
/**

std::basic_string<CharT, Traits, Allocator> str() const;
void str(const std::basic_string<CharT, Traits, Allocator>& );

Gets and sets the underlying string.

1)  Create and returns a std::basic_string object containing a copy of this
    std::basic_stringbuf's underlying character sequence. For input-only streams,
    the returned string contains the characters from the range[eback(), egptr()).
    For input / output or output-only streams, contains the characters form pbase()
    to the last character in the sequence regardless of egptr() and epptr().
2)  Deleted the entire underlying character sequence of this std::basic_stirngbuf
    and then configures a new underlying character sequence containing a copy of
    the contains of the s. The pointers of std::basic_streambuffer initialized as follows:
    -
    -
    -
    -


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
        int n;
        std::istringstream in; /// cloud also use in ("1 2")
        in.rdbuf()->str("1 2");
        in >> n; /// put 1 to n
        std::cout<<"After reading the first int form \"1 2\", the int is: "
                 <<n <<", str(): "<<in.rdbuf()->str()<<std::endl;

        std::ostringstream out("1 2");
        out << 3;
        std::cout<<"After writing the int '3' to output stream \"1 2\""
                 <<"str(): "<<out.rdbuf()->str()<<std::endl;

        std::ostringstream ate("1 2", std::ios_base::ate); /// c++11
        ate << ' ';
        ate << 3;
        std::cout<<"ate: "<<ate.rdbuf()->str()<<std::endl;
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
