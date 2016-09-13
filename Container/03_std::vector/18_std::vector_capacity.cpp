/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Capacity



/// 18_std::vector::capacity
/// definition in header < vector >
/**
size_type capacity() const;

Returns the number of elements that the container has currently allocated space for.

Return:

**/
#include <cstddef>
#include <new>
#include <iostream>
#include <string>
#include <vector>

//#include <unistd.h>
template<typename V>
std::ostream& operator<<(std::ostream& out,const std::vector<V>& v){
    out.put('(');
    char comma = '\0';
    for ( const auto& ve : v){
        out << comma << ve;
        comma = ',';
    }
    return out << ')';
}

template < typename V>
using vec = std::vector<V>;


int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::vector<const char*> you {"how","are","you","today?"};
        std::cout<<"Capacity of you: "<<you.capacity()<<std::endl;
    }

}
