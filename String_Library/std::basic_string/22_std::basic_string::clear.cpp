#include <iostream>
#include <string>
#include <cassert>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::clear
/*

void clear();

Removes all characters from the string as if by executing erase(begin(), end()).
The allocated memory will not be released, effectively leaving the capacity of the string unchanged.
All pointers, references, and iterators are invalidated.
*/


int main() {
    { /// void clear()
        std::string s ("Hello and welcome into the lesson");
        cout<<"s before clear() and capacity() "<<s<<' '<<s.capacity()<<endl;

        s.clear(); /// clear data form s string

        cout<<"s after clear() and capacity() "<<s<<' '<<s.capacity()<<endl;
    }
    { /// Sample of c plus plus reference
        std::basic_string<char> s ("Exemplary");
        std::basic_string<char>::size_type const capacity = s.capacity();

        s.clear();

        assert(capacity == s.capacity()); /// Okay

        assert(s.empty()); /// Okay

        assert(0 == s.size()); /// okay
    }
}


















