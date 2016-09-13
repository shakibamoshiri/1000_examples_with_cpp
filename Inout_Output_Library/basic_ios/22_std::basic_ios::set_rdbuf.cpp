/**
std::basic_ios
**/

#include <iostream>
#include <sstream>
#include <locale>


/// std::basic_ios::set_rdbuf
/**
protected: void set_rdbuf( std::basic_streambuf<CharT,Traits>* sb );

    Sets the associated stream buffer to sb without clearing the error state.
This member function is protected: it is called by the move constructors of the derived
streams such as std::basic_ofstream or std::basic_istringstream, as the final step after
constructing the base class and after moving the stream buffer: only the most derived
stream class knows how to correctly move the stream buffer, but std::basic_ios needs
to be made aware of the stream's new location so that its public member functions can access it.

Parameters
sb	-	stream buffer to associate to

Return value
(none)
**/

int main() {
    {
        /// mine : did not know


    }
    {
        /// the site sample
        /// NO sample in either site

    }
    { /// msdn.microsoft.com
    }

}












