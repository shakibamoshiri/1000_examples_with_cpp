/**
std::basic_ios
**/

#include <iostream>
#include <sstream>
#include <locale>


/// std::basic_ios::init
/**
protected:
void init( std::basic_streambuf<CharT,Traits>* sb );

Sets the associated stream buffer to sb and initializes the internal state.

The postconditions are as follows:
Element	Value
    rdbuf()	sb
    tie()	NULL
    rdstate()	goodbit if sb is not NULL, otherwise badbit
    exceptions()	goodbit
    flags()	skipws | dec
    width()	​0​
precision()	6
    fill()	widen(' ')
    getloc()	a copy of the value returned by std::locale()
    This member function is protected: it is called by the constructors of the derived stream classes
std::basic_istream and std::basic_ostream once the associated stream buffer is known.
Until this function is called, every member function (other than the destructor) of the default-constructed
std::basic_ios invokes undefined behavior. Note that basic_ios is a virtual base class,
and therefore its constructor is not called by the constructors of those directly derived classes, which is why two-stage initialization is necessary.
Parameters
sb	-	stream buffer to associate to
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
        const char* s ("hello");
        std::cout<<s[0]<<std::endl;

        char w;
        w = std::cout.widen(s[0]);
        std::cout<<w<<std::endl;
    }

}












