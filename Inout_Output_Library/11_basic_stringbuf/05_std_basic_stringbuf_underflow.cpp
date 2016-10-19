/**
std::basic_stringbuf
**/
/// protected member
/// 05_std::basic_stringbuf::underflow
/**
protected:
virtual int_type underflow();
Reads the next character from the get area of the buffer.
Specifically:
1)  If the input sequence has a read position available ( egptr() > gptr()),
    returns Traits::to_int_type(*gptr())
2)  Otherwise, if pptr() > egptr() ( some characters were inserted into the
    stream since the last time overflow() changed egptr()) then extends the
    end of the get area to include the most recently inserted characters, by
    changing epgtr() to equal pptr(), and then returns Traits::to_int_type(*gptr()).
3)  Otherwise, returns Traits::eof().

Any character in the buffer which has been initialized, regardless of whether
it originated from the string passed in the constructor or was appended by
overflow(), is considered to be part of the input sequence.

**/
#include <iostream>
#include <sstream>
#include <fstream>
struct mybuf : std::stringbuf {
    mybuf (const std::string& new_str,
           std::ios_base::openmode which = std::ios_base::in|std::ios_base::out)
           : std::stringbuf(new_str, which)
           {}
    int_type overflow( int_type c){
        std::cout<<"Buffer overflow(): get area size is "<<egptr() - eback()
                 <<" the put area size is : "<<epptr()-pbase()<< std::endl;
        int_type rc = std::stringbuf::overflow(c);
        std::cout<<"After overflow(): get area size is: "<< egptr()-eback()
                 <<" put area size is: "<< epptr()-pbase()<<std::endl;
    }
    int_type underflow(){
        std::cout<<"Before underflow(): get area size is: "<<egptr()-eback()
                 <<" put area size is: "<<epptr()-pbase()<<std::endl;
        int_type ch = std::stringbuf::underflow();
        std::cout<<"After underflow(): get area size is: "<<egptr()-eback()
                 <<" put area size is: "<<epptr()-pbase()<<std::endl;
        if(ch == EOF)
            std::cout<<"underflow() returns EOF\n";
        else
            std::cout<<"underflow() returns: |"<<char(ch)<<"|\n";
        return ch;
    }
};
int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        mybuf sbuf("123");
        std::iostream stream(&sbuf);
        int n;
        stream >> n; /// calls sputc() four times
                     /// three calls returns the character '1' , '2' , '3'
                     /// the fourth call, gptr() == egptr() and underflow() is called
                     /// underflow returns EOF
        std::cout<<n<<std::endl;
        stream.clear(); /// clear the eof bit
        stream << "123456"; /// sputc() is called 6 time
                            /// first three calls store "123" in the existing buffer
                            /// fourth call finds that pptr() == epptr() and call overflow()
                            /// overflow() grows the buffer and sets egptr() to 4
                            /// fifth and sixth calls store '5' and '6', advancing pptr()
        stream >> n; /// calls sputc() 4 time
                     /// first call returns the '4' that was mode available by overflow()
                     /// on the second call, epgr() == egptr() and underflow() is called
                     /// underflow() advances egptr() to equal pptr() (which is 6)
                     /// third sputc() returns 6
                     /// fourth sputc() finds gptr() == egptr(), calls underflow()
                     /// underflow() returns EOF
        std::cout<<n<<std::endl;
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
