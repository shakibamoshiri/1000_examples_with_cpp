===Example 2 ===
{{example
| code=
#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::push_back
/*

void push_back( CharT ch );
void pop_back(); (since C++11)

Appends the given character ch to the end of the string.

*/


int main() {
    { /// Test void push_back and pop_back
        std::string s ("Test push_back and pop_back function in c++11");
        cout<<s<<endl;

        s.pop_back();
        s.push_back('7');

        cout<<s<<endl;
    }
}
| output=
Test push_back and pop_back function in c++11
Test push_back and pop_back function in c++17

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.
}}
