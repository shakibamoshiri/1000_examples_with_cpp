/// Sequence containers : set
/// std::map
///
/// Non-member function
/// 30_std::swap ( std::map ) algorithm
/// definition in header < map >

/**
template<class Key, class T, class Compare, class Alloc>
void swap ( map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs);

Specializes the std::swap algorithm for std::map.
Swaps the contents of 'lhs' and 'rhs'. Calls lhs.swap(rhs).
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

        std::map<int,int> i2i2;
        i2i2[1]=100;
        i2i2[2]=200;
        i2i2[3]=300;

        std::map<int,int> i2i3;

        std::swap(i2i3,i2i2);
        std::cout<<i2i3<<std::endl;

    }


}
