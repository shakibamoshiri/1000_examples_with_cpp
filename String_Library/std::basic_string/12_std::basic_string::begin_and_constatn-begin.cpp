#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::begin and constant-begin
/*

iterator begin();

const_iterator begin() const;

const_iterator cbegin() const;  (since C++11


Return value
iterator to the first character


*/



int main (int ac,char **av, char **lvs) {
    { /// Test begin
        std::string s ("Test begin function");
        *s.begin() = 't';
        cout<<s<<endl; /// Output -> test begin function | changing 'T' to 't'

        std::basic_string<char>::iterator sp = s.begin();

        while(*sp) {
            *sp-=32; /// Okay because changeable
            cout<<*sp;
            cout<<' ';
            ++sp;
        }
    }
    cout<<endl;
    { /// Test constant-begin
        std::basic_string<char> s ("Test constant-begin function");
        //*s.cbegin() = 't'; /// Error : assignment of read-only location s.cbegin()
        cout<<s<<endl;

    }
    { /// Test three
        std::string s ("Test cbegin function");
        auto sp = s.cbegin();
        for ( ; *sp!=NULL;++sp)
            cout<<*sp<<endl;

        std::string::const_iterator sp2 = s.cbegin();
        cout<<*sp2<<endl;
    }
}


















