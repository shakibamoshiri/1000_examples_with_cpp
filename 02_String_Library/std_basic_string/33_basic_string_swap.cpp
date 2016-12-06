#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::swap
/*

void swap( basic_string& other );

Exchanges the contents of the string with those of other. All iterators and references may be invalidated.

Parameters
other	-	string to exchange the contents with


Return value
(none)


Exceptions
noexcept specification:
noexcept(std::allocator_traits<Allocator>::propagate_on_container_swap::value
|| std::allocator_traits<Allocator>::is_always_equal::value)


*/


int main() {
    std::basic_string<char> s ("shabiba");
    std::basic_string<char> f ("farsjod");
    cout<<s<<endl;
    cout<<f<<endl;
    s.swap(f);
    cout<<s<<endl;
    cout<<f<<endl;
    {
    /// c plus plus reference
    std::string a = "AAA";
    std::string b = "BBB";

    std::cout << "before swap" << '\n';
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';

    a.swap(b);

    std::cout << "after swap" << '\n';
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    }

}




















