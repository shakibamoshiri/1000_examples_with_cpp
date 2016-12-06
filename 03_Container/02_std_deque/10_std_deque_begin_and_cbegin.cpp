/// Sequence containers : deque
/// iterator

/// 10_std::deque::begin_and_cbegin
/// definition in header < deque >

/**
iterator begin();
const_iterator begin() const;
const_iterator cbegin() const;

Returns an iterator to the first element of the container.
It the container is empty, the returned iterator will be
equal to end().
**/

#include <iostream>
#include <string>
#include <deque>

//#include <unistd.h>

template<typename ALL_TYPE>
std::ostream& operator<<(std::ostream& out, std::deque<ALL_TYPE>& de){
    out.put('[');

    char ch = '\0';
    for ( const auto& t : de ){
        out<<ch<<t;
        ch = ',';
    }
    out.put(']');
    return out;
}
template<typename ALL_TYPE>
std::ostream& operator<<(std::ostream& out, const std::deque<ALL_TYPE>& de){
    out.put('[');

    char ch = '\0';
    for ( const auto& t : de ){
        out<<ch<<t;
        ch = ',';
    }
    out.put(']');
    return out;
}


template < typename D>
using ded = std::deque<D>;

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        ded<const char*> wup {"how","are","you","doing","today?"};
        const char* tmp_begin = wup.front(); /// for wup.begin() is wrong
        /// make a iterator
        ded<const char*>::iterator it = wup.begin();
        std::cout<<*it<<std::endl;
        *it = "HOW";
        std::cout<<*wup.begin()<<std::endl;
        std::cout<<**it<<std::endl;
///        **it = '+'; cannot because of read-only location
///        std::cout<<wup.begin()<<std::endl;

    }

}
