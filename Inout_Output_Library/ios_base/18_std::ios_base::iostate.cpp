/// ios_base

#include <iostream>
#include <fstream>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::ios_base::iostate
/*

static constexpr iostate goodbit = 0;
static constexpr iostate badbit
static constexpr iostate failbit
static constexpr iostate eofbit

goodbit : no error
badbit  : irrecoverable stream error
failbit : input / output operation failed ( formation or extraction error )
eofbit  : associate input sequence bas reached end-of-file


*/

int main() {
    {
        /// mine : did not know
        std::ios_base::goodbit;
        std::ios_base::failbit;
        std::ios_base::badbit;
        std::ios_base::eofbit;

    }
    {
        /// the site no sample
        /// no sample
    }
}





















