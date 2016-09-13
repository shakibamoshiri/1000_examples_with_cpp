/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Iterator



/// 11_std::vector::end_and_cend
/// definition in header < vector >
/**
iterator end();
const_iterator end() const;
const_iterator cend() const;

Returns an iterator to the element following the last element of the container.
This element acts as a placeholder;attempting to access ti results in undefined behavior.


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

        /// dereference end iterator is wrong
        /// std::cout<<*you.end()<<std::endl;

        /// const char* end = *you.end() not correct
        /// because after this assignment --end no point to nowhere
        /// This is correct and work
        const char* end = *--you.end();

        std::cout<<*--you.end()<<std::endl;
        std::cout<<end<<std::endl;
    }

}
