/// Sequence containers : set
/// std::set
///
/// lookup
/// 19_std::set::find
/// definition in header < set >

/**
iterator find ( const Key& k);
const_iterator find ( const Key& key ) const;

template<class K> iterator find ( const K& x);
template<class K> const_iterator find ( const K& x ) const;

1,2)    Finds an element with key equivalent to 'key'
3,4)    Finds an element with key that copares equivalent to the value x.
        This overload only participates in overload resolution if the
        qualified-id Compare::is_transparent is valid and denoted a type.
        It allow calling this function without construction an instance of 'key'.
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
        std::set<int>::iterator ser = integer.find(1);
        std::cout<<"find : "<<*ser<<" in container integer"<<std::endl;

        /// '!' is not exist but find returns last element: 9
        ser = integer.find('!');
        std::cout<<*ser;
    }


}
