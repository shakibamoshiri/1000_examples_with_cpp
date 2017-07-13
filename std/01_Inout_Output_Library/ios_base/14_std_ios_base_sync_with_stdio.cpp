/// ios_base

#include <iostream>
#include <cstdio>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::ios_base::sync_with_stdio
/*

static bool sync_with_stdio ( bool sync = true );

*/

int main() {
    {
        /// mine : did not know
    }
    {
        /// the site no sample
        cout.sync_with_stdio(false);
        cout<<"a\n";
        std::printf("b\n");
        cout<<"c\n";
    }
}





















