/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 18_std::list::erase
/// definition in header < list >

/**
iterator erase (iterator pos);
iterator erase (cosnt_iterator pos);

iterator erase ( iterator_first, iterator last);
iterator erase (cosnt_iterator first,const_iterator last);

Removes specified elements from the container.
1)  Removes the element at 'pos'
2)  Removes the element in the range [first,last).

Reference and iterators to the erased element are invalidated.
Other reference and iterator are not affected. The iterator 'pos'
must be valid and dereferenceable. Thus the end() iterator (which
is valid, but is not dereferenceable ) cannot be used as a value
for 'pos'. The iterator 'first' does not need to be dereferenceable
if 'first'=='last' : erasing an empty range is a no-op.

**/


#include <iostream>
#include <list>
#include <string>
#include <iterator>
//#include <unistd.h>
template < typename L>
std::ostream& operator<<(std::ostream& out, const std::list<L>& listTemp){
    out.put('{');
    char camma = '\0';
    for ( const L l : listTemp ){
        out<< camma << l;
        camma=',';
    }
    out.put('}');

    return out;
}
/// only print size of list member:
void getBack(){
    std::cout<<std::endl;
}
template<typename F,typename... L>
void getBack (F first,L... lists){
    std::cout<<first.back()<<' ';
    getBack(lists...);
}
template<typename I,typename T>
std::iterator<I,T> operator+(std::iterator<I,T>& it,const int i){
}
int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::list<int> c{0,1,2,3,4,5,6,7,8,9};
        std::cout<<c<<std::endl;

        c.erase(c.begin());
        std::cout<<c<<std::endl;

        std::list<int>::iterator range_begin = c.begin();
        std::list<int>::iterator range_end = c.begin();
        std::advance(range_begin,2);
        std::advance(range_end,5);


        std::list<int> t{range_begin,range_end};
        c.erase(range_begin,range_end);

        std::cout<<c<<std::endl;
        std::cout<<"these element are erased : "<<t<<std::endl;
    }

}
/* out put */
/*


*/
