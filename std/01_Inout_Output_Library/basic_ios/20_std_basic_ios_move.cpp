/**
std::basic_ios
**/

#include <iostream>
#include <sstream>
#include <locale>


/// std::basic_ios::move
/**
protected: void move( basic_ios& other ); (since C++11)
protected: void move( basic_ios&& other ); (since C++11)
Replaces the current state with that of other, except for the associated rdbuf.
other is in valid, but unspecified state after the call. After the call to this function,
rdbuf() returns NULL, and other.rdbuf() returns the same value as before the call.
This member function is protected: it is called by the protected move constructors of
the derived stream classes std::basic_ostream and std::basic_istream, which, in turn,
are called by the public move constructors of the further derived stream classes
such as std::basic_ofstream, which know how to correctly move the associated streambuffer.

Parameters
other	-	the basic_ios object to transfer the state from

Return value
(none)

**/

int main() {
    {
        /// mine
    }
    {
        /// the site sample
        /// NO sample in either site

    }
    { /// msdn.microsoft.com
    }

}












