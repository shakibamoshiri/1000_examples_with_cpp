/// Sequence containers : set
/// std::map
///
/// Iterator.
/// 10_std::map::rend_and_crend
/// definition in header < map >

/**
reverse_iterator rend();
const_reverse_iterator rend();
const_reverse_iterator crend();

Returns a reverse iterator to the element following the last element
of the reversed container. It corresponds to the element preceding the
first element of the non-reversed container. This element acts as  a
placeholder, attempting to access it results in undefined behavior.
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

        std::map<char,const char*>::reverse_iterator itManual = --ch.rend(); /// equal to begin()
        auto itAuto = --ch.crend(); /// equal to begin()

        std::cout<<itManual->first<<':'<<itManual->second<<std::endl;
        std::cout<<itAuto->first<<':'<<itAuto->second<<std::endl;

    }


}
