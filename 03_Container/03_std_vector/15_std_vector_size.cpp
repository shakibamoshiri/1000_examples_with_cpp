/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Capacity



/// 15_std::vector::size
/// definition in header < vector >
/**
size_type size() const;

Returns the number of elements in the container, i.e. std::distance(being(),end());

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
        const int len = std::distance(you.begin(),you.end());

        std::cout<<len<<std::endl; /// 4
        /// or
        std::cout<<you.size()<<std::endl; ///  4
    }

}
