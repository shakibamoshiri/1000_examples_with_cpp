/**
std::basic_stringbuf
**/
/// protected member
/// 07_std::basic_stringbuf::overflow()
/**
protected:
virtual int_type overflow(int_type c = Traits::eof());
Appends the character c to the output character sequence.
if c is the end_of_file indicator traits::eq_int_type ( c, traits::oef()) == true
    then there is not character to  append. The function does nothing and returns
    an unspecified value other than traits::oef().
Otherwise,if the output sequence has a write position available if the stringbuf
is open for output ( mode & ios_base::out != 0): in this case, it real locates ( or
initially allocates )the buffer big enough to hold  the entire current buffer plus
at least one more character, if the stringbuf is also open for input( (mode & ios_base::in)
!= 0, then overflow also increases the size of the get area by moving egptr() to
point just past the new write position.ĵs

**/
#include <iostream>
#include <sstream>
#include <fstream>
struct mybuf: std::stringbuf{
    mybuf(const std::string& new_str,std::ios_base::openmode w = std::ios_base::in|std::ios_base::out)
            : std::stringbuf( new_str, w)
            {}
    int_type overflow(int_type c = EOF ) override {
        std::cout<<"Stringbuf::overflow("<<char(c)<<") called \n"
                 <<"Before: size of get area: "<<egptr()-eback()<<std::endl
                 <<"        size of get area: "<<egptr()-pbase()<<std::endl;
        int_type ret  = std::stringbuf::overflow(c);
        std::cout<<"After : size of get area: "<<egptr()-eback()<<std::endl
                 <<"      : size of get area: "<<egptr()-pbase()<<std::endl;
        return ret;
    }
};
int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        std::cout<<"read-write stream:\n";
        mybuf sbuf("    "); /// read-write stream
        std::iostream stream(&sbuf);
        stream << 1234;
        std::cout<<sbuf.str()<<std::endl;

        std::cout<<"\nread-only stream:\n";
        mybuf ro_buf("    ",std::ios_base::in); /// read-only stream
        std::iostream ro_stream(&ro_buf);
        ro_stream<<1234;
        std::cout<<std::endl;
        std::cout<<ro_buf.str()<<std::endl;

        std::cout<<"\nwrite-only stream:\n";
        mybuf wo_buf("    ",std::ios_base::out); /// write-only stream
        std::iostream wo_stream(&wo_buf);
        wo_stream << 1234;
        std::cout<<wo_buf.str()<<std::endl;


    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
