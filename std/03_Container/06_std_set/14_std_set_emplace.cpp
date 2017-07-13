/// Sequence containers : set
/// std::set
///
/// Modifier
/// 14_std::set::emplace
/// definition in header < set >

/**
template<class... Args>
std::pair<iterator, bool> emplace ( Args&&... args );

Inserts a new element into the container by constructing it in-place with
the given 'args' if there is no element with the key in the container.

**/


//#include <unistd.h>
#include <iostream>
#include <string>
#include <set>
#include <cassert>

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

        std::set<int> integer;
        integer.emplace(33);
        std::cout<<integer<<std::endl;
        integer.emplace(33);
        std::cout<<integer<<std::endl;
        integer.emplace(44);
        std::cout<<integer<<std::endl;


    }


}
