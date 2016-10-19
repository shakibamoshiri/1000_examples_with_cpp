/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Modifiers



/// 22_std::vector::emplace
/// definition in header < vector >
/**
template<class... Args>/// parameter packing
    iterator emplace ( const_iterator pos,Args&&... args);

Insert a new element into the container directly before 'pos'.
The element is constructed thought std::allocator_traits::construct
which typically uses placement-new to construct the element in-place
at a location provided by the container. The arguments 'args...' are
forwarded to the constructor as std::forward<Args>(args)...
If the new size() is greater then capacity(), all iterator and
reference are invalidated. Otherwise, only the iterators and
references before the insertion point remain valid. The past-the-end
iterator is also invalidated.

Note : The specialization std::vector<bool> did not have 'emplace()' member until c++14

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
        std::vector<int> i {3,4,5,6,7};
        i.emplace(i.begin(),2);
        std::cout<<i<<std::endl;
        i.emplace(i.end(),8); /// put after last element.
        std::cout<<i<<std::endl;
    }

}
