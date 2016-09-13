/// Sequence containers : set
/// std::set
///
/// lookup
/// 20_std::set::equal_range
/// definition in header < set >

/**
std::pair<iterator,iterator> equal_range ( const Key& key );
set::pair<const_iterator,const_iterator> equal_range ( const Key& key ) const;
template<class K>
std::pair<iterator,iterator> equal_range ( const K& x ) const;
template<class K>
std::pair<const_iterator,const_iterator> equal_range ( const K& x ) const;

Returns a range containing all elements with the giving key in the
container. The range is defined by two iterator, one pointing to the
first element that is not less than 'key' another pointing to the first
element greater than 'key'. Alternatively, the first iterator may be
obtained with lower_bound(), and the second with upper_bound().

1,2)    Compares the key to 'key'
3,4)    Compares the key to the value 'x'.
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
        std::set<int> integer{1,2,3,4,5,6,7,8,9};
        std::pair<std::set<int>::iterator,std::set<int>::iterator> pair1,pair2;
        pair1  = integer.equal_range(5);
        std::cout<<*(pair1.first)<<' '<<*(pair1.second)<<std::endl;
        /// Return value:
        /**
        *  std::pair containing a pair of iterator defining the wanted range:
        *  the first pointing to the first element that is not /less/ than 'key'
        *  and the second pointing to the first element /greater/ than 'key'
        *
        **/
    }


}
