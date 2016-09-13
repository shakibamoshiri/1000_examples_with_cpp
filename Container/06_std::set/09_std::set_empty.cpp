/// Sequence containers : set
/// std::set
///
/// Capacity
/// 09_std::set::empty
/// definition in header < set >

/**
bool empty() const;

Checks if the container has no elements, i.e. whether ( begin() == end() )
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
        std::set<int> emptySet;
        std::boolalpha(std::cout);

        /// Is the container empty ?
        std::cout<<emptySet.empty()<<std::endl;
    }

}
