/// Sequence containers : deque

/// 07_std::deque::operator[] bracket
/// definition in header < deque >

/**

reference operator[] ( size_type pos);
const_reference operator[] ( size_type pos);

Returns a reference to the element at specified location pos.
No bounds checking is performed.

NOTe : Unlike std::map::operator[], this operator never insert
       a new element into the container.

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
        ded<const char*> i {"test","at","in","std::deque"};
        std::cout<<i<<std::endl;
        std::cout<<"get value with [] bracket member inside deque: "<<i[2]<<std::endl;
        i[2]= "IN";
        std::cout<<i<<std::endl;

    }

}
