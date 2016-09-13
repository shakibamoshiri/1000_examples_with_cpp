/// Sequence containers : set
/// std::set
///
/// Member Function
/// 03_std::set::operator=
/// definition in header < set >

/**
set& operator=(const set& other);
set& operator=(set&& other);
set& operator=(std::initializer_list<value_type> ilist);

Replaces the contents of the container.

1. Copy assignment operator. Replaces the contents with a copy of the contents of 'other'.
2. Move assignment operator. Replace the contents with those of 'other' using move semantics.
3. Replaces the contents with those identified by initializer_list 'ilist'.

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
        std::set<int> one{1,2,3,4,5};
        std::set<int> two;
        std::set<int> three;
        std::cout<<"initially :             ";
        printStuff(one,two,three);

        two = one;
        std::cout<<"After copy assignment : ";
        printStuff(one,two,three);

        std::cout<<"After move assignment : ";
        three = std::move(one);
        printStuff(one,two,three);
    }
}














