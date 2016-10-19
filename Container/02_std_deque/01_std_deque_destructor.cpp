/// Sequence containers : deque

/// 01_std::deque::~deque
/// definition in header < deque >

/**

Destructs the container. The destructors of the element are called and
the used storage is deallocated. Note, that if the elements are pointers
, the pointed-to objects are not destroyed.

**/

#include <iostream>
#include <string>
#include <deque>

//#include <unistd.h>

template<typename ALL_TYPE>
std::ostream& operator<<(std::ostream& out, std::deque<ALL_TYPE>& de){
    out.put('[');

    char ch = '\0';
    for ( const auto& t : de ){
        out<<ch<<t;
        ch = ',';
    }
    out.put(']');
    return out;
}


int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        // no samplef
    }

}
