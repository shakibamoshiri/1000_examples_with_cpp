/// Sequence containers : set
/// std::map
///
/// Lookup
/// 23_std::map::find
/// definition in header < map >

/**
iterator find ( const Key& key ) const;
const_iterator find ( const Key& key ) const;
template<class K> iterator find ( const K& x );
template<class K> const_iterator find ( const K& x ) const ;

1,2     Find an element with key equivalent to 'key'
3,4     Find an element with key that compares equivalent to the value 'x'.
        This overload only participates ...

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

        std::map<int,int>::iterator it = i2i.find(3);

        if (!i2i.empty())
            std::cout<<it->first<<':'<<it->second<<std::endl;
        else
            std::cout<<"your given 'key' not found"<<std::endl;
    }


}
