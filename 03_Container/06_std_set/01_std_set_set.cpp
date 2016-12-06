/// Sequence containers : set
/// std::set
///
/// Member Function
/// 00_std::set::set
/// definition in header < set >

/**
explicit set ( const Compare& comp = compare(), const Allocator& alloc = Allocator());
set() : set ( Compare() ) {}

explicit set ( const Compare& comp, const Allocator& alloc = Allocator() );
explicit set ( const Allocator& alloc);

template<class InputIt>
set ( InputIt first, InputIt last, const Compare& comp = Compare() );

template<class InputIt>
set ( InputIt first,InputIt last, const Allocator& alloc)
    : set ( first, list, Compare(), alloc) {}

set ( const set& other);
set ( const set& other, const Allocator& alloc);
set ( const set&& other);
set ( const set&& other, const Allocator& alloc);

set ( std::initializer_list<value_type> init, const Compare& comp = Compare());

set ( std::initializer_list<value_type> init, const Allocator& alloc)
    : set ( init, Compare(), alloc) {}

Constructs new container form a variety of data sources and optionally using
user supplied allocator 'alloc' or comparison function 'comp'

1.  Default constructor. Constructs empty container.
2.  Range constructor. Constructs the containers with the contents of the range [first, last).
3.  copy constructor. Constructs the container with the copy of the contents of the 'other'
4.  Move constructor. Constructs the container with the contents of 'other' using move semantics.
5.  Initialize_list constructor. Constructs the container with the contents of the initializer_list 'init'
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
        ///1. default constructor
        std::set<std::string> one;
        one.insert("something");
        one.insert("anything");
        one.insert("that thing");
        std::cout<<"one : "<<one<<std::endl;

        ///2. iterator constructor
        std::set<std::string> two(one.find("anything"),one.end());
        std::cout<<std::string(40,'=')<<std::endl;;
        std::cout<<"two : "<<two<<std::endl;

        ///3. copy constructor
        std::set<std::string> three(one);
        three.insert("another thing");
        std::cout<<std::string(40,'=')<<std::endl;;
        std::cout<<"three : "<<three<<std::endl;

        ///4. Move constructor
        std::set<std::string> four(std::move(one));
        std::cout<<std::string(40,'=')<<std::endl;;
        std::cout<<"After move-constructor, one = nullptr"<<std::endl;
        std::cout<<"four : "<<four<<std::endl;

        ///5. initializer_list constructor
        std::set<std::string> five {"one","two","three","four","five"};
        std::cout<<std::string(40,'=')<<std::endl;;
        std::cout<<"five : "<<five<<std::endl;

    }
}














