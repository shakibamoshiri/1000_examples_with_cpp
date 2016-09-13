/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 16_std::list::insert
/// definition in header < list >

/**
iterator insert ( iterator pos, const T& value);
iterator insert ( const_iterator pos, const T& value);
iterator insert ( const_iterator pos, T&& value);

void insert ( iterator pos, size_type count, const T& value);

iterator insert ( const_iterator pos, size_type count, const T& );

template <class InputIt>
    void insert (const_iterator pos, InputIt first, InputIt last);
template<class InputIt>
    iterator insert( const_iterator pos,InputIt first, InputIt last);

iterator insert ( const_initializer_list<T> ilist);

Inerts elements at the specified location in the container.

1,2)    Insert 'value' before 'pos'
3)      Insert 'count' copies of the 'value' before 'pos'
4)      Insert element from range [first,last) before 'pos'. This overload
        has the same effect as overload (3) if 'InputIt' is an integral type.
        This overload only participates in overload resolution if 'InputIt'
        qualifies as InputIterator, to avoid ambiguity ( = unclear or confusing )
        with the overload (3). The behavior is undefined if 'first' and 'last'
        are iterators into *this
5)      Insert elements from initializer list 'ilist' before 'pos'

Return value:
1,2)    Iterator pointing to the inserted 'value'.
3)      Iterator pointing to the first element inserted, or 'pos' if 'count'==0.
4)      Iterator pointing to the first element inserted, or 'pos' if first==last.
5)      Iterator pointing to the first element inserted, or 'pos' if 'ilist' is empty.


**/


#include <iostream>
#include <list>
#include <string>
#include <iomanip>
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
        std::list<const char*> you;

        you.insert(you.begin(),"How");
        std::cout<<you<<std::endl;

        you.insert(++you.begin(),2,"are");
        std::cout<<you<<std::endl;

        you.insert(++++++you.begin(),2,"you"); /// it is something,like you.begin()+3 or you.being()+=3
        std::cout<<you<<std::endl;

        you.insert(++++++++++you.begin(),{"today?"}); /// it is funny design that they do not overload + with iterator
        std::cout<<you<<std::endl;

        /// wrong
        // you.begin()+3;

        /// it is wrong to use for going forward or backward.
        const char* &cit = *you.begin();
        std::cout<<++cit<<std::endl;



    }

}
/* out put */
/*


*/
