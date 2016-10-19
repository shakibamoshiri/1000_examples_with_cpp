#include <iostream>
#include <string>
#include <cassert>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::max_size
/*
size_type max_size() const
*/
 /// Returns the maximum number of elements the string is able to hold due to system or library
 /// implementation limitations, i.e. ​std::distance(begin(), end())​ for the largest string.



int main() {
    {
        std::string s;
        cout<<s.max_size()<<endl;
        s = "shakiba";
        cout<<s.max_size()<<endl;
    }
}


















