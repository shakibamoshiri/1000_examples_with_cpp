#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::find_last_off
/*
string (1)	         size_type find_last_of (const basic_string& str, size_type pos = npos) const noexcept;
c-string (2)	     size_type find_last_of (const charT* s, size_type pos = npos) const;
buffer (3)	         size_type find_last_of (const charT* s, size_type pos, size_type n) const;
character (4)	     size_type find_last_of (charT c, size_type pos = npos) const noexcept;
*/

int main() {
    {
        /// size_type find_last_of (const basic_string& str, size_type pos = npos) const noexcept;
        std::string t ("a b d c e f a1 b1 c1 d1 e1");
        std::string::size_type st = t.find_last_of('a');
        cout<<t<<endl;
        cout<<t.substr(st);

        /// size_type find_last_of (const charT* s, size_type pos = npos) const;
        cout<<endl;
        st = t.find_last_of("d1",26,1);
        cout<<t.substr(st)<<endl;


        /// size_type find_last_of (const charT* s, size_type pos, size_type n) const;
        cout<<endl;
        st = t.find_last_of("a1",0);
        cout<<t.substr(st)<<endl;

        ///  size_type find_last_of (charT c, size_type pos = npos) const noexcept;
        cout<<endl;
        cout<<t<<endl;
        st = t.find_last_of('c');
        cout<<t.substr(st)<<endl;
    }
    {
    const std::string path="/root/config";
    auto const pos=path.find_last_of('/');
    const auto leaf=path.substr(pos+1);

    std::cout << leaf << '\n';
    }
}





















