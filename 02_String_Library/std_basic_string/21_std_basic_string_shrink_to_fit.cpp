#include <iostream>
#include <string>
#include <cassert>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::shrink_to_fit
/*


void shrink_to_fit(); n(since C++11)


Requests the removal of unused capacity.

It is a non-binding request to reduce capacity to size. It depends on the implementation if the request is fulfilled.
*/


int main() {
    {
        std::string s;
        cout<<"Default capacity s is : "<<s.capacity()<<endl;
        std::string::size_type sz = 23;
        s.reserve(sz);
        cout<<"Default capacity s is : "<<s.capacity()<<endl;
        s.resize(sz);
        cout<<"Default capacity s is : "<<s.capacity()<<endl;
        s.clear();
        cout<<"Default capacity s is : "<<s.capacity()<<endl;

        s.shrink_to_fit(); /// back to default size -> 15

        cout<<"Default capacity s is : "<<s.capacity()<<endl;

        s = "AAA";

        cout<<"Default capacity s is : "<<s.capacity()<<endl;

        s.shrink_to_fit();
        cout<<"Default capacity s is : "<<s.capacity()<<endl;
    }
}


















