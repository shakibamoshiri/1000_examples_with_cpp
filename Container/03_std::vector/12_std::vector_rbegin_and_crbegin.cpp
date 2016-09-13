/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Iterator



/// 12_std::vector::rbegin_and_crbegin
/// definition in header < vector >
/**
reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
const_reverse_iterator crbegin() const;

Returns a reverse iterator to the first element of the reversed container.
It corresponds to the last element of the non-reversed.


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

        std::cout<<*you.rbegin()<<std::endl; /// : today?

        auto rb = *you.rbegin();

        std::cout<<rb<<std::endl;
        rb++;                   /// skipping 't' and point to oday?

        std::cout<<rb<<std::endl; /// : oday?

        std::cout<<*++you.rbegin()<<std::endl; /// goes next element; meaning  : you
    }

}
