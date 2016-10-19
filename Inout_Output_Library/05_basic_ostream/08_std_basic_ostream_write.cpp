/**
std::basic_ostrream
**/


/// 08_std::basic_ostream::write
/**

basic_ostream& write ( const char_type* s, std::streamsize count );



Behave as an UnformattedOutputFunction. After construction and checking
    and the sentry object, outputs the characters from successive location
    in the character array whose first element is pointed to bys. Characters
    are inserted into the output sequence until one of the following occurs :
    - exactly count characters are inserted
    - inserting into the output sequence fails ( in which case setstate (badbit)
                                                is called )

**/


#include <iostream>
#include <sstream>
#include <fstream>

int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        int n(0x41424344);
        std::cout.write(reinterpret_cast<char*> (&n), sizeof n)<< std::endl;
        n = 0x44434241;
        std::cout.write(reinterpret_cast<char*> (&n), sizeof n)<< std::endl;
        n = 0x63;
        std::cout.write(reinterpret_cast<char*> (&n), sizeof n)<< std::endl;

        char c[]="This is sample text.";
        std::cout.write(c,4)<<std::endl;
        std::cout.write(c,8)<<std::endl;



    }

    {
        /// msdn.microsoft.com
    }

}













