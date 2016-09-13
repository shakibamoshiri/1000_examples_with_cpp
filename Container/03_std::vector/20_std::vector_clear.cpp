/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Modifiers



/// 20_std::vector::clear
/// definition in header < vector >
/**

void clear();

Removes all elements form the container.
Invalidates any reference, pointer, or iterator referring to
contained element. May invalidate any past-the-end iterators.
Leaves the 'capacity()' of the vector unchanged.

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
