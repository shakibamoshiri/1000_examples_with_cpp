/// Sequence containers : set
/// std::map
///
/// Modifier.
/// 16_std::map::insert_or_assign
/// definition in header < map >

/** since c++17
template <class M>
pair<iterator, bool> insert_or_assign(const key_type& k, M&& obj);          (1) 	(since C++17)
template <class M>
pair<iterator, bool> insert_or_assign(key_type&& k, M&& obj);               (2) 	(since C++17)
template <class M>
iterator insert_or_assign(const_iterator hint, const key_type& k, M&& obj); (3) 	(since C++17)
template <class M>
iterator insert_or_assign(const_iterator hint, key_type&& k, M&& obj);      (4) 	(since C++17)

1,3) If a key equivalent to k already exists in the container, assigns std::forward<M>(obj)
    to the mapped_type corresponding to the key k. If the key does not exist, inserts the new
    value as if by insert, constructing it from value_type(k, std::forward<M>(obj))
2,4) Same as (1,3), except the mapped value is constructed from value_type(std::move(k),
    std::forward<M>(obj))

No iterators or references are invalidated.

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
        };


    }


}
