/// Sequence containers : set
/// std::map
///
/// Capacity.
/// 11_std::map::empty
/// definition in header < map >

/**
bool empty() const;
Checks if the container has no element, i.e. whether begin() == end()
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

    }


}
