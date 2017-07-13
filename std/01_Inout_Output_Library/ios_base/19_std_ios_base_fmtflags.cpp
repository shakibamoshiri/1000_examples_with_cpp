/// ios_base

#include <iostream>
#include <fstream>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::ios_base::fmtflags
/*
01    static constexpr fmtflags dec
02    static constexpr fmtflags oct
03    static constexpr fmtflags hex
04    static constexpr fmtflags basefield
05    static constexpr fmtflags left
06    static constexpr fmtflags right
07    static constexpr fmtflags internal
08    static constexpr fmtflags adjustfield
09    static constexpr fmtflags scientific
10    static constexpr fmtflags bollalpha
11    static constexpr fmtflags showbase
12    static constexpr fmtflags showpoint
13    static constexpr fmtflags showpos
14    static constexpr fmtflags skiwpos white position
15    static constexpr fmtflags unitbuf
16    static constexpr fmtflags uppercase

*/

int main() {
    {
        /// mine : did not know
        std::ios_base::fmtflags f;
        std::ios_base::fmtflags::_S_adjustfield;
        cout<<std::ios_base::fmtflags::_S_ios_fmtflags_max<<endl;;
        cout.setf(std::ios_base::fmtflags::_S_boolalpha);
        bool t = false;
        cout<<t<<endl;
        cout.unsetf(std::ios_base::fmtflags::_S_boolalpha);
        int i = 46;
        cout.setf(std::ios_base::fmtflags::_S_hex);
        cout<<i<<endl;


    }
    {
        /// the site no sample
        /// no sample
        /// this section in incomplete
        /// Reason : no example
    }
}





















