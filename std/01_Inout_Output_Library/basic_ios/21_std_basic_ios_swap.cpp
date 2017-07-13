/**
std::basic_ios
**/

#include <iostream>
#include <sstream>
#include <locale>


/// std::basic_ios::swap
/**
protected:
void swap( basic_ios& other );
(since C++11)
    Exchanges the states of *this and other, except for the associated rdbuf objects.
rdbuf() and other.rdbuf() returns the same values as before the call.
    This swap function is protected: it is called by the swap member functions of
the derived stream classes such as std::basic_ofstream or std::basic_istringstream,
which know how to correctly swap the associated streambuffers.

Parameters
other	-	the basic_ios object to exchange the state with

Return value
(none)

**/

int main() {
    {
        /// mine
        std::istringstream in;
        in.str("in.str");

        std::ostringstream ot;
        ot.str("ot.str");

        std::cout<<in.str()<<' '<<ot.str()<<std::endl;
        ot.swap(in.str()); /// Wrong

        std::cout<<in.str()<<' '<<ot.str()<<std::endl;
    }
    {
        /// the site sample
        /// NO sample in either site

    }
    { /// msdn.microsoft.com
    }

}












