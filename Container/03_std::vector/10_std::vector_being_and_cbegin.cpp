/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Iterator



/// 10_std::vector::being_and_cbeing
/// definition in header < vector >
/**
iterator being();
const_iterator being() const;
const_iterator cbeing() const;

Returns an iterator to the first element of the container.
If the container is empty, the returned iterator will be equal to end().

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
        const char* it = *you.begin();

        std::cout<<"const char* &it: "<<it<<std::endl;
        std::cout<<"*you.being(): "<<*you.begin()<<std::endl;

        it++; /// okay form pointing to 'H' now points to "ow"
        /// *you.begin()++; /// wrong needing to overload ++ for it
        std::cout<<it<<std::endl;               ///output: ow

        /// instead you can use + number
        std::cout<<(*you.begin())+1<<std::endl; /// output: ow
        std::cout<<*(you.begin()+1)<<std::endl; /// output: are
    }

}
