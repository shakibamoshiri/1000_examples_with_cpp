/// ios_base

#include <iostream>
#include <fstream>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::ios_base::event
/*
enum event;

Constant        Explanation
erase_event     issued on ~ios_base() or basic_ios::copyfmt() ( before the copy of
                member takes place )
imbue_event     issued on imbue()
copyfmt_event   issued on basic_ios::copyfmt() (after the copy of members takes place
                , but before the exception setting are copied )
*/

int main() {
    {
        /// mine : did not know
        std::ios_base::beg;
        std::ios_base::end;
        std::ios_base::cur;
    }
    {
        /// the site no sample
        /// no sample
        /// this section in incomplete
        /// Reason : no example
    }
}





















