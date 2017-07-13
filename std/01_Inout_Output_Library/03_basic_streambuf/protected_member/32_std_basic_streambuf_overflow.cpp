/**
std::basic_streambuf
**/


/// 32_std::basic_streambuf::overflow
/**
virtual int_type overflow(int_type ch = traits::eof() );

Ensures that there si space at the put area for at least one character
by saving some initial subsequence of characters strings at pbase() to
the output sequence and updating the pointers to the put area(if needed),
if ch is not Traits::eof() (i.e Traits::eq_int_type(ch, Traits::eof)) !=
    true) it is either put to the area or directly saved to the output
    sequence.
The function may update pptr, epptr and pbase pointers to define the location
to write more date. On failure, the function ensures that either pptr() == nullptr
or pptr() == epptr.
The base class version of the function does nothing. The derived classes may
override this function to allow updates to put the area in the case exhaustion.
**/
#include <iostream>
#include <sstream>
#include <array>
/// buffer for std::ostream implemented by std::array
template<std::size_t SIZE, class charT  = char>
class ArrayedStreamBuffer : public std::basic_streambuf<char> {
private:
    std::array<char_type, SIZE> buffer_;
protected:
public:
    using Base = std::basic_streambuf<char>;
    using char_type = typename Base::char_type;
    using int_type = typename Base::int_type;
    ArrayedStreamBuffer() : buffer_{} /// value-initialize buffer_ to all zeros
    {
        Base::setp(buffer_.begin(), buffer_.end()); /// set std::basic_streambuf
        /// put area pointers to work with 'buffer_'
    }
    int_type overflow(int_type ch){
        std::cout<<"overflow\n";
        return Base::overflow(ch);
    }
    void print_buffer(){
        for (const auto& i : buffer_){
            if (i == 0){
                std::cout<<"NULL";
            }else{
                std::cout<<i;
            }
            std::cout<<' ';
        }
        std::cout<<std::endl;
    }
};
int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        ArrayedStreamBuffer<10> streambuf;
        std::ostream stream(&streambuf);
        stream<<"hello";
        streambuf.print_buffer();
        if(stream.good())
            std::cout<<"stream is good\n\n\n";
        stream<<"world";
        streambuf.print_buffer();
        if (stream.good())
            std::cout<<"stream is good\n\n\n";

        stream << '!';
        streambuf.print_buffer();
        if(!stream.good())
            std::cout<<"stream is not good\n";
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













