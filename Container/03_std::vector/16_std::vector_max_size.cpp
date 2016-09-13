/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Capacity



/// 16_std::vector::size_max
/// definition in header < vector >
/**
size_type size_max() const;

Returns the maximum of elements the container is able to hold due to
system or library implementation limitations, i.e std::distance(begin(),
end()) for the largest container.


Note : This value is typically equal to std::numeric_limits<size_type>::max()
       , and reflects the theoretical limit on the size of the container. At
       runtime, the size or the container may be limited to a value smaller
       then max_size() by the amount of RAM available.
Return:

**/

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
        std::vector<const char*> you {"How","are","you","today?"};
        std::cout<<"Maximum size of a  'vector' is: "<<you.max_size()<<std::endl;
    }

}
