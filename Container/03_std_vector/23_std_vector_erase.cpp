/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Modifiers



/// 23_std::vector::erase
/// definition in header < vector >
/**
iterator erase ( iterator pos);
iterator erase ( const_iterator pos);
iterator erase ( iterator first, iterator last);
iterator erase ( const_iterator first , const_iterator last);

Removes specified element form the container.
1)  Removes the element at 'pos'
2)  Removes the element at the range [first,last)
Invalidates iterator and reference at or after the point of the erase,
including the end() iterator.
The iterator 'pos' must be valid and dereferencable. Thus the end()
iterator ( which is valid, but is not dereferencable ) cannot be
used as a value for 'pos'
The iterator 'first' does not need to dereferenceable if 'first'=='last'
erasing an empty range in a no-op.

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
        std::vector<int> i {3,4,5,6,7,8,9,10};

        std::cout<<i<<std::endl;

        i.erase(i.end()-1); /// remove 10
        std::cout<<i<<std::endl;

        i.erase(i.begin()+2,i.begin()+5); /// remove 5,6,7
        std::cout<<i<<std::endl;
    }

}
