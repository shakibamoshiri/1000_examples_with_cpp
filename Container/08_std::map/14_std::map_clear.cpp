/// Sequence containers : set
/// std::map
///
/// Modifier.
/// 14_std::map::clear
/// definition in header < map >

/**
void clear()

Removes all elements from the container.
Invalidates any reference, pointer or iterators referring to contained element.
May invalidate any past-the-end iterators.

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

        const int sz = std::distance(ch.begin(),ch.end());
        std::cout<<"size of ch = "<<sz<<std::endl;

        /// remove all element from the ch
        std::cout<<"Content of ch = "<<ch<<std::endl;
        ch.clear();

        std::cout<<"size of ch = "<<sz<<std::endl;
        std::cout<<"Content of ch = "<<ch<<std::endl;

    }


}
