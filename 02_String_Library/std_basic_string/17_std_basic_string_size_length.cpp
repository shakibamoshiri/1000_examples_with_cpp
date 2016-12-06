#include <iostream>
#include <string>
#include <cassert>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::size, std::basic_string::length
/*
size_type size() const;

size_type length() const;


*/
 /// Returns the number of CharT elements in the string, i.e. std::distance(begin(), end()).



int main() {
    { /// Test size_type size() const;
        std::string s;
        cout<<s.size()<<endl;
        s = "A";
        cout<<s.size()<<endl;
    }
    {/// Test size_type length() const;
        std::basic_string<char> s;
        cout<<s.length()<<endl; /// 0
        s = "ABC";
        cout<<s.length()<<endl; /// 3
    }
    { ///Test std::distance();
        std::string s;
        cout<<std::distance(std::begin(s),std::end(s))<<endl;;
        s = "shakiba";
        cout<<std::distance(std::begin(s),std::end(s))<<endl;
    }
    {
        int size_type = 5;
        cout<<size_type; /// Okay -> 5
    }
    { /// Sample of en c plus plus reference
        std::string s ("Exemplary");
        assert(9 == s.size());
        assert(s.size() == s.length());
        assert(s.size() == static_cast<std::string::size_type>(std::distance(s.begin(),s.end())));
    }
}


















