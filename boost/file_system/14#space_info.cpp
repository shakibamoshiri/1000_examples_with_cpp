
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>

namespace fs = boost::filesystem;


int main( ){

    fs::path user_path( "." );

    fs::space_info si = fs::space( user_path );
    /*
        // all values are byte counts
        boost::uintmax_t capacity;
        boost::uintmax_t free;      // <= capacity
        boost::uintmax_t available; // <= free
    */
    std::cout << "available: " << si.available << '\n'
              << "capacity: " << si.capacity << '\n'
              << "free: " << si.free << '\n';
}
/* the output:

available: 166393266176
capacity: 201451704320
free: 176650014720

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.

*/
