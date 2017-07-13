/// Sequence containers : set
/// std::map
///
/// Lookup
/// 22_std::map::count
/// definition in header < map >

/**
size_type count ( const Key& key ) const;

template<class K>
size_type count ( const K& x ) const;
1.  Returns the number of element with key 'key',which is either 1 or 0
    since this container does not allow duplicates
2.  Returns the number of element with key that compares equivalent to
    the value x. This overload only participates in overload resolution
    if the qualified-id compare::is_transparent is valid and denoted a type.
    They allow calling  this function without constructing an instance of 'key'

Returns  value:
Number of elements with key 'key', that is either 1 or 0.
**/


//#include <unistd.h>
#include <iostream>
#include <string>
#include <map>

template<typename F,typename S>
std::ostream& operator<<(std::ostream& out,const std::map<F,S>& mp ){
    out.put('(').put(' ');
    for ( const std::pair<F,S> t : mp ) /// std::map<F,S> t is not true.
        out<<t.first<<':'<<t.second<<' ';
    return out.put(')');
}
void getStuff(){
    std::cout.put('\n');
}
template<typename F,typename... L>
void getStuff (F first, L... list){
    std::cout<<first.size()<<' ';
    getStuff(list...);
}
int main(){


    { /// my sample

    }
    { /// en.reference.com
        std::map<int,int> i2i;
        i2i.emplace(1,2);
        i2i.emplace(2,3);
        i2i.emplace(3,4);
        std::cout<<i2i<<std::endl;

        std::map<int,int> i2i2;

        std::cout<<i2i.count(1)<<std::endl; /// output is 1
        std::cout<<i2i2.count(1)<<std::endl; /// output is 0
    }


}
