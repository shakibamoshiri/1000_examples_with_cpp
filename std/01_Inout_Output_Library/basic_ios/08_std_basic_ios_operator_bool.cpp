/**
std::basic_ios
**/

#include <iostream>
#include <sstream>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_ios::operator!
/**
operator void* () const;
explicit operator bool() const; /// explicit and implicit

Explanation
1. Return a null pointer if fail() return true. otherwise returns a non-null pointer.
    This pointer is implicitly convertible to bool and may be used in boolean contexts.
2. Returns true if the stream has no error and is ready for I/O operation.
    Specifically, return !fail().

**/

int main() {
    {
        /// mine : did not know
    }
    {
        /// the site sample
        std::basic_istringstream<char> s ("1 2 3 error 4 5 6");
        int n;
        cout<<std::boolalpha <<"(bool)s is " << (bool)s<<endl;
        while ( s >> n ){
            cout<<n<<endl;
        }
        cout<<std::boolalpha <<"(bool)s is " <<(bool)s<<endl;
    }
}

















