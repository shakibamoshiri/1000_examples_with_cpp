    /*

A review of map library

*/
/// std::map:: relational operator ==, !=, <=, >=, <, >

#include <iostream>
#include <map>


int main( ){
    typedef std::map< const char*, unsigned > create_map;

    create_map map_1{
        { "one", 1 },
        { "two", 2 }
    };

    create_map map_2{
        { "one", 1 },
        { "two", 2 }
    };

    create_map map_3{
        { "apple", 1 },
        { "kiwi", 1 }
    };

    std::cout << ( map_1 == map_2 ? "Equal" : "Not equal" ) << '\n';
    std::cout << ( map_1 == map_3 ? "Equal" : "Not equal" ) << '\n';
    std::cout << ( map_2 == map_3 ? "Equal" : "Not equal" ) << '\n';






}
/* output

Equal
Not equal
Not equal

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.



*/
