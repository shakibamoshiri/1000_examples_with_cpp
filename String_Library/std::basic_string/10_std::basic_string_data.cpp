#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::data
/*const CharT* data() const;  (1)
CharT* data();  (2)	(since C++17)

Return value

A pointer to the underlying character storage.

data()[i] == operator[](i) for every i in [0, size()).	(until C++11)
data() + i == &operator[](i) for every i in [0, size()].	(since C++11)

*/



int main (int ac,char **av, char **lvs) {
    { /// Test one
        std::string s("Test data function");
        const char* sp = s.data();
        cout<<sp<<endl;
    }
    { /// Test two
        std::basic_string<char> const s("Test data function");
        const char* sp = s.data();
        cout<<sp<<endl;
    }
    { /// Test three : using [] with data function
        std::string s ("Test data function with [] operator");
        cout<<s.data()<<endl;
        cout<<s.data()[0]<<endl;
        cout<<*s.data()<<endl;
        cout<<s.data()[s.size()-1]<<endl;
    }
}


















