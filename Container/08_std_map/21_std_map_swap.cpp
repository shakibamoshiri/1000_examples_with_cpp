/// Sequence containers : set
/// std::map
///
/// Modifier.
/// 21_std::map::swap
/// definition in header < map >

/**
void swap( map& other );


Exchanges the contents of the container with those of other.
Does not invoke any move, copy, or swap operations on individual elements.

All iterators and references remain valid. The past-the-end iterator is invalidated.
The Pred objects must be Swappable, and they are exchanged using unqualified call to non-member swap.
If std::allocator_traits<allocator_type>::propagate_on_container_swap::value is true,
then the allocators are exchanged using an unqualified call to non-member swap. Otherwise,
they are not swapped (and if get_allocator() != other.get_allocator(), the behavior is undefined).

**/


//#include <unistd.h>
#include <iostream>
#include <string>
#include <map>

template<typename F,typename S>
std::ostream& operator<<(std::ostream& out,const std::map<F,S>& mp ){
    out.put('(').put(' ');
    for ( const std::pair<F,S> t : mp ) /// std::map<F,S> t is not true.
        out<<t.first<<':'<<t.second<<' ';
    return out.put(')');
}
void getStuff(){
    std::cout.put('\n');
}
template<typename F,typename... L>
void getStuff (F first, L... list){
    std::cout<<first.size()<<' ';
    getStuff(list...);
}
int main(){


    { /// my sample

    }
    { /// en.reference.com
        std::map<int,int> i2i;
        i2i.emplace(1,2);
        i2i.emplace(2,3);
        i2i.emplace(3,4);
        std::cout<<i2i<<std::endl;

        std::map<int,int> i2i2;

        /// swapping
        i2i2.swap(i2i);
        std::cout<<std::string(30,'.')<<std::endl;
        std::cout<<i2i2<<std::endl;
        std::cout<<i2i<<std::endl;
    }


}
