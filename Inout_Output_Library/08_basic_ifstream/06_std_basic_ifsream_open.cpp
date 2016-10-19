/**
std::basic_ifstream
**/

/// 06_std::basic_ifstream::open
/**

void open(const char* filename, ios_base::openmode mode = ios_base::in );
void open(const string& filename, ios_base::openmode mode = ios_base::in );

Opens and associated the file with name filename with the file stream.
Calls setstate(failbit) on failure.
1)  Effectively calls rdbuf()->open(filename, mode | ios_base::in).
2)  Effectively call (1) as if by open(filename.c_str(), mode).

**/
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

