/**
std::basic_streambuf
**/


/// 33_std::basic_streambuf::pbump
/**
void pbump ( int count );

Reposition the put pointer ( pptr() ) by count character, where count may be
positive or negative. No checks are done for moving the pointer outside the put
area [ pbsae() , epptr() ].
If the pointer is advanced and then overflow() is called to flush to put area
to the associated character sequence, the effect is that extra count characters
with underfiend value are output.

**/
#include <iostream>
#include <sstream>
#include <fstream>
struct showput_streambuf : std::filebuf {
    using std::filebuf::pbump; /// expose protected
    std::string showput() const{
        return std::string ( pbase(), pptr());
    }
};
int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        showput_streambuf mybuf;
        mybuf.open("test_pbump.txt",std::ios_base::out);
        std::ostream str(&mybuf);
        str<< "this is a test of pbump " << std::flush << "1234";
        std::cout<<"The put area contains : "<<mybuf.showput()<<std::endl;
        mybuf.pbump(10);
        std::cout<<"After pbump(10), it contains : "<<mybuf.showput()<<std::endl;
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













