/// ios_base

#include <iostream>
#include <ctime>
#include <codecvt>
#include <iomanip>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::ios_base::getloc
/*

std::locale getloc () const ;

Return the current locale associated with the stream.

*/

int main() {
    {
        /// mine : did not know

    }
    {
        /// the site no sample : nope
        std::wbuffer_convert<std::codecvt_utf8 <wchar_t> > conv (cout.rdbuf());
        std::wostream out(&conv);
        out.imbue(std::locale(out.getloc(),new std::time_put_byname<wchar_t>("ja_JP")));

        std::time_t t = std::time(NULL);
        out << std::put_time(std::localtime(&t), L"%A %C")<<endl;
    }
}





















