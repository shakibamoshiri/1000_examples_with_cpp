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
Equivalent to erase(size()-1, 1), except the behavior is undefined if the string is empty.

*/


int main() {
    { /// Test void push_back and pop_back
        std::string s ("Test push_back and pop_back function in c++11");
        cout<<s<<endl;

        s.pop_back();
        s.push_back('7');

        cout<<s<<endl;

        s.erase(s.size()-1,1);
        cout<<s<<endl;

        s.push_back('1');
        cout<<s<<endl;
    }
}


















