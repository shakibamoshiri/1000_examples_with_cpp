/**
std::basic_streambuf
**/


/// 34_std::basic_streambuf::setp
/**
void setp( char_type* pbeg, char_type* pend);

Sets the values of the pointers defining the put area. Specially, after
the call pbase() == pbeg(), pptr() == pbeg(), epptr() == pend.
**/
#include <iostream>
#include <sstream>
#include <array>
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
        stream<<',';

        streambuf.print_buffer();
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













