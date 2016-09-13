#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::erase
/*
basic_string& erase( size_type index = 0, size_type count = npos );

iterator erase( iterator position ); (until C++11)

iterator erase( const_iterator position ); (since C++11)

iterator erase( iterator first, iterator last );

iterator erase( const_iterator first, const_iterator last );(since C++11)

Removes specified characters from the string.

1) Removes min(count, size() - index) characters starting at index.
2) Removes the character at position.
3) Removes the characters in the range [first, last).

Parameters
index 	        - 	first character to remove
count 	        -    number of characters to remove
position 	    - 	iterator to the character to remove
first, last 	- 	range of the characters to remove

Return value
1) *this
2) iterator pointing to the character immediately following the character erased, or end() if no such character exists
3) iterator pointing to the character last pointed to before the erase, or end() if no such character exists
Exceptions
1) std::out_of_range if index > size().
2-3) (none)

In any case, if an exception is thrown for any reason, this function has no effect (strong exception guarantee). (since C++11)
*/


int main() {
    { /// 1. basic_string& erase ( size_type index = 0, size_type count = npos )

        std::basic_string<char> s ("My name is Shakiba");
        s.erase();
        cout<<s<<endl;
        s = "My name is Shakiba";
        s.erase(s.find_first_of('S'));
        cout<<s<<endl;
        s.erase(s.find(' '));
        cout<<s<<endl;
        s = "My name is Shakiba";
        s.erase(0,1); /// remove 'M' form "My name is Shakiba"
        cout<<s<<endl;
    }
    {/// c plus plus reference
    std::string s = "This is an example";
    std::cout << s << '\n';

    s.erase(0, 5); // Erase "This "
    std::cout << s << '\n';

    std::find(s.begin(), s.end(), ' '); // Erase ' ' /// using #include <algorithm>
    std::cout << s << '\n';

    s.erase(s.find(' ')); // Trim from ' ' to the end of the string
    std::cout << s << '\n';


    }
}


















