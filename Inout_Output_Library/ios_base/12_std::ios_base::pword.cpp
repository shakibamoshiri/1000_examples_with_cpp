/// ios_base

#include <iostream>
#include <ctime>
#include <codecvt>
#include <iomanip>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::ios_base::xalloc
/*
static int xalloc ();

*/

/// the site cppreference
template< class charT, class traits = std::char_traits<charT>>
class mysteam : public std::basic_ostream<charT, traits>{
public:
    static const int xindex;
    mysteam(std::basic_ostream<charT,traits>& ostr)
        : std::basic_ostream<charT,traits>(ostr.rdbuf())
        {
            this->pword(xindex) = this;
        }
    void myfn (){
    *this << "[special handling for mystream]";
    }
};

template<class charT,class traits>
const int mysteam<charT, traits>::xindex = std::ios_base::xalloc();

template<class charT,class traits>
std::basic_ostream<charT, traits>& mymanip (std::basic_ostream<char, traits>& os)
{
    if (os.pword (mysteam<charT,traits>::xindex) = &os )
        static_cast<mysteam<charT, traits>&>(os).myfn();
    return os;
}


int main() {
    {
        /// mine : did not know
        std::wcout<<"";
    }
    {
        /// the site no sample : nope
        cout<<"cout, narrow-character test"<<mymanip <<endl;
        mysteam<char> myout(cout);
        myout<<"myout, narrow-character test "<<mymanip <<endl;

        std::wcout << "wcout, wide-character test " << mymanip <<endl;
        mysteam <wchar_t> mywout(std::wcout);
        mywout <<" mywcout, wide-character test " << mymanip << endl;
    }
}





















