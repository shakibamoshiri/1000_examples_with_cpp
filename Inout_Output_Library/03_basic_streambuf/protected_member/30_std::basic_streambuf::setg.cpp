/**
std::basic_streambuf
**/


/// 30_std::basic_streambuf::setg
/**
void setg ( char_type* gbeg, char_type* gcurr, char_type* gend);

Sets the value of the pointers defining the get area. Specifically, after
the call eback() == gptr(), gptr() == gcurr(), egptr() == gend.
**/
#include <iostream>
#include <sstream>
#include <fstream>
class null_filter_buf : public std::streambuf {
private:
    std::streambuf* sb;
    char ch; /// single-byte buffer
protected:
    int underflow(){
        while( (ch = sb->sbumpc())=='\0'); /// skip zeros
        setg(&ch, &ch, &ch+1); /// make one read position available
        return ch; /// may return EOF
    }
public:
    null_filter_buf ( std::streambuf* buf) : sb ( buf){
        setg(&ch, &ch+1, &ch+1); /// buffer is initially full
    }
};
void filtered_read ( std::istream& is){
    std::streambuf* orig = is.rdbuf();
    null_filter_buf buf(orig);
    is.rdbuf(&buf);
    for ( char c; is.get(c); )
        std::cout<<c;
    is.rdbuf(orig);
}
int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        char c[]= "this i\0s \nan e\0\0\0xample";
        std::istringstream iss ( std::string ( std::begin(c), std::end(c)));
        filtered_read(iss);
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













