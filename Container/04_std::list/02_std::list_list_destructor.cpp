/// Sequence containers : list
/// std::list
///
/// Member function:
/// 01_std::list::~list or destructor
/// definition in header < list >

/**
~list()

Destructs the container.  The destructors of the element are called and the used
storage is deallocated. Note, that if the elements are pointers the pointed-to
are not destroyed.

**/


#include <iostream>
#include <list>
#include <string>
#include <iomanip>
//#include <unistd.h>
template < typename L>
std::ostream& operator<<(std::ostream& out, const std::list<L>& listTemp){
    out.put('{');
    char camma = '\0';
    for ( const L l : listTemp ){
        out<< camma << l;
        camma=',';
    }
    out.put('}');

    return out;
}



int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com


    }

}
/* out put */
/*

*/
