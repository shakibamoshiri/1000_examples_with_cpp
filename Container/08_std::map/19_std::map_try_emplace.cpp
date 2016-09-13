/// Sequence containers : set
/// std::map
///
/// Modifier.
/// 19_std::map::try_emplace
/// definition in header < map >

/**
template <class... Args>
pair<iterator, bool> try_emplace(const key_type& k, Args&&... args);               (1) 	(since C++17)
template <class... Args>
pair<iterator, bool> try_emplace(key_type&& k, Args&&... args); 	            (2) 	(since C++17)
template <class... Args>
iterator try_emplace(const_iterator hint, const key_type& k, Args&&... args);   (3) 	(since C++17)
template <class... Args>
iterator try_emplace(const_iterator hint, key_type&& k, Args&&... args)         (4) 	(since C++17)

1) If a key equivalent to k already exists in the container, does nothing.
    Otherwise, behaves like emplace except that the element is constructed
    as value_type(std::piecewise_construct, std::forward_as_tuple(k),
                  std::forward_as_tuple(forward<Args>(args)...))
2) If a key equivalent to k already exists in the container, does nothing.
    Otherwise, behaves like emplace except that the element is constructed as
    value_type(std::piecewise_construct, std::forward_as_tuple(std::move(k)),
           std::forward_as_tuple(forward<Args>(args)...))
3) If a key equivalent to k already exists in the container, does nothing.
    Otherwise, behaves like emplace_hint except that the element is constructed
    as value_type(std::piecewise_construct, std::forward_as_tuple(k),
              std::forward_as_tuple(forward<Args>(args)...))
4) If a key equivalent to k already exists in the container, does nothing.
    Otherwise, behaves like emplace_hint except that the element is constructed as
    value_type(std::piecewise_construct, std::forward_as_tuple(std::move(k)),
           std::forward_as_tuple(forward<Args>(args)...))

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
    }


}
