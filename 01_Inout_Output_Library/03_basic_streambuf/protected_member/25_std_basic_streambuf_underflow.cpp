/**
std::basic_streambuf
**/


/// 25_std::basic_streambuf::underflow
/**
virtual int_type underflow();

    Ensures that at least one character is available in the input area by
updating the pointer to the input area ( if needed ) and reading more
date in from the input sequence ( if available ). Returns the value of
that character( converted to int_type with Traits::to_int_type(c)) on
success or Traits::eof() on failure.
    The function may update gptr(), egptr() and eback() pointer to define
the function of newly loaded date ( if any ). On failure, the function
ensures that either pgre() == nullptr or gptr() == egptr(). The base class
version of the function does nothing. The derived classes may override this
function to allow updates to the get area in the case of exhaustion.

**/
#include <iostream>
#include <sstream>
#include <fstream>
class null_filter_buf : public std::streambuf {
private:
    std::streambuf* src;
    char ch; /// single-byte buffer
protected:
    int underflow(){
        while( (ch= src->sbumpc())== '\0'); /// skip zeros
        setg(&ch, &ch, &ch+1); /// make one read position available
        return ch; /// single-byte buffer
    }
public:
    null_filter_buf ( std::streambuf* buf) : src(buf) {
        setg(&ch, &ch+1, &ch+1); /// buffer is initially full
    }
};

void filtered_read(std::istream& in){
    std::streambuf* orig = in.rdbuf();
    null_filter_buf buf(orig);
    in.rdbuf(&buf);
    for(char c; in.get(c); )
        std::cout<<c;
    in.rdbuf(orig);
}

int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        char a[] = "This i\0s \0am e\0\0\0xample";
        std::istringstream in(std::string(std::begin(a),std::end(a)));
        filtered_read(in);
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













