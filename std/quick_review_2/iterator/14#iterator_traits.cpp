/*

A review of iterator library


*/

/// iterator traits
//  Iterator traits


#include <iostream>
#include <iterator>
#include <typeinfo>



int main(){

    typedef std::iterator_traits< int * > int_star_tag;
    std::cout << ( typeid( int_star_tag::iterator_category ) == typeid( std::random_access_iterator_tag ) ? "yes equal" : "not equal" ) << '\n';

}
/* output

yes equal

Process returned 0 (0x0)   execution time : 0.012 s
Press ENTER to continue.



*/
