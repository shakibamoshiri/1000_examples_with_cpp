#include <iostream>
#include <string>
#include <cassert>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::reserve
/*
void reserve( size_type new_cap = 0 );

*/
/*

Return value
(none)

*/



int main() {
    { /// TEst void reserve ( size_type new_cap  = 0)
        std::string s("");
        cout<<s.capacity()<<endl;
        std::string::size_type st = 50;
        s.reserve(st);
        cout<<s.capacity()<<endl;

        /// throw exception length_error if new_cap is bigger than max_size()
        std::string::size_type st = 50000000000000000000;
        s.reserve(st);
        cout<<s.capacity()<<endl;
    }
}


















