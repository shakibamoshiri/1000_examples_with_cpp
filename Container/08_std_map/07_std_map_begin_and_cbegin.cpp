/// Sequence containers : set
/// std::map
///
/// Iterator.
/// 07_std::map::begin and cbegin
/// definition in header < map >

/**
iterator begin();
const_iterator begin();
const_iterator cbegin();

Returns an iterator to the first element of the container.
If the container is empty, the returned iterator will be equal to end().
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

        std::cout<<ch<<std::endl;

        ch['a'] = "HOWWWWWW"; /// repeated is removed if initialize again, like below
        ch['a'] = "HOW";      /// it replace with above | but not in multimap
        ch['b'] = "ARE";
        ch['c'] = "YOU";
        ch['d'] = "TODAY ?";

        std::map<char,const char*>::iterator itManual = ch.begin();
        const auto itAuto = ch.begin();

        std::cout<<itManual->first<<':'<<itManual->second<<std::endl;
        std::cout<<itAuto->first<<':'<<itAuto->second<<std::endl;

    }


}
