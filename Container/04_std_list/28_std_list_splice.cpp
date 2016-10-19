/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 28_std::list::splice
/// definition in header < list >

/**
void splice ( const_iterator pos, list& other);
void splice ( const_iterator pos, list&& other);
void splice ( const_iterator pos, list& other, const_iterator it);
void splice ( const_iterator pos, list&& other, const_iterator it );
void splice ( const_iterator pos, list& other, const_iterator first, const_iterator last);
void splice ( const_iterator pos, list&& other, const_iterator first, const_iterator last);

Transfers elements from one list to another.

No element are copied or moved, only the internal pointers of the list nodes are
re-pointed. The behavior is undefined if:
get_allocator() != other.get_allocator(). No iterator or reference become invalidated
the iterators to moved elements remain valid, but now refer into *this not into other.

1.  Transfers all elements form 'other' into *this. The elements are inserted before the
    element pointed by 'pos'. The container 'other' becomes empty after the operation. The
    behavior is undefined if this == & other
2.  Transfers the element pointed by 'it' form 'other' into *this, the element is inserted
    before the element pointed to by 'pos'.
3.  Transfers the element in the range [first,last) from 'other' into *this. the element are
    inserted before the element pointed to by 'pos'. The behavior is undefined if 'pos'
    is an iterator in the range [first,last).

**/


#include <iostream>
#include <list>
#include <string>
#include <iterator>
//#include <unistd.h>
class Phone {
private:
    const char* name;
    const int age;
protected:
public:
    Phone() : name(""), age(0)
    {}
    Phone(const char* nameTemp,const int ageTemp)
        :name(nameTemp),age(ageTemp) {

        }
    friend std::ostream& operator<<(std::ostream& out,const Phone* objectTemp ){
        std::cout<<objectTemp->name<<' '<<objectTemp->age;
        return out;
    }
};
template < typename L>

std::ostream& operator<<(std::ostream& out, const std::list<L>& listTemp){
    out.put('{');
    out.put('\n');
    char camma = ' ';
    for ( const L l : listTemp ){
        out<< camma << l;
        /// for class boy must use &
         //out<< camma << &l;
        camma=',';
    }
    out.put('\n');
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


int main(){
    { /// user sample:
    }
    { /// sample of en.reference.com
        /// splice : to join the ends of two pieces or rope, film, etc
        ///          so that they form one continuous piece.

        std::list<int> one {1,2,3,4,5};
        std::list<int> two {10,20,30,40,50};

        auto it = one.begin();
        std::advance(it,2);

        one.splice(it, two);

        std::cout<<"one : "<<one<<std::endl;
        std::cout<<"two : "<<two<<std::endl;

        ///        pos      ,other, first, last
        two.splice(two.begin(), one, it, one.end());

        std::cout<<"one " <<one<<std::endl;
        std::cout<<"one " <<two<<std::endl;

    }

}
/* out put */
/*


*/
