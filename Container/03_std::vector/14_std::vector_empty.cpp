/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Capacity



/// 14_std::vector::empty
/// definition in header < vector >
/**
reverse_iterator rend();
const_reverse_iterator crend() const;
const_reverse_iterator crend() const;

Returns a reverse iterator to the element following the last element
of the reversed container. It corresponds to the element preceding
the first element of the non-reversed container. This element acts
as a placeholder, attempting to access it results in undefined behavior.


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

        if( you.empty() )                                   /// empty returns : 0
            std::cout<<"this container is empty"<<std::endl;
        else                                                /// empty returns : 1
            std::cout<<"this container is not empty"<<std::endl;
    }

}
