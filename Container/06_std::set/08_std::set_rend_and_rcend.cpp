/// Sequence containers : set
/// std::set
///
/// Iterator
/// 08_std::set::rend_and_rcend
/// definition in header < set >

/**

reverse_iterator rend();
const_reverse_iterator rend() const;
const_reverse_iterator rcend() const;

Returns a reverse iterator to the element following the last element of the
reversed container. It corresponds to the element preceding the first element
of the non-reversed container. This element acts as a placeholder, attempting
tot access it results in undefined behavior.
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

void printStuff(){
    std::cout<<std::endl;
}
template<typename F, typename... L>
void printStuff(F first,L... list){
    std::cout<<' ';
    std::cout<<first.size();
    printStuff(list...);
}
int main(){


    { /// my sample
    }
    { /// en.reference.com
        /// Such as list, vector, etc
    }

}
