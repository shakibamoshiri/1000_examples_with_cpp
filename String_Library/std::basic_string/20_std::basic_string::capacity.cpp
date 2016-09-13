#include <iostream>
#include <string>
#include <cassert>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::capacity
/*

size_type capacity() const;

*/
/*

Return value

Returns the number of characters that the string has currently allocated space for.

*/

void show_capacity(std::string const& t){
    cout<<"'"<<t<<"' has capacity "<<t.capacity()<<endl;
}

int main() {
    {
        std::string s ("Hello world!");
        cout<<"Capacity of s string is : "<<s.capacity()<<endl;
        s = "My name is Shakib and I live in Iran";
        cout<<"Capacity of s string is : "<<s.capacity()<<endl;
    }
    { /// c plus plsu reference
        std::string s ("Exemplary");
        show_capacity(s);
        s+=" is an example string";
        show_capacity(s);
    }

}


















