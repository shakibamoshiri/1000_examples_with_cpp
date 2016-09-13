/// Sequence containers : set
/// std::set
///
/// Modifier
/// 16_std::set::erase
/// definition in header < set >

/**
void erase(iterator pos);
iterator erase ( iterator pos);
iterator erase (const_iterator pos);
void erase ( iterator first, iterator last);
iterator erase ( const_iterator first, conat_iterator last);
size_type erase ( const key_type& key);

Removes specified element from the container.
1)  Removes the element at 'pos'
2)  Removes the element in the range [first, last), which must be a valid range in *this
3)  Removes the element ( if one exist ) with the key equivalent to 'key'

Reference and iterators to the erased elements are invalidated.
Other references and iterators are not affected.
The iterator 'pos' must be valid and dereferenceable. Thus the end() iterator
( which is valid, but is not dereferenceable ) cannot be used as a value for 'pos'


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
        std::set<int> integer{1,2,3,4,5,6,7,8,9,0};

        for ( auto it = integer.begin();it != integer.end(); )
            if ( *it % 2 == 0 )
                it = integer.erase(it); /// remove odd number
            else
                ++it;

        for ( int n : integer )
            std::cout<<n<<' ';
    }


}
