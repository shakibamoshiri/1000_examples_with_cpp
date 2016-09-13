/**
std::basic_stringbuf
**/
/// protected member
/// 09_std::basic_stringbuf::seekoff
/**
protected:
virtual pos_type( off_type off, ios_base::seekdir dir, ios_base::openmode which = ios_base::in|ios_base::out);
Reposition std::basic_streambuf::gptr() and / or std::basic_streambuf::pptr(),
if possible, to the position that corresponds to exactly off character form
beginning, end, or current position of the get and / or out area of the buffer.


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
        std::stringstream ss("123"); /// in/out
        std::cout<< "put pos: "<<ss.tellp()
                 <<" get pos: "<<ss.tellg()<<std::endl;
        /// absolute positioning both pointer
        ss.rdbuf()->pubseekoff(1,std::ios_base::beg); /// move both 1 forward
        std::cout<<"put pos: "<<ss.tellp()
                 <<" get pos: "<<ss.tellg()<<std::endl;

        /// try to move both  pointer 1 forward from current position
        if(-1 == ss.rdbuf()->pubseekoff(1,std::ios_base::cur))
            std::cout<<"Moving both pointers from current position failed\n";
        std::cout<<"Put pos: "<<ss.tellp()
                 <<" Get pos: "<<ss.tellg()<<std::endl;

        /// move the write pointer 1 forward but not the read pointer
        /// can also be called as ss.seekp()(1, std::ios_base::cur);
        ss.rdbuf()->pubseekoff(1,std::ios_base::cur, std::ios_base::out);
        std::cout<<"Put pos: "<<ss.tellp()
                 <<" Get pos: "<<ss.tellg()<<std::endl;

        ss << 'a'; /// write at put position
        std::cout<<"Wrote 'a' at t put position, the buffer is now: "<<ss.rdbuf()->str()<<std::endl;

        char ch;
        ss >> ch;
        std::cout<<"Reading at get position gives: "<<ch<<std::endl;

        ss.rdbuf()->pubseekoff(0,std::ios_base::beg);
        ss >> ch;
        std::cout<<"Reading at get position gives: "<<ch<<std::endl;


    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
