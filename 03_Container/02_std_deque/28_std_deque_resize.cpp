/// Sequence containers : deque
/// capacity

/// 28_std::deque::resize
/// definition in header < deque >

/**
void resize ( size_type count, T value = T() );
void resize ( size_type count );
void resize ( size_type count, const value_type& value);

REsize the container to contain 'count' element.
If the current size is greater than 'count' the container is
reduced to its first 'count' element.
If the current size is greater than 'count', additional elements
are initialized with copies of 'value'.
If the current size is less then 'count'

1)  additional default-inserted element are appended.
2)  additional copies of value are appended.

Return:

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
        /*
        std::deque<const char*> you {"how","are", "you", "today?" };
        std::cout<<"you holds: "<<you<<std::endl;
        you.resize(6);
        std::cout<<"you, after resize up 6: "<<you<<std::endl;
        you.resize(2);
        std::cout<<"you, after resize down 2: "<<you<<std::endl;
        */
        std::deque<int> number {1,2,3};
        std::cout<<"number, before resize: "<<number<<std::endl;

        number.resize(5);

        std::cout<<"number, after resize up 5: "<<number <<std::endl;

        number.resize(2);
        std::cout<<"number, after resize down 2: "<<number<<std::endl;
    }

}
