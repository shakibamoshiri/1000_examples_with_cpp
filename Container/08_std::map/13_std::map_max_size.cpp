/// Sequence containers : set
/// std::map
///
/// Capacity.
/// 13_std::map::max_size
/// definition in header < map >

/**
size_type max_size() const;

Returns the maximum number of elements the container is able to hold
due to system or library implementation limitation, i.e. std::distance
( begin() , end() ) for the largest container.
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
        std::map<char,const char*> ch{
            {'a',""},{'b',""},{'c',""},{'d',""},{'e',""}
        };
        std::map<int,int> i2i;

        if(i2i.empty())/// means is it empty() ?
            std::cout<<"yes 'i2i is an empty map"<<std::endl;

        const int sz = std::distance(ch.begin(),ch.end());
        std::cout<<"size of ch = "<<sz<<std::endl;

        const long msz = ch.max_size();
        std::cout<<"the maximum size of ch can get = "<<msz<<std::endl;
    }


}
