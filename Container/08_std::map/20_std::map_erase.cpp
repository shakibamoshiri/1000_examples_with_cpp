/// Sequence containers : set
/// std::map
///
/// Modifier.
/// 20_std::map::erase
/// definition in header < map >

/**
void erase ( iterator pos);
iterator erase ( iterator pos);
iterator erase ( const_iterator pos);

void erase ( iterator first, iterator last);
iterator erase ( const_iterator first, const_iterator last);

size_type erase ( const key_value& key);

Removes specified element form the container.
1.  Removes the element at 'pos'
2.  Removes the element in the range [first, last), which must be valid range in *this.
3.  Removes the element ( if not exist ) with the key equivalent to key.

Reference and iterator to the erased elements are invalidated.
Other references and iterators are not affected.
The iterator 'pos' must be valid end dereferenceable. Thus the end()
iterator ( which is valid, but is not deferenceable ) connot be used as
a value of 'pos'.
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
        std::map<int,int> i2i;
        i2i.emplace(1,2);
        i2i.emplace(2,3);
        i2i.emplace(3,4);
        std::cout<<i2i<<std::endl;

        i2i.erase(i2i.begin());
        std::cout<<i2i<<std::endl;

        i2i.emplace_hint(i2i.begin(),1,2);
        std::cout<<i2i<<std::endl;

        i2i.erase(1); /// remove (1:2) with key 1
        std::cout<<i2i<<std::endl;

        i2i.erase(i2i.begin(),i2i.end()); /// remove all element | affecting like i2i.clear
        std::cout<<i2i<<std::endl;
    }


}
