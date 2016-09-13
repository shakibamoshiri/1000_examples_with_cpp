/// Sequence containers : set
/// std::set
///
/// lookup
/// 18_std::set::count
/// definition in header < set >

/**
size_type count ( const Key& key ) const;
template<class K>
size_type count ( const k& x ) const;
1)  Returns the number of elements with key 'key', which is either 1 or 0 since this
    container does not allow duplicates
2)  Returns the number or elements with key that compares equivalent to the value 'x'.
    This overload only participates in overload resolution in the qualified-id
    compare::is_transparent is valid and denotes a type. They allow calling this
    function without constructing an instance of 'key'
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
        /// Number of elements with key 'key, that is either 1 or 0
        /// 1  = exist
        /// 0  = does not exist

        std::set<int>::size_type sz = integer.count(1);
        std::cout<<sz<<std::endl;
        /// or
        const int int_sz = integer.count(4);
        std::cout<<int_sz<<std::endl;
    }


}
