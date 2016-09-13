/// Sequence containers : set
/// std::map
///
/// Access.
/// 06_std::map::operator[]
/// definition in header < map >

/**
T& operator[] (const Key& key);
T& operator[] ( Key&& key);

Returns a reference to the value that is mapped to a key equivalent to 'key',
preforming an insertion if such key does not already exist.


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
        ch.at('a') = "How w w w w w"; /// after repeated key, removed.
        ch.at('a') = "How";           /// repeated key is replaced
        ch.at('b') = "are";
        ch.at('c') = "you";
        ch.at('d') = "today?";

        std::cout<<ch<<std::endl;

        ch['a'] = "HOWWWWWW";
        ch['a'] = "HOW";
        ch['b'] = "ARE";
        ch['c'] = "YOU";
        ch['d'] = "TODAY ?";

        std::cout<<ch<<std::endl;

        ch['e'] = ch['a'];

        std::cout<<ch<<std::endl;

        /// I do not know why it has not effect :(
        ch['e'] = ch.operator[](std::move('a'));

        std::cout<<ch<<std::endl;
    }


}
