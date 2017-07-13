/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Capacity



/// 19_std::vector::shrink_to_fit
/// definition in header < vector >
/**
void shrink_to_fit()

Requests the removal of unused capacity.
It is a non-binding request to reduce capacity() to size().
It depends on the implementation if the request is fulfilled.
All iterator, including the past the end iterator, are potentially
invalidated.

Return:

**/


#include <iostream>
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
        std::vector<const char*> you;

        std::cout<<"Default-Constructed capacity is "<<you.capacity()<<std::endl;
        you.reserve(100);
        std::cout<<"Capacity of a 100-element vector is "<<you.capacity()<<std::endl;
        you.clear();
        std::cout<<"Capacity after clear() is "<<you.capacity()<<std::endl;
        you.shrink_to_fit();
        std::cout<<"Capacity after shrink_to_fit() is "<<you.capacity()<<std::endl;
    }

}
