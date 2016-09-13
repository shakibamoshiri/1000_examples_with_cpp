#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::end and constant-end
/*
iterator end();

const_iterator end() const;

const_iterator cend() const; (since C++11)


Return value
iterator to the character following the last character

*/



int main (int ac,char **av, char **lvs) {
    { /// Test end
        std::basic_string<char> s ("Test end function");

        cout<<s.end()[-1]<<endl; /// Output -> n

        cout<<s.end()[-s.size()]<<endl; /// Output -> T | -s.size() equivalent to beginning address

        cout<<std::end(s)[-17]<<endl;; /// Output -> T
    }
    {/// Test iterator end()
        std::basic_string<char> s ("Test iterator end()");
        std::basic_string<char>::iterator ip = s.end();

        while(*ip != 'T'){
            *ip-=32; /// Changeable because not constant
            cout<<*ip<<' ';
            --ip;
        }
    }
}


















