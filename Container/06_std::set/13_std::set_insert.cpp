/// Sequence containers : set
/// std::set
///
/// Modifier
/// 13_std::set::insert
/// definition in header < set >

/**
std::pair<iterator,bool> insert ( const value_type& value);
std::pair<iterator,bool> insert ( value_type&& value);

iterator insert ( iterator hint, const value_type& value);
iterator insert ( const_iterator hint, const value_type& value);
iterator insert ( const_iterator hint, value_type&& value);

template<class InputIt>
void insert ( InputIt first, InputIt last);
void inset ( std::initializer_list<value_type> ilist);

Inserts element(s) into the container, if the container does not already
contain an element with an equivalent key.
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
        auto r1 = integer.insert(3);
        assert(r1.first != integer.end()); /// it is a valid iterator

        assert(*r1.first == 3);
        if ( r1.second )
            std::cout<<"insert done\n";

        auto r2 = integer.insert(3);
        assert(r2.first == r1.first ); /// same iterator
        assert(*r2.first == 3 );
        if (!r2.second )
            std::cout<<"no insertion\n";
    }


}
