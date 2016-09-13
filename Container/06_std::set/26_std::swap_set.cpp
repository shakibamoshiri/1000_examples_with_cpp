/// Sequence containers : set
/// std::set
///
/// Observes
/// 26_std::swap( std::set
/// definition in header < set >

/**
template<class Key, class Compare,class Alloc>
void swap( set<Key,Compare,Alloc>& lhs,set<Key,Compare,Alloc>& rhs);

Specializes the std::swap algorithm for std::set.
Swaps the contents of 'lsh' and  'rsh. Calling lhs.swap(rhs).
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
std::basic_ostream<CH, TR>& operator<<(std::basic_ostream<CH, TR>& out, std::set<CON>& container){
    out<<'{'<<*container.begin();
    for ( auto it = ++(container.begin());it != container.end();++it)
        out<<','<<*it;
    return out<<'}';
}

int main(){


    { /// my sample

    }
    { /// en.reference.com
        std::set<const char*> she{"she"};
        std::set<const char*> he{"he"};
        std::swap(she,he);
        std::cout<<"He : "<<he<<std::endl;


    }


}
