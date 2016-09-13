/**
std::basic_ios
**/

#include <iostream>
#include <sstream>


/// std::basic_ios::setstate
/**

void setstate (iostate state);

Explanation:
Sets the steam error flags state in addition to currently set falgs.
Essentially calls clear ( rdstate() | state ). May throw an exception.

Parameter :
        goodbit     No error
        badbit      Irrecoverable stream error
        failbit     Input / output operation failed ( formation or extraction error )
        eofbit      Associated input sequence had reached end-of-file

**/

int main() {
    {
        /// mine : did not know

    }
    {
        /// the site sample
        std::basic_ostringstream<char> sm;

        if (!sm.fail())
            std::cout<<"Stream is not fail()\n";

        sm.setstate(std::ios_base::failbit);

        if (sm.fail())
            std::cout<<"Now stream is fail()\n";

        if(!sm.good())
            std::cout<<"And stream is not good()\n";
    }
}

















