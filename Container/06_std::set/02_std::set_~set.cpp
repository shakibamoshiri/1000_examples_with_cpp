/// Sequence containers : set
/// std::set
///
/// Member Function
/// 02_std::set::~set or destructor
/// definition in header < set >

/**
~set()

Destructs the container. The destructors of the elements are called and
used storage is deallocated. Note, that if the elements are pointers, the
pointed-to objects are not destroyed.

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

    }
}














