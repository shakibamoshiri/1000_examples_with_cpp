/// Sequence containers : set
/// std::set
///
/// lookup
/// 21_std::set::lower_bound
/// definition in header < set >

/**
iterator lower_bound ( const Key& key );
const_iterator lower_bound ( const Key& key ) const;

template <class K> iterator lower_bound ( const K& x);
template <class K> const_iterator lower_bound ( const K& x) const;

1.  Returns an iterator pointing to the first element that is not less than 'key'
2.  Returns an iterator pointing to the first element that compares not less to the
    value x. This overload only participates to overload resolution if the qualified-id
    Compare::is_transparent is valid and denotes type. They allow calling this function
    without constructing an instance of 'key'
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
        std::set<int> integer{10,20,30,40,50,100,200,500};
        std::pair<std::set<int>::iterator,std::set<int>::iterator> pair1,pair2;
        pair1  = integer.equal_range(55);
        std::cout<<*(pair1.first)<<' '<<*(pair1.second)<<std::endl;

        std::set<int>::iterator lower;
        lower = integer.lower_bound(22);
        std::cout<<*lower<<std::endl;

        std::set<int>::iterator upper;
        upper = integer.upper_bound(30);
        std::cout<<*upper<<std::endl;


    }


}
