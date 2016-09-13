/**
std::basic_filebuf
**/

/// protected  member :
/// 15_std::basic_filebuf::imbue
/**

protected:
virtual  void imbue ( const std::locale& loc);
Changes the associated locale so that all characters inserted or
extracted after this call ( and until another call to imbue() )
are converted using the std::codecvt facet of loc.
If the old locale's encoding is state-dependent and file is not
positioned at the beginning , then the new locale must have the
same std::codecvt facet as the one previously imbued.


**/
#include <iostream>
#include <locale>
#include <fstream>

int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        /// no sample
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

