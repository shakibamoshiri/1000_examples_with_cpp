/// Sequence containers : deque

/// 06_std::deque::at
/// definition in header < deque >

/**
reference at ( size_type pos );
const_reference at( size_type pos) const;

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
        std::cout<<"get value with at member inside deque: "<<i.at(2);
        i.at(2) = "IN";
        std::cout<<i<<std::endl;

    }

}
