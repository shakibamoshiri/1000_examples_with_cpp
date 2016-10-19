/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Element access



/// 09_std::vector::date
/// definition in header < vector >
/**
T* date();
const T* date() const;

Returns pointer to the underlying array serving as element storage.
The pointer is such that range [data(); data()+size()) is always a
valid range, even if the container is empty.

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
        std::cout<<*you.data()<<std::endl;

        /// date point to how
        const char** data = you.data();

        std::cout<<*data<<std::endl;

        data++; /// now point to are
        std::cout<<*data<<std::endl;

        data++; /// now point to you
        std::cout<<*data<<std::endl;

        /// now changing you to YOU
        *data = "YOU";

        /// now returning back data
        data-=2; /// point to how

        std::cout<<you<<std::endl;


    }

}
