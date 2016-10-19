/// Sequence containers : set
/// std::set
///
/// Modifier
/// 17_std::set::swap
/// definition in header < set >

/**
void swap ( set& other );
Exchanges the contents of the container with those of 'other',
Does not invoke any move, copy, or swap operation on invalidated
elements.
All iterator  and reference remain valid. The past-the-end iterator is invalidated.

**/


//#include <unistd.h>
#include <iostream>
#include <string>
#include <set>


/// helper function for printing pairs
template<class CH,class TR,class A,class B>
std::basic_ostream<CH, TR>& operator<<(std::basic_ostream<CH, TR>& out,std::pair<A, B>& pair){
    return out <<'('<<pair.first<<','<<pair.second<<')';
}

/// helper function for printing containers
template<class CH, class TR, class CON>
std::basic_ostream<CH, TR>& operator<<(std::basic_ostream<CH, TR>& out, CON& container){
    out<<'{'<<*container.begin();
    for ( auto it = ++(container.begin());it != container.end();++it)
        out<<','<<*it;
    return out<<'}';
}

int main(){


    { /// my sample

    }
    { /// en.reference.com
        std::set<int> integer{1,2,3};
        std::set<int> _int{10,20,30};
        integer.swap(_int);
        for ( const int  f : _int )
            std::cout<<f<<' ';

        /// Notice
        /// swap can not swap two different kink of type
        /// such as int with float
        /// this is wrong:
        /// int_value.swap(float_value)
        /// both of two value must be the same type
    }


}
