/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Capacity



/// 18_std::vector::capacity
/// definition in header < vector >
/**

void reserve ( size_type new_cap);

Increase the capacity of the container to a value that is greater
or equal to new_cap. If new_cap is greater then the current capacity().
'new' storage is allocated, otherwise the method does nothing. If 'new_cap'
is greater then capacity(), all iterator and reference, including the
past-the-end iterator, are invalidated. Otherwise, no iterators or reference
are invalidated.

Note: reserve() cannot be used to reduce the capacity of the container,
      to that end shrink_to_fit() is provided.

Return:

**/
#include <cstddef>
#include <new>
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


/// minimal c++11 allocator with debug output
template < class Tp>
struct NAlloc {
    typedef Tp value_type;
    NAlloc() = default;
    template<class T> NAlloc ( const NAlloc<T>&) {}
    Tp* allocate(std::size_t n){
        n *= sizeof(Tp);
        std::cout<<"allocator "<<n<<" bytes\n";
        return static_cast<Tp*>(::operator new(n));
    }
    void deallocate(Tp* p,std::size_t n){
        std::cout<<"deallocate "<<n*sizeof*p<<" bytes\n";
        ::operator delete(p);
    }
};

template<class T, class U>
bool operator==(const NAlloc<T>&, const NAlloc<U>&){return true;}
template<class T, class U>
bool operator!=(const NAlloc<T>&, const NAlloc<U>&){return false;}

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        int sz = 100;
        std::cout<<"Using reserve: \n";
        {
            std::vector<int,NAlloc<int>> v1;
            v1.reserve(sz);
            for (int n =0;n<sz;++n)
                v1.push_back(n);
        }
        std::cout<<"\n.....................\n"
                 <<"not using reserve: \n";
        {
            std::vector<int, NAlloc<int>> v1;
            for (int n=0; n<sz; ++n)
                v1.push_back(n);
        }
    }

}
