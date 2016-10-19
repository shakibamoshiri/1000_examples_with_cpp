/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;



/// 02_std::vector::operator=
/// definition in header < vector >

/**
vector& operator=( const vector& other);
vector& operator=( vector&& other);
vector& operator=(std::initializer_list<T> ilist);

Replaces the contents of the container.

1)  Copy assignment operator, Replaces the contents with a copy of the
    contents of 'other' if std::allocator_traits<allocator_type>::
    propagate_on_container_copy_assignment() is true, the target
    allocator is replaced by a copy of the source allocator, If the
    target and the source allocator do not compare equal, the target
    (*this) allocator is used to deallocate the memory, then 'other's
    allocator is used to allocate it before copying the element ( since c++11).
2)  Move assignment operator. Replace the contents with those of 'other'
    using move semantics ( i.e. the data is 'other' is moved form 'other'
    into this container ) 'other' is in a valid but unspecified state afterwards.
    If std::allocator_traits<allocator_type>::propagate_on_container_move_assignment()
    is true, the target allocator is replaced by a copy of the source allocator.
    If it is false and the source ad the target allocators do not compares
    equal, the target cannot take ownership of the source memory and must
    move-assign each element individually, allocating additional memory
    using its own allocator as needed.
3)  Replaces the contents with those identified by initializer list 'ilist'

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
        typedef const char* cchs;
        std::vector<cchs> you {"How","are","you","today?"};

        std::cout<<you.size()<<std::endl; /// output: 4

        std::vector<cchs> she = you;

        std::cout<<she.size()<<std::endl; /// : 4

        std::vector<cchs> he;

        he = (std::move(you));

        std::cout<<you<<std::endl; /// you is empty
        std::cout<<he<<std::endl;  /// he takes the elements of you
    }

}
