/// Sequence containers : set
/// std::map
///
/// Modifier.
/// 18_std::map::emplace_hint
/// definition in header < map >

/**
template<class... Args>
iterator emplace_hint ( const_iterator hint, Args&&.. args);

Insert a new element to the container as close as possible to
the position just before 'hint'. The element is constructed
in-place i.e. no copy or move operations are preformed.
The constructor of the element type ( value_type, that is
std::pair<const Key, T> ) is called with exactly the same
arguments as supplies to the function, forwarded with std::forward<Args>(args)....

No iterators or reference are invalidated.

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
        std::map<char,const char*> ms{
            {'A',"key testing"}
        };

        ms.emplace_hint(ms.begin(),'a',"hello");
        std::cout<<ms<<std::endl;

        ms.clear();
        ms.emplace_hint(ms.begin(),'A',"Begin");
        ms.emplace_hint(ms.end(),std::pair<char,const char*>('Z',"end"));
        std::cout<<ms<<std::endl;

        ms.emplace_hint(ms.begin(),'A',"Begin again"); /// does not insert
        std::cout<<ms<<std::endl;

    }


}
