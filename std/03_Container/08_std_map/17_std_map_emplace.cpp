/// Sequence containers : set
/// std::map
///
/// Modifier.
/// 17_std::map::emplace
/// definition in header < map >

/**
template<class... Args>
std::pair<iterator,bool> emplace ( Args&&... args);

Insert a new element into the container by constructing it in-place
with the given 'args' if there is no element with the key in the container.

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
            {'A',"key testing"}
        };
        ch.emplace('A',"test of 'A' key");
        ch.emplace('h',"How");
        ch.emplace('a',"are");
        ch.emplace('y',"you");
        ch.emplace('t',"today ?");
        std::cout<<ch<<std::endl;

        ch.clear();

        std::map<std::string,std::string> ms;

        /// uses  pair's move constructor
        ms.emplace(std::make_pair(std::string("a"), std::string("a")));

        /// uses pair's converting move constructor
        ms.emplace(std::make_pair("b", "ABCD"));

        /// uses pair's piecewise constructor
        ms.emplace(std::piecewise_construct,std::forward_as_tuple("c"),std::forward_as_tuple(10, 'c'));

        std::cout<<ms<<std::endl;



    }


}
